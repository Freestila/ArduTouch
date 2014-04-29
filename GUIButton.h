/*
 * GUIButton.h
 *
 *  Created on: 14.03.2013
 *      Author: hstasch
 */

#ifndef GUIBUTTON_H_
#define GUIBUTTON_H_
#include <Arduino.h>
#include <ITDB02_Graph16.h>
#include <ITDB02_Touch.h>
extern ITDB02 myGLCD;
extern ITDB02_Touch myTouch;
extern uint8_t SmallFont [];
extern uint8_t BigFont [];



	class GUIButton {
	public:
		 int xMin, xMax, yMin, yMax;
		const char*  caption;
		bool bigFont;
		void (*action)(int x, int y, int page);
		GUIButton (int x1,int x2, int y1, int y2,const char* cap, void (*act)(int x, int y, int page) = NULL, bool useBigFont = false);
		virtual ~GUIButton ();

		virtual void printButton();
		virtual void processTouch(int x, int y, int pagenr);
//		void endTouch();
	protected:
		void waitForIt (  );

	};

	class IntValueChangerButton : public GUIButton{
	public:
		int * valuePointer;
		int changeValue;
		int minValue;
		int maxValue;
		IntValueChangerButton ( int x1,int x2, int y1, int y2,const char* cap, int * value,int changevalue=1, int min=-1, int max=-1, bool useBigFont = false );
		virtual void processTouch(int x, int y, int pagenr);
	protected:
//			void waitForIt (  );
	};

	class ValueFaderButton : public GUIButton {
//	public:
//
//		GUIPage ( const char * name, int nr, GUIButton* buttonl []=NULL, int buttonc=0, void (*func) () = NULL ) :
//					pagename ( name ), pagenumber ( nr ), buttonlist ( buttonl ), buttonCount ( buttonc ), externalBuild ( func ) {
//			}

	};

#endif /* GUIBUTTON_H_ */
