/********************************************
 * Qt5.8
 * CCTV,video monitor,watchdog
 * By:Why
 * 2017.07.15
 *******************************************/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
