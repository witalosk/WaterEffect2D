#pragma once

#include "ofMain.h"
#include "spring.h"

#define springNum 201

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int windowW = 1200;
        int windowH = 800;
    
        spring springs[springNum];
    
        float spread = 0.05f;

        float addVelocity = 200.0f;
    
        float leftDeltas[springNum];
        float rightDeltas[springNum];
    
};

