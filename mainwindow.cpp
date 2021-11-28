#include "mainwindow.h"
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
#include "csvwriter.h"
#include "Car.h"
#include <typeinfo>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    error = new QError();
    error->setTextColor(QColor("red"));
    ui->verticalLayout->addWidget(error);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenFileButton_clicked()
{
    CSVReader CSV;
    if (!ui->lineEdit->text().endsWith(".csv")){
        error->addText("Файл должен иметь расширение '.csv'");
        return;
    }
    if (CSV.openFile(ui->lineEdit->text()))
    {
        ui->CloseFileButton->setEnabled(true);
        ui->OpenFileButton->setEnabled(false);
        ui->lineFind->setEnabled(true);
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
        ui->radioButton_3->setEnabled(true);
        ui->lineEdit->setEnabled(false);
        ui->label->setEnabled(false);
        ui->label_2->setEnabled(true);
        ui->lineWriteModel->setEnabled(true);
        ui->lineWriteYear->setEnabled(true);
        ui->ComboWriteColor->setEnabled(true);
        ui->WriteButton->setEnabled(true);
        ui->WriteFileButton->setEnabled(true);

        vector<Car> Cars = CSV.GetVector();
        for (int i = 0; i < Cars.size(); i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(Cars[i].pos)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(Cars[i].model)));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(Cars[i].Convert()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(Cars[i].year)));
        }
    } else
    {
        error->addText("Не удалось открыть файл");
        return;
    }
}

void MainWindow::on_lineFind_textChanged(const QString &arg1)
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        ui->tableWidget->showRow(i);

    if (ui->lineFind->text() != "")
    {
        if (ui->radioButton->isChecked())
            for (int i = 0; i < ui->tableWidget->rowCount(); i++)
                if (ui->tableWidget->item(i,0)->text() != ui->lineFind->text())
                    ui->tableWidget->hideRow(i);

        if (ui->radioButton_2->isChecked())
            for (int i = 0; i < ui->tableWidget->rowCount(); i++)
                if (ui->tableWidget->item(i,1)->text().lastIndexOf(ui->lineFind->text()) == -1)
                    ui->tableWidget->hideRow(i);

        if (ui->radioButton_3->isChecked())
            for (int i = 0; i < ui->tableWidget->rowCount(); i++)
                if (ui->tableWidget->item(i,2)->text() != ui->lineFind->text())
                    ui->tableWidget->hideRow(i);
    }
}


void MainWindow::on_CloseFileButton_clicked()
{
    while (ui->tableWidget->rowCount() != 0)
        ui->tableWidget->removeRow(0);

    ui->lineFind->setText("");

    ui->CloseFileButton->setEnabled(false);
    ui->OpenFileButton->setEnabled(true);
    ui->lineFind->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->radioButton_3->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->label->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineWriteModel->setEnabled(false);
    ui->lineWriteYear->setEnabled(false);
    ui->ComboWriteColor->setEnabled(false);
    ui->WriteButton->setEnabled(false);
    ui->WriteFileButton->setEnabled(false);

    Car::deleteId();
}

void MainWindow::on_WriteButton_clicked()
{
    if (ui->lineWriteModel->text() == "")
    {
        error->addText("Не введена модель авто");
        return;
    }

    if (ui->lineWriteYear->text() == "")
    {
        error->addText("Не введен год выпуска авто");
        return;
    }

    if ((ui->lineWriteYear->text()).toInt()<1850)
    {
        error->addText("Не верно введен год выпуска авто");
        return;
    }

    int tableSize = ui->tableWidget->rowCount();
    Car newCar;
    newCar.model = ui->lineWriteModel->text().toStdString();
    newCar.color = static_cast<colors>(strToEnum(ui->ComboWriteColor->currentText()));
    newCar.year = ui->lineWriteYear->text().toInt();

    ui->tableWidget->insertRow(tableSize);
    ui->tableWidget->setItem(tableSize,0,new QTableWidgetItem(QString::number(newCar.pos)));
    ui->tableWidget->setItem(tableSize,1,new QTableWidgetItem(QString::fromStdString(newCar.model)));
    ui->tableWidget->setItem(tableSize,2,new QTableWidgetItem(newCar.Convert()));
    ui->tableWidget->setItem(tableSize,3,new QTableWidgetItem(QString::number(newCar.year)));

    ui->lineWriteModel->setText("");
    ui->lineWriteYear->setText("");
    ui->ComboWriteColor->setCurrentIndex(0);
}

void MainWindow::on_WriteFileButton_clicked(){
    csvwriter CSV;
    CSV.WriteFile(ui->lineEdit->text(), ui->tableWidget);
}

