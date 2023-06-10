//
//  RK4_3body.hpp
//  HelloOpenGL
//
//  Created by William Davie on 01/06/2023.
//

#ifndef RK4_3body_hpp
#define RK4_3body_hpp

#include <stdio.h>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen ;

// Project specific typing

typedef Array<Vector2d,Dynamic,1> vecArray;
typedef Array<vecArray, Dynamic, 1> vecArray2;

class RK4_3body {
    
public:
    
    // Constructor
    
    RK4_3body(float m1,float m2,float m3){
        Mass1 = m1;
        Mass2 = m2;
        Mass3 = m3;
    };
    
    // Methods
    
    Vector2d bodyFunc(Vector2d r1,Vector2d r2,Vector2d r3,float mass1,float mass2,float mass3);
    vecArray2 Run(float step, int N, Vector2d r1_0 , Vector2d r2_0 , Vector2d r3_0, const Vector2d v1_0 , Vector2d v2_0 , Vector2d v3_0);
    
private:
    
    float G = 1;
    float Mass1;
    float Mass2;
    float Mass3;
    
    
};
#endif /* RK4_3body_hpp */
