/*
 * tx_bmap_wr.c
 *
 *  Created on: 2017Äê9ÔÂ20ÈÕ
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "debug.h"
#include "tx_bmap.h"

int tx_bmap_wr(cfg_t *config, int **Di, int **Do)
{

  //int *DoDemux;

	/*
	 * parameter definition
	 */
	int Mod = config->Mod;
	//int Len = config->Len;
	int numBits = config->numBits;


  //debug(V_DEBUG,"output file name is :  %s\n",config->FnameTxBmapMapDoI);

	/*
	 * procedure
	 */

	//DoDemux = (int *)malloc(numBits * sizeof(int));
  tx_bmap(Mod, numBits, &(*Di), &(*Do));
  //tx_bmap_map(Mod, Len, &DoDemux, &(*DoI), &(*DoQ));

   /*
    * log
    */
  //write_af(config->FnameTxBmapMapDoI, Len, &(*DoI));
  //write_af(config->FnameTxBmapMapDoQ, Len, &(*DoQ));

  //free(DoDemux);

	return EXIT_SUCCESS;
}
