//
//  Circle.hpp
//
//  Created by William Davie on 29/05/2023.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>

// Circle Asset Class

class CircleGL {
    
public:
    
    // Constructor
    
    CircleGL(float x, float y, float radius,float R,float G,float B){
        
        circleX = x;
        circleY = y;
        circleRadius = radius;
        Red = R;
        Green = G;
        Blue = B;
        
    };
    
    // Methods
    
    void draw(bool trial);
    
    void move(float newX,float newY);
    
    std::vector<float> Xpositions;
    std::vector<float> Ypositions;

private:
    
    float circleX;
    float circleY;
    float circleRadius;
    
    float Red;
    float Green;
    float Blue;
};


#endif /* Circle_hpp */
