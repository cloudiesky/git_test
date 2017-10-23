/*
  ============================================================================
  Name        : Constellation.c
  Author      : CC
  Version     :
  Copyright   : NZ
  Description : Hello World in C, Ansi-style
  ============================================================================
*/

#ifndef TX_MAP_REF_H_
#define TX_MAP_REF_H_

#include "config.h"
int tx_map_ref_rd(cfg_t **config, int **Di, float **DoI, float **DoQ);
int tx_map_ref_cmp(cfg_t **config, float **RefI, float **RefQ, float **MapI, float **MapQ);
#endif

