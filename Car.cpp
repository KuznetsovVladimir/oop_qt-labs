#include "Car.h"

QString Car::Convert()
{
    switch (color)
    {
        case 0: return ("Black");
        case 1: return ("Blue");
        case 2: return ("Green");
        case 3: return ("Red");
    }
}
