/*
 * tx_bmap_wr.c
 *
 *  Created on: 2017年9月20日
 *      Author: cloudieskyx
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include "config.h"
#include "debug.h"

int tx_map_ref_rd(cfg_t **config, int **Di, float **DoI, float **DoQ)
{
  int i;
  //int Len;
  //int con_tmp;
  long long unsigned long_tmp;
  double double_tmp;
  FILE *fp;
  //int MAX_uint16 = pow(2,16);
  //int MAX_int16 = pow(2,15) - 1;
  //Len = 518400;

  //printf("sizeof long : %d; longlong : %d\n", sizeof(long), sizeof(long long));

  fp=fopen("data/bmap_tx_do.txt","r");
  i = 0;
  while (1) {
    fscanf(fp,"%d",&((*Di)[i]));
    if (feof(fp))
      break;
    else
      i++;
  }
  fclose(fp);
  assert(i > 0);
  debug(V_DEBUG,"bmap tx lenth is %d\n",i);



  fp=fopen("data/conrot_tx_do.txt","r");
  i = 0;
  while (1) {
    fscanf(fp,"%I64x",&long_tmp);
    if (feof(fp))      break;
    if (i<100) debug(V_DEBUG, "real: %016x\t",long_tmp);
    memcpy(&double_tmp, &long_tmp, 8);
    if (i<100) debug(V_DEBUG, "double: %+05f\t",double_tmp);
    (*DoI)[i] = (float)(double_tmp);

    fscanf(fp,"%I64x",&long_tmp);
    if (feof(fp))      break;
    if (i<100) debug(V_DEBUG, "imag: %016x\t",long_tmp);
    memcpy(&double_tmp, &long_tmp, 8);
    if (i<100) debug(V_DEBUG, "double: %+05f\t",double_tmp);
    (*DoQ)[i] = (float)(double_tmp);

    if (i<100) debug(V_DEBUG, "%05f%+05fi\n",(*DoI)[i],(*DoQ)[i]);
    i++;
  }
  fclose(fp);
  assert(i > 0);
  debug(V_DEBUG,"conrot tx lenth is %d\n",i) ;


  /* fp=fopen("data/conrot_tx_do.txt","r"); */
  /* i = 0; */
  /* while (1) { */

  /*   fscanf(fp,"%x",&con_tmp); */
  /*   if (feof(fp))      break; */
  /*   con_tmp = (con_tmp <= MAX_int16) ? con_tmp :  (con_tmp - MAX_uint16); */
  /*   debug(V_DEBUG, "real: %5d\t",con_tmp); */
  /*   (*DoI)[i] = (float)con_tmp / 10000; */

  /*   fscanf(fp,"%x",&con_tmp); */
  /*   if (feof(fp))      break; */
  /*   con_tmp = (con_tmp <= MAX_int16) ? con_tmp :  (con_tmp - MAX_uint16); */
  /*   debug(V_DEBUG, "imag: %5d\t",con_tmp); */
  /*   (*DoQ)[i] = (float)con_tmp / 10000; */

  /*   debug(V_DEBUG, "%5f%+5fi\n",(*DoI)[i],(*DoQ)[i]); */
  /*   i++; */
  /* } */
  /* fclose(fp); */
  /* assert(i > 0); */
  /* debug(V_DEBUG,"conrot tx lenth is %d\n",i) ;*/

	return EXIT_SUCCESS;
}

int tx_map_ref_cmp(cfg_t **config, float **RefI, float **RefQ, float **MapI, float **MapQ)
{
	return EXIT_SUCCESS;
  
}


