# csgoon

A CS2 C++ internal.

## Architecture

- **D3D11 Present Hook** — ImGui overlay for menu, ESP, and visual features
- **CreateMove Hook** — Intercepts input commands for aim and anti-aim
- **Entity System** — Walks the client entity list each frame, resolves controllers to pawns, caches data behind a shared mutex
- **Safe Memory** — SEH-wrapped read/write wrappers around CS2 netvars; bad pointers are caught rather than crashing

## Feature Status

### Working

| Feature | Description |
|---------|-------------|
| **Rage Aimbot** | Instant lock with FOV, team check, hitbox selection (head/body), RCS compensation, autoshoot, counter-strafe auto-shot |
| **Legit Aimbot** | Smooth aim with configurable FOV, smoothing factor, hitbox selection, team check |
| **Triggerbot** | Fire-on-crosshair with smoke check, configurable delay, toggle/hold keybind, recoil settle check for non-snipers |
| **ESP** | Box, corner box, box fill, skeleton, health bar — separate colors for enemies and teammates |
| **Enemy Counter** | Live count of alive enemies |
| **No Flash** | Zeroes flashbang alpha overlays |
| **FOV Circle** | On-screen circle showing current aimbot FOV |
| **Config System** | Create, save, load, delete, autoload, and reset configs to disk |
| **Menu** | Custom ImGui with dark purple theme, sidebar tabs, keybind system, color pickers, live ESP preview |

### Not Working

| Feature | Status |
|---------|--------|
| Silent Aim | Broken |
| Legit RCS | Broken |
| No Smoke | Broken |
| No Spread | broken |
| Bunny Hop | Broken |
| Multipoint | Not implemented |
| Autoshoot | Broken |
| Third Person | Broken |
| Auto Strafe | Not implemented |

### Removed

- Radar
- Name esp

## New Since Last Update

- **Auto Accurate** — Counter-strafe auto-shot in ragebot. Fires during the brief velocity window between A-D or D-A strafe changes when horizontal speed drops below 10 u/s. Includes wall visibility check and sniper bypass.
- **FOV Circle** — Visual overlay showing the active aimbot FOV range.
- **Sniper Detection** — Triggerbot and Auto Accurate skip recoil checks when using sniper rifles (AWP, G3SG1, SCAR-20, SSG 08).
- **Recoil Check** — Triggerbot waits for aim punch to settle before firing on non-sniper weapons.

## Building

- Windows 11 SDK
- DirectX SDK (June 2010)
- C++17 or later

Compile as a DLL and inject into `cs2.exe`.

## Project Structure

```
src/
  core/           — Entry point, D3D11/CreateMove hooks, input handling
  feature/
    combat/       — Ragebot, legit aimbot, triggerbot
    misc/         — Bhop, noflash, nosmoke, configs
    visuals/      — ESP, enemy counter
  menu/           — ImGui overlay and controls
  sdk/
    entity/       — Entity manager, schema classes
    memory/       — Pattern scanner, offsets, safe R/W
    utils/        — Math, vectors, W2S, globals
  ext/            — MinHook, ImGui
```

## Notes

- Offsets are pulled from `Offsets.h` (CS2 schema dump). Update after game patches.
- The `CreateMove` hook is pattern-scanned at runtime.
- All memory reads are wrapped in SEH `__try/__except` blocks.

## Disclaimer

For educational  purposes only. Use at your own risk.
