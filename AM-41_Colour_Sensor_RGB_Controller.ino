#include <LiquidCrystal.h>
//==================================================
 // LCD CONNECTION
 // RS  -> D13
 // EN  -> D12
 // D4  -> D11
 // D5  -> D10
 // D6  -> D9
 // D7  -> D8
 //==================================================
LiquidCrystal lcd(8,9,10,11,12,13);
//==================================================
 // TCS3200 COLOUR SENSOR CONNECTION
 //==================================================
#define S0 A0
 #define S1 A1
 #define S2 A2
 #define S3 A3
#define SENSOR_OUT A4
//==================================================
 // RGB LED CONNECTION
 // PWM PINS
 //==================================================
#define RED_LED   3
 #define GREEN_LED 5
 #define BLUE_LED  6
//==================================================
 // SENSOR READING VARIABLES
 //==================================================
 unsigned long redFrequency;
 unsigned long greenFrequency;
 unsigned long blueFrequency;
//==================================================
 // COLOUR VALUE VARIABLES
 //==================================================
 int redValue;
 int greenValue;
 int blueValue;
//==================================================
 // DETECTED COLOUR STORAGE
 //==================================================
 String colourName;
 //==================================================
 // SENSOR STABILITY DELAY
 //==================================================
 #define SAMPLE_DELAY 100
//==================================================
 // RGB LED PWM VALUE
 //==================================================
int redPWM;
 int greenPWM;
 int bluePWM;
 
 //==================================================
 // READ RED COLOUR VALUE
 //==================================================
unsigned long readRed()
 {
 unsigned long value;
// Select RED filter
 digitalWrite(S2,LOW);
 digitalWrite(S3,LOW);
delay(10);
// Measure frequency
 value = pulseIn(SENSOR_OUT,LOW);
return value;
 }
//==================================================
 // READ GREEN COLOUR VALUE
 //==================================================
 unsigned long readGreen()
 {
 unsigned long value;
// Select GREEN filter
 digitalWrite(S2,HIGH);
 digitalWrite(S3,HIGH);
delay(10);
value = pulseIn(SENSOR_OUT,LOW);
return value;
 }
//==================================================
 // READ BLUE COLOUR VALUE
 //==================================================
unsigned long readBlue()
 {
 unsigned long value;
// Select BLUE filter
 digitalWrite(S2,LOW);
 digitalWrite(S3,HIGH);
delay(10);
value = pulseIn(SENSOR_OUT,LOW);
return value;
 }
 //==================================================
 // COLOUR DETECTION FUNCTION
 //==================================================
void detectColour()
 {

 if(redFrequency < greenFrequency &&
 redFrequency < blueFrequency)
 {
 colourName = "RED";
 }
else if(greenFrequency < redFrequency &&
 greenFrequency < blueFrequency)
 {
 colourName = "GREEN";
 }
else if(blueFrequency < redFrequency &&
 blueFrequency < greenFrequency)
 {
 colourName = "BLUE";
 }
else
 {
 colourName = "UNKNOWN";
 }
}
//==================================================
 // RGB LED CONTROL FUNCTION
 //==================================================
 void controlRGB()
 {
 // First turn OFF all LEDs
redPWM = 0;
 greenPWM = 0;
 bluePWM = 0;
if(colourName == "RED")
 {
 redPWM = 255;
 }
else if(colourName == "GREEN")
 {
 greenPWM = 255;
 }
else if(colourName == "BLUE")
 {
 bluePWM = 255;
 }
else
 {
 redPWM = 0;
 greenPWM = 0;
 bluePWM = 0;
 }
// Output PWM
analogWrite(RED_LED,redPWM);
analogWrite(GREEN_LED,greenPWM);
analogWrite(BLUE_LED,bluePWM);
}
//==================================================
 // LCD DISPLAY FUNCTION
 //==================================================
void displayColour()
 {
lcd.clear();
 lcd.setCursor(0,0);
lcd.print("Detected:");
lcd.setCursor(0,1);
lcd.print(colourName);
}

void setup()
 {
 //==================================================
 // LCD INITIALIZATION
 //==================================================
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
 lcd.print("AM-41 COLOUR");
lcd.setCursor(0,1);
 lcd.print("RGB CONTROLLER");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Initializing");
lcd.setCursor(0,1);
 lcd.print("Sensor...");
//==================================================
 // TCS3200 PIN CONFIGURATION
 //==================================================
pinMode(S0,OUTPUT);
pinMode(S1,OUTPUT);
pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);
pinMode(SENSOR_OUT,INPUT);
//==================================================
 // TCS3200 FREQUENCY SCALING
 //==================================================
 //
 // S0 HIGH
 // S1 LOW
 //
 // Output frequency = 20%
 // Best for Arduino measurement
 //==================================================
digitalWrite(S0,HIGH);
 digitalWrite(S1,LOW);
//==================================================
 // RGB LED PIN CONFIGURATION
 //==================================================
pinMode(RED_LED,OUTPUT);
pinMode(GREEN_LED,OUTPUT);
pinMode(BLUE_LED,OUTPUT);
// Turn OFF RGB LED initially
analogWrite(RED_LED,0);
analogWrite(GREEN_LED,0);
analogWrite(BLUE_LED,0);
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Place Object");
lcd.setCursor(0,1);
lcd.print("For Detection");
delay(2000);
lcd.clear();
}
 
void loop()
 {
//==================================================
 // READ COLOUR SENSOR VALUES
 //==================================================
redFrequency = readRed();
delay(SAMPLE_DELAY);
greenFrequency = readGreen();
delay(SAMPLE_DELAY);
blueFrequency = readBlue();
delay(SAMPLE_DELAY);
//==================================================
 // DISPLAY RAW SENSOR VALUES
 // (For testing and calibration)
 //==================================================

 //==================================================
 // DETECT COLOUR
 //==================================================
detectColour();
//==================================================
 // CONTROL RGB LED
 //==================================================
controlRGB();
//==================================================
 // DISPLAY RESULT ON LCD
 //==================================================
displayColour();
delay(500);
}
