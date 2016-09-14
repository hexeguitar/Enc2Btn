/*
 * button_out.h
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

#ifndef BUTTONOUT_BUTTON_OUT_H_
#define BUTTONOUT_BUTTON_OUT_H_

#define DEFAULT_PRESS_PERIOD_MS 		63

extern uint8_t pressPeriod_ms;


void buttonUpdate(void);
void buttonHandle(void);



#endif /* BUTTONOUT_BUTTON_OUT_H_ */
