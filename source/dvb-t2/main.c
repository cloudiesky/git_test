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
#include "tx_map_wr.h"
#include "tx_fadapt_wr.h"
#include "tx_ofdm_wr.h"
#include "rx_ofdm_wr.h"
#include "rx_fadapt_wr.h"
#include "rx_bmap_wr.h"
#include "cmp_tx_rx.h"

int main(void) {

  cfg_t *config;
  //FILE *FidLogFile;
   FILE *FidCfgFile;

  int *TxBmapDi;
  int *TxBmapDo;

  int *TxMapDi;
  float *TxMapDoI;
  float *TxMapDoQ;

  float *RxBmapDiI;
  float *RxBmapDiQ;
  int *RxBmapDo;

  float *TxFadaptDiI;
  float *TxFadaptDiQ;
  float *TxFadaptDoI;
  float *TxFadaptDoQ;

  float *TxOfdmDiI;
  float *TxOfdmDiQ;
  float *TxOfdmDoI;
  float *TxOfdmDoQ;

  float *RxOfdmDiI;
  float *RxOfdmDiQ;
  float *RxOfdmDoI;
  float *RxOfdmDoQ;

  float *RxFadaptDiI;
  float *RxFadaptDiQ;
  float *RxFadaptDoI;
  float *RxFadaptDoQ;

  puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

  printf("Info Verbosity = %d\n",VERB);

  FidCfgFile = fopen("./log/tx_bmap_cfg.txt","w");
  assert(FidCfgFile);

  // initial config;
  init_cfg(&config, FidCfgFile);

  // tx gen data in
	TxBmapDi=(int*)malloc((config->numBits)*(sizeof(int)));
  tx_bmap_di_gen(config, &TxBmapDi);

  // tx bmap
  TxBmapDo = (int *)malloc(config->Len * sizeof(int));
  tx_bmap_wr(config, &TxBmapDi, &TxBmapDo);

 // tx map
  TxMapDi = TxBmapDo;
  TxMapDoI = (float*)malloc(config->Len * sizeof(float));
  TxMapDoQ = (float*)malloc(config->Len * sizeof(float));
  tx_map_wr(config, &TxMapDi, &TxMapDoI, &TxMapDoQ);

  // tx frame adapt
  TxFadaptDiI = TxMapDoI;
  TxFadaptDiQ = TxMapDoQ;
  TxFadaptDoI = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  TxFadaptDoQ = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  tx_fadapt_wr(config,  &TxFadaptDiI, &TxFadaptDiQ, &TxFadaptDoI, &TxFadaptDoQ);

  // tx ofdm
  TxOfdmDiI = TxFadaptDoI ;
  TxOfdmDiQ = TxFadaptDoQ ;
  TxOfdmDoI = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  TxOfdmDoQ = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  tx_ofdm_wr(config,  &TxOfdmDiI, &TxOfdmDiQ, &TxOfdmDoI, &TxOfdmDoQ);


  // rx ofdm
  RxOfdmDiI = TxOfdmDoI;
  RxOfdmDiQ = TxOfdmDoQ;
  RxOfdmDoI = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  RxOfdmDoQ = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  rx_ofdm_wr(config, &RxOfdmDiI, &RxOfdmDiQ, &RxOfdmDoI, &RxOfdmDoQ);

 // rx fadapt
  RxFadaptDiI = RxOfdmDoI;
  RxFadaptDiQ = RxOfdmDoQ;
  RxFadaptDoI = (float *)malloc(sizeof(float)*(config->Len));
  RxFadaptDoQ = (float *)malloc(sizeof(float)*(config->Len));
  rx_fadapt_wr(config, &RxFadaptDiI, &RxFadaptDiQ, &RxFadaptDoI, &RxFadaptDoQ);

  // rx demap
  RxBmapDiI = RxFadaptDoI;
  RxBmapDiQ = RxFadaptDoQ;
  RxBmapDo = (int *)malloc(sizeof(int) * config->numBits);
  rx_bmap_wr(config, &RxBmapDiI, &RxBmapDiQ, &RxBmapDo);


  cmp_tx_rx(config->numBits, &TxBmapDi, &RxBmapDo);

  free(TxBmapDo);

  free(TxMapDoI);
  free(TxMapDoQ);

  free(RxBmapDo);

  free(TxOfdmDoI);
  free(TxOfdmDoQ);

  //free(RxFftDiI);
  //free(RxFftDiQ);

  /* free(RxFftDoI); */
  /* free(RxFftDoQ); */

  //free(RxBmapDiI);
  //free(RxBmapDiQ);

  fclose(FidCfgFile);
  //fclose(FidLogFile);

  return EXIT_SUCCESS;
}
