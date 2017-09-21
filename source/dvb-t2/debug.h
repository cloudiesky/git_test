/*
 * debug.h
 *
 *  Created on: 2017年9月21日
 *      Author: zhang.zhi
 */

#ifndef DEBUG_H_
#define DEBUG_H_

typedef enum{
V_DEBUG  = 100,
V_HIGH   = 75,
V_MERIUM = 50,
V_LOW    = 25,
V_NONE   = 0
}Verb;



void debug(int level, const char *fmt, ...);
#endif
