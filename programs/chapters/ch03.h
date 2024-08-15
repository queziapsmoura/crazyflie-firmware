#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR1);

// Main program
int main()
{
    motor1.period(1.0/500.0);
    int i =0;
    while(i<3){
    motor1 = 0.1;
    wait(4);
    motor1 = 0.0;
    wait(7);

    motor1 = 0.2;
    wait(4);
    motor1 = 0.0;
    wait(7);

    motor1 = 0.3;
    wait(4);
    motor1 = 0.0;
    wait(7);

    motor1 = 0.4;
    wait(4);
    motor1 = 0.0;
    wait(7);

    motor1 = 0.5;
    wait(4);
    motor1 = 0.0;
    wait(7);   

    motor1 = 0.6;
    wait(4);
    motor1 = 0.0;
    wait(7);  

    motor1 = 0.7;
    wait(4);
    motor1 = 0.0;
    wait(7); 

    motor1 = 0.8;
    wait(4);
    motor1 = 0.0;
    wait(7);

    motor1 = 0.9;
    wait(4);
    motor1 = 0.0;
    wait(7); 

    motor1 = 1;
    wait(4);
    motor1 = 0.0;
    wait(7);   
      
    i++; 
    }  
}
