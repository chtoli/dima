CONFIG += qt
QT += widgets gui core

QMAKE_CXXFLAGS += -std=c++11

unix:INCLUDEPATH += "./include"
unix:OBJECTS_DIR = "./bin"

VPATH += ./include
VPATH += ./src


HEADERS += "./include/rational.h"
HEADERS += "./include/is_unit_inv.h"
HEADERS += "./include/gcd_lcm.h"
HEADERS += "./include/polynomial.h"
HEADERS += "./include/residue.h"
HEADERS += "./include/matrix.h"
HEADERS += "./include/MatrixModel.h"
HEADERS += "./include/mainwindow.h"

SOURCES += "./main.cpp"
SOURCES += "./src/rational.cpp"
SOURCES += "./src/is_unit_inv.cpp"
SOURCES += "./src/gcd_lcm.cpp"
SOURCES += "./src/polynomial.cpp"
SOURCES += "./src/mainwindow.cpp"



TARGET = dima
