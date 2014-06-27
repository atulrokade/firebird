/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created: Fri Jun 27 13:01:28 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "mainopenglwindow2.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QAction *actionEnviourment;
    QAction *actionRobot;
    QAction *actionEnvironment;
    QAction *actionRobot_2;
    QAction *actionAtul_Rokade_IITB;
    QWidget *centralwidget;
    mainOpenglWindow2 *widget;
    QLabel *label;
    QPushButton *browseEnvButton;
    QLabel *label_2;
    QPushButton *browseRobotButton;
    QLabel *label_3;
    QPushButton *initRobotButton;
    QPushButton *locationResetButton;
    QLabel *label_10;
    QSpinBox *locationXspinBox;
    QSpinBox *locationYspinBox;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label_9;
    QSpinBox *locationZspinBox;
    QPushButton *locationUndoButton;
    QPushButton *locationSaveButton;
    QSpinBox *locationAnglespinBox;
    QLabel *label_12;
    QLineEdit *envNamelineEdit;
    QLineEdit *robotNamelineEdit;
    QPushButton *startButton;
    QLabel *statuslabel;
    QDoubleSpinBox *leftSpinBox;
    QPushButton *FpushButton;
    QPushButton *LpushButton;
    QDoubleSpinBox *rightSpinBox;
    QPushButton *RpushButton;
    QPushButton *BpushButton;
    QPushButton *pushButton_2;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_4;
    QPushButton *resetButton;
    QPushButton *stopButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAuthor;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName(QString::fromUtf8("MainWindow2"));
        MainWindow2->resize(1300, 730);
        actionEnviourment = new QAction(MainWindow2);
        actionEnviourment->setObjectName(QString::fromUtf8("actionEnviourment"));
        actionRobot = new QAction(MainWindow2);
        actionRobot->setObjectName(QString::fromUtf8("actionRobot"));
        actionEnvironment = new QAction(MainWindow2);
        actionEnvironment->setObjectName(QString::fromUtf8("actionEnvironment"));
        actionRobot_2 = new QAction(MainWindow2);
        actionRobot_2->setObjectName(QString::fromUtf8("actionRobot_2"));
        actionAtul_Rokade_IITB = new QAction(MainWindow2);
        actionAtul_Rokade_IITB->setObjectName(QString::fromUtf8("actionAtul_Rokade_IITB"));
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new mainOpenglWindow2(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 1010, 700));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1031, 20, 140, 17));
        browseEnvButton = new QPushButton(centralwidget);
        browseEnvButton->setObjectName(QString::fromUtf8("browseEnvButton"));
        browseEnvButton->setGeometry(QRect(1181, 10, 98, 27));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1031, 111, 140, 17));
        browseRobotButton = new QPushButton(centralwidget);
        browseRobotButton->setObjectName(QString::fromUtf8("browseRobotButton"));
        browseRobotButton->setGeometry(QRect(1181, 101, 98, 27));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1031, 90, 66, 17));
        initRobotButton = new QPushButton(centralwidget);
        initRobotButton->setObjectName(QString::fromUtf8("initRobotButton"));
        initRobotButton->setGeometry(QRect(1101, 190, 180, 27));
        locationResetButton = new QPushButton(centralwidget);
        locationResetButton->setObjectName(QString::fromUtf8("locationResetButton"));
        locationResetButton->setEnabled(false);
        locationResetButton->setGeometry(QRect(1114, 354, 60, 28));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(1031, 230, 21, 18));
        locationXspinBox = new QSpinBox(centralwidget);
        locationXspinBox->setObjectName(QString::fromUtf8("locationXspinBox"));
        locationXspinBox->setEnabled(false);
        locationXspinBox->setGeometry(QRect(1031, 250, 64, 28));
        locationXspinBox->setMinimum(0);
        locationXspinBox->setMaximum(2700);
        locationXspinBox->setSingleStep(1);
        locationXspinBox->setValue(20);
        locationYspinBox = new QSpinBox(centralwidget);
        locationYspinBox->setObjectName(QString::fromUtf8("locationYspinBox"));
        locationYspinBox->setEnabled(false);
        locationYspinBox->setGeometry(QRect(1101, 250, 64, 28));
        locationYspinBox->setMinimum(10);
        locationYspinBox->setMaximum(2700);
        locationYspinBox->setSingleStep(10);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1101, 230, 21, 18));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1031, 200, 71, 18));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1171, 230, 21, 18));
        locationZspinBox = new QSpinBox(centralwidget);
        locationZspinBox->setObjectName(QString::fromUtf8("locationZspinBox"));
        locationZspinBox->setEnabled(false);
        locationZspinBox->setGeometry(QRect(1171, 250, 64, 28));
        locationZspinBox->setMinimum(20);
        locationZspinBox->setMaximum(2700);
        locationZspinBox->setSingleStep(10);
        locationUndoButton = new QPushButton(centralwidget);
        locationUndoButton->setObjectName(QString::fromUtf8("locationUndoButton"));
        locationUndoButton->setEnabled(false);
        locationUndoButton->setGeometry(QRect(1034, 354, 60, 28));
        locationSaveButton = new QPushButton(centralwidget);
        locationSaveButton->setObjectName(QString::fromUtf8("locationSaveButton"));
        locationSaveButton->setEnabled(false);
        locationSaveButton->setGeometry(QRect(1194, 354, 61, 30));
        locationAnglespinBox = new QSpinBox(centralwidget);
        locationAnglespinBox->setObjectName(QString::fromUtf8("locationAnglespinBox"));
        locationAnglespinBox->setEnabled(false);
        locationAnglespinBox->setGeometry(QRect(1031, 310, 64, 28));
        locationAnglespinBox->setMinimum(-360);
        locationAnglespinBox->setMaximum(360);
        locationAnglespinBox->setSingleStep(10);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(1031, 290, 50, 18));
        envNamelineEdit = new QLineEdit(centralwidget);
        envNamelineEdit->setObjectName(QString::fromUtf8("envNamelineEdit"));
        envNamelineEdit->setGeometry(QRect(1030, 50, 250, 27));
        robotNamelineEdit = new QLineEdit(centralwidget);
        robotNamelineEdit->setObjectName(QString::fromUtf8("robotNamelineEdit"));
        robotNamelineEdit->setGeometry(QRect(1030, 144, 250, 27));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(1040, 400, 240, 80));
        statuslabel = new QLabel(centralwidget);
        statuslabel->setObjectName(QString::fromUtf8("statuslabel"));
        statuslabel->setGeometry(QRect(1040, 560, 240, 20));
        statuslabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        statuslabel->setWordWrap(true);
        leftSpinBox = new QDoubleSpinBox(centralwidget);
        leftSpinBox->setObjectName(QString::fromUtf8("leftSpinBox"));
        leftSpinBox->setGeometry(QRect(1429, 620, 62, 27));
        leftSpinBox->setMinimum(-300);
        leftSpinBox->setMaximum(300);
        leftSpinBox->setSingleStep(1);
        leftSpinBox->setValue(10);
        FpushButton = new QPushButton(centralwidget);
        FpushButton->setObjectName(QString::fromUtf8("FpushButton"));
        FpushButton->setGeometry(QRect(1350, 590, 30, 27));
        LpushButton = new QPushButton(centralwidget);
        LpushButton->setObjectName(QString::fromUtf8("LpushButton"));
        LpushButton->setGeometry(QRect(1320, 620, 30, 27));
        rightSpinBox = new QDoubleSpinBox(centralwidget);
        rightSpinBox->setObjectName(QString::fromUtf8("rightSpinBox"));
        rightSpinBox->setGeometry(QRect(1500, 620, 62, 27));
        rightSpinBox->setMinimum(-300);
        rightSpinBox->setMaximum(300);
        rightSpinBox->setSingleStep(1);
        rightSpinBox->setValue(10);
        RpushButton = new QPushButton(centralwidget);
        RpushButton->setObjectName(QString::fromUtf8("RpushButton"));
        RpushButton->setGeometry(QRect(1380, 620, 30, 27));
        BpushButton = new QPushButton(centralwidget);
        BpushButton->setObjectName(QString::fromUtf8("BpushButton"));
        BpushButton->setGeometry(QRect(1350, 650, 30, 27));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1430, 650, 131, 27));
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(1120, 580, 110, 27));
        doubleSpinBox->setMaximum(500);
        doubleSpinBox->setSingleStep(5);
        doubleSpinBox->setValue(10);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1040, 590, 90, 17));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(1040, 533, 240, 27));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(1040, 493, 240, 27));
        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAuthor = new QMenu(menuFile);
        menuAuthor->setObjectName(QString::fromUtf8("menuAuthor"));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow2->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionEnvironment);
        menuFile->addAction(actionRobot_2);
        menuFile->addSeparator();
        menuFile->addAction(menuAuthor->menuAction());
        menuAuthor->addAction(actionAtul_Rokade_IITB);

        retranslateUi(MainWindow2);
        QObject::connect(menubar, SIGNAL(triggered(QAction*)), MainWindow2, SLOT(menuClicked(QAction*)));
        QObject::connect(MainWindow2, SIGNAL(setEnvName(string)), widget, SLOT(getEnvName(string)));
        QObject::connect(browseEnvButton, SIGNAL(clicked()), MainWindow2, SLOT(browseEnvButtonClicked()));
        QObject::connect(browseRobotButton, SIGNAL(clicked()), MainWindow2, SLOT(browseRobotButtonClicked()));
        QObject::connect(initRobotButton, SIGNAL(clicked()), MainWindow2, SLOT(initRobotButtonClicked()));
        QObject::connect(locationUndoButton, SIGNAL(clicked()), MainWindow2, SLOT(undoButtonClicked()));
        QObject::connect(locationResetButton, SIGNAL(clicked()), MainWindow2, SLOT(resetButtonClicked()));
        QObject::connect(locationSaveButton, SIGNAL(clicked()), MainWindow2, SLOT(locationSaveButtonClicked()));
        QObject::connect(locationXspinBox, SIGNAL(valueChanged(int)), MainWindow2, SLOT(locationXspinBoxValueChanged(int)));
        QObject::connect(locationYspinBox, SIGNAL(valueChanged(int)), MainWindow2, SLOT(locationYspinBoxValueChanged(int)));
        QObject::connect(locationZspinBox, SIGNAL(valueChanged(int)), MainWindow2, SLOT(locationZspinBoxValueChanged(int)));
        QObject::connect(locationAnglespinBox, SIGNAL(valueChanged(int)), MainWindow2, SLOT(locationAnglespinBoxValueChanged(int)));
        QObject::connect(MainWindow2, SIGNAL(setEnvName(string)), widget, SLOT(getEnvName(string)));
        QObject::connect(MainWindow2, SIGNAL(setRobotName(string)), widget, SLOT(getRobotName(string)));
        QObject::connect(startButton, SIGNAL(clicked()), widget, SLOT(start()));
        QObject::connect(MainWindow2, SIGNAL(setRobotLocation(robotLocation)), widget, SLOT(updateRobotLocation(robotLocation)));
        QObject::connect(LpushButton, SIGNAL(clicked()), widget, SLOT(left()));
        QObject::connect(FpushButton, SIGNAL(clicked()), widget, SLOT(forward()));
        QObject::connect(RpushButton, SIGNAL(clicked()), widget, SLOT(right()));
        QObject::connect(BpushButton, SIGNAL(clicked()), widget, SLOT(backward()));
        QObject::connect(leftSpinBox, SIGNAL(valueChanged(double)), widget, SLOT(setVelocityLeft(double)));
        QObject::connect(rightSpinBox, SIGNAL(valueChanged(double)), widget, SLOT(setVelocityRight(double)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(stop()));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), widget, SLOT(setVelocity(double)));
        QObject::connect(resetButton, SIGNAL(clicked()), widget, SLOT(reset()));
        QObject::connect(stopButton, SIGNAL(clicked()), widget, SLOT(stop()));

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QApplication::translate("MainWindow2", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionEnviourment->setText(QApplication::translate("MainWindow2", "Enviourment", 0, QApplication::UnicodeUTF8));
        actionRobot->setText(QApplication::translate("MainWindow2", "Robot", 0, QApplication::UnicodeUTF8));
        actionEnvironment->setText(QApplication::translate("MainWindow2", "Enviourment", 0, QApplication::UnicodeUTF8));
        actionRobot_2->setText(QApplication::translate("MainWindow2", "Robot", 0, QApplication::UnicodeUTF8));
        actionAtul_Rokade_IITB->setText(QApplication::translate("MainWindow2", "Atul Rokade (IITB)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow2", "Environment Name :", 0, QApplication::UnicodeUTF8));
        browseEnvButton->setText(QApplication::translate("MainWindow2", "Browse", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow2", "Name :", 0, QApplication::UnicodeUTF8));
        browseRobotButton->setText(QApplication::translate("MainWindow2", "Browse", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow2", "Robot:", 0, QApplication::UnicodeUTF8));
        initRobotButton->setText(QApplication::translate("MainWindow2", "Initialise Robot Position", 0, QApplication::UnicodeUTF8));
        locationResetButton->setText(QApplication::translate("MainWindow2", "Reset", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow2", "X :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow2", "Y :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow2", "Location :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow2", "Z :", 0, QApplication::UnicodeUTF8));
        locationUndoButton->setText(QApplication::translate("MainWindow2", "Undo", 0, QApplication::UnicodeUTF8));
        locationSaveButton->setText(QApplication::translate("MainWindow2", "Save", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow2", "Angle :", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("MainWindow2", "Start", 0, QApplication::UnicodeUTF8));
        statuslabel->setText(QApplication::translate("MainWindow2", ". . .", 0, QApplication::UnicodeUTF8));
        FpushButton->setText(QApplication::translate("MainWindow2", "F", 0, QApplication::UnicodeUTF8));
        LpushButton->setText(QApplication::translate("MainWindow2", "L", 0, QApplication::UnicodeUTF8));
        RpushButton->setText(QApplication::translate("MainWindow2", "R", 0, QApplication::UnicodeUTF8));
        BpushButton->setText(QApplication::translate("MainWindow2", "B", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow2", "Stop", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow2", "Velocity", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("MainWindow2", "Reset", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MainWindow2", "Stop", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow2", "File", 0, QApplication::UnicodeUTF8));
        menuAuthor->setTitle(QApplication::translate("MainWindow2", "Author", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
