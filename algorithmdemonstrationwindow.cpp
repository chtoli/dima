#include <QtWidgets>
#include "algorithmdemonstrationwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>


AlgorithmDemonstrationWindow::AlgorithmDemonstrationWindow() : textEdit(new QTextEdit), prev(new QPushButton(tr("<<"))), next(new QPushButton(tr(">>")))
{
    prev->setMaximumWidth(100);
    next->setMaximumWidth(100);

    buttons = new QHBoxLayout();
    buttons->addWidget(prev);
    buttons->addWidget(next);
    buttons->setAlignment(Qt::AlignHCenter);

    main = new QVBoxLayout();
    main->addWidget(textEdit);
    main->addLayout(buttons);
    this->setLayout(main);

    textEdit->setReadOnly(true);

}
