#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

// Define all LEDs as digital output objects
DigitalOut led_red(LED_RED_R,false);
DigitalOut led_blue(LED_BLUE_L,false);
DigitalOut led_green(LED_GREEN_R,false);
BMI088 imu(IMU_SDA,IMU_SCL);
VL53L1X range(E_SDA,E_SCL);

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);
// float freq = 0;
int i =0 ;

// Main program
int main()
{
    motor1.period(1.0/400);
    motor2.period(1.0/700);
    motor3.period(1.0/800);
    motor4.period(1.0/1000);
    
    while(i<3)
    {        
    // Blink blue LED indicating inicialization (5 seconds)
    led_blue = !led_blue;
    wait(1);
    led_blue = !led_blue;
    // Turn on red LEDs indicating motors are armed
    motor1 = 0.2;
    wait(1);
    motor2 = 0.2;
    wait(1);
    motor3 = 0.2;
    wait(1);
    motor4 = 0.2;
    led_red = !led_red;
    wait(2);
    // Test all motors with different frequencies (to make different noises)
    // Turn off red LEDs indicating motors are disarmed
    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;
    led_red = !led_red;
    // Blink green LEDs indicating end of program
    led_green = !led_green; 
    wait(0.5);
    led_green = !led_green;    
    i ++;
    }
}
