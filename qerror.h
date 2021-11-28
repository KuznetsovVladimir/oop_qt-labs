#ifndef QERROR_H
#define QERROR_H

#include <QTextBrowser>

class QError : public QTextBrowser
{
    protected:
        static int id;
public:
    QError();
    void addText(std::string text);
};

#endif // QERROR_H
