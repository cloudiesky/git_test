/*
 * rx_bmap_demap.c
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "debug.h"
#include "global.h"

void rx_bmap_demap(int Mod,                     \
                   int Len,                     \
                   int **DO,                    \
                   float **DI_I,                \
                   float **DI_Q                 \
                   )
{
  int i, j;
  float delta_min, delta_tmp;
  int i_min;
  int c_loop;
  float c_f[64][2];

  debug(V_DEBUG,"Rotate Constellation map:\n");
  switch (Mod)
    {
    case 0 :
      c_loop = 2;
      c_f[0][0] = 1;
      c_f[0][1] = 0;
      debug(V_DEBUG,"%d,%f,%f\n",0,c_f[0][0],c_f[0][0]);
      break;
    case 1 : // QPSK
      c_loop = 4;
      for (i=0; i<4; i++) {
        c_f[i][0] = C_POINTS_QPSK[i][0] * cos(ROT_QPSK) / C_QPSK;
        c_f[i][1] = C_POINTS_QPSK[i][1] * sin(ROT_QPSK) / C_QPSK;
        debug(V_DEBUG,"%d,%f,%f\n",i,c_f[i][0],c_f[i][1]);
      }
      debug(V_DEBUG,"c_qpsk %f\n",(C_QPSK));
      break;
    case 2 : // 16-QAM
      c_loop = 16;
      for (i=0; i<16; i++) {
        c_f[i][0] = C_POINTS_16QAM[i][0] * cos(ROT_16QAM) / C_16QAM;
        c_f[i][1] = C_POINTS_16QAM[i][1] * sin(ROT_16QAM) / C_16QAM;
        debug(V_DEBUG,"%d,%f,%f\n",i,c_f[i][0],c_f[i][1]);
      }
      debug(V_DEBUG,"c_16qam %f\n",(C_16QAM));
      break;
    case 3 :
      c_loop = 64;
      for (i=0; i<64; i++) {
        c_f[i][0] = C_POINTS_64QAM[i][0] * cos(ROT_64QAM) / C_64QAM;
        c_f[i][1] = C_POINTS_64QAM[i][1] * sin(ROT_64QAM) / C_64QAM;
        debug(V_DEBUG,"%d,%f %fi,%d,%d\n",i,c_f[i][0],c_f[i][1],C_POINTS_64QAM[i][0],C_POINTS_64QAM[i][1]);
      }
      debug(V_DEBUG,"c_64qam %f\n",(C_64QAM));
      break;
    default :
      assert(Mod <= 3);
    }
  debug(V_DEBUG,"\nGen done\n");

  if (Mod == 0) {
    for (i = 0; i < Len; i++){
      i_min = 0;
      delta_min = abs((*DiI)[i] - c_f[0][0]);
      for (j = 1; j < c_loop; j++){
        delta_tmp = abs((*DiI)[i] - c_f[0][j]);
        if (delta_min > delta_tmp){
          delta_min = delta_tmp;
          i_min = j;
        }
      }
    }
    else if (Mod <= 3) {
      
    }
  }
}

