/*
 * encoder.c
 *
 *  Created on: 14.08.2016
 *      Author: Piotr Zapart
 *
 * based on work of Ben Buxton
 * http://www.buxtronix.net/2011/10/rotary-encoders-done-properly.html
 *
 *  This program is free software: you can redistribute it and/or modify
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

#include"encoder.h"

volatile int encoderCnt;
volatile uint8_t encoderDir;
volatile uint8_t encoderFlag;
volatile uint8_t encoderType;

// pointer to encoder envent function
static void (*encEventCallback) (void);

// Half step encoder
const uint8_t encTabHS[6][4] PROGMEM=
{
	{0x03, 0x02, 0x01, 0x00}, {0x23, 0x00, 0x01, 0x00},
	{0x13, 0x02, 0x00, 0x00}, {0x03, 0x05, 0x04, 0x00},
	{0x03, 0x03, 0x04, 0x10}, {0x03, 0x05, 0x03, 0x20}
};

// Full step encoder
const uint8_t encTabFS[7][4] PROGMEM=
{
	{0x00, 0x02, 0x04, 0x00}, {0x03, 0x00, 0x01, 0x10},
	{0x03, 0x02, 0x00, 0x00}, {0x03, 0x02, 0x01, 0x00},
	{0x06, 0x00, 0x04, 0x00}, {0x06, 0x05, 0x00, 0x20},
	{0x06, 0x05, 0x04, 0x00}
};
// ================================================================================
void regEncoderEventCallback(void(*callback)(void))
{
	encEventCallback = callback;
}
// ================================================================================
int getEncoder (void)
{
    uint8_t sreg = SREG;
    cli();
    int res = encoderCnt;
    SREG = sreg;
    return res;
}
// ================================================================================
void setEncoder(int val)
{
    uint8_t sreg = SREG;
    cli();
    encoderCnt = val;
    SREG = sreg;
}
// ================================================================================
void encoderService(void)
{
    static volatile uint8_t encoderState;
    register uint8_t pin = PINB;
    register uint8_t ABstate = (((pin&ENC_B) ? 2:0) | ((pin&ENC_A) ? 1:0));

    encoderType = (pin&ENC_TYPE) ? FULL_STEP : HALF_STEP;

    if (encoderType == HALF_STEP)	encoderState = pgm_read_byte(&encTabHS[encoderState & 0x0F][ABstate]);
    else							encoderState = pgm_read_byte(&encTabFS[encoderState & 0x0F][ABstate]);

    ABstate = (encoderState & 0x30);
    if (ABstate)
    {
        encoderDir = ABstate;
        if (ABstate == ENC_RIGHT) encoderCnt++;
        else encoderCnt--;
        encoderFlag = 1;
    }
}
// ================================================================================
void encoderInit(void)
{
	ENC_DIR &= ~(ENC_A | ENC_B);
    ENC_PORT |= ENC_A | ENC_B;
    encoderService();

    GIMSK |= (1<<PCIE);						//enable PCINT
    PCMSK |= (1<<PCINT_B) | (1<<PCINT_A);	//enable PCINT3&4
}
// ================================================================================
void encoderEvent(void)
{
    if (encoderFlag)
    {
        if(encEventCallback) encEventCallback();
        encoderFlag=0;
    }
}
// ================================================================================
ISR (PCINT_IRQ_VECT)
{
	encoderService();
}


