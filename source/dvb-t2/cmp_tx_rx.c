/*
 * cmp_tx_rx.c
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "debug.h"

void cmp_tx_rx(int numBits, int **TXDI, int **RXDO)
{
  int i;
  int cnt_err;
  float rat_err;

  cnt_err = 0;
  for (i = 0; i < numBits; i++)
    {
      if ((*TXDI)[i] != (*RXDO)[i]){
        cnt_err++;
        debug(V_MEDIUM, "Wrong Bit No.%d; tx: %d; rx: %d");
      }
    }

  rat_err = cnt_err / numBits *100;
  debug(V_NONE, "Total Wrong Bit After Mux, %d, Error Rate %.2f\%\n", cnt_err, rat_err);
}
