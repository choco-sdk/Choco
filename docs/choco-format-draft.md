# Choco Mod Package Format — Draft

Status: **proposal only; not finalized**.

The user-defined product requirement is that distributed mods use the `.choco` extension and contain compiled code. The compiler is planned to support Termux and GitHub-hosted builds. This draft records requirements and a candidate container, without treating the candidate as an approved ABI or executable format.

## Requirements

- Mod files distributed/installed use the `.choco` extension.
- The package contains compiled mod code; it is not a source-only archive.
- Package metadata must identify the mod, its version, and compatibility/API version.
- Choco in-game manages installed mods and their settings. The launcher home remains minimal (Logo, Launch, Settings).
- Compiler workflows must be able to produce the same package on Termux and GitHub Actions.
- The package format needs versioning, validation, and safe rejection of malformed packages.

## Candidate container (not approved)

A ZIP-based container could hold:
- `manifest.json`: metadata and compatibility requirements
- `payload/`: compiled payload, with the actual payload type/ABI intentionally undecided
- optional assets/resources

This is only a candidate. Do not implement readers/writers or assume ZIP, JSON keys, payload names, or binary ABI until the format is approved.

## Decisions still open

1. Container: ZIP, custom container, or another format?
2. Manifest syntax: JSON, TOML, or binary metadata?
3. Payload architecture: native code, VM/bytecode, or hybrid?
4. Target architecture and ABI version policy?
5. Dependencies and ordering?
6. Signing/trust and permissions model?
7. Resource/assets layout and limits?

## Next engineering milestone

Compare container choices and settle the package structure, then implement a parser/validator with test fixtures before connecting any mod execution.
