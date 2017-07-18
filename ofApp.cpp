#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(windowW, windowH);
    ofSetWindowPosition(10, 10);

	objWave.initWave();

    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update(){
	objWave.updateWave();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor startColor(0, 0, 0);
    ofColor endColor(100, 100, 100);
    
    ofBackgroundGradient(startColor, endColor, OF_GRADIENT_LINEAR);
    
	objWave.drawWave();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	objWave.dropObject(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
