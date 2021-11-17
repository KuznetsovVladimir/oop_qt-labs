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
#include "CSVReader.h"

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

void WorkerCSVReader::openFile(QString FileName)
    {
        if (FileName.endsWith(".csv"))
            this->File.setFileName(FileName);
        else
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Ошибка");
            msgBox.setText("Файл должен иметь расширение '.csv'");
            msgBox.exec();
        }
    }

bool WorkerCSVReader::isOpen()
    {
        if (!File.open(QIODevice::ReadOnly)) return false;
        else return true;
    }

std::vector<Car> WorkerCSVReader::GetVector()
    {
        vector<Car> w;

        QTextStream in(&File);

        while (!in.atEnd())
        {
            QString line = in.readLine().toUtf8();
            string str = line.toStdString();


            auto v = split(str, ';');
            Car c;
            c.pos = stoi(v[0]);
            c.model = v[1];
            c.color = static_cast<Car::colors>(stoi(v[2]));
            c.year =   stoi(v[3]);
            w.push_back(c);
        }
        File.close();
        return w;
    }
