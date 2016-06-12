#include <QtWidgets>
#include "matrixalgorithmdemonstrationwindow.h"

MatrixAlgorithmDemonstrationWindow::MatrixAlgorithmDemonstrationWindow() : tableView(new QTableView)
{
    main->insertWidget(0,tableView);
}
