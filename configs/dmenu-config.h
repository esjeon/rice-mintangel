/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"Hack:pixelsize=15"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char col_normfg[]      = "#bdc3c7";
static const char col_normbg[]      = "#212121";
static const char col_selfg[]       = "#bdc3c7";
static const char col_selbg[]       = "#1f2d3a";
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { col_normfg, col_normbg },
	[SchemeSel] = { col_selfg, col_selbg },
	[SchemeOut] = { "#000000", "#00ffff" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;
static unsigned int lineheight = 32;         /* -h option; minimum height of a menu line     */

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
