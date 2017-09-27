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

#include "config.h"
#include "init_cfg.h"
#include "tx_bmap_wr.h"
#include "tx_bmap_di_gen.h"
#include "rx_bmap_wr.h"
#include "cmp_tx_rx.h"

int main(void) {

  cfg_t *config;
  //FILE *FidLogFile;
   FILE *FidCfgFile;

  int *TxDi;
  float *TxDoI;
  float *TxDoQ;

  float *RxDiI;
  float *RxDiQ;
  int *RxDo;

  puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */



  FidCfgFile = fopen("./log/tx_bmap_cfg.txt","w");
  assert(FidCfgFile);


  init_cfg(&config, FidCfgFile);

  if (config->InSrc == 0)
  {
    tx_bmap_di_gen(config->numBits, &TxDi);
  }

  tx_bmap_wr(config, &TxDi, &TxDoI, &TxDoQ);

  RxDiI = TxDoI;
  RxDiQ = TxDoQ;

  rx_bmap_wr(config, &RxDiI, &RxDiQ, &RxDo);


  cmp_tx_rx(config->numBits, &TxDi, &RxDo);

  fclose(FidCfgFile);
  //fclose(FidLogFile);

  return EXIT_SUCCESS;
}
