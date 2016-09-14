/*
 * device.c
 *
 *  Created on: 14.08.2016
 *      Author: Piotr Zapart
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include "device.h"
#include "../encoder/encoder.h"

void hdwInit(void)
{
	// ### Configure ports ###
	/*
	 * 0 = input, 1 = output
	 *
	 * PB0 = output Encoder Increase, active low /SPI MOSI
	 * PB1 = output Encoder Decrease, active low /SPI MISO
	 * PB2 = input, SPI SCK
	 * PB3 = input + pullup, PCINT3, Encoder A input
	 * PB4 = input + pullup, PCINT4, Encoder B input
	 * PB5 = RESET
	 *
	 * DDRB = 0b00000011
	 */

	DDRB |= INC_BTN + DEC_BTN;
	PORTB |= INC_BTN + DEC_BTN + ENC_TYPE;		//SET OUTPUTS TO 1 (active low)

	// ### Configure timers ###

	//Timer0, 1ms
	//Internal clock 1MHz
	TCCR0A |= _BV(WGM01);						// turn on CTC
	TCCR0B |= _BV(CS01)+_BV(CS00);				// prescaler /64
	OCR0A = 0x7C;
	TIMSK |= _BV(OCIE0A);						// turn on OutCompare 0 interrupt

	encoderInit();

	// ### Configure Watchdog
	wdt_enable(WDTO_2S);	 //wlaczenie watchdoga, 2s
}

