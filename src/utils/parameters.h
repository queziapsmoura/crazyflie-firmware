#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

const float a1 = 2.4234e-10;    // Cte que multiplica w  (p2)
const float a2 = 1.4902e-07;    // Cte que multiplica w² (p1)

const float kl =1.8798e-08;    // N.s²  Cte de sustentação (Cte que multiplica w²) (p1)
const float kd =1.5292e-10;    // N.m.s² Cte de arrasto
const float dt = 2e-3 ;        // Frequência de amostragem
const float wc = 1.0;
const float alpha = (wc*dt)/(1.0+wc*dt);

#endif