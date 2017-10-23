/*
 * tx_ift_wr.c
 *
 *  Created on: 2017年9月20日
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "config.h"
#include "global.h"
#include "debug.h"

int tx_fadapt(int FftTyp, int Mod, int Len, float **DiI, float **DiQ, float **DoI, float **DoQ)
{

  int i;
  //float tmp, tmp1;
	/*
	 * parameter definition
	 */
  int numPad;


  //test;
  //tmp = M_PI * 256;
  //tmp1 = M_PI << 8;
  //debug(V_DEBUG,"Multiply %f, lefshit %f", tmp, tmp1);


  // Input data should not fill all cells.
  // Demo version: less then a half cells is actived.
  // To Do : Check the real available cells.
  numPad = FFT_SIZE[FftTyp]/2 - Len;
  assert(numPad >= 0);

  // Now put even data to even cell, odd data to odd cells.
  // eg: 0 -> 0; 1 -> 3; 2 -> 4; 3 ->7; ...
  // To Do : get the properbly cell for data
  for (i = 0; i < Len; i++){
    if ((i%2) == 0) {
      (*DoI)[i*2] = (*DiI)[i];
      (*DoQ)[i*2] = (*DiQ)[i];
    }
    else {
      (*DoI)[i*2+1] = (*DiI)[i];
      (*DoQ)[i*2+1] = (*DiQ)[i];
    }
  }

  // Now fill the pading cell.
  // demo vesion : fill with 0.
  // To Do : get the properbly data for padding.
  for (i = 0; i < numPad; i++){
    if ((i%2) == 0) {
      (*DoI)[(i+Len)*2] = rand()%2;
      (*DoQ)[(i+Len)*2] = rand()%2;
    }
    else {
      (*DoI)[(i+Len)*2+1] = rand()%2;
      (*DoQ)[(i+Len)*2+1] = rand()%2;
    }
  }

  // Fill unused cell.
  // demo version: fill with 0;
  // To Do : fill with PN seriel data.
  for (i = 0; i < numPad + Len; i++){
    if ((i%2) == 0) {
      (*DoI)[i*2+1] = rand()%2;
      (*DoQ)[i*2+1] = rand()%2;
    }
    else {
      (*DoI)[i*2] = rand()%2;
      (*DoQ)[i*2] = rand()%2;
    }
  }


  debug(V_DEBUG, "ift align done, aligned data:\n");
  for (i = 0; i < FFT_SIZE[FftTyp]; i++)
    debug(V_DEBUG, "Cell No.%d, I = %f, Q = %f\n", i, (*DoI)[i], (*DoQ)[i]);
  debug(V_DEBUG,"align data ends\n");

	/*
	 * procedure
	 */
  //tx_ift_demux(Mod, numBits, &DoDemux, &(*Di));
  //tx_ift_map(Mod, Len, &(*DoI), &(*DoQ),  &DoDemux);

  /*
   * log
   */
  //write_af(FnameDoI, Len, &(*DoI));
  //write_af("./log/tx_ift_map__do_map_i.txt", Len, &(*DoI));
  //write_af("./log/tx_ift_map__do_map_q.txt", Len, &(*DoQ));

	return EXIT_SUCCESS;
}
