/*
 * GUIPage.cpp
 *
 *  Created on: 14.03.2013
 *      Author: hstasch
 */

#include "GUIPage.h"

//GUIPage::GUIPage()

//GUIPage::GUIPage ( const char * name, int nr) {
//	pagename = name;
//	pagenumber = nr;
////	this->buttonlist = buttonlist;
//}

//GUIPage::~GUIPage(){
//
//}

void GUIPage::buildScreen () {
//	clearScreen ();
	printHeader ( pagename );

	myGLCD.setColor ( 64, 64, 64 );
	myGLCD.drawRect ( 0, 196, 319, 194 );
	for ( int i = 0; i < buttonCount; i++ ) {
		buttonlist [i]->printButton (  );
	}

}

void GUIPage::processTouch ( int x, int y ) {

	for ( int i = 0; i < buttonCount; i++ ) {
		if ( ( x >= buttonlist [i]->xMin ) && ( x <= buttonlist [i]->xMax ) && ( y >= buttonlist [i]->yMin ) && ( y <= buttonlist [i]->yMax ) ) {
			buttonlist[i]->processTouch(x,y, pagenumber);
			return;
		}
	}
	if ( noHitFunktion ) {
		noHitFunktion ( x, y, pagenumber );
	}
}

void GUIPage::printHeader ( const char* headline ) {
	setFont ( SMALL, 255, 255, 0, 255, 255, 0 );
	myGLCD.fillRect ( 1, 1, 318, 14 );
	myGLCD.setColor ( 0, 0, 0 );
	myGLCD.print ( (char*) headline, CENTER, 1 );
}
void GUIPage::setFont ( boolean font, byte cr, byte cg, byte cb, byte br, byte bg, byte bb ) {
	myGLCD.setBackColor ( br, bg, bb );               //font background black
	myGLCD.setColor ( cr, cg, cb );                   //font color white
	if ( font == LARGE )
		myGLCD.setFont ( BigFont );                 //font size LARGE
	else if ( font == SMALL ) myGLCD.setFont ( SmallFont );
}


//
//void GUIPage::printButton ( GUIButton* button, boolean fontsize ) {
//	int stl = strlen ( button->caption );
//	int fx, fy;
//
//	myGLCD.setColor ( 0, 0, 255 );
//	myGLCD.fillRoundRect ( button->xMin, button->yMin, button->xMax, button->yMax );
//	myGLCD.setColor ( 255, 255, 255 );
//	myGLCD.drawRoundRect ( button->xMin, button->yMin, button->xMax, button->yMax );
//
//	myGLCD.setBackColor ( 0, 0, 255 );
//	if ( fontsize ) {
//		myGLCD.setFont ( BigFont );
//		fx = button->xMin + ( ( ( button->xMax - button->xMin + 1 ) - ( stl * 16 ) ) / 2 );
//		fy = button->yMin + ( ( ( button->yMax - button->yMin + 1 ) - 16 ) / 2 );
//		myGLCD.print ( (char*) button->caption, fx, fy );
//	}
//	else {
//		myGLCD.setFont ( SmallFont );
//		fx = button->xMin + ( ( ( button->xMax - button->xMin ) - ( stl * 8 ) ) / 2 );
//		fy = button->yMin + ( ( ( button->yMax - button->yMin - 1 ) - 8 ) / 2 );
//		myGLCD.print ( (char*) button->caption, fx, fy );
//	}
//}


