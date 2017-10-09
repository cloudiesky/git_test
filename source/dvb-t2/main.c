/*
 ============================================================================
 Name        : Constellation.c
 Author      : CC
 Version     :
 Copyright   : NZ
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "global.h"
#include "debug.h"
#include "config.h"
#include "init_cfg.h"
#include "tx_bmap_di_gen.h"
#include "tx_bmap_wr.h"
#include "tx_ift_wr.h"
#include "rx_fft_wr.h"
#include "rx_bmap_wr.h"
#include "cmp_tx_rx.h"

int main(void) {

  cfg_t *config;
  //FILE *FidLogFile;
   FILE *FidCfgFile;

  int *TxBmapDi;
  float *TxBmapDoI;
  float *TxBmapDoQ;

  float *RxBmapDiI;
  float *RxBmapDiQ;
  int *RxBmapDo;

  float *TxIftDoI;
  float *TxIftDoQ;

  float *RxFftDiI;
  float *RxFftDiQ;
  float *RxFftDoI;
  float *RxFftDoQ;
  puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

  printf("Info Verbosity = %d\n",VERB);

  FidCfgFile = fopen("./log/tx_bmap_cfg.txt","w");
  assert(FidCfgFile);

  // initial config;
  init_cfg(&config, FidCfgFile);

  // tx gen data in
	TxBmapDi=(int*)malloc((config->numBits)*(sizeof(int)));
  tx_bmap_di_gen(config, &TxBmapDi);

  // tx map
  TxBmapDoI = (float*)malloc(config->Len * sizeof(float));
  TxBmapDoQ = (float*)malloc(config->Len * sizeof(float));
  tx_bmap_wr(config, &TxBmapDi, &TxBmapDoI, &TxBmapDoQ);

  // tx ifft
  TxIftDoI = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  TxIftDoQ = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  tx_ift_wr(config,  &TxBmapDoI, &TxBmapDoQ, &TxIftDoI, &TxIftDoQ);


  // rx fft
  RxFftDiI = TxIftDoI;
  RxFftDiQ = TxIftDoQ;
  RxFftDoI = (float *)malloc(sizeof(float)*(config->Len));
  RxFftDoQ = (float *)malloc(sizeof(float)*(config->Len));
  rx_fft_wr(config, &RxFftDiI, &RxFftDiQ, &RxFftDoI, &RxFftDoQ);

  // rx demap
  RxBmapDiI = RxFftDoI;
  RxBmapDiQ = RxFftDoQ;
  RxBmapDo = (int *)malloc(sizeof(int) * config->numBits);
  rx_bmap_wr(config, &RxBmapDiI, &RxBmapDiQ, &RxBmapDo);


  cmp_tx_rx(config->numBits, &TxBmapDi, &RxBmapDo);

  free(TxBmapDoI);
  free(TxBmapDoQ);

  free(RxBmapDo);

  free(TxIftDoI);
  free(TxIftDoQ);

  //free(RxFftDiI);
  //free(RxFftDiQ);

  free(RxFftDoI);
  free(RxFftDoQ);

  //free(RxBmapDiI);
  //free(RxBmapDiQ);

  fclose(FidCfgFile);
  //fclose(FidLogFile);

  return EXIT_SUCCESS;
}
