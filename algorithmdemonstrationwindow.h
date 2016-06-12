#ifndef ALGORITHMDEMONSTRATIONWINDOW_H
#define ALGORITHMDEMONSTRATIONWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

class QPushButton;
class QTextEdit;
class QVBoxLayout;
class QHBoxLayout;

class AlgorithmDemonstrationWindow : public QWidget
{
    Q_OBJECT
public:
    AlgorithmDemonstrationWindow();

protected:
    QPushButton *prev;
    QPushButton *next;
    QTextEdit *textEdit;
    QHBoxLayout *buttons;
    QVBoxLayout *main;
};

#endif // ALGORITHMDEMONSTRATIONWINDOW_H
