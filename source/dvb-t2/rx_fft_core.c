/*
 * rx_fft_core.c
 *
 *  Created on: 2017年9月20日
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <complex.h>

#include "config.h"
#include "global.h"
#include "debug.h"
#include "fft.h"

int rx_fft_core(int FftTyp,  \
                float **DiI, \
                float **DiQ, \
                float **DoI, \
                float **DoQ  )
{

  size_t n;

	/*
	 * parameter definition
	 */

  size_t N = FFT_SIZE[FftTyp];
  float complex vector[N];

  for(n = 0; n < N; n++) {
    vector[n] = (*DiI)[n] + (*DiQ)[n] * I;
	}

  fft(vector, N);

  for(n = 0; n < N; n++) {
    (*DoI)[n] = creal(vector[n]);
    (*DoQ)[n] = cimag(vector[n]);
	}

  debug(V_DEBUG, "fft results:\n");
  for(n = 0; n < N; n++) {
    debug(V_DEBUG, "Frequency No.%d : %f%+fi\n", n,(*DoI)[n],(*DoQ)[n]);
	}
  debug(V_DEBUG, "fft result ends\n\n");

	return EXIT_SUCCESS;
}
