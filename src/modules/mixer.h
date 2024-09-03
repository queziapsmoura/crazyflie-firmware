#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "crazyflie.h"

class Mixer
{
public:
    Mixer();
    void arm();
    void disarm();
    void actuate(float f_t, float thau_phi, float thau_theta, float thau_psi);
private:
    bool armed;
    DigitalOut led_red, led_green;
    PwmOut motor_1, motor_2, motor_3, motor_4;
    float omega_1, omega_2, omega_3, omega_4;
    void mixer(float f_t, float thau_phi, float thau_theta, float thau_psi);
    float control_motor(float omega);
};

#endif 