#include <iostream>
#include <QFile>
#include <map>

#ifndef CAR_H
#define CAR_H

enum colors {
    Black,
    Blue,
    Green,
    Red
};

colors strToEnum(QString str);


class Car
{
protected:
    static int currentId;
public:
    int pos;
    std::string model;
    colors color;
    int year;

    QString Convert();
    Car();
    Car(const Car& orig);
    Car& operator=(const Car& orig);
    Car(Car&& orig);
    Car& operator=(Car &&orig);
    static void deleteId();
};

#endif // CAR_H
