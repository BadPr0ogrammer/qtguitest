/********************************************************************************
** Form generated from reading UI file 'ParaViewMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAVIEWMAINWINDOW_H
#define UI_PARAVIEWMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <pqpipelinebrowserwidget.h>
#include "pqOutputWidget.h"
#include "pqPropertiesPanel.h"

QT_BEGIN_NAMESPACE

class Ui_pqClientMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *MultiViewWidget;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;
    QDockWidget *outputWidgetDock;
    pqOutputWidget *outputWidget;
    QDockWidget *pythonShellDock;
    QWidget *pythonShellDummy;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDockWidget *pipelineBrowserDock;
    pqPipelineBrowserWidget *pipelineBrowser;
    QDockWidget *propertiesDock;
    pqPropertiesPanel *propertiesPanel;

    void setupUi(QMainWindow *pqClientMainWindow)
    {
        if (pqClientMainWindow->objectName().isEmpty())
            pqClientMainWindow->setObjectName(QString::fromUtf8("pqClientMainWindow"));
        pqClientMainWindow->resize(1152, 762);
        pqClientMainWindow->setAcceptDrops(true);
        centralwidget = new QWidget(pqClientMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MultiViewWidget = new QWidget(centralwidget);
        MultiViewWidget->setObjectName(QString::fromUtf8("MultiViewWidget"));

        gridLayout->addWidget(MultiViewWidget, 0, 0, 1, 1);

        pqClientMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(pqClientMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1152, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        pqClientMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(pqClientMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        pqClientMainWindow->setStatusBar(statusbar);
        outputWidgetDock = new QDockWidget(pqClientMainWindow);
        outputWidgetDock->setObjectName(QString::fromUtf8("outputWidgetDock"));
        outputWidgetDock->setFloating(false);
        outputWidget = new pqOutputWidget();
        outputWidget->setObjectName(QString::fromUtf8("outputWidget"));
        outputWidgetDock->setWidget(outputWidget);
        pqClientMainWindow->addDockWidget(Qt::BottomDockWidgetArea, outputWidgetDock);
        pythonShellDock = new QDockWidget(pqClientMainWindow);
        pythonShellDock->setObjectName(QString::fromUtf8("pythonShellDock"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pythonShellDock->sizePolicy().hasHeightForWidth());
        pythonShellDock->setSizePolicy(sizePolicy);
        pythonShellDock->setFloating(false);
        pythonShellDummy = new QWidget();
        pythonShellDummy->setObjectName(QString::fromUtf8("pythonShellDummy"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pythonShellDummy->sizePolicy().hasHeightForWidth());
        pythonShellDummy->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(pythonShellDummy);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(pythonShellDummy);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        pythonShellDock->setWidget(pythonShellDummy);
        pqClientMainWindow->addDockWidget(Qt::BottomDockWidgetArea, pythonShellDock);
        pipelineBrowserDock = new QDockWidget(pqClientMainWindow);
        pipelineBrowserDock->setObjectName(QString::fromUtf8("pipelineBrowserDock"));
        pipelineBrowserDock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        pipelineBrowser = new pqPipelineBrowserWidget();
        pipelineBrowser->setObjectName(QString::fromUtf8("pipelineBrowser"));
        pipelineBrowser->setContextMenuPolicy(Qt::DefaultContextMenu);
        pipelineBrowserDock->setWidget(pipelineBrowser);
        pqClientMainWindow->addDockWidget(Qt::LeftDockWidgetArea, pipelineBrowserDock);
        propertiesDock = new QDockWidget(pqClientMainWindow);
        propertiesDock->setObjectName(QString::fromUtf8("propertiesDock"));
        propertiesDock->setMinimumSize(QSize(80, 41));
        propertiesDock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        propertiesPanel = new pqPropertiesPanel();
        propertiesPanel->setObjectName(QString::fromUtf8("propertiesPanel"));
        propertiesDock->setWidget(propertiesPanel);
        pqClientMainWindow->addDockWidget(Qt::LeftDockWidgetArea, propertiesDock);

        menubar->addAction(menu_File->menuAction());

        retranslateUi(pqClientMainWindow);

        QMetaObject::connectSlotsByName(pqClientMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *pqClientMainWindow)
    {
        pqClientMainWindow->setWindowTitle(QCoreApplication::translate("pqClientMainWindow", "MainWindow", nullptr));
        menu_File->setTitle(QCoreApplication::translate("pqClientMainWindow", "&File", nullptr));
        outputWidgetDock->setWindowTitle(QCoreApplication::translate("pqClientMainWindow", "Output Messages", nullptr));
        outputWidget->setProperty("settingsKey", QVariant(QCoreApplication::translate("pqClientMainWindow", "OutputMessages", nullptr)));
        pythonShellDock->setWindowTitle(QCoreApplication::translate("pqClientMainWindow", "Python Shell", nullptr));
        label->setText(QCoreApplication::translate("pqClientMainWindow", "Python support not available!", nullptr));
        pipelineBrowserDock->setWindowTitle(QCoreApplication::translate("pqClientMainWindow", "Pipeline Browser", nullptr));
        propertiesDock->setWindowTitle(QCoreApplication::translate("pqClientMainWindow", "Properties", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pqClientMainWindow: public Ui_pqClientMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAVIEWMAINWINDOW_H
