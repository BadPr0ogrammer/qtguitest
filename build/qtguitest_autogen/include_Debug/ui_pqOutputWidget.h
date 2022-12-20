/********************************************************************************
** Form generated from reading UI file 'pqOutputWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQOUTPUTWIDGET_H
#define UI_PQOUTPUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pqConsoleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OutputWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView;
    QWidget *page_2;
    QVBoxLayout *verticalLayout;
    pqConsoleWidget *consoleWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *showFullMessagesCheckBox;
    QCheckBox *alwaysOpenForNewMessagesCheckBox;
    QPushButton *copyButton;
    QPushButton *saveButton;
    QPushButton *filterButton;
    QPushButton *clearButton;

    void setupUi(QWidget *OutputWidget)
    {
        if (OutputWidget->objectName().isEmpty())
            OutputWidget->setObjectName(QString::fromUtf8("OutputWidget"));
        OutputWidget->resize(581, 520);
        verticalLayout_3 = new QVBoxLayout(OutputWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        stackedWidget = new QStackedWidget(OutputWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeView = new QTreeView(page);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setAlternatingRowColors(true);
        treeView->setSelectionMode(QAbstractItemView::NoSelection);
        treeView->setWordWrap(true);
        treeView->setHeaderHidden(true);
        treeView->header()->setMinimumSectionSize(32);
        treeView->header()->setDefaultSectionSize(32);

        verticalLayout_2->addWidget(treeView);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout = new QVBoxLayout(page_2);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        consoleWidget = new pqConsoleWidget(page_2);
        consoleWidget->setObjectName(QString::fromUtf8("consoleWidget"));

        verticalLayout->addWidget(consoleWidget);

        stackedWidget->addWidget(page_2);

        verticalLayout_3->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        showFullMessagesCheckBox = new QCheckBox(OutputWidget);
        showFullMessagesCheckBox->setObjectName(QString::fromUtf8("showFullMessagesCheckBox"));

        horizontalLayout->addWidget(showFullMessagesCheckBox);

        alwaysOpenForNewMessagesCheckBox = new QCheckBox(OutputWidget);
        alwaysOpenForNewMessagesCheckBox->setObjectName(QString::fromUtf8("alwaysOpenForNewMessagesCheckBox"));
        alwaysOpenForNewMessagesCheckBox->setChecked(true);

        horizontalLayout->addWidget(alwaysOpenForNewMessagesCheckBox);

        copyButton = new QPushButton(OutputWidget);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        horizontalLayout->addWidget(copyButton);

        saveButton = new QPushButton(OutputWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout->addWidget(saveButton);

        filterButton = new QPushButton(OutputWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        horizontalLayout->addWidget(filterButton);

        clearButton = new QPushButton(OutputWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout->addWidget(clearButton);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(OutputWidget);
        QObject::connect(clearButton, SIGNAL(clicked()), OutputWidget, SLOT(clear()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OutputWidget);
    } // setupUi

    void retranslateUi(QWidget *OutputWidget)
    {
        OutputWidget->setWindowTitle(QCoreApplication::translate("OutputWidget", "Form", nullptr));
#if QT_CONFIG(tooltip)
        showFullMessagesCheckBox->setToolTip(QCoreApplication::translate("OutputWidget", "<html><head/><body><p>Check to see raw messages generated by the application.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        showFullMessagesCheckBox->setText(QCoreApplication::translate("OutputWidget", "Show full messages", nullptr));
#if QT_CONFIG(tooltip)
        alwaysOpenForNewMessagesCheckBox->setToolTip(QCoreApplication::translate("OutputWidget", "<html><head/><body><p>If unchecked and the window is closed, the window will remain closed when new messages are available.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        alwaysOpenForNewMessagesCheckBox->setText(QCoreApplication::translate("OutputWidget", "Always open for new messages", nullptr));
        copyButton->setText(QCoreApplication::translate("OutputWidget", "Copy to Clipboard", nullptr));
        saveButton->setText(QCoreApplication::translate("OutputWidget", "Save to File...", nullptr));
        filterButton->setText(QCoreApplication::translate("OutputWidget", "Filter Messages", nullptr));
        clearButton->setText(QCoreApplication::translate("OutputWidget", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutputWidget: public Ui_OutputWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQOUTPUTWIDGET_H
