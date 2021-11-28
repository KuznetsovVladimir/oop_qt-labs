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
#include "csvreader.h"

using namespace std;

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, (end - start)));
            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}

bool CSVReader::openFile(QString FileName)
    {
        if (FileName.endsWith(".csv"))
            this->File.setFileName(FileName);
        else return false;

        if (!File.open(QIODevice::ReadOnly)) return false;
        else return true;

    }


std::vector<Car> CSVReader::GetVector()
    {
        vector<Car> Cars;

        QTextStream in(&File);

        while (!in.atEnd())
        {
            QString line = in.readLine().toUtf8();
            string str = line.toStdString();
            auto slices = split(str, ';');
            Car currCar;
            currCar.model = slices[1];
            currCar.color = static_cast<colors>(std::stoi(slices[2]));
            currCar.year = std::stoi(slices[3]);

            Cars.push_back(currCar);
        }
        File.close();
        return Cars;
    }
