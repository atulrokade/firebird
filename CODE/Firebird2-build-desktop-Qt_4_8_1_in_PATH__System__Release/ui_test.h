/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created: Wed May 14 10:13:58 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "testopenglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_test
{
public:
    QAction *actionEnv;
    QWidget *centralwidget;
    testOpenglWindow *widget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuNew_Load;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *test)
    {
        if (test->objectName().isEmpty())
            test->setObjectName(QString::fromUtf8("test"));
        test->resize(800, 600);
        actionEnv = new QAction(test);
        actionEnv->setObjectName(QString::fromUtf8("actionEnv"));
        centralwidget = new QWidget(test);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new testOpenglWindow(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(19, 29, 211, 311));
        test->setCentralWidget(centralwidget);
        menubar = new QMenuBar(test);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew_Load = new QMenu(menuFile);
        menuNew_Load->setObjectName(QString::fromUtf8("menuNew_Load"));
        test->setMenuBar(menubar);
        statusbar = new QStatusBar(test);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        test->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(menuNew_Load->menuAction());
        menuNew_Load->addAction(actionEnv);

        retranslateUi(test);
        QObject::connect(menubar, SIGNAL(triggered(QAction*)), test, SLOT(menuClicked(QAction*)));
        QObject::connect(test, SIGNAL(setEnvName(string)), widget, SLOT(getEnvName(string)));

        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QMainWindow *test)
    {
        test->setWindowTitle(QApplication::translate("test", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionEnv->setText(QApplication::translate("test", "Enviourment", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("test", "File", 0, QApplication::UnicodeUTF8));
        menuNew_Load->setTitle(QApplication::translate("test", "New/Load", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
