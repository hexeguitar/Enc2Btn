/*
 * encoder.h
 *
 *  Created on: 14.08.2016
 *      Author: Piotr Zapart
 *
 * based on work of Ben Buxton
 * http://www.buxtronix.net/2011/10/rotary-encoders-done-properly.html
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

#ifndef ENCODER_ENCODER_H_
#define ENCODER_ENCODER_H_

#define ENC_A 		(1<<PB4)
#define ENC_B 		(1<<PB3)
#define ENC_PIN 	PINB
#define ENC_PORT 	PORTB
#define ENC_DIR		DDRB
#define HALF_STEP	0
#define FULL_STEP	1
#define ENC_TYPE	(1<<2)

#define PCINT_IRQ_VECT	PCINT0_vect
#define PCMSK_REG		PCMSK2
#define PCINT_A			PCINT3
#define PCINT_B			PCINT4

#define enc_A_HI		(ENC_PIN & ENC_A)
#define enc_B_HI		(ENC_PIN & ENC_B)

#ifdef 	GIMSK
#define GICR	GIMSK
#endif

#define ENC_LEFT		0x10
#define ENC_RIGHT		0x20

extern volatile uint8_t encoderDir;

void encoderInit (void);
void encoderEvent(void);

void regEncoderEventCallback(void(*callback)(void));

void encoderService(void);
int getEncoder(void);
void setEncoder(int value);

#endif /* ENCODER_ENCODER_H_ */
