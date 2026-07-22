#!/bin/bash

TARGET_DIR="$HOME/Pictures/Screenshots"
mkdir -p "$TARGET_DIR"
TMP_PREFIX="$TARGET_DIR/tmp_dsktp"

MOD_KEY="super"

ACTIVE_WS_RAW=$(wmctrl -l | awk '$2 != "-1" {print $2}' | sort -n -u)

WORKSPACES=()
for ws in $ACTIVE_WS_RAW; do
    WORKSPACES+=($((ws + 1)))
done

CURRENT_WS=$(wmctrl -d | awk '$2 == "*" {print $1}')
CURRENT_WS=$((CURRENT_WS + 1))

if [ ${#WORKSPACES[@]} -eq 0 ]; then
    WORKSPACES+=($CURRENT_WS)
fi

COLLAGE_FILE="$TARGET_DIR/collage_$(date +%Y%m%d_%H%M%S).png"

# ==============================================================================
# SINGLE WORKSPACE MODE
# ==============================================================================
if [ ${#WORKSPACES[@]} -le 1 ]; then
    maim "$COLLAGE_FILE"
    xclip -selection clipboard -t image/png -i "$COLLAGE_FILE"
    echo "!only 1 work space active, fast snapshot done!"
    exit 0
fi

# ==============================================================================
# MULTIPLE WORKSPACES MODE (COLLAGE)
# ==============================================================================
ORIGINAL_DESKTOP=$CURRENT_WS

PICOM_ARGS=$(ps -C picom -o args= | head -n 1)
killall picom 2>/dev/null
sleep 0.1 # pause for X-server

SNAPSHOTS=()

for ws in "${WORKSPACES[@]}"; do
    xdotool key "${MOD_KEY}+${ws}"

    sleep 0.2

    FILE_PATH=$(printf "%s_%02d.png" "$TMP_PREFIX" "$ws")

    maim "$FILE_PATH"
    SNAPSHOTS+=("$FILE_PATH")
done

xdotool key "${MOD_KEY}+${ORIGINAL_DESKTOP}"
sleep 0.1

if [ -n "$PICOM_ARGS" ]; then
    eval "$PICOM_ARGS &"
else
    picom &
fi

montage "${SNAPSHOTS[@]}" -tile x1 -geometry +0+0 "$COLLAGE_FILE"

xclip -selection clipboard -t image/png -i "$COLLAGE_FILE"

rm "${SNAPSHOTS[@]}"

echo "!finded ${#SNAPSHOTS[@]} work spaces, collage done!"
