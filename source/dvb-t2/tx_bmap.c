/*
 * tx_bmap_dmux.c
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: zhang.zhi
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "debug.h"
void tx_bmap(int Mod, int numBits, int **DI, int **DO)
{
	unsigned InLen;
	unsigned OutLen;

	int i;

	InLen = numBits;
	switch (Mod){
	case 0 :
		OutLen = InLen;
		break;
	case 1 :
		OutLen = InLen / 2;
		break;
	case 2 :
		OutLen = InLen / 4;
		break;
	case 3 :
		OutLen = InLen / 6;
		break;
	default :
		assert(Mod<=3);
    OutLen = 0;
	}


	switch (Mod){
	case 0 :
		for(i = 0; i < OutLen; i++){
			(*DO)[i] = (*DI)[i];
		}
		break;
	case 1 :
		for(i = 0; i < OutLen; i++){
			(*DO)[i] = (((*DI)[2*i]   << 0) |         \
                  ((*DI)[2*i+1] << 1));
		}
		break;
	case 2 :
		for(i = 0; i < OutLen; i++){
			(*DO)[i] = (((*DI)[4*i] << 0)   |         \
                  ((*DI)[4*i+1] << 1) |         \
                  ((*DI)[4*i+2] << 2) |         \
                  ((*DI)[4*i+3] << 3));
		}
		break;
	case 3 :
		for(i = 0; i < OutLen; i++){
			(*DO)[i] = (((*DI)[6*i] << 0)   |        \
                  ((*DI)[6*i+1] << 1) |        \
                  ((*DI)[6*i+2] << 2) |        \
                  ((*DI)[6*i+3] << 3) |        \
                  ((*DI)[6*i+4] << 4) |        \
                  ((*DI)[6*i+5] << 5) );
			debug(V_DEBUG, "%d, %d \n",i,(*DO)[i]);
		}
		break;
	default :
		assert(Mod<=3);
	}

	debug(V_DEBUG,"Demux data out\n");

}
