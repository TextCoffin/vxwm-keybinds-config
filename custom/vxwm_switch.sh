#!/bin/bash

# ================= SPEED SETTINGS =================
# Step multiplier. 1 = switch strictly by 1 workspace per scroll click.
# Increase to 2 or 3 to scroll faster by skipping workspaces.
STEP=1
# ==================================================

STATE_FILE="/tmp/vxwm_tag"
[ ! -f "$STATE_FILE" ] && echo "1" > "$STATE_FILE"
current=$(cat "$STATE_FILE")

if [ "$1" == "next" ]; then
    target=$((current + STEP))
    if [ "$target" -gt 9 ]; then target=1; fi
else
    target=$((current - STEP))
    if [ "$target" -lt 1 ]; then target=9; fi
fi

echo "$target" > "$STATE_FILE"

# Instant execution without any delays.
# The --delay 0 flag removes default xdotool keypress delays.
xdotool key --delay 0 --clearmodifiers "Super+$target"
