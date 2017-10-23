/*
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include "debug.h"
#include "global.h"

int vec_rd_f(char * Fname, int length, float **Vec){
  int i;
  int vec_max_lenth;
  FILE * fp;
  long unsigned ulong_tmp;
  float float_tmp;

  debug(V_DEBUG,"read: %s\n",Fname);
  fp  = fopen(Fname, "r");
  assert(fp);

  // init
  i = 0;
  vec_max_lenth = 2;
  (*Vec) = (float*)malloc(vec_max_lenth * sizeof(float));

  // read file
  while (1) {
    fscanf(fp,"%lx",&ulong_tmp);

    if (feof(fp)){
      length = i;
      debug(V_DEBUG, "Last line  %d\n", i);
      break;
    }

    memcpy(&float_tmp, &ulong_tmp, sizeof(long unsigned));
    (*Vec)[i] = float_tmp;
    i++;
    if (i == (vec_max_lenth-1)) {
      vec_max_lenth = vec_max_lenth * 2;
      (*Vec) = realloc((*Vec), (vec_max_lenth * sizeof(float)));
    }

    if (i%10000 == 0)
      debug(V_DEBUG, "Line = %d\n", i);
  }

  (*Vec) = realloc((*Vec), (length * sizeof(float)));

  for (i=0; i<100; i++)
    debug(V_DEBUG, "line: %d %f\n",i,(*Vec)[i]);

  fclose(fp);
  return EXIT_SUCCESS;
}


int vec_rd_fd(char * Fname, int length, float **Vec){
  int i;
  int vec_max_lenth;
  FILE * fp;
  long long unsigned long_tmp;
  double double_tmp;

  debug(V_DEBUG,"read: %s\n",Fname);
  fp  = fopen(Fname, "r");
  assert(fp);

  // init
  i = 0;
  vec_max_lenth = 2;
  (*Vec) = (float*)malloc(vec_max_lenth * sizeof(float));

  // read file
  while (1) {
    fscanf(fp,"%I64x",&long_tmp);

    if (feof(fp)){
      length = i;
      debug(V_DEBUG, "Last line  %d\n", i);
      break;
    }

    memcpy(&double_tmp, &long_tmp, sizeof(long long unsigned));
    (*Vec)[i] = (float)(double_tmp);
    i++;
    if (i == (vec_max_lenth-1)) {
      vec_max_lenth = vec_max_lenth * 2;
      (*Vec) = realloc((*Vec), (vec_max_lenth * sizeof(float)));
    }

    if (i%10000 == 0)
      debug(V_DEBUG, "Line = %d\n", i);
  }

  (*Vec) = realloc((*Vec), (length * sizeof(float)));

  for (i=0; i<100; i++)
    debug(V_DEBUG, "line: %d %f\n",i,(*Vec)[i]);

  fclose(fp);
  return EXIT_SUCCESS;
}


int vec_rd_i(const char * Fname, int length, int **Vec){
  int i;
  int vec_max_lenth;
  FILE * fp;

  debug(V_DEBUG,"read: %s\n",Fname);
  fp  = fopen(Fname, "r");
  assert(fp);

  // init
  i = 0;
  vec_max_lenth = 2;
  (*Vec) = (int*)malloc(vec_max_lenth * sizeof(int));

  // read file
  while (1) {
    fscanf(fp,"%d", &(*Vec)[i]);

    if (feof(fp)){
      length = i;
      debug(V_DEBUG, "Last line  %d\n", i);
      break;
    }

    i++;
    if (i == (vec_max_lenth-1)) {
      vec_max_lenth = vec_max_lenth * 2;
      (*Vec) = realloc((*Vec), (vec_max_lenth * sizeof(int)));
    }

    if (i%10000 == 0)
      debug(V_DEBUG, "Line = %d\n", i);
  }

  (*Vec) = realloc((*Vec), (length * sizeof(int)));

  for (i=0; i<100; i++)
    debug(V_DEBUG, "line: %d %d\n",i,(*Vec)[i]);

  fclose(fp);

 return EXIT_SUCCESS;
}
