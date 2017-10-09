/*
  ============================================================================
  Name        : Constellation.c
  Author      : CC
  Version     :
  Copyright   : NZ
  Description : Hello World in C, Ansi-style
  ============================================================================
*/

#ifndef RX_FFT_CORE_H_
#define RX_FFT_CORE_H_

#include "config.h"
int rx_fft_core(int FftTyp,   \
                float **DiI,  \
                float **DiQ,  \
                float **DoI,  \
                float **DoQ   \
                );
#endif
