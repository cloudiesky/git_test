/*
 * tx_bmap_map.h
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */


#ifndef VEC_RD_H_
#define VEC_RD_H_

int vec_rd_fd(const char * Fname, int length, float **Vec);
int vec_rd_f(const char * Fname, int length, float **Vec);
int vec_rd_i(const char * Fname, int length, int **Vec);
#endif
