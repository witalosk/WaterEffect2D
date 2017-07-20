//
//  wave.h
//  waterEffect2D
//
//  Created by witalosk on 2017/07/18.
//
//

#include "spring.h"
#define springNum 201

#ifndef wave_h
#define wave_h

class wave {


private:
	spring springs[springNum];
	constexpr static const float spread = 0.05f;
	constexpr static const float addVelocity = 50.0f;
	float leftDeltas[springNum];
	float rightDeltas[springNum];

public:
	void init();
	void update();
	void draw();
	void dropObject(int startX, int endX, int y);

};

#endif /* wave_h */

