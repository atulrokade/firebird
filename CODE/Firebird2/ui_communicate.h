/********************************************************************************
** Form generated from reading UI file 'communicate.ui'
**
** Created: Thu May 29 12:09:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATE_H
#define UI_COMMUNICATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_communicate
{
public:

    void setupUi(QWidget *communicate)
    {
        if (communicate->objectName().isEmpty())
            communicate->setObjectName(QString::fromUtf8("communicate"));
        communicate->resize(400, 300);

        retranslateUi(communicate);

        QMetaObject::connectSlotsByName(communicate);
    } // setupUi

    void retranslateUi(QWidget *communicate)
    {
        communicate->setWindowTitle(QApplication::translate("communicate", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class communicate: public Ui_communicate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATE_H
