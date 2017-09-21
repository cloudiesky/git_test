/*
 * tx_bmap_di_gen.c
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: zhang.zhi
 */



#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
void tx_bmap_di_gen(int numBits, int **DI)
{
	int i;

	(*DI)=(int*)malloc((numBits)*(sizeof(int)));

	//puts("DI in gen.");
	for (i = 0; i<(numBits); i++)
	{
		(*DI)[i] = rand() % 2;
		debug(V_DEBUG,"%d",(*DI)[i]);
	}

	//printf("\naddress = %d\n", (int)(*DI));
	//puts("Out of gen");
	debug(V_DEBUG,"\nGen done\n");
}
