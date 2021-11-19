#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_OpenFileButton_clicked();

    void on_lineFind_textChanged(const QString &arg1);

    void on_CloseFileButton_clicked();

    void on_WriteButton_clicked();

    void on_WriteFileButton_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
