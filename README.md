# vxwm keybinds config *1.1.2*
*vxwm repo - https://github.com/wh1tepearll/vxwm.git*


# WARNING! YOU USE THIS AT YOUR OWN RISK! THIS IS YOUR RESPONSIBILITY!
*arch linux*
```bash
cd ~/vxwm
git clone https://github.com/TextCoffin/vxwm-keybinds-config.git
rm -rf config.h
mv ~/vxwm/vxwm-keybinds-config/config.h ~/vxwm
rm -rf ~/vxwm/vxwm-keybinds-config
sudo make clean install
#program for work keybinds
sudo pacman -S dmenu xclip maim playerctl kitty
```
*and you need exit the session(ctrl+super+alt+q)*

list of keybinds
*it list has in the config.h*
*
0========
super+
z - zoom to active program
w - dmenu mode(browse program)
a/d - switch the program(may be useful if you lost your window)
space - set preset 0, and try f, t
r - move to x0 y0 coordinate
b - hide dmenu bar
1-9 - you may be guess
tab - show 1-9 window
1========
super+shift+
s - screenshot(fast screenshot)
c - close the program
q - fullscreen
w - terminal
enter - terminal
1-9 - move program to work space
2========
alt+
x - last track
c - pause music
v - next track
3========
super+alt+
s - full screenshot
4========
super+ctrl+
1-9 - show programs into another work spaces
5========
super+ctrl+shift+
1-9 - link the window to multiple tables at once1
6========
super+ctrl+alt - exit session
*
