#include "bus.h"

bus::bus()
{

}
std::string bus::repr(){
    std::string x = "Модель: " + model +", цвет: ";
    switch (color){
            case Black: x+= " Black,"; break;
            case Blue: x+=  " Blue,"; break;
            case Green: x+= " Green,"; break;
            case Red: x+= " Red,"; break;
        }

    x= x+" год выпуска: " + std::to_string(year) + ", Категория: Автобус, Вместимость пассажиров: " + std::to_string(passengerCapacity) + ", тип топлива: " + typeOfFuel;
    return x;
}
