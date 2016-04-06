#include "mainwindow.h"
#include "MatrixModel.h"
#include "residue.h"
#include "rational.h"

//TODO: CopyCtor Matrix  other types??
MainWindow::MainWindow() {
    //textEdit = new QPlainTextEdit;
    //setCentralWidget(textEdit);
    tableView = new QTableView;	
    //dima::matrix<int> m = {{1,2,3},{4,5,6},{7,8,9}};
    //dima::matrix<dima::residue<5>> m_res = {{1,2,3},{4,5,6},{7,8,9}};
    dima::matrix<dima::rational> m_rat = {{1,2,3},{4,5,6},{7,8,9}};
    //MatrixModel<int>* model = new MatrixModel<int>(m);
    //MatrixModel<dima::residue<5>>* model_res = new MatrixModel<dima::residue<5>>(m_res);
    MatrixModel<dima::rational>* model_rat = new MatrixModel<dima::rational>(m_rat);

    tableView->setModel(model_rat);
    setCentralWidget(tableView);

    createActions();
    createMenus();
	//createToolBars();
	//createStatusBar();
	
	//readSettings();
	
	//connect(

}


/*template<typename T>
void MainWindow::displayMatrix(dima::matrix<T> m) {
    MatrixModel<int> model(m);
    this->tableView->setModel(&model);
}*/

void MainWindow::createActions() {
    exitAct = new QAction(tr("Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus() {
	fileMenu = menuBar()->addMenu(tr("&File"));
    menuBar()->setNativeMenuBar(false);// Trick to see native MenuBar
    //fileMenu->addAction(newAct);
    //fileMenu->addAction(openAct);
    //fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    //editMenu = menuBar()->addMenu(tr("&Edit"));
    //editMenu->addAction(cutAct);
    //editMenu->addAction(copyAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    //helpMenu->addAction(aboutAct);
    //helpMenu->addAction(aboutQtAct);*/
}
