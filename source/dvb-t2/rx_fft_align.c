/*
 * rx_fft_wr.c
 *
 *  Created on: 2017年9月20日
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "config.h"
#include "global.h"
#include "debug.h"

int rx_fft_align(int FftTyp, int Mod, int Len, float **DiI, float **DiQ, float **DoI, float **DoQ)
{

  int i;

  // Now put even data to even cell, odd data to odd cells.
  // eg: 0 -> 0; 1 -> 3; 2 -> 4; 3 ->7; ...
  // To Do : get the properbly cell for data
  for (i = 0; i < Len; i++){
    if ((i%2) == 0) {
      (*DoI)[i] = (*DiI)[i*2];
      (*DoQ)[i] = (*DiQ)[i*2];
    }
    else {
      (*DoI)[i] = (*DiI)[i*2+1];
      (*DoQ)[i] = (*DiQ)[i*2+1];
    }
  }

  debug(V_DEBUG, "fft align done, aligned data:\n");
  for (i = 0; i < Len; i++)
    debug(V_DEBUG, "No.%d, I = %f, Q = %f\n", i, (*DoI)[i], (*DoQ)[i]);
  debug(V_DEBUG,"align data ends\n");


  /*
   * log
   */
  //write_af("./log/rx_fft_map__do_map_i.txt", Len, &(*DoI));
  //write_af("./log/rx_fft_map__do_map_q.txt", Len, &(*DoQ));

	return EXIT_SUCCESS;
}
