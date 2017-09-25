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

int main(void) {

	cfg_t config;
	//FILE *FidLogFile;
	 FILE *FidCfgFile;

  int *DI;

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

  

  FidCfgFile = fopen("./log/tx_bmap_cfg.txt","w");
  //FidLogFile = fopen("./log/tx_bmap_log.txt","w");

  //assert(FidCfgFile);
  //assert(FidLogFile);

	init_cfg(&config, FidCfgFile);

  if (config.InSrc == 0)
  {
    tx_bmap_di_gen(config.numBits, &DI);
  }

	tx_bmap_wr(&config, &DI);

  fclose(FidCfgFile);
  //fclose(FidLogFile);

	return EXIT_SUCCESS;
}
