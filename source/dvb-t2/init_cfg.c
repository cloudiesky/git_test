/*
 * init_cfg.c
 *
 *  Created on: 2017Äê9ÔÂ20ÈÕ
 *      Author: cloudieskyx
 */


#include <stdio.h>
#include <stdlib.h>
#include "config.h"
int init_cfg(cfg_t* config, int FidCfgFile)
{
	config->mod=3;
	config->length=128;
	return EXIT_SUCCESS;
}
