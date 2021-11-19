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


struct Car
{
    int pos;
    std::string model;
    colors color;
    int year;

    QString Convert();

};

#endif // CAR_H
