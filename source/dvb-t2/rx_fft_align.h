/*
  ============================================================================
  Name        : Constellation.c
  Author      : CC
  Version     :
  Copyright   : NZ
  Description : Hello World in C, Ansi-style
  ============================================================================
*/

#ifndef RX_FFT_ALIGN_H_
#define RX_FFT_ALIGN_H_

#include "config.h"
int rx_fft_align(int FftTyp,  \
                 int Mod,     \
                 int numBits, \
                 float **DiI, \
                 float **DiQ, \
                 float **DoI, \
                 float **DoQ );
#endif
