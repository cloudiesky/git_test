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


  init_cfg(&config, FidCfgFile);

  if (config->InSrc == 0)
  {
    tx_bmap_di_gen(config->numBits, &TxBmapDi);
  }

  // tx map
  tx_bmap_wr(config, &TxBmapDi, &TxBmapDoI, &TxBmapDoQ);

  // tx ifft
  TxIftDoI = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  TxIftDoQ = (float *)malloc(sizeof(float)*FFT_SIZE[config->FftTyp]);
  tx_ift_wr(config,  &TxBmapDoI, &TxBmapDoQ, &TxIftDoI, &TxIftDoQ);
  //debug(V_DEBUG,"Sizeof tx_ift_do_i %d\n", sizeof(TxIftDoQ));


  // rx fft
  RxFftDiI = TxIftDoI;
  RxFftDiQ = TxIftDoQ;
  RxFftDoI = (float *)malloc(sizeof(float)*(config->Len));
  RxFftDoQ = (float *)malloc(sizeof(float)*(config->Len));
  rx_fft_wr(config, &RxFftDiI, &RxFftDiQ, &RxFftDoI, &RxFftDoQ);

  // rx demap
  RxBmapDiI = TxBmapDoI;
  RxBmapDiQ = TxBmapDoQ;
  rx_bmap_wr(config, &RxBmapDiI, &RxBmapDiQ, &RxBmapDo);


  cmp_tx_rx(config->numBits, &TxBmapDi, &RxBmapDo);

  free(TxIftDoI);
  free(TxIftDoQ);
  fclose(FidCfgFile);
  //fclose(FidLogFile);

  return EXIT_SUCCESS;
}
