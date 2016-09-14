/*
 * device.h
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

#ifndef HARDWARE_DEVICE_H_
#define HARDWARE_DEVICE_H_

#define INC_BTN				(1<<0)		//Increment/CW  button = PORTB0
#define DEC_BTN				(1<<1)		//Decrement/CCW button = PORTB1
#define BTN_PORT			PORTB

void hdwInit(void);

#endif /* HARDWARE_DEVICE_H_ */
