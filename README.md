# vxwm keybinds config *1.1*
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
```
*and you need exit the session(ctrl+super+alt+q)*

*program for work keybinds*
```bash
sudo pacman -S dmenu xclip maim playerctl
```
