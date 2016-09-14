## Encoder to button adapter ##

This little board is designed to convert the CW and CCW encoder rotation into an active low "press button" events.
The main use for this adapter are DIY joystick/cockpit systems with no dedicated rotary encoder inputs.
With this board the encoder can be connected to ordinary active low button inputs.

![alt text][pic1]

The outputs of the encoder are filtered, debounced and work on PinChange interrupts basis, thus delivering a reliable operation, even with cheaper types of encoders.  
The number of steps is buffered and "clicked out" in a constant period pulses to avoid missing steps due to button debounce routines. A quick turn of a 30 step rotary encoder will be definitely too fast for typical button input with 20-50ms debounce time. The default press on and release time of a one button press event is set to about 30ms in firmware.

Two types of encoders are implemented: half step and full step. Setting is done via a jumper.
How to determine the encoder type: one step should generate one button press event. If it takes two steps to make one click, or one step generates two clicks, simply change the encoder type setting to the opposite one.

##### Programming the ATTINY25 chip: #####  
use any ISP AVR programmer, like USBasp or AVR MKII.   
First, set the fuses to
* Low  = 0xE2
* High = 0xDD
* Ext  = 0xFF

then upload the **Enc2Btn.hex** file found in firmware/hex directory.

##### Compatible encoder models (11mm):#####
* ALPS EC11 series
* BOURNS PEC11L-4xxxF series
* various no name 11mm rotary encoders  

##### Operation: #####
1. Connect the power lines: GND and VCC (3-5V DC).
2. Connect the INC and DEC outputs to any active low button inputs in your joystick/controller board.
3. If encoder has a built in button, attach the BTN out to another button input.

Depending on the encoder type and it's internal construction it may happen the INC and DEC outputs will work backwards, CW rotation will generate pulses on DEC and vice versa. No big deal, as you can swap the button inputs freely.

##### Construction: #####
Boards can be ordered directly from OSH Park:

<a href="https://www.oshpark.com/shared_projects/oFZJGAvs"><img src="https://www.oshpark.com/assets/badge-5b7ec47045b78aef6eb9d83b3bac6b1920de805e9a0c227658eac6e19a045b9c.png" alt="Order from OSH Park"></img></a>

![alt text][pcbtop] ![alt text][pcbbtm]

Passive components are in 0603 size. The ATTINY25SU chip is in SOIC8 **Wide** package.

![alt text][pic2]

![alt text][pic3]

![alt text][pic4]

![alt text][pic5]


##### Credits: #####

The encoder subroutines are heavily inspired by the work of Ben Buxton   http://www.buxtronix.net/2011/10/rotary-encoders-done-properly.html  


------
(c) 08/09.2016 by Piotr Zapart
www.hexeguitar.com

License:
Creative Commons - Attribution - ShareAlike 3.0
[http://creativecommons.org/licenses/by-sa/3.0/](http://creativecommons.org/licenses/by-sa/3.0/)

[pic1]: pics/Enc2Btn_operation.png "Enc2Btn"
[pic2]: pics/Enc2Btn1.png "Enc2Btn"
[pic3]: pics/Enc2Btn2.png "Enc2Btn"
[pic4]: pics/Enc2Btn3.jpg "Enc2Btn"
[pic5]: pics/Enc2Btn4.jpg "Enc2Btn"
[pcbtop]: pics/pcb_top.png "PCB top"
[pcbbtm]: pics/pcb_btm.png "PCB bottom"
