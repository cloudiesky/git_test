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
#include "tx_bmap_demux.h"
#include "tx_bmap_map.h"

int tx_bmap_wr(cfg_t *config, int **Di, float **DoI, float **DoQ)
{

	
	int *DoDemux;

	/*
	 * parameter definition
	 */
	int Mod = config->Mod;
	int Len = config->Len;
	int numBits = config->numBits;

  //printf("cfg file name %c\n", config->FnameTxBmapMapDoI);

  debug(V_DEBUG,"output file name is :  %s\n",config->FnameTxBmapMapDoI);
  debug(V_DEBUG,"Mod is  %d ",config->Mod);

	/*
	 * procedure
	 */

  tx_bmap_demux(Mod, numBits, &DoDemux, &(*Di));
  
  tx_bmap_map(Mod, Len, &(*DoI), &(*DoQ),  &DoDemux);

   /*
    * log
    */
  //write_af(FnameDoI, Len, &(*DoI));
  write_af("./log/tx_bmap_map__do_map_i.txt", Len, &(*DoI));
  write_af("./log/tx_bmap_map__do_map_q.txt", Len, &(*DoQ));

	return EXIT_SUCCESS;
}
