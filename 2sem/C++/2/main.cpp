#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //qDebug() << "dkl";

    Window wnd;
    wnd.show();

//    MainWindow w;

    //qDebug() << "djk";

  //  w.show();
    return a.exec();
}
