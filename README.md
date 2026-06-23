# MHUR Launcher

Bypasses Easy Anti-Cheat (EAC) and the Epic Online Services anti-cheat check for **My Hero Ultra Rumble** under Linux/Proton.

## Problem

1. EAC's `start_protected_game.exe` launcher fails under Proton with *"no anti-cheat module has been found for this game and platform"*.
2. Even after bypassing EAC, `MHUR.exe` exits immediately because the EOS SDK anti-cheat client is unavailable.

## Solution

This replaces `start_protected_game.exe` with a minimal Windows PE that:

1. Launches `HerovsGame/Binaries/Win64/MHUR.exe` directly (bypassing EAC).
2. Sets `EOS_USE_ANTICHEATCLIENTNULL=1` — an Epic Online Services SDK dev flag that loads a null/stub anti-cheat client instead of the real one.

## Usage

1. Copy `start_protected_game.exe` to the game root directory:
   ```
   steamapps/common/My Hero Ultra Rumble/
   ```
   Back up the original first if desired.

2. Set Launch Option (Right Click game in steam > "properties..." > General -> Launch Options) to: EOS_USE_ANTICHEATCLIENTNULL=1 %command%

3. Launch from Steam as usual.

## Building from source

Requires `x86_64-w64-mingw32-gcc` (MinGW-w64).

```sh
x86_64-w64-mingw32-gcc -mwindows -O2 -static -s -o start_protected_game.exe launcher.c
```
