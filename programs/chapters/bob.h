#include "mbed.h"
#include "rectangle.h"

Rectangle rect();

int main()
{
    rect.set_values(3,4);
    print("The area is %d", rect);
}