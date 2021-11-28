#include "lorry.h"

lorry::lorry()
{

}
std::string lorry::repr(){
    std::string x = "Модель: " + model +", цвет: ";
    switch (color){
            case Black: x+= " Black,"; break;
            case Blue: x+=  " Blue,"; break;
            case Green: x+= " Green,"; break;
            case Red: x+= " Red,"; break;
        }

    x= x+" год выпуска: " + std::to_string(year) + ", Категория: Грузовой автомобиль, грузоподьемность: " + std::to_string(cargoCapacity) + ", наличие прицепа: ";
    if (isCoupledTotrailer == false)
    {
         x += "нет";
    }
    if (isCoupledTotrailer == true)
    {
         x += "да";
    }
    return x;
}
