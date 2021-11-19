#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ui_mainwindow.h"
#include <algorithm>
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include <QMessageBox>
#include "Car.h"

#ifndef CSVWRITER_H
#define CSVWRITER_H


class csvwriter
{
private:
    QFile File;
public:
    bool WriteFile(QString FileName, QTableWidget *Data);
};

#endif // CSVWRITER_H
