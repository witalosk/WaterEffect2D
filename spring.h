//
//  spring.hpp
//  waterEffect2D
//
//  Created by Kousuke on 2017/07/17.
//
//

#ifndef spring_h
#define spring_h

class spring {
    
public:
    float x_;
    float position_, velocity_;
    
private:
    constexpr static const float defaultPosition = 500;
    constexpr static const float tension = 0.02f;
    constexpr static const float dampening = 0.04f;

public:
    spring();
    void setX(int x);
    void update();
    
};

#endif /* spring_h */
