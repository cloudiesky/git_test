/*
 * rx_bdemap_demap.h
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */


#ifndef RX_BMAP_DEMAP_H_
#define RX_BMAP_DEMAP_H_

int* rx_bmap_demap(int Mod,                       \
                   int Len,                       \
                   float **DI_I,                  \
                   float **DI_Q,                  \
                   int **DO                   );

#endif
