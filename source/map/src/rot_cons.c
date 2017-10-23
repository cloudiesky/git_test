/*
 * rot_gen.c
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "global.h"
#include "debug.h"
#include "config.h"

int rot_cons(int Mod, float (*c_f)[64][2])
{

  int i;
  /* const float ROT_RADIAN_QPSK  = (2 * M_PI * ROT_ANGLE_QPSK / 360); */
  /* const float ROT_RADIAN_16QAM = (2 * M_PI * ROT_ANGLE_16QAM / 360); */
  /* const float ROT_RADIAN_64QAM = (2 * M_PI * ROT_ANGLE_64QAM / 360); */

  const double ROT_RADIAN_QPSK  = (2 * M_PI * ROT_ANGLE_QPSK / 360);
  const double ROT_RADIAN_16QAM = (2 * M_PI * ROT_ANGLE_16QAM / 360);
  const double ROT_RADIAN_64QAM = (2 * M_PI * ROT_ANGLE_64QAM / 360);


  debug(V_DEBUG,"Rotate Constellation map:\n");
  switch (Mod)
    {
    case 0 :
      (*c_f)[0][0] = C_POINTS_BPSK[0];
      (*c_f)[0][1] = C_POINTS_BPSK[1];
      debug(V_DEBUG,"%d,%f,%f\n",0,(*c_f)[0][0],(*c_f)[0][0]);
      break;

    case 1 : // QPSK
      for (i=0; i<4; i++) {
        (*c_f)[i][0] = (C_POINTS_QPSK[i][0] * cos(ROT_RADIAN_QPSK) -  \
                        C_POINTS_QPSK[i][1] * sin(ROT_RADIAN_QPSK)    \
                        )/ C_QPSK;
        (*c_f)[i][1] = (C_POINTS_QPSK[i][0] * sin(ROT_RADIAN_QPSK)  + \
                        C_POINTS_QPSK[i][1] * cos(ROT_RADIAN_QPSK)    \
                        )/ C_QPSK;
        debug(V_DEBUG,"%d,%f,%f\n",i,(*c_f)[i][0],(*c_f)[i][1]);
      }
      debug(V_DEBUG,"c_qpsk %f\n",(C_QPSK));
      break;

    case 2 : // 16-QAM
      for (i=0; i<16; i++) {
        (*c_f)[i][0] = (C_POINTS_16QAM[i][0] * cos(ROT_RADIAN_16QAM) -  \
                        C_POINTS_16QAM[i][1] * sin(ROT_RADIAN_16QAM)    \
                        )/ C_16QAM;
        (*c_f)[i][1] = (C_POINTS_16QAM[i][0] * sin(ROT_RADIAN_16QAM) +  \
                        C_POINTS_16QAM[i][1] * cos(ROT_RADIAN_16QAM)    \
                        )/ C_16QAM;
        debug(V_DEBUG,"%d,%f,%f\n",i,(*c_f)[i][0],(*c_f)[i][1]);
      }
      debug(V_DEBUG,"c_16qam %f\n",(C_16QAM));
      break;

    case 3 :
      debug(V_DEBUG,"sin = %f cos = %f c = %f\n",sin(ROT_RADIAN_64QAM),cos(ROT_RADIAN_64QAM), C_64QAM);
      for (i=0; i<64; i++) {
        (*c_f)[i][0] = (float)((C_POINTS_64QAM[i][0] * cos(ROT_RADIAN_64QAM) - \
                                C_POINTS_64QAM[i][1] * sin(ROT_RADIAN_64QAM) \
                                ) / C_64QAM);
        (*c_f)[i][1] = (float)((C_POINTS_64QAM[i][0] * sin(ROT_RADIAN_64QAM) + \
                                C_POINTS_64QAM[i][1] * cos(ROT_RADIAN_64QAM) \
                                )/ C_64QAM) ;

        debug(V_DEBUG,"%d,%f %fi,%d,%d\n",i,(*c_f)[i][0],(*c_f)[i][1],C_POINTS_64QAM[i][0],C_POINTS_64QAM[i][1]);
      }
      debug(V_DEBUG,"c_64qam %f\n",(C_64QAM));
      break;

    default :
      assert(Mod <= 3);
    }
  debug(V_DEBUG,"\nGen done\n");

  return EXIT_SUCCESS;
}
