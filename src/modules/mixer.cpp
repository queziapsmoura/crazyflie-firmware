#include "mixer.h"

Mixer::Mixer():motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4), led_red(LED_RED_R), led_green(LED_GREEN_L)
{
    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);  
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
    armed =  false;
    led_red = false;
    led_green = true;
}
void Mixer:: actuate(float f_t, float thau_phi, float thau_theta, float thau_psi)
{
    if (armed == true) {
        mixer(f_t,thau_phi, thau_theta, thau_psi);
        motor_1 = control_motor(omega_1);
        motor_2 = control_motor(omega_2);
        motor_3 = control_motor(omega_3);
        motor_4 = control_motor(omega_4);    
    }
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

void Mixer:: arm(){
    armed = true;

    //melodia do MARIO THEME
    int melodia[] = {660,660,660,510,660,770,380,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,500,500,500,580,660,500,430,380,500,500,500,500,580,660,870,760,500,500,500,500,580,660,500,430,380,660,660,660,510,660,770,380};
    //duraçao de cada nota
    int duracaodasnotas[] = {100,100,100,100,100,100,100,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,60,80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,60,80,60,80,80,80,80,80,80,100,100,100,100,100,100,100};
  
    //pausa depois das notas
    int pausadepoisdasnotas[] ={150,300,300,100,300,550,575,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,150,300,350,150,350,150,300,150,600,150,300,350,150,150,550,325,600,150,300,350,150,350,150,300,150,600,150,300,300,100,300,550,575};


    //for para tocar as 156 notas começando no 0 ate 156 ++ incrementado
    // for para tocar as 156 notas começando no 0 ate 6 ++ incrementado - Toque Inicial
    for (int nota = 0; nota < 6; nota++) {
        float duracaodanota = duracaodasnotas[nota]/2000.00;
        float pausa = pausadepoisdasnotas[nota]/2000.00;
        float periodo = melodia[nota];
        motor_1.period(1.0/periodo);
        motor_2.period(1.0/periodo);
        motor_3.period(1.0/periodo);
        motor_4.period(1.0/periodo);
        motor_1 = 0.1;
        motor_2 = 0.1;
        motor_3 = 0.1;
        motor_4 = 0.1;
        wait(duracaodanota);
        motor_1 = 0;
        motor_2 = 0;
        motor_3 = 0;
        motor_4 = 0;
        wait(pausa);
    }

    for (int i=0; i<20; i++)
    {        
        // Blink red LEDs indicating motor arm
        led_red = !led_red;
        wait(0.25);  
    }
    led_red = false;
}

void Mixer:: disarm(){
    actuate(0, 0, 0, 0);
    led_red = true;
    led_green = false;
    armed = false;
}
