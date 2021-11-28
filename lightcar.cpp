#include "lightcar.h"

lightCar::lightCar()
{

}
std::string lightCar::repr(){
    std::string x = "Модель: " + model +", цвет: ";
    switch (color){
            case Black: x+= " Black,"; break;
            case Blue: x+=  " Blue,"; break;
            case Green: x+= " Green,"; break;
            case Red: x+= " Red,"; break;
        }

    x= x+" год выпуска: " + std::to_string(year) + ", Категория: Легковой автомобиль, мощность: " + std::to_string(horsepower) + ", тип кузова: " + typeOfBody;
    return x;
}
