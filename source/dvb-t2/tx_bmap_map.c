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

void tx_bmap_map(int Mod,                       \
                 int Len,                       \
                 float **DO_I,                  \
                 float **DO_Q,                  \
                 int **DI){
  int i;
  int i_cond;
  float c_f[64][2];

  debug(V_DEBUG,"Rotate Constellation map:\n");
  switch (Mod)
    {
    case 0 :
      c_f[0][0] = 1;
      c_f[0][1] = 0;
      debug(V_DEBUG,"%d,%f,%f\n",0,c_f[0][0],c_f[0][0]);
      break;
    case 1 : // QPSK
      for (i=0; i<4; i++) {
        c_f[i][0] = C_POINTS_QPSK[i][0] * cos(ROT_QPSK) / C_QPSK;
        c_f[i][1] = C_POINTS_QPSK[i][1] * sin(ROT_QPSK) / C_QPSK;
        debug(V_DEBUG,"%d,%f,%f\n",i,c_f[i][0],c_f[i][0]);
      }
      break;
    case 2 : // 16-QAM
      for (i=0; i<16; i++) {
        c_f[i][0] = C_POINTS_16QAM[i][0] * cos(ROT_16QAM) / C_16QAM;
        c_f[i][1] = C_POINTS_16QAM[i][1] * sin(ROT_16QAM) / C_16QAM;
        debug(V_DEBUG,"%d,%f,%f\n",i,c_f[i][0],c_f[i][0]);
      }
      break;
    case 3 :
      for (i=0; i<64; i++) {
        c_f[i][0] = C_POINTS_64QAM[i][0] * cos(ROT_64QAM) / C_64QAM;
        c_f[i][1] = C_POINTS_64QAM[i][1] * sin(ROT_64QAM) / C_64QAM;
        debug(V_DEBUG,"%d,%f %fi,%d,%d\n",i,c_f[i][0],c_f[i][1],C_POINTS_64QAM[i][0],C_POINTS_64QAM[i][1]);
      }
      break;
    default :
      assert(Mod <= 3);
    }
  debug(V_DEBUG,"\nGen done\n");

  (*DO_I) = (float*)malloc(Len * sizeof(float));
  (*DO_Q) = (float*)malloc(Len * sizeof(float));

  debug(V_DEBUG,"MAPPING START\n");
  
  if (Mod == 0){
    for(i=0; i<Len; i++){
      (*DO_I)[i] = (*DI)[i];
      (*DO_Q)[i] = 0;
    }
  }
  else if (Mod <= 3){
    for (i=0; i<Len; i++){
      (*DO_I)[i] = c_f[((*DI)[i])][0];
      (*DO_Q)[i] = c_f[((*DI)[i])][1];
      debug(V_DEBUG,"%d,%.2d,%f,%f\n",i,(*DI)[i],(*DO_I)[i],(*DO_Q)[i]);
    }
  }
  else
    assert(Mod <= 3);

  debug(V_DEBUG,"MAPPING FINISHED\n");

}

