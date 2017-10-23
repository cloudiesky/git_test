/*
  ============================================================================
  Name        : Constellation.c
  Author      : CC
  Version     :
  Copyright   : NZ
  Description : Hello World in C, Ansi-style
  ============================================================================
*/

#ifndef CONFIG_H_
#define CONFIG_H_

typedef struct __cfg
{
	// constellation type,
	// bpsk = 0,
	// qpsk = 1,
	// 16-qam = 2,
	// 64-qam = 3
	int Mod;

  // data length in bit.
  int Len;

  /* total bits */
  int numBits;

  // input source,
  // 0, generate random;
  // 1 read from file.
  int InSrc;

  // randseed
  unsigned RandSeed;

  // fft/ifft size: 0 -> 1k; 1 -> 4k
  int FftTyp;

  char *FnameTxBmapDi;
  char *FnameTxBmapMapDoI;
  char *FnameTxBmapMapDoQ;

  char *FnameTxIftAlignDoI;
  char *FnameTxIftAlignDoQ;

  char *FnameRxFftCoreDoI;
  char *FnameRxFftCoreDoQ;

  char *FnameRxBmapMapDo;

}cfg_t;

#endif
