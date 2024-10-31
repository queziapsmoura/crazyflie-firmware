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

// PWM
const float a1 = 2.4234e-10;    // Cte que multiplica w  (p2)
const float a2 = 1.4902e-07;    // Cte que multiplica w² (p1)

// Constantes aerodinamicas
const float kl =1.8798e-08;    // N.s²  Cte de sustentação (Cte que multiplica w²) (p1)
const float kd =1.5292e-10;    // N.m.s² Cte de arrasto

//
const float dt = 2e-3 ;        // Frequência de amostragem

// Estimador de atitude
const float wc = 1.0;
const float alpha = (wc*dt)/(1.0+wc*dt);

// Controlador de atitude
const float Ts_phi = 0.3;
const float OS_phi = 0.005;
const float zeta_phi = abs(log(OS_phi))/(sqrt(pi*pi+log(OS_phi)*log(OS_phi)));
const float wn_phi = 4.0/(Ts_phi*zeta_phi);
const float kp_phi = wn_phi*wn_phi;
const float kd_phi = 2.0*zeta_phi*wn_phi;

const float Ts_psi = 0.6;
const float OS_psi = 0.005;
const float zeta_psi = abs(log(OS_psi))/(sqrt(pi*pi+log(OS_psi)*log(OS_psi)));
const float wn_psi = 4.0/(Ts_psi*zeta_psi);
const float kp_psi = wn_psi*wn_psi;
const float kd_psi = 2.0*zeta_phi*wn_psi;

// Estimador  Vertical
const float wc_v = 10.0;
const float zeta_v = sqrt(2.0)/2.0;

const float dt_v = 50.0e-3;

const float l1_v = wc_v*wc_v;
const float l2_v = 2.0*zeta_v*wc_v;

// Controle Vertical
const float Ts_ver = 2.0;
const float OS_ver = 0.005;
const float zeta_ver = abs(log(OS_ver))/(sqrt(pi*pi+log(OS_ver)*log(OS_ver)));
const float wn_ver = 4.0/(Ts_ver*zeta_ver);
const float kp_ver = wn_ver*wn_ver;
const float kd_ver = 2.0*zeta_ver*wn_ver;

// Estimador Horizontal
const float W = 420; // Pixels
const float gama =  42; // Ângulo de visão
const float sigma = 2*tan(gama/2)/W*dt;


const float wc_h = 50; // rad/s - Frequência de corte Estimador Horizontal
const float l_h = wc_h; // Ganho horizontal
const float dt_h = 50.0e-3;

#endif