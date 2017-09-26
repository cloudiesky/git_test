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

int main(void) {

  cfg_t *config;
  //FILE *FidLogFile;
   FILE *FidCfgFile;

  int *TxDI;
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
    tx_bmap_di_gen(config->numBits, &TxDI);
  }

  tx_bmap_wr(config, &TxDI, &TxDoI, &TxDoQ);

  RxDiI = TxDoI;
  RxDiQ = TxDoQ;

  rx_bmap_wr(config, &RxDiI, &RxDiQ, &RxDo);

  fclose(FidCfgFile);
  //fclose(FidLogFile);

  return EXIT_SUCCESS;
}
