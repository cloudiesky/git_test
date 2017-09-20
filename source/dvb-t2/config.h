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
  char mod; // constellation type, bpsk, qpsk, 16-qam, 64-qam
  int length; // data length in bit.
}cfg_t;

#endif
