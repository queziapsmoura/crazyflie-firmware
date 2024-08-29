#include "my_led_class.h"

MyLedClass::MyLedClass() : led(LED1)
{
}

void MyLedClass::blink
{
    led = true;
    wait(0.5);
    led = false;
    wait(0.5);
}