#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR1);

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega)
{
    float motor1 = (omega*omega)*a2 + (omega)*a1;
    return motor1;
}

// Main program
int main()
{
    // Set PWM frequency to 500Hz
    motor1.period(1.0/500.0);
    // Turn on motor with 1.000 rad/s for 0.5s
    motor1 = control_motor(2000.0);
    wait(2.0);
    motor1 = 0.0;
    while(true)
    {
    }
}

// 10054 rpm medido -> 1052.85 rad/s
// 17819 rpm medido -> 1866 rad/s