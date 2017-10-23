/*
  ============================================================================
  Name        : Constellation.c
  Author      : CC
  Version     :
  Copyright   : NZ
  Description : Hello World in C, Ansi-style
  ============================================================================
*/

#ifndef TX_OFDM_WR_H_
#define TX_OFDM_WR_H_

#include "config.h"
int tx_ofdm_wr(cfg_t *config, float **DiI, float **DiQ, float **DoI, float **DoQ);
#endif
