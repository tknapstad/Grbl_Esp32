/*
  esp32_ioexp.cpp - code pertaining to I2C I/O expander on the Grbl ESP32 board

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

#include "esp32_ioexp.h"

// If MSB is set this is an I/O expander pin
static inline bool is_io_expander_pin(uint8_t pin)
{
    return (pin & (1 << 7));
}

void esp32_ioexp_init()
{
    // TODO: Set up I2C
    // TODO: Configure I/O expander
}

// Sets the mode for a pin to either INPUT or OUTPUT.
void esp32_ioexp_pinMode(uint8_t pin, uint8_t mode)
{
    if (is_io_expander_pin(pin))
    {
        // TODO: Configure pin on I/O expander
    }
    else
    {
        pinMode(pin, mode);
    }
}

// Read the level of a given pin, returns either HIGH or LOW
uint8_t esp32_ioexp_digitalRead(uint8_t pin)
{
    if (is_io_expander_pin(pin))
    {
        // TODO: Read pin on I/O expander
    }
    else
    {
        return digitalRead(pin);
    }
}

// Set a given pin to either LOW or HIGH
void esp32_ioexp_digitalWrite(uint8_t pin, uint8_t level)
{
    if (is_io_expander_pin(pin))
    {
        // TODO: Set pin on I/O expander
    }
    else
    {
        digitalWrite(pin, level);
    }
}

// Register ISR for a given pin.
// The ISR must be a function that returns void and takes no arguments.
// The mode parameter can be either FALLING, RISING or CHANGE
void esp32_ioexp_attachInterrupt(uint8_t pin, ISRCallback cb, int mode)
{
    if (is_io_expander_pin(pin))
    {
        // TODO: Set pin on I/O expander
    }
    else
    {
        attachInterrupt(digitalPinToInterrupt(pin), cb, mode);
    }
}

