#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
    ofAppGlutWindow window;

	window.setGlutDisplayString( "rgb double depth alpha samples>=8 ");
	ofSetupOpenGL(&window, 1280,768, OF_WINDOW);			// <-------- setup the GL context
	ofSetFrameRate(160);
//	window.setGlutDisplayString("rgba double samples>=4 depth");

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
