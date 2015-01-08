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
    
        int square, squaretotalX, squaretotalY;
        ofPoint center;
        ofPoint trione_tlc, trione_trc, trione_blc;
        ofPoint tritwo_trc, tritwo_brc, tritwo_blc, tritwo_strc, tritwo_sbrc, tritwo_sblc;
        ofPoint stlc, strc, sblc, sbrc;
        ofColor colors[5];
        ofColor tritwo_colors[5];
        ofColor previouscolor, tritwo_previouscolor;
        int c, c1;
    
        bool state1, state2, state3, stateswitch;
};
