#ifndef MATRIXALGORITHMDEMONSTRATIONWINDOW_H
#define MATRIXALGORITHMDEMONSTRATIONWINDOW_H

#include "algorithmdemonstrationwindow.h"

class QTableView;

class MatrixAlgorithmDemonstrationWindow : public AlgorithmDemonstrationWindow
{
    Q_OBJECT
public:
    MatrixAlgorithmDemonstrationWindow();

private:
    QTableView *tableView;
};

#endif // MATRIXALGORITHMDEMONSTRATIONWINDOW_H
