#include "mainwindow.h"

#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QFile file(":/styles/style.css");
    file.open(QIODevice::ReadOnly);
    a.setStyleSheet(file.readAll());
    file.close();
    return a.exec();
}
