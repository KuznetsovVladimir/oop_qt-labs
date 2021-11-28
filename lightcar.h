#ifndef LIGHTCAR_H
#define LIGHTCAR_H
#include "Car.h"

class lightCar : public Car
{
public:
    lightCar();
    int horsepower;
    std::string typeOfBody;
    std::string repr();
};

#endif // LIGHTCAR_H
