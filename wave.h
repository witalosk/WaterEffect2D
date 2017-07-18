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
	constexpr static const float addVelocity = 200.0f;
	float leftDeltas[springNum];
	float rightDeltas[springNum];
	constexpr static const int windowW = 1200;
	constexpr static const int windowH = 800;

public:
	void initWave();
	void updateWave();
	void drawWave();
	void dropObject(int x, int y);

};

#endif /* wave_h */

