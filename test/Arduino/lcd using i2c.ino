/*
* https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/
*
* In order to run the subsequent sketches you’ll need to install a library called LiquidCrystal_I2C. 
* This library is an improved version of the LiquidCrystal library that comes packaged with your Arduino IDE.
* To install the library navigate to the Sketch > Include Library > Manage Libraries… Wait for Library Manager 
* to download libraries index and update list of installed libraries.
* Filter your search by typing ‘liquidcrystal’. There should be a couple entries. 
* Look for LiquidCrystal I2C library by Frank de Brabander. Click on that entry, and then select Install.
*
* The I2C address of your LCD depends on the manufacturer, as mentioned earlier. If your LCD has a PCF8574 chip from Texas Instruments,
* its default I2C address is 0x27Hex.
*
* Hardware Connection
* GND - GND
* VCC - 5V
* SDA - SDA of arduino
* SCL - SCL of arduino
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Defining the lcd parameters with address

void setup()
{
    lcd.init(); // initialize the lcd
    lcd.backlight();
    Serial.begin(9600);
}

void loop()
{
    // Print a message on both lines of the LCD.
    lcd.setCursor(2, 0); //Set cursor to character 2 on line 0
    lcd.print("Hello world!");

    lcd.setCursor(2, 1); //Move cursor to character 2 on line 1
    lcd.print("QWERTY");
}
