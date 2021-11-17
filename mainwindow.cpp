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
#include "CSVReader.h"
#include "Car.h"

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


void MainWindow::on_pushButton_clicked()
{
    WorkerCSVReader CSV;
    CSV.openFile(ui->lineEdit->text());
    if (CSV.isOpen())
    {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton->setEnabled(false);
        ui->lineEdit_2->setEnabled(true);
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
        ui->radioButton_3->setEnabled(true);
        ui->lineEdit->setEnabled(false);
        ui->label->setEnabled(false);
        ui->label_2->setEnabled(true);

        vector<Car> w = CSV.GetVector();
        for (int i = 0; i < w.size(); i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(w[i].pos)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(w[i].model)));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(w[i].Convert()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(w[i].color)));
        }
    } else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Не удалось открыть файл");
        msgBox.exec();
    }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        ui->tableWidget->showRow(i);

    if (ui->lineEdit_2->text() != "")
    {
        if (ui->radioButton->isChecked())
            for (int i = 0; i < ui->tableWidget->rowCount(); i++)
                if (ui->tableWidget->item(i,0)->text() != ui->lineEdit_2->text())
                    ui->tableWidget->hideRow(i);

        if (ui->radioButton_2->isChecked())
            for (int i = 0; i < ui->tableWidget->rowCount(); i++)
                if (ui->tableWidget->item(i,1)->text().lastIndexOf(ui->lineEdit_2->text()) == -1)
                    ui->tableWidget->hideRow(i);

        if (ui->radioButton_3->isChecked())
            for (int i = 0; i < ui->tableWidget->rowCount(); i++)
                if (ui->tableWidget->item(i,2)->text() != ui->lineEdit_2->text())
                    ui->tableWidget->hideRow(i);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    while (ui->tableWidget->rowCount() != 0)
        ui->tableWidget->removeRow(0);

    ui->lineEdit_2->setText("");

    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(true);
    ui->lineEdit_2->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->radioButton_3->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->label->setEnabled(true);
    ui->lineEdit->setEnabled(true);
}
