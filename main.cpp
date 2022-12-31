#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow;
    w->show();
    //connect(a,&QCoreApplication::aboutToQuit())

    return a.exec();
}
