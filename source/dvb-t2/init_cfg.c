/*
 * init_cfg.c
 *
 *  Created on: 2017Äê9ÔÂ20ÈÕ
 *      Author: cloudieskyx
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "config.h"
#include "global.h"
#include "debug.h"

int init_cfg(cfg_t **config, FILE FidCfgFile)
{

  int i;
  const char FnameTxBmapMapDoI[] = "./log/tx_bmap_map__do_map_i.txt";
  const char FnameTxBmapMapDoQ[] = "./log/tx_bmap_map__do_map_Q.txt";
  const char FnameRxBmapMapDo[] =  "./log/rx_bmap_map__do_map.txt";


  (*config) = (cfg_t *)malloc(sizeof(cfg_t));
  (*config)->FnameTxBmapMapDoI = (char *)malloc(sizeof(FnameTxBmapMapDoI) * sizeof(char));
  (*config)->FnameTxBmapMapDoQ = (char *)malloc(sizeof(FnameTxBmapMapDoQ) * sizeof(char));
  (*config)->FnameRxBmapMapDo  = (char *)malloc(sizeof(FnameRxBmapMapDo) * sizeof(char));

  memcpy((*config)->FnameTxBmapMapDoI, FnameTxBmapMapDoI, sizeof(FnameTxBmapMapDoI));
  memcpy((*config)->FnameTxBmapMapDoQ, FnameTxBmapMapDoQ, sizeof(FnameTxBmapMapDoQ));
  memcpy((*config)->FnameRxBmapMapDo,  FnameRxBmapMapDo,  sizeof(FnameRxBmapMapDo));

	(*config)->Mod      = 3;
	(*config)->Len      = 128;
	(*config)->InSrc    = 0;
  (*config)->FftTyp   = 0;

  debug(V_DEBUG, "config->Mod  %d\n", (*config)->Mod);
  debug(V_DEBUG, "config->Len  %d\n", (*config)->Len);
  debug(V_DEBUG, "config->InSrc  %d\n", (*config)->InSrc);
  debug(V_DEBUG, "config->FftTyp  %d: FFT_SIZE %d\n", (*config)->FftTyp, FFT_SIZE[(*config)->FftTyp]);
  debug(V_DEBUG, "config->FnameTxBmapMapDoI  %s\n", (*config)->FnameTxBmapMapDoI);
  debug(V_DEBUG, "config->FnameTxBmapMapDoQ  %s\n", (*config)->FnameTxBmapMapDoQ);
  debug(V_DEBUG, "config->FnameRxBmapMapDo   %s\n", (*config)->FnameRxBmapMapDo);
  

	switch ((*config)->Mod){
	case (0) :
			(*config)->numBits = (*config)->Len;
			break;
	default :
		assert((*config)->Mod <= 3);
		(*config)->numBits = ((*config)->Len) * ((*config)->Mod) * 2;
	}


#ifdef RANDSEED
	(*config)->RandSeed = RANDSEED;
#else
	(*config)->RandSeed = (unsigned)time(NULL);
#endif
	printf("RandSeed = %d\n",(*config)->RandSeed);
	srand((*config)->RandSeed);



	return EXIT_SUCCESS;
}
