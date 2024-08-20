#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega)
{
    float motor = (omega*omega)*a2 + (omega)*a1;
    return motor;
}

// Main program
int main()
{
    // Set PWM frequency to 500Hz
    motor1.period(1.0/500.0);
    motor2.period(1.0/500.0);
    motor3.period(1.0/500.0);
    motor4.period(1.0/500.0);

    // Turn on motor with 1.000 rad/s for 0.5s
    motor1 = control_motor(2000.0);
    motor2 = control_motor(2000.0);
    motor3 = control_motor(2000.0);
    motor4 = control_motor(2000.0);

    wait(5.0);
    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;
    while(true)
    {
    }
}

// 10054 rpm medido -> 1052.85 rad/s
// 17819 rpm medido -> 1866 rad/s