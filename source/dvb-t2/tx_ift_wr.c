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
#include "tx_ift_align.h"
#include "tx_ift_core.h"
#include "ift.h"

int tx_ift_wr(cfg_t *config, float **DiI, float **DiQ, float **DoI, float **DoQ)
{
  
	/*
	 * parameter definition
	 */
	int Mod = config->Mod;
	int Len = config->Len;
	int numBits = config->numBits;
  int FftTyp = config->FftTyp;

  //printf("cfg file name %c\n", config->FnameTxIftMapDoI);

  float *DoAlignI, *DoAlignQ;

  DoAlignI = (float *)malloc(sizeof(float) * FFT_SIZE[FftTyp]);
  DoAlignQ = (float *)malloc(sizeof(float) * FFT_SIZE[FftTyp]);



  //debug(V_DEBUG,"output file name is :  %s\n",config->FnameTxIftMapDoI);
  //debug(V_DEBUG,"Mod is  %d ",config->Mod);

	/*
	 * procedure
	 */
  tx_ift_align(FftTyp, Mod, Len, &(*DiI), &(*DiQ), &(DoAlignI), &(DoAlignQ));
  tx_ift_core(FftTyp,  &(DoAlignI), &(DoAlignQ), &(*DoI), &(*DoQ));

  /*
   * log
   */
  //write_af(FnameDoI, Len, &(*DoI));
  //write_af("./log/tx_ift_map__do_map_i.txt", Len, &(*DoI));
  //write_af("./log/tx_ift_map__do_map_q.txt", Len, &(*DoQ));

  free(DoAlignI);
  free(DoAlignQ);
  
	return EXIT_SUCCESS;
}
