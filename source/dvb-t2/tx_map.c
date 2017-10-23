/*
 * tx_bmap_map.c
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: zhang.zhi
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "debug.h"
#include "global.h"
#include "rot_cons.h"

void tx_map(int Mod,                \
            int Len,                \
            int **DI,               \
            float **DO_I,           \
            float **DO_Q){
  int i;
  float c_f[64][2];

  //gen rotated constellation map
  rot_cons(Mod, c_f);

  debug(V_DEBUG,"\nMAPPING START\n");

  if (Mod == 0){
    for(i=0; i<Len; i++){
      (*DO_I)[i] = c_f[0][(*DI)[i]];
      (*DO_Q)[i] = 0;
    }
  }
  else if (Mod <= 3){
    for (i=0; i<Len; i++){
      (*DO_I)[i] = c_f[((*DI)[i])][0];
      (*DO_Q)[i] = c_f[((*DI)[i])][1];
      debug(V_DEBUG,"%.3d, %.2d,%f,%f\n",i,(*DI)[i],(*DO_I)[i],(*DO_Q)[i]);
    }
  }
  else
    assert(Mod <= 3);

  debug(V_DEBUG,"MAPPING FINISHED\n");

}

