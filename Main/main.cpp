//
//  main.cpp
//  HelloOpenGL
//
//  Created by William Davie on 28/05/2023.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>
#include "Circle.hpp"
#include "RK4_3body.hpp"
#include <Eigen/Dense>

using namespace Eigen;

typedef Array<Vector2d,Dynamic,1> vecArray;
typedef Array<vecArray, Dynamic, 1> vecArray2;

int main(void)
{
    
    GLFWwindow* window;
        
        Vector2d r1(0.746156, 0);
        Vector2d r2(-0.373078, 0.238313);
        Vector2d r3(-0.373078, - 0.238313);
        Vector2d v1(0,0.324677);
        Vector2d v2(0.764226,-0.162339);
        Vector2d v3(-0.764226,-0.162339);
           
        CircleGL circle1(r1(0),r1(1),0.025,0.65,0.01,0.36);
        CircleGL circle2(r2(0),r2(1),0.025,0.95,0.45,0.012);
        CircleGL circle3(r3(0),r3(1),0.025,0.95,0.020,0.19);
    
    // Running RK4
    
    RK4_3body main(1,1,1);
    vecArray2 finalVals = main.Run(0.0012, 10000, r1, r2, r3, v1, v2, v3);
    
    
    // Initializing GLFW
    
    if (!glfwInit())
        return -1;
    
    // Create window
    
    window = glfwCreateWindow(800, 800, "Hello World", NULL, NULL);
    if (!window)
        
    {
        glfwTerminate();
        return -1;
    }

    // Make context current
    
    glfwMakeContextCurrent(window);
    
    float i = 0;

    // Loop until window closed
    
    while (!glfwWindowShouldClose(window))
    {
        // Render
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        circle1.draw(true);
        circle2.draw(true);
        circle3.draw(true);
        
        // Updating position according to RK4 results
        
        if (i < 10000){
            
            circle1.move(finalVals[0][i][0],finalVals[0][i][1]);
            circle2.move(finalVals[1][i][0],finalVals[1][i][1]);
            circle3.move(finalVals[2][i][0],finalVals[2][i][1]);
            
        }
        
        i += 1;
        
        // Swap front and back buffers
        
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
        
    }

    glfwTerminate();
    return 0;
}
