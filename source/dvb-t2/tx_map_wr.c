/*
 * tx_bmap_wr.c
 *
 *  Created on: 2017年9月20日
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "debug.h"
#include "tx_map.h"

int tx_map_wr(cfg_t *config, int **Di, float **DoI, float **DoQ)
{

  //int *DoDemux;

	/*
	 * parameter definition
	 */
	int Mod = config->Mod;
	int Len = config->Len;
	//int numBits = config->numBits;


  //debug(V_DEBUG,"output file name is :  %s\n",config->FnameTxBmapMapDoI);

	/*
	 * procedure
	 */

	//DoDemux = (int *)malloc(numBits * sizeof(int));
  //tx_bmap_demux(Mod, numBits, &(*Di), &DoDemux);
  tx_map(Mod, Len, &(*Di), &(*DoI), &(*DoQ));

  /*
   * log
   */
  write_af(config->FnameTxBmapMapDoI, Len, &(*DoI));
  write_af(config->FnameTxBmapMapDoQ, Len, &(*DoQ));

  //free(DoDemux);

	return EXIT_SUCCESS;
}
