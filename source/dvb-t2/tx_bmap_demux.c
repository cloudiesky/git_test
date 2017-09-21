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
void tx_bmap_demux(int Mod, int numBits, int **DO_I, int **DO_Q, int **DI)
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
	}

	*DO_I = (int *)malloc(OutLen * sizeof(int));
	*DO_Q = (int *)malloc(OutLen * sizeof(int));

	switch (Mod){
	case 0 :
		for(i = 0; i < OutLen; i++){
			(*DO_I)[i] = (*DI)[i];
			(*DO_Q)[i] = 0;
		}
		break;
	case 1 :
		for(i = 0; i < OutLen; i++){
			(*DO_I)[i] = ((*DI)[2*i]   << 0);
			(*DO_Q)[i] = ((*DI)[2*i+1] << 1);
		}
		break;
	case 2 :
		for(i = 0; i < OutLen; i++){
			(*DO_I)[i] = ((*DI)[4*i] << 0)   | \
					     ((*DI)[4*i+1] << 1) ;
			(*DO_Q)[i] = ((*DI)[4*i+2] << 2) | \
						 ((*DI)[4*i+3] << 0);
		}
		break;
	case 3 :
		for(i = 0; i < OutLen; i++){
			(*DO_I)[i] = ((*DI)[6*i] << 0)   | \
					     ((*DI)[6*i+1] << 1) | \
						 ((*DI)[6*i+2] << 2) ;
			(*DO_Q)[i] = ((*DI)[6*i+3] << 0) | \
						 ((*DI)[6*i+4] << 1) | \
						 ((*DI)[6*i+5] << 2) ;
			debug(V_DEBUG, "%d ,%d\n",(*DO_I)[i],(*DO_Q)[i]);
		}
		break;
	default :
		assert(Mod<=3);
	}

	debug(V_DEBUG,"Demux data out\n");

}
