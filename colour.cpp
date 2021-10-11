#include "colour.h"

Colour3::Colour3()
{
    r = 1.0;
    g = 1.0;
    b = 1.0;
}

Colour3::Colour3(int red, int green, int blue)
{
    r = red / 255.0;
    g = green / 255.0;
    b = blue / 255.0;
}