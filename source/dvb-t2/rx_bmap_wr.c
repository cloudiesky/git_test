/*
 * rx_bmap_wr.c
 *
 *  Created on: 2017年9月20日
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "debug.h"

#include "rx_bmap_demap.h"
#include "rx_bmap_mux.h"

int rx_bmap_wr(cfg_t *config, float **DiI, float **DiQ, int **Do)
{


  int *DoDemap;

	/*
	 * parameter definition
	 */
	int Mod = config->Mod;
	int Len = config->Len;
	int numBits = config->numBits;


	/*
	 * procedure
	 */

  DoDemap = (int *)malloc(sizeof(int) * Len);

  rx_bmap_demap(Mod, Len, &(*DiI),  &(*DiQ), &DoDemap);

  rx_bmap_mux(Mod, numBits, &DoDemap, &(*Do));

  /*
   * log
   */
  //write_ai(config->FnameRxBmapMapDo, Len, &DoDemap);

	return EXIT_SUCCESS;
}
