/*
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "debug.h"
#include "global.h"

int VecCmpF(int length, float **VecRef, float **VecRes){
  int i;
  const float EPSINON = 0.00001;
  float delta;
  for (i = 0; i < length; i++){
    delta = fabs(((*VecRef)[i] - (*VecRes)[i]) /  (*VecRef)[i]);

    if ((delta - EPSINON) > 0 ){
      printf("error: UNEQUIE Vec No. %d\tRef = %f, Res = %f\n", i, (*VecRef)[i], (*VecRes)[i]);
      return 1;
    }
  }
  return 0;
}

int VecCmpI(int length, int **VecRef, int **VecRes){
  int i;
  for (i = 0; i < length; i++){
    if ((*VecRef)[i] != (*VecRes)[i]){
      printf("Vec No. %d\tRef = %d, Res = %d\n", i, (*VecRef)[i], (*VecRes)[i]);
      return 1;
    }
  }
  return 0;
}

