/********************************************************************************
** Form generated from reading UI file 'pqPythonShell.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQPYTHONSHELL_H
#define UI_PQPYTHONSHELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pqConsoleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PythonShell
{
public:
    QVBoxLayout *verticalLayout;
    pqConsoleWidget *consoleWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *runScriptButton;
    QPushButton *clearButton;
    QPushButton *resetButton;

    void setupUi(QWidget *PythonShell)
    {
        if (PythonShell->objectName().isEmpty())
            PythonShell->setObjectName(QString::fromUtf8("PythonShell"));
        PythonShell->resize(296, 78);
        verticalLayout = new QVBoxLayout(PythonShell);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        consoleWidget = new pqConsoleWidget(PythonShell);
        consoleWidget->setObjectName(QString::fromUtf8("consoleWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(consoleWidget->sizePolicy().hasHeightForWidth());
        consoleWidget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(consoleWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        runScriptButton = new QPushButton(PythonShell);
        runScriptButton->setObjectName(QString::fromUtf8("runScriptButton"));

        horizontalLayout->addWidget(runScriptButton);

        clearButton = new QPushButton(PythonShell);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setEnabled(false);

        horizontalLayout->addWidget(clearButton);

        resetButton = new QPushButton(PythonShell);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setEnabled(false);

        horizontalLayout->addWidget(resetButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(PythonShell);

        QMetaObject::connectSlotsByName(PythonShell);
    } // setupUi

    void retranslateUi(QWidget *PythonShell)
    {
        PythonShell->setWindowTitle(QCoreApplication::translate("PythonShell", "Form", nullptr));
        runScriptButton->setText(QCoreApplication::translate("PythonShell", "Run Script", nullptr));
        clearButton->setText(QCoreApplication::translate("PythonShell", "Clear", nullptr));
        resetButton->setText(QCoreApplication::translate("PythonShell", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PythonShell: public Ui_PythonShell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQPYTHONSHELL_H
