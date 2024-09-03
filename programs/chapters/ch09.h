#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;



// Main program
int main()
{
    // Arm mixer 
    mixer.arm();
    // Set PWM frequency to 500Hz
    mixer.actuate(0.0,0.0,0.0,0.001);
    wait(5);
    // disarm mixer
    mixer.disarm();
    while(true)
    {
    }
}

