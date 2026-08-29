# vxwm keybinds config *1.1.2*

*WARNING! YOU USE THIS AT YOUR OWN RISK! THIS IS YOUR RESPONSIBILITY!* <br>
👇install👇😲 <br>
https://github.com/TextCoffin/reponstall.git <br>

*vxwm repo - https://github.com/wh1tepearll/vxwm.git* <br>
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

1======== <br>
super+shift+ <br>
s - screenshot(fast screenshot) <br>
c - close the program <br>
q - fullscreen <br>
w - terminal <br>
enter - terminal <br>
1-9 - move program to work space <br>

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

5======== <br>
super+ctrl+shift+ <br>
1-9 - link the window to multiple tables at once1 <br>

6======== <br>
super+ctrl+alt - exit session <br>
</details>
if you want use another terminal, edit this string - https://github.com/TextCoffin/vxwm-keybinds-config/blob/aadc16b491702142a1a247fab9de63a098659fe2/config.h#L120
if you want to use rofi or another launcher, edit this string - https://github.com/TextCoffin/vxwm-keybinds-config/blob/aadc16b491702142a1a247fab9de63a098659fe2/config.h#L118
to like this

```bash
static const char *dmenucmd[] = { "rofi", "-show", "run", NULL };
```
