#include "csvwriter.h"
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
#include <Car.h>

bool csvwriter::WriteFile(QString FileName, QTableWidget *Data){
    if (!FileName.endsWith(".csv")) return false;
    this->File.setFileName(FileName);
    File.remove();
    if (!File.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    QTextStream out(&File);


    for (int i = 0; i < Data->rowCount(); i++)

       out << Data->item(i,0)->text() << ";"<< Data->item(i,1)->text() << ";"<< strToEnum(Data->item(i,2)->text()) << ";"<< Data->item(i,3)->text() << '\n';
    File.close();
    return true;
}
