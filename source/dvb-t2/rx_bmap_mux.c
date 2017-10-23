/*
 * rx_bmap_mux.c
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "debug.h"
void rx_bmap_mux(int Mod, int numBits, int **DI, int **DO)
{
  unsigned InLen;
	unsigned OutLen;

	int i;

	OutLen = numBits;
	switch (Mod){
	case 0 :
		InLen = OutLen;
		break;
	case 1 :
		InLen = OutLen / 2;
		break;
	case 2 :
		InLen = OutLen / 4;
		break;
	case 3 :
		InLen = OutLen / 6;
		break;
	default :
		assert(Mod<=3);
    InLen = 0;
	}


  switch (Mod){

	case 0 :
		for(i = 0; i < InLen; i++){
			(*DO)[i] = (*DI)[i];
		}
		break;

	case 1 :
		for(i = 0; i < InLen; i++){
			(*DO)[i*2]   = ((*DI)[i] & 0x1) ;
			(*DO)[i*2+1] = ((*DI)[i] & 0x2) >>1 ;
		}
		break;

	case 2 :
		for(i = 0; i < InLen; i++){
			(*DO)[i*4]   = ((*DI)[i] & 0x1) ;
			(*DO)[i*4+1] = ((*DI)[i] & 0x2) >> 1 ;
			(*DO)[i*4+2] = ((*DI)[i] & 0x4) >> 2 ;
			(*DO)[i*4+3] = ((*DI)[i] & 0x8) >> 3 ;
		}

		break;
	case 3 :
		for(i = 0; i < InLen; i++){
			(*DO)[i*6]   = ((*DI)[i] & 0x1) ;
			(*DO)[i*6+1] = ((*DI)[i] & 0x2) >> 1 ;
			(*DO)[i*6+2] = ((*DI)[i] & 0x4) >> 2 ;
			(*DO)[i*6+3] = ((*DI)[i] & 0x8) >> 3 ;
			(*DO)[i*6+4] = ((*DI)[i] & 0x10) >> 4 ;
			(*DO)[i*6+5] = ((*DI)[i] & 0x20) >> 5 ;
			debug(V_DEBUG, "%d, %d \n",i,(*DO)[i]);
		}
		break;
	default :
		assert(Mod<=3);
	}

	debug(V_DEBUG,"Mux data out\n");

}
