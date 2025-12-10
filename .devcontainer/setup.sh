#!/bin/bash
set -e

# Clone ZMK if it doesn't exist
if [ ! -d "/workspaces/zmk/.git" ]; then
  echo "Setting up ZMK..."
  cd /workspaces
  git clone https://github.com/zmkfirmware/zmk.git
  cd zmk
  west init -l app/
  west update
  west zephyr-export
  echo "ZMK setup complete!"
else
  echo "ZMK already exists, skipping setup"
fi

# Add build alias for convenience
echo "alias miryoku-build='cd /workspaces/zmk/app && west build -d build/\$1 -p -b \$2 -- -DSHIELD=\$3 -DZMK_CONFIG=/workspaces/miryoku_zmk/config'" >> /root/.bashrc