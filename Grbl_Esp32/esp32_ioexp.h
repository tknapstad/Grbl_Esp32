/*
  esp32_ioexp.h - code pertaining to I2C I/O expander on the Grbl ESP32 board

  Copyright (c) 2018 Tarjei Knapstad

  Grbl_Esp32 is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl_Esp32 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl_Esp32.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef esp32_ioexp_h
#define esp32_ioexp_h

#include <stdint.h>

// Typedef for ISR
typedef void (*ISRCallback)(void);

// Pin definitions for the I2C I/O expander
typedef enum
{
    GPIO_EXP_NUM_1 = 127,
    GPIO_EXP_NUM_2,
    GPIO_EXP_NUM_3,
    GPIO_EXP_NUM_4,
    GPIO_EXP_NUM_5,
    GPIO_EXP_NUM_6,
    GPIO_EXP_NUM_7,
    GPIO_EXP_NUM_8,
    GPIO_EXP_NUM_9,
    GPIO_EXP_NUM_10,
    GPIO_EXP_NUM_11,
    GPIO_EXP_NUM_12,
    GPIO_EXP_NUM_13,
    GPIO_EXP_NUM_14,
    GPIO_EXP_NUM_15,
    GPIO_EXP_NUM_16
} gpio_ext_num_t;

// Initialise the I/O expander
void esp32_ioexp_init();

// Sets the mode for a pin to either INPUT or OUTPUT.
void esp32_ioexp_pinMode(uint8_t pin, uint8_t mode);

// Read the level of a given pin, returns either HIGH or LOW
uint8_t esp32_ioexp_digitalRead(uint8_t pin);

// Set a given pin to either LOW or HIGH
void esp32_ioexp_digitalWrite(uint8_t pin, uint8_t level);

// Register ISR for a given pin.
// The ISR must be a function that returns void and takes no arguments.
// The mode parameter can be either FALLING, RISING or CHANGE
void esp32_ioexp_attachInterrupt(uint8_t pin, ISRCallback cb, int mode);


#endif
