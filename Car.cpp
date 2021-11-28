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

int Car::currentId = 0;

Car::Car() {
 pos = ++currentId;
 model = "Unknown";
 color = Black;
 year = 0;
}

Car::Car(const Car& orig) {
 pos = orig.pos;
 model = orig.model;
 color = orig.color;
 year = orig.year;
}

Car& Car::operator=(const Car& orig) {
 pos = orig.pos;
 model = orig.model;
 color = orig.color;
 year = orig.year;
 return(*this);
}

Car::Car(Car&& orig):
    pos(std::move(orig.pos)),
    model(std::move(orig.model)),
    color(std::move(orig.color)),
    year(std::move(orig.year))
{}

Car& Car::operator=(Car &&orig){
    if (&orig==this) return *this;

    pos = orig.pos;
    model = orig.model;
    color = orig.color;
    year = orig.year;

    orig.pos = 0;
    orig.model = nullptr;
    orig.color = Black;
    orig.year = 0;

    return *this;
}

void Car::deleteId(){
    currentId = 0;
}

