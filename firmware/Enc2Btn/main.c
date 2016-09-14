/*
 * Encoder to button converter
 * (c) 08-09 2016 Piotr Zapart
 * www.hexeguitar.com
 *
 * Converts CW and CCW encoder rotation into a constant width active low
 * "button press" events.
 * The main purpose of this module is to interface a rotary encoder
 * to two/three button inputs in USB joystick/DIY cockpit projects.
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
 *
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/wdt.h>
#include "hardware/device.h"
#include "encoder/encoder.h"
#include "buttonOUT/button_out.h"



// ================================================================
int main(void)
{
	regEncoderEventCallback(buttonUpdate);
	hdwInit();
	setEncoder(0);
	/*
	 *
	 */
	pressPeriod_ms=63;

	sei();

	while(1)
	{
		wdt_reset();
		encoderEvent();
		buttonHandle();
	}

}

// END
