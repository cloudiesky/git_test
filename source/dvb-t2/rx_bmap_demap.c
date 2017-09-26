/*
 * rx_bmap_demap.c
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
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
  float delta_min, delta_tmp, delta_i, delta_q;
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
        //debug(V_DEBUG,"%d,%f %fi,%d,%d\n",i,c_f[i][0],c_f[i][1],C_POINTS_64QAM[i][0],C_POINTS_64QAM[i][1]);
      }
      //debug(V_DEBUG,"c_64qam %f\n",(C_64QAM));
      break;
    default :
      c_loop = 0;
      assert(Mod <= 3);
    }
  debug(V_DEBUG,"\nDemap Gen done\n");

  *DO = (int *)malloc(sizeof(int) * Len);

  debug(V_DEBUG, "Demap start\n");
  if (Mod == 0) {
    for (i = 0; i < Len; i++){
      if (abs((*DI_I)[i] - c_f[0][0]) < \
          abs((*DI_I)[i] - c_f[0][1]))
        (*DO)[i] = 0;
      else
        (*DO)[i] = 1;
    }
  }
  else if (Mod <= 3) {
    for (i = 0; i < Len; i++){
      i_min = 0;
      delta_min = FLT_MAX;

      for (j = 0; j < c_loop; j++){
        //delta_tmp = abs((*DI_I)[i] - c_f[i][0]) + abs((*DI_Q)[i] - c_f[i][1]);
        delta_i = (((*DI_I)[i]) - c_f[j][0]);
        delta_q = (((*DI_Q)[i]) - c_f[j][1]);
        delta_tmp = delta_i * delta_i + delta_q * delta_q;

        if(delta_min > delta_tmp){
          delta_min = delta_tmp;
          i_min = j;
        }
        //debug(V_MEDIUM, "%d %f \n", i_min, delta_min);
      }
      (*DO)[i] = i_min;
      debug(V_DEBUG, "Demap: %d\t%d\t%f\t%f\t%f\n", i, (*DO)[i], (*DI_I)[i], (*DI_Q)[i], delta_min);
    }
  }
  else
    assert(Mod <= 3);

  //debug(V_DEBUG, "%d\n", (*DO)[0]);
  debug(V_DEBUG, "Demap Done");
}

