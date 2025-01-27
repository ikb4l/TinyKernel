/**
 * @file utils.h
 * @author Owen Boreham (owenkadeboreham@gmail.com)
 * @version 0.1.2
 * @date 2021-07-09
 * 
 * @copyright Copyright (c) 2021 TinyKernel
 * This file is part of TinyKernel which is released
 * under Apache License 2.0.  See file LICENSE or go
 * to https://www.apache.org/licenses/LICENSE-2.0 for
 * full license details.
 */

#ifndef UTILS_H
#define UTILS_H

#include "types.h"

extern uint32 strlen(const char*);
extern uint32 digit_count(int);
extern void itoa(int, char*);

#endif