#include <iostream>
#include <QFile>

#ifndef CAR_H
#define CAR_H


struct Car
{
    int pos;
    std::string model;
    enum colors {
        Black,
        Blue,
        Green,
        Red
    };
    colors color;
    int year;

    QString Convert();

};

#endif // CAR_H
