#include <QApplication>
#include <QLabel>

#include "mainwindow.h"
#include "algorithmdemonstrationwindow.h"
#include "matrixalgorithmdemonstrationwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
   /* MainWindow mw;
    mw.show();
    AlgorithmDemonstrationWindow adw;
    adw.show();*/
    MatrixAlgorithmDemonstrationWindow madw;
    madw.show();
    return app.exec();
}
