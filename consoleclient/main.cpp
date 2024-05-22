#include "mainwindow.h"
#include "singletonclient.h"
#include "managementwindow.h"
#include <iostream>
#include <QString>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ManagementWindow w;
    return a.exec();
}
