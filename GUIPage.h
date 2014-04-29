/*
 * GUIPage.h
 *
 *  Created on: 14.03.2013
 *      Author: hstasch
 */

#ifndef GUIPAGE_H_
#define GUIPAGE_H_
#include <GUIButton.h>
#include <ITDB02_Graph16.h>
#include <ITDB02_Touch.h>


//template< const int i_Elements > class GUIPage
//  {
//  public:
//	GUIButton  buttonlist [ i_Elements ];
//	int pagenumber;
//	const char* pagename;
//	GUIPage (const char * name, int nr,GUIButton  buttonl[]) {
//		pagename = name;
//		pagenumber = nr;
//	buttonlist = buttonl;
//	};
////	virtual ~GUIPage ();
//  };

extern ITDB02 myGLCD;
extern ITDB02_Touch myTouch;
extern uint8_t SmallFont [];
extern uint8_t BigFont [];
extern uint8_t SevenSegNumFont [];

class GUIPage {
public:
	int pagenumber;
	int buttonCount;
	void (*externalBuild) ();
	void (*noHitFunktion) (int x, int y, int page);
#define LARGE true
#define SMALL false
	const char* pagename;
	// extern vector<*buttonlist>
	GUIButton **buttonlist;
	GUIPage ( const char * name, int nr, GUIButton* buttonl []=NULL, int buttonc=0, void (*func) () = NULL ) :
			pagename ( name ), pagenumber ( nr ), buttonlist ( buttonl ), buttonCount ( buttonc ), externalBuild ( func ) {
	}
	void buildScreen ();
	void processTouch(int x, int y);
private:
	void printHeader ( const char* headline );
	void setFont ( boolean font, byte cr, byte cg, byte cb, byte br, byte bg, byte bb );
//	void printButton ( const char* text, int x1, int y1, int x2, int y2, boolean fontsize = false );
//	void printButton ( GUIButton* button, boolean fontsize = false );

//		virtual ~GUIPage ();
};

#endif /* GUIPAGE_H_ */
