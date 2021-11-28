#ifndef LORRY_H
#define LORRY_H
#include "Car.h"


class lorry : public Car
{
public:
    lorry();
    int cargoCapacity;
    bool isCoupledTotrailer;
    std::string repr();
};

#endif // LORRY_H
