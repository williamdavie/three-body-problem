//
//  RK4_3body.cpp
//  HelloOpenGL
//
//  Created by William Davie on 01/06/2023.
//

#include "RK4_3body.hpp"
#include <cmath>

// Vector Library
#include <Eigen/Dense>

using namespace Eigen;

typedef Array<Vector2d,Dynamic,1> vecArray;
typedef Array<vecArray, Dynamic, 1> vecArray2;

// Three body problem general equation, Newtons law of gravition.

Vector2d RK4_3body::bodyFunc(Vector2d r1,Vector2d r2,Vector2d r3,float mass1,float mass2,float mass3){
    
    Vector2d dr_dt;
    
    float mag_r1_r2 = (r1 - r2).norm();
    float mag_r1_r3 = (r1 - r3).norm();
    
    dr_dt = - G * mass2 * ( r1 - r2 ) / pow(mag_r1_r2,3) - G * mass3 * ( r1 - r3 ) / pow(mag_r1_r3,3);
    
    return dr_dt;
    
};

// Fourth Order Runge-Kutta Method for solving ODEs

vecArray2 RK4_3body::Run(float h, int N, Vector2d r1_0 , Vector2d r2_0 , Vector2d r3_0, const Vector2d v1_0 , Vector2d v2_0 , Vector2d v3_0){
    
    // Parameters to store positions
    
    vecArray rA(N);
    vecArray rB(N);
    vecArray rC(N);
    
    rA(0) = r1_0;
    rB(0) = r2_0;
    rC(0) = r3_0;
    
    vecArray vA(N);
    vecArray vB(N);
    vecArray vC(N);
    
    vA(0) = v1_0;
    vB(0) = v2_0;
    vC(0) = v3_0;

    ArrayXf t(N);
    t(0) = 0;
    
    // Iterative Loop
    
    for (int i = 1; i < N; ++i){
        t(i) = t(i-1) + h;
        
        // ——————————————————————————————————
        // K_1
        // ——————————————————————————————————
        
        Vector2d k_1_A(vA(i-1));
        Vector2d k_1_B(vB(i-1));
        Vector2d k_1_C(vC(i-1));
        Vector2d k_1_A_v(bodyFunc(rA(i-1), rB(i-1), rC(i-1), Mass1, Mass2, Mass3));
        Vector2d k_1_B_v(bodyFunc(rB(i-1), rC(i-1), rA(i-1), Mass2, Mass3, Mass1));
        Vector2d k_1_C_v(bodyFunc(rC(i-1), rA(i-1), rB(i-1), Mass3, Mass1, Mass2));
        
        // ——————————————————————————————————
        // K_2
        // ——————————————————————————————————
        
        Vector2d k_2_A(vA(i-1) + h*k_1_A_v/2);
        Vector2d k_2_B(vB(i-1) + h*k_1_B_v/2);
        Vector2d k_2_C(vC(i-1) + h*k_1_C_v/2);
        
        Vector2d k_2_A_v(bodyFunc(rA(i-1) + h * k_1_A/2, rB(i-1) + h * k_1_B/2, rC(i-1) + h * k_1_C/2, Mass1, Mass2, Mass3));
        Vector2d k_2_B_v(bodyFunc(rB(i-1) + h * k_1_B/2, rC(i-1) + h * k_1_C/2, rA(i-1) + h * k_1_A/2, Mass2, Mass3, Mass1));
        Vector2d k_2_C_v(bodyFunc(rC(i-1) + h * k_1_C/2, rA(i-1) + h * k_1_A/2, rB(i-1) + h * k_1_B/2, Mass3, Mass1, Mass2));
        
        // ——————————————————————————————————
        // K_3
        // ——————————————————————————————————
        
        Vector2d k_3_A(vA(i-1) + h*k_2_A_v/2);
        Vector2d k_3_B(vB(i-1) + h*k_2_B_v/2);
        Vector2d k_3_C(vC(i-1) + h*k_2_C_v/2);
        
        Vector2d k_3_A_v(bodyFunc(rA(i-1) + h * k_2_A/2, rB(i-1) + h * k_2_B/2, rC(i-1) + h * k_2_C/2, Mass1, Mass2, Mass3));
        Vector2d k_3_B_v(bodyFunc(rB(i-1) + h * k_2_B/2, rC(i-1) + h * k_2_C/2, rA(i-1) + h * k_2_A/2, Mass2, Mass3, Mass1));
        Vector2d k_3_C_v(bodyFunc(rC(i-1) + h * k_2_C/2, rA(i-1) + h * k_2_A/2, rB(i-1) + h * k_2_B/2, Mass3, Mass1, Mass2));
        
        
        // ——————————————————————————————————
        // K_4
        // ——————————————————————————————————
        
        Vector2d k_4_A(vA(i - 1) + h * k_3_A_v);
        Vector2d k_4_B(vB(i - 1) + h * k_3_B_v);
        Vector2d k_4_C(vC(i - 1) + h * k_3_C_v);
        
        Vector2d k_4_A_v(bodyFunc(rA(i - 1) + h * k_3_A, rB(i - 1) + h * k_3_B, rC(i - 1) + h * k_3_C, Mass1, Mass2, Mass3));
        Vector2d k_4_B_v(bodyFunc(rB(i - 1) + h * k_3_B, rC(i - 1) + h * k_3_C, rA(i - 1) + h * k_3_A, Mass2, Mass3, Mass1));
        Vector2d k_4_C_v(bodyFunc(rC(i - 1) + h * k_3_C, rA(i - 1) + h * k_3_A, rB(i - 1) + h * k_3_B, Mass3, Mass1, Mass2));
        
        // Updating position
        
        rA(i) = rA(i-1) + (h/6) * ( k_1_A + 2*k_2_A + 2*k_3_A + k_4_A );
        rB(i) = rB(i-1) + (h/6) * ( k_1_B + 2*k_2_B + 2*k_3_B + k_4_B );
        rC(i) = rC(i-1) + (h/6) * ( k_1_C + 2*k_2_C + 2*k_3_C + k_4_C );
        
        vA(i) = vA(i-1) + (h/6) * ( k_1_A_v + 2*k_2_A_v + 2*k_3_A_v + k_4_A_v );
        vB(i) = vB(i-1) + (h/6) * ( k_1_B_v + 2*k_2_B_v + 2*k_3_B_v + k_4_B_v );
        vC(i) = vC(i-1) + (h/6) * ( k_1_C_v + 2*k_2_C_v + 2*k_3_C_v + k_4_C_v );
        
    }
    
    // Returning required arrays. 
        
    vecArray2 finalArray(3,1);
    
    finalArray(0) = rA;
    finalArray(1) = rB;
    finalArray(2) = rC;

    
    return finalArray;
        
};
    
        


