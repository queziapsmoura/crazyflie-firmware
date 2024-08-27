#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);


float omega_1;
float omega_2;
float omega_3;
float omega_4;

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega)
{
    float motor = (omega*omega)*a2 + (omega)*a1;
    return motor;
}


void mixer(float f_t, float thau_phi, float thau_theta, float thau_psi){
    float o_1 =  f_t/(4.0*kl) - thau_phi/(4.0*kl*l) - thau_theta/(4.0*kl*l) - thau_psi/(4.0*kd);
    float o_2 =  f_t/(4.0*kl) - thau_phi/(4.0*kl*l) + thau_theta/(4.0*kl*l) + thau_psi/(4.0*kd);
    float o_3 =  f_t/(4.0*kl) + thau_phi/(4.0*kl*l) + thau_theta/(4.0*kl*l) - thau_psi/(4.0*kd);
    float o_4 =  f_t/(4.0*kl) + thau_phi/(4.0*kl*l) - thau_theta/(4.0*kl*l) + thau_psi/(4.0*kd);

    if (o_1 > 0)
    {
        omega_1 = sqrt(o_1);
    }
    else
    {
        omega_1 = 0;
    }
    /////
        if (o_2 > 0)
    {
        omega_2 = sqrt(o_2);
    }
    else
    {
        omega_2 = 0;
    }
    //////
        if (o_3 > 0)
    {
        omega_3 = sqrt(o_3);
    }
    else
    {
        omega_3 = 0;
    }
    /////
        if (o_4 > 0)
    {
        omega_4 = sqrt(o_4);
    }
    else
    {
        omega_4 = 0;
    }

}

void actuate(float f_t, float thau_phi, float thau_theta, float thau_psi){
    mixer(f_t,thau_phi, thau_theta, thau_psi);
    motor1 = control_motor(omega_1);
    motor2 = control_motor(omega_2);
    motor3 = control_motor(omega_3);
    motor4 = control_motor(omega_4);
}

// Main program
int main()
{
    // Set PWM frequency to 500Hz
    motor1.period(1.0/500.0);
    motor2.period(1.0/500.0);
    motor3.period(1.0/500.0);
    motor4.period(1.0/500.0);

    actuate(0.15,0,0,0.001);
    wait(5);
    actuate(0,0,0,0);
    while(true)
    {
    }
}

