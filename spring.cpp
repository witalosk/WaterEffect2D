//
//  spring.cpp
//  waterEffect2D
//
//  Created by Kousuke on 2017/07/17.
//
//

#include "spring.h"

spring::spring() {
    
    x_ = 0;
    position_ = defaultPosition;
    velocity_ = 0;
    
}

void spring::setX(int x) {
    
    x_ = x;
    
}

void spring::update() {
    
    float x = position_ - defaultPosition;
    float acceleration = -tension * x - dampening * velocity_;
    
    position_ += velocity_;
    velocity_ += acceleration;
    
}
