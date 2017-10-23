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
#include "tx_map_ref.h"
#include "tx_map_wr.h"
#include "vec_cmp.h"
#include "vec_rd.h"
int main(void) {

  cfg_t *config;
  int length_tmp;

  const char FnameCfg[]     = "data/init_cfg.txt";

  //int *TxBmapDo;

  int *TxMapDi;
  float *TxMapDoI;
  float *TxMapDoQ;

  int *TxRefMapDi;
  float *TxRefMapDoI;
  float *TxRefMapDoQ;

  puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

  printf("Info Verbosity = %d\n",VERB);

  //vec_rd_fd("data/conrot_tx_do.txt", length_tmp, &TxRefMapDoI);
  length_tmp=0;
  //vec_rd_f("data/fftDI.txt", length_tmp, &TxRefMapDoI);
  vec_rd_i("data/bmap_tx_do.txt", length_tmp, &TxMapDi);
  free(TxRefMapDoI);

  init_cfg(&config, FnameCfg);

  TxRefMapDi  = (int*)malloc(config->Len * sizeof(int));
  TxRefMapDoI = (float*)malloc(config->Len * sizeof(float));
  TxRefMapDoQ = (float*)malloc(config->Len * sizeof(float));
  tx_map_ref_rd(&config, &TxRefMapDi, &TxRefMapDoI, &TxRefMapDoQ);

 // tx map
  TxMapDi = TxRefMapDi;
  TxMapDoI = (float*)malloc(config->Len * sizeof(float));
  TxMapDoQ = (float*)malloc(config->Len * sizeof(float));
  tx_map_wr(config, &TxMapDi, &TxMapDoI, &TxMapDoQ);

  VecCmpF((config->Len), &TxRefMapDoI, &TxMapDoI);
  VecCmpF((config->Len), &TxRefMapDoQ, &TxMapDoQ);

  return EXIT_SUCCESS;
}
