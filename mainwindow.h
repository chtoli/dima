#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTextEdit;
class QTableView;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
private:

    void createMenu();
    void createActions();
    void createDockWindows();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *demoMenu;
    QMenu *helpMenu;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;

    QAction *cutAction;
    QAction *copyAction;
    QAction *insertAction;
    QAction *selectAllAction;

    QAction *gaussAction;
    QAction *gaussJordanAction;
    QAction *solveAction;
    QAction *invertAction;
    QAction *laplaceAction;
    QAction *chpolAction;
    QAction *eigenAction;

    QAction *contentAction;
    QAction *contextAction;
    QAction *aboutQtAction;
    QAction *aboutDimaAction;

    QTextEdit *textEdit;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QPushButton *submitButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
};

#endif // MAINWINDOW_H
