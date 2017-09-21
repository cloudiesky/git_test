/*
 * debug.c
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: zhang.zhi
 */
#include <stdio.h>
#include <stdlib.h> /* atoi() */
#include <stdarg.h>

#define V_DEBUG  100
#define V_HIGH   75
#define V_MEDIUM 50
#define V_LOW    25
#define V_NONE   0
#ifndef VERB
#define VERB 100
#endif
void debug(int level, const char *fmt, ...)
{
	int debug_level;

	debug_level = VERB;

	va_list ap;
	if( level <= debug_level ){
		va_start(ap, fmt);
		vprintf(fmt, ap);
		va_end(ap);
	}
}
