/*
 * status.c - this is a personally crafted xroot title setter
 * 
 * Copyright 2018 Eon S. Jeon <esjeon@hyunmu.am>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <X11/Xlib.h>

static const char timecode[] = "YXWVUTSRQPONZABCDEFGHIKLM";
static const char *month_name[] = {
	"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
	"JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

static char output[1024];
static int len;
static Display *dpy;

int
main(int argc, char *argv[])
{
	time_t t;
	struct tm tm;

	if (!(dpy = XOpenDisplay(NULL))) {
		fprintf(stderr, "status: cannot open display");
		return 1;
	}

	for(;;) {
		len = 0;

		/* current time in military date time group: DDhhmmZMonYY */
		t = time(NULL);
		tm = *localtime(&t);
		len += sprintf(output, "[%02d %02d%02d%c %s%2d]",
				tm.tm_mday, tm.tm_hour, tm.tm_min,
				timecode[tm.tm_gmtoff/3600 + 12], month_name[tm.tm_mon], tm.tm_year % 100);

		XStoreName(dpy, DefaultRootWindow(dpy), output);
		XFlush(dpy);
		sleep(2);
	}

	return 0;
}


