#ifndef BUS_H
#define BUS_H
#include "Car.h"

class bus : public Car
{
public:
    bus();
    int passengerCapacity;
    std::string typeOfFuel;
    std::string repr();
};

#endif // BUS_H
