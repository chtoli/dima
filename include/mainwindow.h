#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QToolBar>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QTableView>
#include "matrix.h"

class MainWindow : public QMainWindow {
	Q_OBJECT //must be added for slot usage
	
public:
	MainWindow();

    //matrix
    template<typename T>
    void displayMatrix(dima::matrix<T> m);
	
protected:
	//notify user about unsaved changes
	//void closeEvent(QCloseEvent *event);
	
private slots:
	/*void newFile();
	void open();
	bool save();
	bool saveAs();
	void about();
	void documentWasModified();*/

private:
    void createActions();
	void createMenus();
	void createToolBars();
	void createStatusBar();
	void readSettings();
	void writeSettings();
	void loadFile(const QString &fileName);
	void saveFile(const QString &fileName);
	
	QPlainTextEdit *textEdit;
    QTableView *tableView;
	
	//toolbar menus
	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *helpMenu;
	QToolBar *fileToolBar;
	QToolBar *editToolBar;
	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *exitAct;
    QAction *cutAct;
    QAction *copyAct;
	QAction *aboutAct;
	QAction *aboutQtAct;
};

#endif //MAINWINDOW_H
