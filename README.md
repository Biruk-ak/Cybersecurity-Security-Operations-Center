# Cybersecurity & Security Operations Center (SOC) Platform

[![License](https://img.shields.io/badge/license-Proprietary-blue.svg)](./LICENSE)
[![Platform](https://img.shields.io/badge/platform-Kubernetes-326CE5.svg)](#architecture)
[![Backend](https://img.shields.io/badge/backend-C11-00599C.svg)](#architecture)
[![Frontend](https://img.shields.io/badge/frontend-React-61DAFB.svg)](#applications)
[![Tests](https://img.shields.io/badge/tests-2500%2B-success.svg)](#testing)

Next-generation **enterprise cybersecurity platform** for manufacturing and critical operations — designed in the spirit of Microsoft Sentinel, Splunk Enterprise Security, CrowdStrike Falcon, and IBM QRadar.

Built and maintained by **[Biruk-ak](https://github.com/Biruk-ak)** (`birukaklilu0110@gmail.com`).

---

## Table of Contents

- [Introduction](#introduction)
- [Core Modules](#core-modules)
- [Architecture](#architecture)
- [Applications](#applications)
- [Repository Layout](#repository-layout)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage Examples](#usage-examples)
- [Configuration](#configuration)
- [Testing](#testing)
- [Contributing](#contributing)
- [Security](#security)
- [License](#license)

---

## Introduction

The **Cybersecurity & Security Operations Center (SOC) Platform** unifies identity, detection, response, and compliance into a single operating model for security analysts, administrators, and plant-floor defenders.

It provides:

- Real-time SIEM ingest and correlation
- SOAR playbooks for automated response
- EDR command-and-control for endpoints
- Threat intelligence matching (IOC / STIX-TAXII)
- Privileged access, MFA, and SSO controls
- Manufacturing / OT-ICS vertical protections
- Executive risk and compliance reporting

Use it as a full SOC stack, or adopt individual microservices (gateway, identity, detection, SOAR, analytics) behind your existing control plane.

---

## Core Modules

| Domain | Modules |
| --- | --- |
| Identity | IAM, SSO, MFA, PAM |
| Detect & Respond | SIEM, SOAR, EDR, AI Threat Detection |
| Intelligence | Threat Intelligence, Vulnerability Scanner, Asset Discovery |
| Governance | Compliance, Risk Assessment, Audit Logging, Security Policies |
| Protect | DLP, Encryption, Certificate Management, Device Management |
| Cloud & Network | API Security, Cloud Security, Kubernetes Security, Network Monitoring, Firewall Management |
| Insight | Security Analytics, Reporting, Executive Dashboard |

---

## Architecture

```text
                 ┌──────────────────────────────┐
                 │  Analyst / Admin / Mobile UI │
                 └──────────────┬───────────────┘
                                │
                         API Gateway (C)
                                │
        ┌───────────┬───────────┼───────────┬───────────┐
        ▼           ▼           ▼           ▼           ▼
   Identity     SIEM Ingest  Detection   SOAR Engine   EDR
        │           │           │           │           │
        └───────────┴─────┬─────┴───────────┴───────────┘
                          │
          Kafka · Redis · PostgreSQL · ClickHouse
          Elasticsearch · OpenSearch
                          │
              Prometheus · Grafana · Loki · Jaeger
```

**Infrastructure:** Kubernetes, Terraform, Helm  
**Streaming & data:** Kafka, Redis, PostgreSQL, ClickHouse, Elasticsearch, OpenSearch  
**Observability:** Prometheus, Grafana, Loki, Jaeger  

---

## Applications

| App | Path | Description |
| --- | --- | --- |
| Security Analyst Dashboard | `apps/web` | React console for detections, cases, and investigations |
| Admin Portal | `apps/admin` | Tenant, policy, and platform administration |
| Mobile App | `apps/mobile` | On-call monitoring client |
| Desktop Client | `apps/desktop` | Local monitoring companion |
| CLI | `apps/cli` | Analyst and automation command line |
| Public API | `apps/public-api` | OpenAPI surface for integrations |

---

## Repository Layout

```text
.
├── apps/                 # Web, admin, mobile, desktop, CLI, public API
├── services/             # C microservices (gateway, identity, SIEM, SOAR, …)
├── libs/shared/          # Shared C libraries (Kafka, Redis, metrics, …)
├── verticals/            # Manufacturing / OT-ICS controls
├── rules/                # Detection rule packs
├── infra/                # Docker Compose, Helm, Terraform, monitoring
├── migrations/           # PostgreSQL schemas
├── protos/               # gRPC / protobuf contracts
├── tests/load/           # Performance harnesses
├── docs/                 # Architecture, security, runbooks
└── .github/              # Issue & PR templates
```

---

## Prerequisites

- **Git** 2.30+
- **Node.js** 18+ and npm (web / admin clients)
- **GCC** with C11 support (`gcc` / `clang`)
- **Make**
- **Docker** & **Docker Compose** (local dependencies)
- **kubectl**, **Helm** 3+, **Terraform** 1.0+ (cluster deploy)
- Optional: `gh` CLI for GitHub workflows

---

## Installation

### 1. Clone the repository

```bash
git clone git@github.com:Biruk-ak/Cybersecurity-Security-Operations-Center.git
cd Cybersecurity-Security-Operations-Center
```

### 2. Start local infrastructure

```bash
docker compose -f infra/docker-compose.yml up -d
```

This brings up PostgreSQL, Redis, Kafka, Elasticsearch, ClickHouse, and OpenSearch.

### 3. Apply database migrations

```bash
export PGPASSWORD=soc
psql -h localhost -U soc -d soc -f migrations/001_tenants.sql
# Apply remaining module migrations as needed:
# psql -h localhost -U soc -d soc -f migrations/100_iam.sql
```

### 4. Build a C microservice

```bash
cd services/gateway
make
# or build objects / run unit tests:
make test
cd ../..
```

### 5. Run the React analyst dashboard

```bash
cd apps/web
npm install
npm start
```

The dashboard expects the API gateway on `http://localhost:8080` by default.

### 6. Deploy to Kubernetes (optional)

```bash
kubectl apply -f infra/k8s/namespace.yaml
helm upgrade --install soc-gateway infra/helm/gateway -n soc-platform
terraform -chdir=infra/terraform init
terraform -chdir=infra/terraform apply -var="environment=dev"
```

---

## Usage Examples

### CLI — identity check and commands

```bash
# From apps/cli after building
./soc whoami
# Biruk-ak <birukaklilu0110@gmail.com>

./soc login
./soc alerts
./soc incidents
```

### Public API — list alerts (OpenAPI)

```bash
curl -sS -H "Authorization: Bearer $SOC_TOKEN" \
  "https://api.soc.example.com/v1/siem?status=open&severityMin=7"
```

### Analyst UI routes

After `npm start` in `apps/web`:

| Route | Module |
| --- | --- |
| `/siem` | SIEM detections & events |
| `/soar` | Playbooks & cases |
| `/edr` | Endpoint response |
| `/iam` | Identity & access |
| `/executive-dashboard` | Leadership KPIs |

### Detection rules

Rule packs live under `rules/packs/`. Example:

```yaml
id: rule-00-000
name: Detection 0-0
severity: 1
actions: [create_alert, enrich_threat_intel, notify_soar]
```

Load evaluators from `services/detection-rules` as part of your detection pipeline.

### Gateway health

```bash
export SOC_PORT=8080
./services/gateway/build/gateway   # or your built binary
curl -f "http://localhost:8080/healthz"
```

---

## Configuration

Common environment variables:

| Variable | Purpose | Example |
| --- | --- | --- |
| `SOC_PORT` | Service listen port | `8080` |
| `SOC_KAFKA_BROKERS` | Kafka bootstrap | `kafka:9092` |
| `SOC_REDIS_URL` | Cache / sessions | `redis://redis:6379` |
| `SOC_POSTGRES_DSN` | Primary DB | `postgres://soc:soc@postgres:5432/soc` |
| `SOC_CLICKHOUSE_URL` | Analytics store | `http://clickhouse:8123` |
| `SOC_ELASTICSEARCH_URL` | Search | `http://elasticsearch:9200` |
| `SOC_OPENSEARCH_URL` | Alt search | `http://opensearch:9200` |

**Never commit secrets.** Use `.env` locally (ignored) or your cluster secret manager.

---

## Testing

```bash
# C service tests
cd services/detection && make test

# Web unit / integration tests
cd apps/web && npm test

# Load scenarios
gcc -O2 tests/load/scenario_00.c -o /tmp/soc-load && /tmp/soc-load
```

Target coverage: **2500+ automated tests** across C services, React clients, contracts, and load harnesses. See [`docs/TESTING.md`](docs/TESTING.md).

---

## Contributing

We welcome improvements that harden detection quality, reduce analyst toil, and improve manufacturing/OT coverage.

1. Read [`CONTRIBUTING.md`](CONTRIBUTING.md)
2. Open an issue using the [bug](.github/ISSUE_TEMPLATE/bug_report.md) or [feature](.github/ISSUE_TEMPLATE/feature_request.md) template
3. Submit a PR using the [pull request template](.github/pull_request_template.md)

---

## Security

- Report vulnerabilities privately to **birukaklilu0110@gmail.com**
- See [`docs/SECURITY.md`](docs/SECURITY.md) for mesh, secrets, and audit expectations
- Do not open public issues for active exploitation details

---

## License

Copyright © 2020–2026 Biruk-ak. All rights reserved. See [`LICENSE`](LICENSE).

---

**Cybersecurity & Security Operations Center (SOC) Platform** — detect faster, respond smarter, operate safer.
