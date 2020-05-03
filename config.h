/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=14" };
static const char dmenufont[]       = "monospace:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_black[]       = "#000000";
static const char col_blue[]        = "#3399ff";
static const char col_green[]       = "#00aa00";
static const char col_red[]         = "#aa0000";
static const char col_yellow[]      = "#ddb200";
static const char col_white[]       = "#ffffff";
static const char *colors[][7]      = {
	/*               fg         bg         border   */
	[SchemeNorm] =  { col_gray3, col_black, col_black },
	[SchemeSel]  =  { col_gray1, col_yellow,  col_yellow },
    [Scheme3]   =   { col_yellow, col_black, col_black },
	[Scheme4]   =   { col_blue, col_black, col_black },
	[Scheme5]   =   { col_green, col_black, col_black },
	[Scheme6]   =   { col_red, col_black, col_black },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	/*{ "Gimp",     NULL,       NULL,       0,              1,           -1 },*/
    { "NULL",       NULL,       NULL,       0,              0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ KeyPress, MODKEY,                       KEY,  view,       {.ui = 1 << TAG} }, \
	{ KeyPress, MODKEY|ControlMask,           KEY,  toggleview, {.ui = 1 << TAG} }, \
	{ KeyPress, MODKEY|ShiftMask,             KEY,  tag,        {.ui = 1 << TAG} }, \
	{ KeyPress, MODKEY|ControlMask|ShiftMask, KEY,  toggletag,  {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static Button buttons[] = {
	/* click            event mask  button      function    argument */
	{ ClkTagBar,        0,          Button1,    view,       {0} },
};

static Key keys[] = {
	/*            modifier          key    function        argument */
	{ KeyPress,   MODKEY,           44,    focusstack,     {.i = +1 } },
	{ KeyPress,   MODKEY,           45,    focusstack,     {.i = -1 } },
	/*{ KeyPress,   MODKEY,           31,    incnmaster,     {.i = +1 } },*/
	/*{ KeyPress,   MODKEY,           40,    incnmaster,     {.i = -1 } },*/
	{ KeyPress,   MODKEY,           43,    setmfact,       {.f = -0.05} },
	{ KeyPress,   MODKEY,           46,    setmfact,       {.f = +0.05} },
	{ KeyPress,   MODKEY,           36,    spawn,          SHCMD("$TERMINAL") },
	{ KeyPress,   MODKEY,           9,     spawn,          SHCMD("$TERMINAL") },
	{ KeyPress,   MODKEY,           66,    spawn,          SHCMD("$TERMINAL") },
	{ KeyPress,   MODKEY|ShiftMask, 26,    quit,           {0} },
	{ KeyPress,   MODKEY,           24,    killclient,     {0} },
	{ KeyPress,   MODKEY,           22,    killclient,     {0} },
	{ KeyPress,   MODKEY,           65,    setlayout,      {0} },
	{ KeyPress,   MODKEY|ShiftMask, 65,    togglefloating, {0} },
	{ KeyPress,   MODKEY,           0,     view,           {.ui = ~0 } },
	{ KeyPress,   MODKEY|ShiftMask, 0,     tag,            {.ui = ~0 } },
	{ KeyPress,   MODKEY,           59,    focusmon,       {.i = -1 } },
	{ KeyPress,   MODKEY,           60,    focusmon,       {.i = +1 } },
	{ KeyPress,   MODKEY|ShiftMask, 59,    tagmon,         {.i = -1 } },
	{ KeyPress,   MODKEY|ShiftMask, 60,    tagmon,         {.i = +1 } },
	{ KeyPress,   MODKEY,           38,    spawn,          SHCMD("anki") },
	{ KeyPress,   MODKEY,           54,    spawn,          SHCMD("exec $BROWSER https://mackuba.eu/corona/#germany") },
	{ KeyPress,   MODKEY,           58,    spawn,          SHCMD("exec $BROWSER https://mail.protonmail.com/login") },
	{ KeyPress,   MODKEY,           57,    spawn,          SHCMD("exec $TERMINAL -e newsboat -rq") },
	{ KeyPress,   MODKEY,           32,    spawn,          SHCMD("exec $TERMINAL -e view") },
	{ KeyPress,   MODKEY,           33,    spawn,          SHCMD("exec $TERMINAL -e play") },
	{ KeyPress,   MODKEY,           55,    spawn,          SHCMD("exec $TERMINAL -e vpn") },
	{ KeyPress,   MODKEY,           25,    spawn,          SHCMD("exec $BROWSER") },
	{ KeyPress,   MODKEY,           53,    spawn,          SHCMD("slock") },
	{ KeyPress,   MODKEY,           39,    spawn,          SHCMD("doas -n zzz") },
	{ KeyRelease, MODKEY,           38,    spawn,          SHCMD("scrot 'screenshot_%Y_%m_%d_%s.png' -e 'mv $f ~/media/screenshots/' -s") },
	/*{ KeyRelease, MODKEY,           38,    spawn,          SHCMD("scrot 'screenshot_%Y_%m_%d_%s.png' -e 'mv $f ~/media/screenshots/'") },*/
	/*{ KeyRelease, MODKEY,           38,    spawn,          SHCMD("scrot -s -e 'xclip -selection clipboard -t \"image/png\" < $f && rm $f'") },*/
	{ KeyPress,   0,                107,   unhidebar,      {0} },
	{ KeyRelease, 0,                107,   hidebar,        {0} },
	{ KeyPress,   0,                121,   spawn,          SHCMD("amixer set Master toggle; pkill -SIGRTMIN+6 dwmblocks") },
	{ KeyPress,   0,                122,   spawn,          SHCMD("amixer set Master 5%-; pkill -SIGRTMIN+6 dwmblocks") },
	{ KeyPress,   0,                123,   spawn,          SHCMD("amixer set Master 5%+; pkill -SIGRTMIN+6 dwmblocks") },
	{ KeyPress,   0,                232,   spawn,          SHCMD("xbacklight -dec 10 -time 100 -steps 10; pkill -SIGRTMIN+10 dwmblocks") },
	{ KeyPress,   0,                233,   spawn,          SHCMD("xbacklight -inc 10 -time 100 -steps 10; pkill -SIGRTMIN+10 dwmblocks") },
	{ KeyPress,   0,                235,   spawn,          SHCMD("chmonitor") },
	{ KeyPress,   0,                246,   spawn,          SHCMD("sleep 1; pkill -SIGRTMIN+4 dwmblocks") },
	{ KeyPress,   0,                179,   spawn,          SHCMD("toggleMouse") },
	{ KeyPress,   0,                225,   spawn,          SHCMD("exec $BROWSER \"https://duckduckgo.com/?q=$(xclip -out -selection primary)\"") },
	{ KeyPress,   0,                128,   spawn,          SHCMD("exec $TERMINAL -e $EDITOR $HOME/documents/notes/00_todo") },
	{ KeyPress,   0,                152,   spawn,          SHCMD("exec $TERMINAL -e calcurse -D $HOME/.config/calcurse") },
	TAGKEYS(                        10,                    0)
	TAGKEYS(                        11,                    1)
	TAGKEYS(                        12,                    2)
	TAGKEYS(                        13,                    3)
	TAGKEYS(                        14,                    4)
	TAGKEYS(                        15,                    5)
	TAGKEYS(                        16,                    6)
	TAGKEYS(                        17,                    7)
	TAGKEYS(                        18,                    8)
};
