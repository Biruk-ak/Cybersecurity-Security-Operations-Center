# Architecture Deep Dive (2021)

Early design notes for gateway, identity, and SIEM ingest boundaries.

## Goals
- Isolate auth at the gateway
- Keep ingest pipelines horizontally scalable via Kafka
- Persist entities in PostgreSQL; search alerts in Elasticsearch
