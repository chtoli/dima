#include <iostream>

#include "mainwindow.h"
#include <QApplication>
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    app.setOrganizationName("Muhtech");
    app.setApplicationName("Wimat 2");
    MainWindow mainWin;
    mainWin.show();

    return app.exec();
}
