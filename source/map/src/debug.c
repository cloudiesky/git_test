/*
 * debug.c
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: zhang.zhi
 */
#include <stdio.h>
#include <stdlib.h> /* atoi() */
#include <stdarg.h>
#include <assert.h>

#define V_DEBUG  100
#define V_HIGH   75
#define V_MEDIUM 50
#define V_LOW    25
#define V_NONE   0

#ifndef VERB
#define VERB 50
#endif

void debug(int level, const char *fmt, ...)
{

	va_list ap;
  if( level <= VERB ){
		va_start(ap, fmt);
		vprintf(fmt, ap);
		va_end(ap);
	}
}

void write_ai(const char *fname, int len, int **ai)
{

  int i;
  FILE *fid;

  fid = fopen(fname, "w");

  for(i=0; i<len; i++)
    {
      fprintf(fid, "%d\n", (*ai)[i]);
    }

  fclose(fid);
}

void write_af(const char *fname, int len, float **af)
{

  int i;
  FILE *fid;

  fid = fopen(fname, "w");

  for(i=0; i<len; i++)
    {
      fprintf(fid, "%f\n", (*af)[i]);
    }

  fclose(fid);
}
