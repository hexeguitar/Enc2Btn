/*
 * button_out.c
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
#include<avr/io.h>
#include<avr/pgmspace.h>
#include<avr/interrupt.h>
#include "../hardware/device.h"
#include"../encoder/encoder.h"
#include"button_out.h"

static volatile uint8_t incBtnPressed = 0;
static volatile uint8_t incBtnSent = 0;
static volatile uint8_t decBtnPressed = 0;
static volatile uint8_t decBtnSent = 0;
static volatile uint8_t incDelay, decDelay;
uint8_t pressPeriod_ms = DEFAULT_PRESS_PERIOD_MS;


// ================================================================
void buttonUpdate(void)
{
	if (encoderDir == ENC_RIGHT)
	{
		incBtnPressed++;
	}
	if (encoderDir == ENC_LEFT)
	{
		decBtnPressed++;
	}
}
// ================================================================
void buttonHandle(void)
{

	// Increment button
	if (incBtnSent != incBtnPressed)
	{
		if (incDelay > (pressPeriod_ms>>1))		BTN_PORT &= ~INC_BTN;		//pull INC button down
		else									BTN_PORT |= INC_BTN;		//release INC button

		if (incDelay == 0)
		{
			incBtnSent++;
			incDelay = pressPeriod_ms;
		}
	}
	else	incDelay = pressPeriod_ms;

	// Decrement button
	if (decBtnSent != decBtnPressed)
	{
		if (decDelay > (pressPeriod_ms>>1))		BTN_PORT &= ~DEC_BTN;		//pull DEC button down
		else									BTN_PORT |= DEC_BTN;		//release DEC button

		if (decDelay == 0)
		{
			decBtnSent++;
			decDelay = pressPeriod_ms;
		}
	}
	else	decDelay = pressPeriod_ms;


}
// ================================================================
// 1ms interrupt
ISR(TIM0_COMPA_vect)
{
	uint8_t temp8;

	temp8 = incDelay;
	if (temp8) temp8--;
	incDelay = temp8;

	temp8 = decDelay;
	if (temp8) temp8--;
	decDelay = temp8;
}

// =
