#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int square, xsquares, ysquares;
        ofPoint dynamictopleft, dynamicbottomright;
        ofPoint stlc, strc, sblc, sbrc;
    
        ofPoint center;
    
        ofColor colors[5];
        ofColor previouscolor, tritwo_previouscolor;
        int c, c2, batch, batchprev;
    
        bool state1, state2, state3, stateswitch;
};
