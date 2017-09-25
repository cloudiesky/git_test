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
//#include "rx_bmap_demux.h"
//#include "rx_bmap_map.h"

int rx_bmap_wr(cfg_t* config, FILE *FidLogFile)
{

	//int *DI;
	//int *DO_DEMUX;
	//float *DO_MAP_I;
	//float *DO_MAP_Q;
	//int i;

	/*
	 * parameter definition
	 */
	//int Mod = config->Mod;
	//int Len = config->Len;
	//int numBits = config->numBits;
	//int InSrc = config->InSrc;

	/*
	 * procedure
	 */
  //if (InSrc == 0)
  //  {
      //rx_bmap_di_gen(numBits, &DI);
  //  }

  //rx_bmap_demux(Mod, numBits, &DO_DEMUX, &DI);

  //rx_bmap_map(Mod, Len, &DO_MAP_I, &DO_MAP_Q,  &DO_DEMUX);

  /*
   * log
   */
  //write_af("./log/rx_bmap_map__do_map_i", Len, &DO_MAP_I);
  //write_af("./log/rx_bmap_map__do_map_q", Len, &DO_MAP_Q);

	return EXIT_SUCCESS;
}
