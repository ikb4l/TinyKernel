/**
 * @file keyboard.c
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

#include <kernel/cpu/ports.h>
#include <kernel/keyboard.h>

char get_input_keycode()
{
  char ch = 0;
  while ((ch = inb(KEYBOARD_PORT)) != 0x60)
  {
    if (ch > 0)
      return ch;
  }
  return ch;
}

/**
 * keep the cpu busy for doing nothing(nop)
 * so that io port will not be processed by cpu
 * here timer can also be used, but lets do this in looping counter
 */
void wait_for_io(uint32 timer_count)
{
  while (1)
  {
    asm volatile("nop");
    timer_count--;
    if (timer_count <= 0)
      break;
  }
}

void sleep(uint32 timer_count)
{
  wait_for_io(timer_count);
}