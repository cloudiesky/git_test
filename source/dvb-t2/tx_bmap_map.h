/*
 * tx_bmap_map.h
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: zhang.zhi
 */


#ifndef TX_BMAP_MAP_H_
#define TX_BMAP_MAP_H_

int* tx_bmap_map(int numBits, \
				int Len,  \
				float **DO_MAP_I, \
				float **DO_MAP_Q,  \
				int **DO_DEMUX_I, \
				int **DO_DEMUX_Q);

#endif
