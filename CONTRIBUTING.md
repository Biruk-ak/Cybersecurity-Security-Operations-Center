# Contributing to the SOC Platform

Thank you for your interest in improving the **Cybersecurity & Security Operations Center (SOC) Platform**. This guide explains how to clone, run, develop, and submit changes to this repository.

## Code of Conduct

- Be respectful and constructive in issues and pull requests.
- Do not share production secrets, customer data, or active exploit details in public channels.
- Security-sensitive reports go to **birukaklilu0110@gmail.com** (see [Security](#security-reports)).

## Ways to Contribute

- Bug reports (detections, UI, services, infra)
- Feature proposals (modules, APIs, playbooks, rules)
- Documentation and runbook improvements
- Tests (unit, integration, load)
- Performance and reliability hardening

## Development Setup

### 1. Fork and clone

```bash
git clone git@github.com:YOUR_USER/Cybersecurity-Security-Operations-Center.git
cd Cybersecurity-Security-Operations-Center
git remote add upstream git@github.com:Biruk-ak/Cybersecurity-Security-Operations-Center.git
```

### 2. Create a branch

```bash
git fetch upstream
git checkout -b feature/short-description upstream/main
```

Use prefixes such as `fix/`, `feature/`, `docs/`, `test/`, or `chore/`.

### 3. Run local dependencies

```bash
docker compose -f infra/docker-compose.yml up -d
```

### 4. Backend (C services)

```bash
cd services/gateway   # or identity, detection, soar-engine, …
make
make test
```

### 5. Frontend (React)

```bash
cd apps/web
npm install
npm start
npm test
```

### 6. CLI (optional)

```bash
cd apps/cli/cmd
gcc -O2 soc.c -o ../../soc
../../soc whoami
```

## Project Conventions

| Area | Guidance |
| --- | --- |
| C code | C11, clear module boundaries under `services/*/src`, tests in `services/*/tests` |
| React | TypeScript under `apps/web/src`, page + API + types + tests per module |
| Commits | Imperative mood, scoped when helpful (`feat(siem): …`, `fix(gateway): …`) |
| Secrets | Never commit `.env`, keys, tokens, or cloud credentials |
| Docs | Update `README.md` / `docs/` when behavior or setup changes |

## Submitting a Pull Request

1. Ensure your branch builds and relevant tests pass.
2. Push your branch to your fork (or this repo if you have write access):

   ```bash
   git push -u origin HEAD
   ```

3. Open a pull request against `main` using the [PR template](.github/pull_request_template.md).
4. Link related issues (`Closes #123`).
5. Request review and respond to feedback promptly.

### PR checklist (summary)

- [ ] Clear description of the change and why it is needed
- [ ] Tests added or updated when behavior changes
- [ ] No secrets or generated junk committed
- [ ] Docs updated if user-facing or operational behavior changed

## Opening Issues

Use the templates under [`.github/ISSUE_TEMPLATE/`](.github/ISSUE_TEMPLATE/):

- **Bug report** — reproducible failures, incorrect detections, UI defects
- **Feature request** — new module capability, API, or workflow improvement

Search existing issues before opening a duplicate. Include logs, versions, and reproduction steps when reporting bugs.

## Security Reports

Do **not** file public issues for vulnerabilities that could enable exploitation.

Email **birukaklilu0110@gmail.com** with:

- Affected component and version / commit
- Impact assessment
- Reproduction details (responsible disclosure)

## Maintainers

- Owner: **Biruk-ak** — `birukaklilu0110@gmail.com`

## License

By contributing, you agree that your contributions are provided under the same terms as the project [`LICENSE`](LICENSE).
