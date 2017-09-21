/*
 * tx_bmap_wr.c
 *
 *  Created on: 2017Äê9ÔÂ20ÈÕ
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "tx_bmap_di_gen.h"
#include "tx_bmap_demux.h"
int tx_bmap_wr(cfg_t* config, int FidLogFile)
{

	int *DI;
	int *DO_DEMUX_I;
	int *DO_DEMUX_Q;
	float *DO_MAP_I;
	float *DO_MAP_Q;

	int i;

	/*
	 * parameter definition
	 */
	int Mod = config->Mod;
	int Len = config->Len;
	int numBits = config->numBits;
	int InSrc = config->InSrc;

	/*
	 * procedure
	 */
	 if (InSrc == 0)
	 {
		 tx_bmap_di_gen(numBits, &DI);
	 }

	 tx_bmap_demux(Mod, numBits, &DO_DEMUX_I, &DO_DEMUX_Q, &DI);

	 tx_bamp_map(Mod, Len, &DO_MAP_I, &DO_MAP_Q,  &DO_DEMUX_I, &DO_DEMUX_Q);

	return EXIT_SUCCESS;
}
