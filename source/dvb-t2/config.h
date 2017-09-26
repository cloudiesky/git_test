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

  int Len;
  // data length in bit.

  /* total bits */
  int numBits;

  // input source,
  // 0, generate random;
  // 1 read from file.
  int InSrc;

  unsigned RandSeed;
  // randseed

  char *FnameTxBmapMapDoI;
  char *FnameTxBmapMapDoQ;

  char *FnameRxBmapMapDo;

}cfg_t;

#endif
