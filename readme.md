# Miryoku ZMK Config

Personal ZMK firmware configuration using Miryoku layout for Corne keyboard with nice!nano v2.

## Building Firmware

### GitHub Actions (Recommended)

Push to GitHub and the workflow automatically builds firmware. Download the `.uf2` files from the Actions artifacts.

Builds generated:
- Corne without display (left + right)
- Corne with nice!view (left + right)

### Local Build (Docker/Devcontainer)

This repo includes a devcontainer that sets up the ZMK build environment.

1. Open in VS Code with the Dev Containers extension, or manually start the devcontainer

2. Inside the container, build firmware:
   ```bash
   cd /workspaces/zmk/app
   
   # Build left half
   west build --build-dir /workspaces/miryoku_zmk/build/corne_left --pristine \
     --board nice_nano_v2 -- \
     -DSHIELD=corne_left \
     -DZMK_CONFIG=/workspaces/miryoku_zmk/config
   
   # Build right half
   west build --build-dir /workspaces/miryoku_zmk/build/corne_right --pristine \
     --board nice_nano_v2 -- \
     -DSHIELD=corne_right \
     -DZMK_CONFIG=/workspaces/miryoku_zmk/config
   
   # For nice!view builds, add the shields:
   # -DSHIELD="corne_left nice_view_adapter nice_view"
   ```

3. Flash: Firmware is in `build/*/zephyr/zmk.uf2` - copy to your keyboard's bootloader drive