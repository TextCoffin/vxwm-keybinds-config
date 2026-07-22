#pragma once
/*program whitch you need(for me!)*/
/*sudo pacman -S dmenu xclip maim playerctl kitty*/

/*okay sure, here lists of keybinds
0========================================
super+
z - zoom to active program
w - dmenu mode(browse program)
a/d - switch the program(may be useful if you lost your window)
space - set preset 0, and try f, t
r - move to x0 y0 coordinate
b - hide dmenu bar
1-9 - you may be guess
tab - show 1-9 window
1========================================
super+shift+
s - screenshot(fast screenshot)
c - close the program
q - fullscreen
w - terminal
enter - terminal
1-9 - move program to work space
2========================================
alt+
x - last track
c - pause music
v - next track
3========================================
super+alt+
s - full screenshot
4========================================
super+ctrl+
1-9 - show programs into another work spaces
s - screenshot everything active work spaces
5========================================
super+ctrl+shift+
1-9 - link the window to multiple tables at once1
6========================================
super+ctrl+alt - exit session
*/


/* See LICENSE file for copyright and license details. */
/*link on author - https://github.com/wh1tepearll/vxwm/tree/main*/
/* music const's */
static const char *mediapausecmd[] = { "playerctl", "play-pause", NULL };
static const char *medianextcmd[] = { "playerctl", "next", NULL };
static const char *mediaprevcmd[] = { "playerctl", "previous", NULL };
/* screenshots - xclip maim */
static const char *screenshot_select_clip[] = { "sh", "-c", "maim -s | xclip -selection clipboard -t image/png", NULL };
static const char *screenshot_collage_cmd[] = { "~/vxwm/custom/screenshot_all.sh", NULL };


/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
#define COORDINATES_STYLE "[x%d y%d]" /* The style of coordinates displayed in bar, do not remove %d. */

static MAYBE_CONST char normbgcolor[]           = "#222222";
static MAYBE_CONST char normbordercolor[]       = "#444444";
static MAYBE_CONST char normfgcolor[]           = "#bbbbbb";
static MAYBE_CONST char selfgcolor[]            = "#eeeeee";
static MAYBE_CONST char selbordercolor[]        = "#005577";
static MAYBE_CONST char selbgcolor[]            = "#005577";
static MAYBE_CONST char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

#define CENTER_NEW_FLOATING_WINDOWS 1 // so, basically, it does what it says. (make 0 to turn off)
#define NEW_FLOATING_WINDOWS_APPEAR_UNDER_CURSOR 0 // so, basically, it does what it says. (make 0 to turn off) 

#if GAPS
static const unsigned int gappx = 5;
#endif

#if BAR_HEIGHT
static const int user_bh = 0;
#endif

#if BAR_PADDING
static const int top_vertpad = 3;          /* top vertical padding of bar */ 
static const int bottom_vertpad = 3;       /* bottom vertical padding of bar */
static const int left_sidepad = 3;         /* left horizontal padding of bar */
static const int right_sidepad = 3;        /* right horizontal padding of bar */
#endif

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

#if OCCUPIED_TAGS_DECORATION
static const char *occupiedtags[] = { "1+", "2+", "3+", "4+", "5+", "6+", "7+", "8+", "9+" };
#endif

#if INFINITE_TAGS
#define MOVE_CANVAS_STEP 120 /* Defines how many pixel will be jumped when using movecanvas function */
#endif

#if INFINITE_TAGS && IT_SHOW_COORDINATES_IN_BAR
#define COORDINATES_DIVISOR 10 /* Defines by what number coordinates on the bar will be divided, can be used for making numbers smaller which makes navigation easier */
#endif

#if MOVE_RESIZE_WITH_KEYBOARD
#define MOVE_WITH_KEYBOARD_STEP 50 /* Defines by how many pixels windows will be resized with keyboard */
#define RESIZE_WITH_KEYBOARD_STEP 50 /* Defines by how many pixels windows will be resized with keyboard */
#endif

#if AUTOSTART
/* vxwm will execute this on startup (can be skipped with -ignoreautostart vxwm flag). */

static const char *const autostart[] = {
	"st",
	NULL /* must end with NULL */
};
#endif

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
#if LOCK_MOVE_RESIZE_REFRESH_RATE
static const int refreshrate = 360;  /* refresh rate (per second) for client move/resize, set it to your monitor refresh rate or double of that*/
#endif //LOCK_MOVE_RESIZE_REFRESH_RATE
static const Layout layouts[] = {
	/* symbol     arrange function */
  { "><>",      NULL },    /* no layout function means floating behavior */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTERNATE_MODKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,                     KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };

static const char *termcmd[]  = { "kitty", NULL };

static const Key keys[] = {
	/*my keys for pause track*/
        /*utilite - playerctl*/
	{ Mod1Mask, XK_c, spawn, {.v = mediapausecmd} },
	{ Mod1Mask, XK_v, spawn, {.v = medianextcmd} },
	{ Mod1Mask, XK_x, spawn, {.v = mediaprevcmd} },

	{ Mod4Mask|ShiftMask, XK_s, spawn, {.v = screenshot_select_clip } },
    { MODKEY|Mod1Mask,  XK_s,  spawn,          SHCMD("maim | xclip -selection clipboard -t image/png") },
	{ MODKEY|ControlMask, XK_s, spawn, {.v = screenshot_collage_cmd} },


	/* modifier                     key        function        argument */
	/*dmenu bar*/
        { MODKEY,                       XK_w,      spawn,          {.v = dmenucmd } },
  { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
  { MODKEY|ShiftMask,             XK_w, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_a,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_s,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, swapmaster,     {0} },
	{ MODKEY,                       XK_0,      view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_y,  togglefloating, {0} }, //default toggle floating bind.
	{ MODKEY,                       XK_Tab,    view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ Mod4Mask|ControlMask|Mod1Mask,             XK_q,      quit,           {0} },
#if XRDB
  { MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
#endif
#if FULLSCREEN
  { MODKEY|ShiftMask,             XK_q,      togglefullscr,  {0} },
#endif
#if ENHANCED_TOGGLE_FLOATING
  { MODKEY,                       XK_z,      enhancedtogglefloating, {0} }, //enhanced toggle floating bind.
#endif
#if GAPS
  { MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
  { MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
  { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
#endif
#if MOVE_RESIZE_WITH_KEYBOARD
  { MODKEY,					              XK_Down,	moveresize,		{.v = (int []){ 0, MOVE_WITH_KEYBOARD_STEP, 0, 0 }}}, // Move window to down
  { MODKEY,					              XK_Up,		moveresize,		{.v = (int []){ 0, -MOVE_WITH_KEYBOARD_STEP, 0, 0 }}}, // Move window to up
  { MODKEY,					              XK_Right,	moveresize,		{.v = (int []){ MOVE_WITH_KEYBOARD_STEP, 0, 0, 0 }}}, // Move window to right
  { MODKEY,					              XK_Left,	moveresize,		{.v = (int []){ -MOVE_WITH_KEYBOARD_STEP, 0, 0, 0 }}}, // Move window to left
  { MODKEY|ControlMask,			      XK_Down,	moveresize,		{.v = (int []){ 0, 0, 0, RESIZE_WITH_KEYBOARD_STEP }}}, // Resize window
  { MODKEY|ControlMask,			      XK_Up,		moveresize,		{.v = (int []){ 0, 0, 0, -RESIZE_WITH_KEYBOARD_STEP }}}, // Resize window
  { MODKEY|ControlMask,			      XK_Right,	moveresize,		{.v = (int []){ 0, 0, RESIZE_WITH_KEYBOARD_STEP, 0 }}}, // Resize window
  { MODKEY|ControlMask,			      XK_Left,	moveresize,		{.v = (int []){ 0, 0, -RESIZE_WITH_KEYBOARD_STEP, 0 }}}, // Resize window
#endif
#if INFINITE_TAGS
  { MODKEY,                       XK_r,      homecanvas,       {0} }, // Return to x:0, y:0 position
  { MODKEY|ShiftMask,             XK_Left,   movecanvas,       {.i = 0} }, // Move your position to left
  { MODKEY|ShiftMask,             XK_Right,  movecanvas,       {.i = 1} }, // Move your position to right
  { MODKEY|ShiftMask,             XK_Up,     movecanvas,       {.i = 2} }, // Move your position up
  { MODKEY|ShiftMask,             XK_Down,   movecanvas,       {.i = 3} }, // Move your position down
  { MODKEY|ShiftMask,             XK_d,      centerwindow,     {0} },
  { MODKEY|ControlMask,           XK_z,      pinwindow,        {0} },
#endif
#if DIRECTIONAL_FOCUS
	{ ALTERNATE_MODKEY,             XK_Left,   focusdir,       {.i = 0 } }, // left
	{ ALTERNATE_MODKEY,             XK_Right,  focusdir,       {.i = 1 } }, // right
	{ ALTERNATE_MODKEY,             XK_Up,     focusdir,       {.i = 2 } }, // up
	{ ALTERNATE_MODKEY,             XK_Down,   focusdir,       {.i = 3 } }, // down
#endif
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
#if INFINITE_TAGS
  { ClkRootWin,      MODKEY|ShiftMask,         Button1,        movecanvasmouse,     {.f = 1.5 } }, 
  { ClkClientWin,    MODKEY|ShiftMask,         Button1,        movecanvasmouse,     {.f = 1.5 } },
  /* .f = 1 is moving multiplier, for example if set to 0.5, canvas will move 2 times slower, if set to 2, canvas will move 2 times faster. 
     If you want inverted canvas move then set the value to a negative value. */
#endif
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        swapmaster,     {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
