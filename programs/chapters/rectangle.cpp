#include "rectangle.h"

Rectangle::Rectangle()
{
    width = 0;
    height = 0;
    area = 0;
}

void Rectangle::set_values(int w, int h)
{
    width = w;
    height = h;
    area = width*height;
}