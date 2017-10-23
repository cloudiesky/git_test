/*
 * tx_ift_wr.c
 *
 *  Created on: 2017年9月20日
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "debug.h"
#include "global.h"
#include "tx_ofdm.h"
#include "ift.h"

int tx_ofdm_wr(cfg_t *config, float **DiI, float **DiQ, float **DoI, float **DoQ)
{
  
	/*
	 * parameter definition
	 */
	//int Mod = config->Mod;
	//int Len = config->Len;
	//int numBits = config->numBits;
  int FftTyp = config->FftTyp;


  //float *DoAlignI, *DoAlignQ;

  //DoAlignI = (float *)malloc(sizeof(float) * FFT_SIZE[FftTyp]);
  //DoAlignQ = (float *)malloc(sizeof(float) * FFT_SIZE[FftTyp]);


	/*
	 * procedure
	 */
  //tx_ift_align(FftTyp, Mod, Len, &(*DiI), &(*DiQ), &(DoAlignI), &(DoAlignQ));
  //tx_ift_core(FftTyp,  &(DoAlignI), &(DoAlignQ), &(*DoI), &(*DoQ));
  tx_ofdm(FftTyp, &(*DiI), &(*DiQ), &(*DoI), &(*DoQ));

  /*
   * log
   */
  //write_af(config->FnameTxIftAlignDoI, FFT_SIZE[FftTyp], &(DoAlignI));
  //write_af(config->FnameTxIftAlignDoQ, FFT_SIZE[FftTyp], &(DoAlignQ));

  //free(DoAlignI);
  //free(DoAlignQ);
  
	return EXIT_SUCCESS;
}
