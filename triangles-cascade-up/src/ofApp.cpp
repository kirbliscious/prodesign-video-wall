#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(2816, 1408);
    ofSetFrameRate(29);
    ofBackground(29, 209, 130);
    
    state1 = true;
    state2 = false;
    state3 = false;
    stateswitch = false;
    
    
    //grid
    square = 176; //176, 16, 44
    xsquares = ofGetWidth() / square;
    ysquares = ofGetHeight()/ square;
    center.set(square/2, square/2);
    
    
    //colors
    c = 2;
    c2 = 3;
    colors[0] = ofColor(0,188,227); //blue
    colors[1] = ofColor(20,35,51); //navy
    colors[2] = ofColor(29,209,130); //green
    colors[3] = ofColor(232,232,232); //grey
    colors[4] = ofColor(244,244,245); //lightgrey
    previouscolor.set(colors[0]);
    
    //Æ
        //static
        stlc.set(0, 0);
        strc.set(square, 0);
        sblc.set(0, square);
        sbrc.set(square, square);
    
        //dynamic
        dynamictopleft.set(stlc);
        dynamicbottomright.set(sbrc);
    
    //batch
    batch = 0;
    batchprev = -1;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    dynamicbottomright.x-=5;
    dynamicbottomright.y-=5;
    
    if (dynamicbottomright.y < center.y) {
        dynamicbottomright.set(square, square);
        batch++;
        batchprev++;
    }
    
    if (batch == 20) {
        batch = 0;
        batchprev = 0;
        if (c2<4) { c=c2; c2++; } else { c=c2; c2=0; }
    }
    
    if (stateswitch) {
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //sequential
    for (int i=0; i<=xsquares; i++) {
        for (int j=0; j<=ysquares; j++) {
            ofPushMatrix();
            ofTranslate(square*i, square*j);
                ofSetColor(colors[c]);
                ofBeginShape();
                    ofVertex(sbrc);
                    ofVertex(sblc);
                    ofVertex(strc);
                ofEndShape();
            ofPopMatrix();
        }
    }
    
    for (int k=0; k<=batchprev; k++) {
        for (int l=(batchprev-k); l>=0; l--) {
            ofPushMatrix();
            testx=(ofGetWidth()-square)-square*k;
            testy=(ofGetHeight()-square)-square*l;
            ofTranslate(testx, testy);
            ofSetColor(colors[c2]);
            ofBeginShape();
                ofVertex(strc);
                ofVertex(sbrc);
                ofVertex(sblc);
            ofEndShape();
            ofPopMatrix();
        }
    }

    
    for (int k=0; k<=batch; k++) {
        ofPushMatrix();
        ofTranslate(((ofGetWidth()-square)-square*k), ((ofGetHeight()-square)-square*(batch-k)));
            //reveal
            ofSetColor(colors[c2]);
            ofBeginShape();
                ofVertex(strc);
                ofVertex(sbrc);
                ofVertex(sblc);
            ofEndShape();
        
            //dynamic
            ofSetColor(colors[c]);
            ofBeginShape();
                ofVertex(strc);
                ofVertex(dynamicbottomright);
                ofVertex(sblc);
            ofEndShape();
        ofPopMatrix();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}