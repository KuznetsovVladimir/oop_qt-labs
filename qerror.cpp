#include "qerror.h"

QError::QError()
{

}

int QError::id = 0;

void QError:: addText(std::string text){
    ++id;
    this -> setText(QString::number(id) + ". " + QString::fromStdString(text) + '\n' + this -> toPlainText());
}
