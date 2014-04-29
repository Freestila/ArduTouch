#include <ITDB02_Graph16.h>
#include <ITDB02_Touch.h>
#include <GUIPage.h>
//#include <GUI.h>
#include <GUIButton.h>

void clearScreen () {
	myGLCD.setColor ( 0, 0, 0 );
	myGLCD.fillRect ( 1, 15, 318, 226 );
}

ITDB02 myGLCD ( 38, 39, 40, 41, ITDB32S );   // Remember to add the parameter for your display if you are not using an ITDB02-3.2!
ITDB02_Touch myTouch ( 6, 5, 4, 3, 2 );


GUIPage mainPage ( "AquaDino V1.0", 0, 0 );


void aboutAction ( int x, int y, int page ) {

	clearScreen ();
	myGLCD.print ( "Hello world", 215, 227 );

}

GUIButton aboutButton ( 165, 149, 310, 179, "About", &aboutAction );

void cancelAction ( int x, int y, int page ) {
	clearScreen ();
	myGLCD.print ( "cancel", 215, 227 );
}
GUIButton cancelButton ( 215, 200, 315, 220, "Cancel", &cancelAction );

void timeAndDateAction ( int x, int y, int page ) {

	clearScreen ();
	myGLCD.print ( "time and date", 215, 227 );
}
GUIButton timeAndDate ( 10, 29, 155, 59, "TIME and Date", &timeAndDateAction );

GUIButton* menu1Buttons [] = { &timeAndDate,
		&aboutButton, &cancelButton };

GUIPage demopage2 ( "Choose wise", 1, menu1Buttons, 9 );

void maindispNoHit ( int x, int y, int page ) {
	dispScreen = 1;
	clearScreen ();
//	menuScreen ();
	actPage = &demopage2;
	actPage->buildScreen ();
}

void initGui () {
		mainPage.noHitFunktion = maindispNoHit;
	}

void setup () {
	randomSeed ( analogRead ( 0 ) );

// Setup the LCD
	myGLCD.InitLCD ( LANDSCAPE );
	myGLCD.clrScr ();

	myTouch.InitTouch ( LANDSCAPE );
	myTouch.setPrecision ( PREC_MEDIUM );
	initGui();

}



void loop () {
}
