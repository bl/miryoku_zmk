## Overview
This project has wrapped the zmk Docker as a devcontainer, which will
1. Spin up the zmk tools docker container
2. Mount all zmk tool docker volumes to /workspaces (modules, tools, zephyr, zmk)
3. Mount the miryoku_zmk repo onto /workspaces
4. Pull zmk-config source on setup.sh


### Build Instructions
Under the Docker container, run the following to build left & right halves

```
cd /workspaces/zmk/app

west build --build-dir /workspaces/miryoku_zmk/build/corne_left --pristine --board nice_nano_v2 -- -DSHIELD=corne_left -DZMK_CONFIG=/workspaces/miryoku_zmk/config

west build --build-dir /workspaces/miryoku_zmk/build/corne_right --pristine --board nice_nano_v2 -- -DSHIELD=corne_right -DZMK_CONFIG=/workspaces/miryoku_zmk/config
```

Then access builds via the miryoku_zmk/build/* directory