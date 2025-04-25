hey guys, 
what it is?
its a code for uploading/flashing firmware into a microcontrollers like esp32.

procedure to create ur own

components needed 
5V replay (optional)
IR sensor module
ESP32 Dev Module 

CIRCUIT:
5V relay to ESP32
VCC ---------->	VIN
GND ---------->	GND
IN  ---------->	GPIO5
	
ESP32 to IR sensor module
GPIO13 ------->	OUT
GND ---------->	GND
3V3 ---------->	VCC


Paste the source code in the arduino editor
ctrl + shift + M > select board as esp32 dev module
library > search : ESP32 BLE Keyboard by T-vK.
verify to compile code
connect microcontroller to computer
select COMP USB port then upload. 
everything is done now ull see the esp32 enlisted in Bluetooth list.
connect and use simple hand gestures for switch controls of media players.

Enjoy, until next time ;)
