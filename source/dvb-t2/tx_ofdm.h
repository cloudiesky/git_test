/*
  ============================================================================
  Name        : Constellation.c
  Author      : CC
  Version     :
  Copyright   : NZ
  Description : Hello World in C, Ansi-style
  ============================================================================
*/

#ifndef TX_OFDM_CORE_H_
#define TX_OFDM_CORE_H_

#include "config.h"
int tx_ofdm(int FftTyp, float **DiI, float **DiQ, float **DoI, float **DoQ);
#endif
