/*
  This a simple example of the aREST Library for Arduino (Uno/Mega/Due/Teensy)
  using the Serial port. See the README file for more details.

  Written in 2014 by Marco Schwartz under a GPL license.
*/

// Libraries
#include <SPI.h>
#include <aREST.h>
#include <avr/wdt.h>
#include <LiquidCrystal.h>

/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Create aREST instance
aREST rest = aREST();

// Variables to be exposed to the API
int temperature;
int humidity;

// Declare functions to be exposed to the API
int ledControl(String command);

void setup(void)
{
  // Start Serial
  Serial.begin(19200);

  // Init variables and expose them to REST API
  temperature = 24;
  humidity = 40;
  rest.variable("temperature",&temperature);
  rest.variable("humidity",&humidity);

  // Give name and ID to device (ID should be 6 characters long)
  rest.set_id("2");
  rest.set_name("serial");

  lcd.begin(16, 2);
  rest.function("lcd",lcdControl);

  // Start watchdog
  wdt_enable(WDTO_4S);
}

void loop() {

  // Handle REST calls
  rest.handle(Serial);
  wdt_reset();

}

// Custom function accessible by the API
int lcdControl(String text) {
  String text2ndLine = "";
  lcd.clear();
  if (text.length() > 16)
  {
    text2ndLine = text.substring(16, text.length());
    lcd.print(text.substring(0,16));
    lcd.setCursor(0, 1);
    lcd.print(text2ndLine);
  }
  else
  {
    lcd.print(text.substring(0,text.length()));    
  }
  
  return 1;
}
