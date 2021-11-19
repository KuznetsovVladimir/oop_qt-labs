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
colors strToEnum(QString str){
    std::map <QString, colors> mapping{
        {"Black", Black},
        {"Blue", Blue},
        {"Green", Green},
        {"Red", Red}
    };
    return mapping[str];
}
