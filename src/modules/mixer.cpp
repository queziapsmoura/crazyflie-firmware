#include "mixer.h"

Mixer::Mixer():motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4)
{
    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);  
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
}
void Mixer:: actuate(float f_t, float thau_phi, float thau_theta, float thau_psi)
{
    mixer(f_t,thau_phi, thau_theta, thau_psi);
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);    
}

void Mixer::mixer(float f_t, float thau_phi, float thau_theta, float thau_psi)
{
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

float Mixer::control_motor(float omega)
{
    float motor = (omega*omega)*a2 + (omega)*a1;
    return motor;
}