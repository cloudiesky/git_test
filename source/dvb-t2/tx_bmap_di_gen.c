/*
 * tx_bmap_di_gen.c
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: zhang.zhi
 */



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "debug.h"
#include "config.h"

void tx_bmap_di_gen(cfg_t *config, int **DI)
{
	int i;
  int di_tmp;
  FILE *fp;

  if (config->InSrc == 0) {
    debug(V_DEBUG,"DI in gen.");
    for (i = 0; i<(config->numBits); i++)
      {
        (*DI)[i] = rand() % 2;
        debug(V_DEBUG,"%d",(*DI)[i]);
        if ((i%4 == 0) | (i == config->numBits-1))
          debug(V_DEBUG,"\n");
      }
    debug(V_DEBUG,"Gen done\n");
    write_ai(config->FnameTxBmapDi, config->numBits, DI);
  }
  else {
    fp = fopen(config->FnameTxBmapDi, "r");
    assert(fp);
    for (i = 0; i<(config->numBits); i++)
      {
        if(fscanf(fp,"%d",&di_tmp)){
          assert((di_tmp == 0) | (di_tmp == 1));
          (*DI)[i] = di_tmp;
        }
        else
          printf("Error: Reading from file %s\n",config->FnameTxBmapDi);
      }
  }
}
