#include <QtWidgets>

#include "mainwindow.h"
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow() : textEdit(new QTextEdit), tableView(new QTableView), lineEdit(new QLineEdit),
    submitButton(new QPushButton(tr("submit"))), addButton(new QPushButton(tr("add"))),deleteButton(new QPushButton(tr("delete"))), editButton(new QPushButton(tr("edit"))) {

    //Layout
    QHBoxLayout *cmdLayout = new QHBoxLayout;
    cmdLayout->addWidget(lineEdit);
    cmdLayout->addWidget(submitButton);

    QHBoxLayout *varLayout = new QHBoxLayout;
    varLayout->setAlignment(Qt::AlignRight);
    varLayout->addWidget(addButton);
    varLayout->addWidget(deleteButton);
    varLayout->addWidget(editButton);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(textEdit);
    leftLayout->addLayout(cmdLayout);
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(tableView);
    rightLayout->addLayout(varLayout);

    QWidget *leftWidget = new QWidget();
    leftWidget->setLayout(leftLayout);
    QWidget *rightWidget = new QWidget();
    rightWidget->setLayout(rightLayout);


    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(leftWidget);
    splitter->addWidget(rightWidget);

    setCentralWidget(splitter);



    //Widget Configuration
    textEdit->append("Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. "
                     "Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. "
                     "Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. "
                     "Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. "
                     "Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. "
                     "Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. "
                     "Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. "
                     "Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum. Ipsum sum sum badbum");
    textEdit->setReadOnly(true);

    setWindowTitle(tr("Dima"));

    createActions();
    createMenu();
}

void MainWindow::createMenu() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(insertAction);
    editMenu->addAction(selectAllAction);

    demoMenu = menuBar()->addMenu(tr("Algorithm Demonstration"));
    demoMenu->addAction(gaussAction);
    demoMenu->addAction(gaussJordanAction);
    demoMenu->addAction(solveAction);
    demoMenu->addAction(invertAction);
    demoMenu->addAction(laplaceAction);
    demoMenu->addAction(chpolAction);
    demoMenu->addAction(eigenAction);

    helpMenu = menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(contentAction);
    helpMenu->addAction(contextAction);
    helpMenu->addAction(aboutDimaAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createActions() {

    //File Menu Actions
    newAction = new QAction(tr("&New"), this);
    openAction = new QAction(tr("Open"), this);
    saveAction = new QAction(tr("Save"), this);
    saveAsAction = new QAction(tr("Save as"), this);
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    //Edit Menu Actions
    cutAction = new QAction(tr("Cut"), this);
    copyAction = new QAction(tr("Copy"), this);
    insertAction = new QAction(tr("Insert"), this);
    selectAllAction = new QAction(tr("Select all"), this);

    //Algorithm Demonstration Menu Actions
    gaussAction = new QAction(tr("Gauss"), this);
    gaussJordanAction = new QAction(tr("Gauss Jordan"), this);
    solveAction = new QAction(tr("Solve Linear Equation System"), this);
    invertAction = new QAction(tr("Invert"), this);
    laplaceAction = new QAction(tr("Laplace"), this);
    chpolAction = new QAction(tr("Characteristic Polynomial"), this);
    eigenAction = new QAction(tr("Eigenvector and Eigenvalues"), this);

    //Help Menu Actions
    contentAction = new QAction(tr("Content"), this);
    contextAction = new QAction(tr("Contexthelp"), this);
    aboutQtAction = new QAction(tr("About Qt"), this);
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    aboutDimaAction = new QAction(tr("About Dima"), this);
}

