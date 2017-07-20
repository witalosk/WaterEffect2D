//
//  wave.cpp
//  waterEffect2D
//
//  Created by witalosk on 2017/07/18.
//
//

#include "ofMain.h"
#include "wave.h"


void wave::init() {
    
	for (int i = 0; i < springNum; i++) {
		springs[i].setX((float)ofGetWidth() / (springNum - 1) * i);
		printf("%f, %f\n", springs[i].x_, springs[i].position_);
		leftDeltas[i] = 0;
		rightDeltas[i] = 0;
	}
    
}

void wave::update() {
    
	for (int i = 0; i < springNum; i++) {
		springs[i].update();
		leftDeltas[i] = 0;
		rightDeltas[i] = 0;
	}

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < springNum; i++) {
			if (i > 0) {
				leftDeltas[i] = spread * (springs[i].position_ - springs[i - 1].position_);
				springs[i - 1].velocity_ += leftDeltas[i];
			}
			if (i < springNum - 1) {
				rightDeltas[i] = spread * (springs[i].position_ - springs[i + 1].position_);
				springs[i + 1].velocity_ += rightDeltas[i];
			}
		}

		for (int i = 0; i < springNum; i++) {
			if (i > 0) {
				springs[i - 1].position_ += leftDeltas[i];
			}
			if (i < springNum - 1) {
				springs[i + 1].position_ += rightDeltas[i];
			}
		}
	}
    
}

void wave::draw() {
    
	ofSetColor(0, 0, 240, 0);
	ofBeginShape();
	ofVertex(0, ofGetHeight());
	ofVertex(0, springs[0].position_);
	for (int i = 1; i < springNum; i++) {
		ofVertex(springs[i].x_, springs[i].position_);
	}
	ofVertex(ofGetWidth(), ofGetHeight());
	ofEndShape();

	ofSetLineWidth(2);
	for (int j = 0; j < 10; j++) {
		ofSetColor(240, 240, 240, 255 - j * 25);
		for (int i = 0; i < springNum - 1; i++) {
			ofDrawLine(springs[i].x_, springs[i].position_ + 2 * j, springs[i + 1].x_, springs[i + 1].position_ + 2 * j);
		}
	}
    
}

void wave::dropObject(int startX, int endX, int y) {
    
	float width = (float)ofGetWidth() / (springNum - 1);
    if (startX == endX) {
        for (int i = 0; i < ofGetWidth(); i++) {
            if (startX <= width * i) {
                springs[i].velocity_ += addVelocity + (ofGetHeight() - y)/5;
                break;
            }
        }
    } else {
        for (int i = 0; i < ofGetWidth(); i++) {
            if (startX <= width*i && width*i <= endX ) {
                springs[i].velocity_ += addVelocity + (ofGetHeight() - y)/5;
            }
        }
    }
    
}
