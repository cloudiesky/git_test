/*
 * tx_bmap_wr.c
 *
 *  Created on: 2017��9��20��
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int tx_bmap_wr(cfg_t* config, int FidLogFile)
{
	printf("mod = %0d, length= %0d",config->mod,config->length);
	return EXIT_SUCCESS;
}
