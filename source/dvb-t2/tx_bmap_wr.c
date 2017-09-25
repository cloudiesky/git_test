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
#include "tx_bmap_di_gen.h"
#include "tx_bmap_demux.h"
#include "tx_bmap_map.h"

int tx_bmap_wr(cfg_t* config, int **DI)
{

	
	int *DO_DEMUX;
	float *DO_MAP_I;
	float *DO_MAP_Q;

	/*
	 * parameter definition
	 */
	int Mod = config->Mod;
	int Len = config->Len;
	int numBits = config->numBits;

	/*
	 * procedure
	 */
	 //if (InSrc == 0)
	 //{
	 //  tx_bmap_di_gen(numBits, &DI);
	 //}

  tx_bmap_demux(Mod, numBits, &DO_DEMUX, &(*DI));
  
  tx_bmap_map(Mod, Len, &DO_MAP_I, &DO_MAP_Q,  &DO_DEMUX);

   /*
    * log
    */
   write_af("./log/tx_bmap_map__do_map_i", Len, &DO_MAP_I);
   write_af("./log/tx_bmap_map__do_map_q", Len, &DO_MAP_Q);

	return EXIT_SUCCESS;
}
