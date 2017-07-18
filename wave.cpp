//
//  wave.cpp
//  waterEffect2D
//
//  Created by witalosk on 2017/07/18.
//
//

#include "ofMain.h"
#include "wave.h"


void wave::initWave() {
	for (int i = 0; i < springNum; i++) {
		springs[i].setX((float)windowW / (springNum - 1) * i);
		printf("%f, %f\n", springs[i].x_, springs[i].position_);
		leftDeltas[i] = 0;
		rightDeltas[i] = 0;
	}
}

void wave::updateWave() {
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

void wave::drawWave() {
	ofSetColor(0, 0, 240, 0);
	ofBeginShape();
	ofVertex(0, windowH);
	ofVertex(0, springs[0].position_);
	for (int i = 1; i < springNum; i++) {
		ofVertex(springs[i].x_, springs[i].position_);
	}
	ofVertex(windowW, windowH);
	ofEndShape();

	ofSetLineWidth(2);
	for (int j = 0; j < 10; j++) {
		ofSetColor(240, 240, 240, 255 - j * 25);
		for (int i = 0; i < springNum - 1; i++) {
			ofDrawLine(springs[i].x_, springs[i].position_ + 2 * j, springs[i + 1].x_, springs[i + 1].position_ + 2 * j);
		}
	}
}

void wave::dropObject(int x) {
	float width = (float)windowW / (springNum - 1);
	for (int i = 0; i < windowW; i++) {
		if (x < width * i) {
			springs[i].velocity_ += addVelocity;
			break;
		}
	}
}