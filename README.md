# CUSTOM branch
# vxwm keybinds config *1.1.6*

*!WARNING! YOU USE THIS AT YOUR OWN RISK! THIS IS YOUR RESPONSIBILITY!*

# install <br>
https://github.com/TextCoffin/reponstall.git <br>

*vxwm repo - https://github.com/wh1tepearll/vxwm.git* <br>
*vxwm vcompgr - https://codeberg.org/wh1tepearl/vcompmgr.git* <br>

*and you need exit the session(ctrl+super+alt+q)* <br>
<details>
  <summary>LIST OF KEYBINDS</summary>
  <br>
0======== <br>
super+ <br>
z - zoom to active program <br>
w - dmenu mode(browse program) <br>
a/d - switch the program(may be useful if you lost your window) <br>
space - set preset 0, and try f, t <br>
r - move to x0 y0 coordinate <br>
b - hide dmenu bar <br>
1-9 - you may be guess <br>
tab - show 1-9 window <br>
<details>
  <summary>MOUSE scroll - switch work spaces</summary>
<img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/keybinds/switch-work-spaces.gif" width="100%">
</details> <br>
1======== <br>
super+shift+ <br>
s - screenshot(fast screenshot) <br>
c - close the program <br>
q - fullscreen <br>
w - terminal <br>
enter - terminal <br>
1-9 - move program to work space <br>
<details>
  <summary>MOUSE scroll - zoom </summary>
<img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/keybinds/zoom-preview.gif" width="100%">
</details>
<details>
  <summary>MOUSE scroll button - reset zoom</summary>
<img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/keybinds/reset-zoom.gif" width="100%">
</details> <br>
2======== <br>
alt+ <br>
x - last track <br>
c - pause music <br>
v - next track <br>

3======== <br>
super+alt+ <br>
s - full screenshot <br>

4======== <br>
super+ctrl+ <br>
1-9 - show programs into another work spaces <br>
<details>
  <summary>S - screensot active work spaces</summary> 
<img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/keybinds/screen-active-workspaces.png" width="100%">
</details> <br>
5======== <br>
super+ctrl+shift+ <br>
1-9 - link the window to multiple tables at once1 <br>

6======== <br>
super+ctrl+alt - exit session <br>
</details>

<details>
  <summary>ADVICES</summary>
if you want use another terminal, edit this string
  https://github.com/TextCoffin/vxwm-keybinds-config/blob/3f08700c98e2109aeb69751b34191e7ee94a45f0/config.h#L121 <br>
if you want to use rofi or another launcher, edit this string 
  https://github.com/TextCoffin/vxwm-keybinds-config/blob/df381fd24922e5c7240be96f8d35c0c7faf1c8f4/config.h#L119
to like this

```bash
static const char *dmenucmd[] = { "rofi", "-show", "run", NULL };
```
<details>
  <summary>ACTIVE/INACTIVE window</summary>
  <img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/advices/active_inactive_window.png" width="100%"> <br>
  inactive border color - https://github.com/TextCoffin/vxwm-keybinds-config/blob/39860b0053e3a5afcdba9c2e34049fce9ad57511/config.h#L21 <br>
  active border color - https://github.com/TextCoffin/vxwm-keybinds-config/blob/39860b0053e3a5afcdba9c2e34049fce9ad57511/config.h#L24 <br>

  i uses ```#260069``` for inactive <br>
  and ```#5e03fc``` for active
</details>
<details>
  <summary>BAR</summary>
  <img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/advices/bar_0.png" width="100%"> <br>
  hide bar - 0 <br>
  <img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/advices/bar_1.png" width="100%"> <br>
  show bar - 1 <br>
  you can hide bar use https://github.com/TextCoffin/vxwm-keybinds-config/blob/4e2229a46403e2df8c157401d30692924744425d/README.md?plain=1#L23 <br>
  show bar 0-1 - https://github.com/TextCoffin/vxwm-keybinds-config/blob/4e2229a46403e2df8c157401d30692924744425d/config.h#L14 <br>
  <img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/advices/font_of_dmenu_15.png" width="100%">
  bar font
  if you need set font for bar
  https://github.com/TextCoffin/vxwm-keybinds-config/blob/4e2229a46403e2df8c157401d30692924744425d/config.h#L16 <br>
  and
  https://github.com/TextCoffin/vxwm-keybinds-config/blob/4e2229a46403e2df8c157401d30692924744425d/config.h#L17 <br>

  <img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/advices/topbar_0.png" width="100%">
  topbar - 0 <br>
  <img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/advices/topbar_1.png" width="100%">
  topbar - 1 <br>
</details>
<details>
  <summary>BORDER</summary>
  <img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/advices/borderpx3.png" width="100%">
  border px - 3
  <img src="https://github.com/TextCoffin/preview-of-my-keybinds-config/blob/main/advices/borderpx10.png" width="100%">
  border px - 10
  for it edit this string
  https://github.com/TextCoffin/vxwm-keybinds-config/blob/4e2229a46403e2df8c157401d30692924744425d/config.h#L12 <br>
</details>
test end
</details>
