/*
 * init_cfg.c
 *
 *  Created on: 2017Äê9ÔÂ20ÈÕ
 *      Author: cloudieskyx
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "config.h"
#include <time.h>
int init_cfg(cfg_t* config, int FidCfgFile)
{


	config->Mod      = 3;
	config->Len      = 128;
	config->InSrc    = 0;


	switch (config->Mod){
	case (0) :
			config->numBits = config->Len;
			break;
	default :
		assert(config->Mod <= 3);
		config->numBits = config->Len * config->Mod * 2;
	}


#ifdef RANDSEED
	config->RandSeed = `RANDSEED;
#else
	config->RandSeed = (unsigned)time(NULL);
#endif
	printf("RandSeed = %d\n",config->RandSeed);
	srand(config->RandSeed);



	return EXIT_SUCCESS;
}
