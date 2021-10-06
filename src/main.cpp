#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <stdlib.h>
#include <string.h>

static const float CPM_TO_SVT = 0.0045f;
static double sieverts = 0.f;
static volatile unsigned short numClicks = 0;
static volatile bool clicked = false;
static const byte PIN_TUBE_INIT = 2;
static const volatile byte PIN_TUBE_READ = 3;
static const volatile short PIN_BUZZ = 9;
static const byte SENSITIVITY_BUTTON = 6;
static unsigned long startTime, curTime;
static const byte senseArr[4] = { 60, 20, 12, 6 };	// every 1 second, 3 seconds, or 5 seconds
static const uint16_t senseTime[4] = { 1000, 3000, 5000, 10000 };
static byte senseIdx = 0;
static const byte SENSE_IDX_MAX = 3;
static bool buttonPressed = false;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void countClick() 
{ 
	++numClicks;
	clicked = true;
	digitalWrite(PIN_BUZZ, HIGH); 
}

void drawScreen()
{
	char cSievert[32] = {'\0'};	// 00.0000μSv/h
	dtostrf(sieverts, 7, 4, cSievert);
	strncat(cSievert, "uSv/h", sizeof("μSv/h"));
	lcd.clear();
	lcd.setCursor(16 - strlen(cSievert),0);
	lcd.print(cSievert);
	
	char cCpm[16] = {'\0'};
	strcpy(cCpm, "CPM:");
	
	// have to do this because Arduino does not support sprintf()
	char cCpmNum[4] = {'\0'};
	itoa(numClicks, cCpmNum, 10);
	strncat(cCpm, cCpmNum, sizeof(cCpmNum));

	lcd.setCursor(0,1);
	lcd.print(cCpm);

	char cSeconds[16] = {'\0'};
	itoa(senseTime[senseIdx] / 1000, cSeconds, 10);
	strncat(cSeconds, "s", sizeof(char));
	lcd.setCursor(16 - strlen(cSeconds),1);
	lcd.print(cSeconds);
}

void setup() 
{
	lcd.begin();
	lcd.backlight();
	lcd.setCursor(0, 0);
	lcd.print("Powering up...");
	lcd.display();

	delay(1200);

	pinMode(PIN_TUBE_INIT, OUTPUT);
	pinMode(PIN_TUBE_READ, INPUT_PULLUP);
	pinMode(SENSITIVITY_BUTTON, INPUT_PULLUP);
	pinMode(PIN_BUZZ, OUTPUT);
	digitalWrite(PIN_TUBE_INIT, HIGH);	// turn on tube
	digitalWrite(PIN_BUZZ, LOW);
	
	attachInterrupt(digitalPinToInterrupt(PIN_TUBE_READ), countClick, FALLING);
	startTime = millis();
}

void loop() 
{
	
	if (clicked) {
		detachInterrupt(digitalPinToInterrupt(PIN_TUBE_READ));
		
		delayMicroseconds(200);
		clicked = false;
		if (digitalRead(PIN_BUZZ) == HIGH)
			digitalWrite(PIN_BUZZ, LOW);

		attachInterrupt(digitalPinToInterrupt(PIN_TUBE_READ), countClick, FALLING);
	}

	curTime = millis();

	if ((curTime - startTime) >= senseTime[senseIdx])
	{
		detachInterrupt(digitalPinToInterrupt(PIN_TUBE_READ));
		sieverts = ((numClicks * senseArr[senseIdx]) * CPM_TO_SVT);
		
		drawScreen();

		numClicks = 0;
		attachInterrupt(digitalPinToInterrupt(PIN_TUBE_READ), countClick, FALLING);
		startTime = millis();
	}

	if (digitalRead(SENSITIVITY_BUTTON) == LOW && !buttonPressed)
	{
		senseIdx = (senseIdx < SENSE_IDX_MAX ? (senseIdx + 1) : 0);
		buttonPressed = true;
		startTime = millis();
		numClicks = 0;
		sieverts = 0.f;
		drawScreen();
	}
		
	if (digitalRead(SENSITIVITY_BUTTON) == HIGH && buttonPressed)
		buttonPressed = false;
}