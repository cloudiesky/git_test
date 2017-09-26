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

  rx_bmap_demap(Mod, Len, &DoDemap, &(*DiI),  &(*DiQ));

  rx_bmap_mux(Mod, numBits, &(*Do), &DoDemap);

  /*
   * log
   */
  //write_af("./log/rx_bmap_map__do_map_i", Len, &DO_MAP_I);
  //write_af("./log/rx_bmap_map__do_map_q", Len, &DO_MAP_Q);

	return EXIT_SUCCESS;
}
