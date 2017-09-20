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
#include "config.h"
#include "init_cfg.h"
#include "tx_bmap_wr.h"

int main(void) {

	cfg_t config;
	int FidLogFile;
	int FidCfgFile;
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */


	init_cfg(&config, FidCfgFile);

	tx_bmap_wr(&config, FidLogFile);

	return EXIT_SUCCESS;
}
