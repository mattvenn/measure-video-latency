#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	width = ofGetWidth();
	height = ofGetHeight();
	frames = 0;
		vidGrabber.setVerbose(true);
		vidGrabber.initGrabber(320, 240);
	colorImg.allocate(320, 240);
	grayImage.allocate(320, 240);
	grayBg.allocate(320, 240);
	grayDiff.allocate(320, 240);
	ofSetBackgroundAuto(false);

		bLearnBakground = true;

	threshold = 80;

}

//--------------------------------------------------------------

void testApp::update() {

	if(  ofGetElapsedTimeMillis() > timed  + 1000)
	{
		timed = ofGetElapsedTimeMillis();
		printf( "%d\n", frames );
		frames = 0;
	}
	bool bNewFrame = false;

		vidGrabber.grabFrame();
		bNewFrame = vidGrabber.isFrameNew();

		if (bNewFrame) {
			frames ++;
				colorImg.setFromPixels(vidGrabber.getPixels(), 320, 240);

			grayImage = colorImg;
			if (bLearnBakground == true) {
				grayBg = grayImage;
				bLearnBakground = false;
			}

			// take the abs value of the difference between background and incoming and then threshold:
			grayDiff.absDiff(grayBg, grayImage);
			grayDiff.threshold(threshold);

			// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
			// also, find holes is set to true so we will get interior contours as well....
			contourFinder.findContours(grayDiff, 5, 200, 1, true); // find holes
		}

}

//--------------------------------------------------------------
void testApp::draw() {
	//ofBackground(100,100,100);

			if (contourFinder.nBlobs > 0)
			{
				ofSetColor(0xffffff);
						ofFill();
						ofRect(0, 0, width, height);
			}
			else
			{
				ofSetColor(0x000000);
						ofFill();
						ofRect(0, 0, width, height);
			}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {

	switch (key) {
	case ' ':
		bLearnBakground = true;
		break;
	case '+':
		threshold++;
		if (threshold > 255)
			threshold = 255;
		break;
	case '-':
		threshold--;
		if (threshold < 0)
			threshold = 0;
		break;
	case 'd':
		if (debug) {
			ofBackground(255, 255, 255);

			debug = false;
		} else
			debug = true;
		break;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}

