#!/bin/bash

#set your path
WALLPAPER_DIR="$HOME/Wallpapers"


if [ ! -d "$WALLPAPER_DIR" ]; then
exit 1
fi

RANDOM_WALLPAPER=$(find "$WALLPAPER_DIR" -type f \( -name "*.jpg" -o -name "*.jpeg" -o -name "*.png" \) | shuf -n 1)

if [ -n "$RANDOM_WALLPAPER" ]; then
feh --bg-fill "$RANDOM_WALLPAPER"
else
exit 1
fi

