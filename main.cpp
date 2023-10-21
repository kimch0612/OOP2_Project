#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Yahtzee Dice");
    w.setFixedSize(850, 460);
    w.show();
    return a.exec();
}
