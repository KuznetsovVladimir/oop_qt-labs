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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenFileButton_clicked()
{
    CSVReader CSV;
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
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Не удалось открыть файл");
        msgBox.exec();
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
}

void MainWindow::on_WriteButton_clicked()
{
    if (ui->lineWriteModel->text() == "")
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Не введена модель авто");
        msgBox.exec();
        return;
    }

    if (ui->lineWriteYear->text() == "")
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Не введен год выпуска авто");
        msgBox.exec();
        return;
    }

    if ((ui->lineWriteYear->text()).toInt()<1850)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Не верно введен год выпуска авто");
        msgBox.exec();
        return;
    }

//    if (typeid(ui->lineWriteYear->text()).name() != )
//    {
//        QMessageBox msgBox;
//        msgBox.setWindowTitle("Ошибка");
//        msgBox.setText("Не введен год выпуска авто");
//        msgBox.exec();
//        return;
//    }
    int tableSize = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(tableSize);
    ui->tableWidget->setItem(tableSize,0,new QTableWidgetItem(QString::number(tableSize+1)));
    ui->tableWidget->setItem(tableSize,1,new QTableWidgetItem(ui->lineWriteModel->text()));
    ui->tableWidget->setItem(tableSize,2,new QTableWidgetItem(ui->ComboWriteColor->currentText()));
    ui->tableWidget->setItem(tableSize,3,new QTableWidgetItem(QString::number((ui->lineWriteYear->text()).toInt())));

    ui->lineWriteModel->setText("");
    ui->lineWriteYear->setText("");
    ui->ComboWriteColor->setCurrentIndex(0);
}

void MainWindow::on_WriteFileButton_clicked(){
    csvwriter CSV;
    CSV.WriteFile(ui->lineEdit->text(), ui->tableWidget);
}

