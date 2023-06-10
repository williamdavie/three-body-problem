//
//  Circle.cpp
//
//  Created by William Davie on 29/05/2023.
//
#include <vector>
#include "Circle.hpp"


// trail parameters

float trail_length = 1000;
float trail_width = 0.1;

// ********************
// Drawing method
// ********************

void CircleGL::draw(bool trail)
{
    float angle;
    int numPoints = 100;
    
    // Trail
    
    if (trail == true){
        
        // trail consists of a concatenation of cirlces
        
        for (int k = 0; k < Xpositions.size(); k += 1){
            
            float scalefactor = 1/log((Xpositions.size() - k));
            
            float colourfactor = k/trail_length;
            
            // initializing a respective circles colour and position
            
            glBegin(GL_TRIANGLE_FAN);
            
            glColor4f((Red + (1-Red)*colourfactor),
                      (Green + (1-Green)*colourfactor),
                      (Blue + (1-Blue)*colourfactor),
                      1-2*scalefactor); // opacity
            
            glVertex2f(Xpositions[Xpositions.size() - k],
                       Ypositions[Ypositions.size() - k]);
            
            // drawing the respective circle
            
            for (int i = 0; i <= numPoints; ++i) {
                angle = 2.0f * M_PI * static_cast<float>(i) / numPoints;
                
                float x = (trail_width*circleRadius - trail_width*circleRadius*scalefactor) * std::cos(angle);
                
                float y = (trail_width*circleRadius - trail_width*circleRadius*scalefactor) * std::sin(angle);
                
                glVertex2f(Xpositions[Xpositions.size() - k] + x, Ypositions[Ypositions.size() - k] + y);
                    
            }
            glEnd();
            
        }
    }
    
    // Main Body
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(Red, Green, Blue);
    glVertex2f(circleX, circleY);
    
    for (int i = 0; i <= numPoints; ++i) {
        
        angle = 2.0f * M_PI * static_cast<float>(i) / numPoints;
        
        float x = circleRadius * std::cos(angle);
        
        float y = circleRadius * std::sin(angle);
        
        glVertex2f(circleX + x, circleY + y);
            
    }
        
    glEnd();
}

// ********************
// Moving method
// ********************


void CircleGL::move(float newX, float newY){
    
    circleX = newX;
    
    circleY = newY;
    
    //  Positions stored for trail
    
    Xpositions.push_back(newX);
    
    Ypositions.push_back(newY);
    
    if (Xpositions.size() > trail_length) {
        
           // Positions removed to retain trail length
        
           Xpositions.erase(Xpositions.begin());
           Ypositions.erase(Ypositions.begin());
       }
    
};



