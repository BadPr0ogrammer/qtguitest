/********************************************************************************
** Form generated from reading UI file 'pqSearchBox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQSEARCHBOX_H
#define UI_PQSEARCHBOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchBox
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *SearchLineEdit;
    QToolButton *AdvancedButton;

    void setupUi(QWidget *SearchBox)
    {
        if (SearchBox->objectName().isEmpty())
            SearchBox->setObjectName(QString::fromUtf8("SearchBox"));
        SearchBox->resize(251, 27);
        horizontalLayout = new QHBoxLayout(SearchBox);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        SearchLineEdit = new QLineEdit(SearchBox);
        SearchLineEdit->setObjectName(QString::fromUtf8("SearchLineEdit"));

        horizontalLayout->addWidget(SearchLineEdit);

        AdvancedButton = new QToolButton(SearchBox);
        AdvancedButton->setObjectName(QString::fromUtf8("AdvancedButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pqWidgets/Icons/pqAdvanced.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AdvancedButton->setIcon(icon);
        AdvancedButton->setCheckable(true);
        AdvancedButton->setChecked(false);

        horizontalLayout->addWidget(AdvancedButton);

        horizontalLayout->setStretch(0, 1);

        retranslateUi(SearchBox);

        QMetaObject::connectSlotsByName(SearchBox);
    } // setupUi

    void retranslateUi(QWidget *SearchBox)
    {
        SearchBox->setWindowTitle(QCoreApplication::translate("SearchBox", "Form", nullptr));
#if QT_CONFIG(tooltip)
        SearchLineEdit->setToolTip(QCoreApplication::translate("SearchBox", "<html><head/><body><p>Search for properties by name</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        SearchLineEdit->setPlaceholderText(QCoreApplication::translate("SearchBox", "Search ... (use Esc to clear text)", nullptr));
#if QT_CONFIG(tooltip)
        AdvancedButton->setToolTip(QCoreApplication::translate("SearchBox", "<html><head/><body><p>Toggle advanced properties</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        AdvancedButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SearchBox: public Ui_SearchBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQSEARCHBOX_H
