/*
 * rx_fft_wr.c
 *
 *  Created on: 2017年9月20日
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "debug.h"
#include "global.h"
#include "rx_fft_core.h"
#include "rx_fft_align.h"
#include "ift.h"

int rx_fft_wr(cfg_t *config, float **DiI, float **DiQ, float **DoI, float **DoQ)
{
  
	/*
	 * parameter definition
	 */
	int Mod = config->Mod;
	int Len = config->Len;
	int numBits = config->numBits;
  int FftTyp = config->FftTyp;

  //printf("cfg file name %c\n", config->FnameTxIftMapDoI);

  float *DoFftI, *DoFftQ;

  DoFftI = (float *)malloc(sizeof(float) * FFT_SIZE[FftTyp]);
  DoFftQ = (float *)malloc(sizeof(float) * FFT_SIZE[FftTyp]);



  //debug(V_DEBUG,"output file name is :  %s\n",config->FnameTxIftMapDoI);
  //debug(V_DEBUG,"Mod is  %d ",config->Mod);

	/*
	 * procedure
	 */
  rx_fft_core(FftTyp,  &(DoFftI), &(DoFftQ), &(*DiI), &(*DiQ));
  rx_fft_align(FftTyp, Mod, Len, &(*DoI), &(*DoQ), &(DoFftI), &(DoFftQ));

  /*
   * log
   */
  //write_af(FnameDoI, Len, &(*DoI));
  //write_af("./log/rx_fft_map__do_map_i.txt", Len, &(*DoI));
  //write_af("./log/rx_fft_map__do_map_q.txt", Len, &(*DoQ));

  free(DoFftI);
  free(DoFftQ);
  
	return EXIT_SUCCESS;
}
