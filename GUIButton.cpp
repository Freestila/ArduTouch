/*
 * GUIButton.cpp
 *
 *  Created on: 14.03.2013
 *      Author: hstasch
 */

#include "GUIButton.h"

GUIButton::GUIButton ( int x1, int x2, int y1, int y2, const char* cap, void (*act) ( int x, int y, int page ), bool useBigFont ) {
	xMin = x1;
	xMax = x2;
	yMin = y1;
	yMax = y2;
	caption = cap;
	action = act;
	bigFont = useBigFont;

}

GUIButton::~GUIButton () {
	// TODO Auto-generated destructor stub
}

void GUIButton::waitForIt ()   // Draw a red frame while a button is touched
{
	myGLCD.setColor ( 255, 0, 0 );
	myGLCD.drawRoundRect ( xMin, yMin, xMax, yMax );
	while ( myTouch.dataAvailable () ) {
		myTouch.read ();
	}
	myGLCD.setColor ( 255, 255, 255 );
	myGLCD.drawRoundRect ( xMin, yMin, xMax, yMax );
}

void GUIButton::processTouch ( int x, int y, int pagenr ) {
	waitForIt ();
	if ( action ) {
		action ( x, y, pagenr );
	}
}

void GUIButton::printButton () {
	int stl = strlen ( caption );
	int fx, fy;

	myGLCD.setColor ( 0, 0, 255 );
	myGLCD.fillRoundRect ( xMin, yMin, xMax, yMax );
	myGLCD.setColor ( 255, 255, 255 );
	myGLCD.drawRoundRect ( xMin, yMin, xMax, yMax );

	myGLCD.setBackColor ( 0, 0, 255 );
	if ( bigFont ) {
		myGLCD.setFont ( BigFont );
		fx = xMin + ( ( ( xMax - xMin + 1 ) - ( stl * 16 ) ) / 2 );
		fy = yMin + ( ( ( yMax - yMin + 1 ) - 16 ) / 2 );
		myGLCD.print ( (char*) caption, fx, fy );
	}
	else {
		myGLCD.setFont ( SmallFont );
		fx = xMin + ( ( ( xMax - xMin ) - ( stl * 8 ) ) / 2 );
		fy = yMin + ( ( ( yMax - yMin - 1 ) - 8 ) / 2 );
		myGLCD.print ( (char*) caption, fx, fy );
	}
}

/*
 * IntValueChangerButton: Changes the value of an integer variable with up and down buttons
 */

IntValueChangerButton::IntValueChangerButton ( int x1, int x2, int y1, int y2, const char* cap, int * value, int changevalue, int min, int max,
		bool useBigFont ) :
		GUIButton ( x1, x2, y1, y2, cap ) {
	valuePointer = value;
	minValue = min;
	changeValue = changevalue;
	maxValue = max;
	bigFont = useBigFont;
}

void IntValueChangerButton::processTouch ( int x, int y, int pagenr ) {
	GUIButton::waitForIt ();
	Serial.print ( "old value: " );
	Serial.println ( *valuePointer );
	Serial.print ( "max value: " );
	Serial.println ( maxValue );

	if ( changeValue > 0 ) {
		*valuePointer += changeValue;
		Serial.print ( "new value: " );
		Serial.println ( *valuePointer );
		if ( maxValue > -1 && *valuePointer > maxValue ) {
			*valuePointer = maxValue;
		}
	}
	else {
		*valuePointer -= changeValue;
		if ( minValue > -1 && *valuePointer < minValue ) {
			*valuePointer = minValue;
		}
	}
}
