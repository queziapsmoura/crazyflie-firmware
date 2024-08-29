#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;


// Main program
int main()
{
    // Set PWM frequency to 500Hz
    mixer.actuate(0.15,0,0,0.001);
    wait(5);
    mixer.actuate(0,0,0,0);
    while(true)
    {
    }
}

