/* CONNECTIONS:
 *---------------------
 * HC-05        ARDUINO
 *--------------------- 
 *  EN            9
 *  VCC           5V
 *  GND           GND
 *  TXD           10
 *  RXD           11
 *  
 *  PROCEDURE:
 * 1. Connect HC-05 to Arduino as shown above.
 * 2. Upload this sketch to Arduino.
 * 3. Press the push button on Hc-05 and then power up Arduino (via USB cable).
 * 4. Notice the LED on HC-05 blinks at a lower frequency (0.5 Hz).
 * 5. Open Serial Monitor and set "Both NL & CR" and "9600 baud".
 * 6. Type in the AT commands into the terminal window and hit send.
 * 
 * NOTE:
 * In order for AT+NAME? command to work, press the push button on the HC-05 module and then hit Enter to transmit the command.
 */

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11); // RX,TX

void setup() 
{
  pinMode(9,OUTPUT);  // This will pull the HC-05 pin 34 (Key/EN/Wakeup pin) HIGH to switch module to AT mode
  digitalWrite(9,HIGH); 
  Serial.begin(9600);
  Serial.println("Enter AT Commands:");
  BTSerial.begin(38400);  // HC-05 default baudate in AT command mode
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
