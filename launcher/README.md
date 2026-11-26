# Choco Launcher (planned)

The Android launcher is part of this **same repository**, not a separate repository.

## Home design

Reference: minimal Geode-like launcher screen:
- light, near-white background
- centered Choco logo
- single primary **Launch** button
- Settings gear beside Launch
- no mod list, store, cards, bottom navigation, or mod-management controls on Home

## Responsibilities

- Launch Geometry Dash through the defined Choco startup integration.
- Provide launcher settings in a separate Settings screen.
- No mod management UI here; mod management and mod settings are in-game and available when the Choco native loader is active.

## Planned stack

Kotlin + Jetpack Compose is a proposed Android UI stack; not yet adopted in code.

## Implementation status

Design/architecture note only. No Android project or launcher build workflow has been created yet.
