/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jun 27 12:51:58 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "myopenglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Load_Robot;
    QAction *actionEnviourmrnt;
    QAction *actionRobot;
    QWidget *centralWidget;
    MyOpenGLWindow *panelGL;
    QRadioButton *lineFollowerButton;
    QRadioButton *greenHouseButton;
    QRadioButton *radioButton;
    QLabel *label;
    QRadioButton *radioButton_2;
    QPushButton *LpushButton;
    QPushButton *FpushButton;
    QDoubleSpinBox *leftSpinBox;
    QDoubleSpinBox *rightSpinBox;
    QPushButton *BpushButton;
    QPushButton *RpushButton;
    QDoubleSpinBox *leftSpinBox_2;
    QPushButton *FpushButton_2;
    QPushButton *LpushButton_2;
    QDoubleSpinBox *rightSpinBox_2;
    QPushButton *RpushButton_2;
    QPushButton *BpushButton_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew_Load;
    QMenu *menuAbout;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1408, 700);
        actionNew_Load_Robot = new QAction(MainWindow);
        actionNew_Load_Robot->setObjectName(QString::fromUtf8("actionNew_Load_Robot"));
        actionEnviourmrnt = new QAction(MainWindow);
        actionEnviourmrnt->setObjectName(QString::fromUtf8("actionEnviourmrnt"));
        actionRobot = new QAction(MainWindow);
        actionRobot->setObjectName(QString::fromUtf8("actionRobot"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        panelGL = new MyOpenGLWindow(centralWidget);
        panelGL->setObjectName(QString::fromUtf8("panelGL"));
        panelGL->setGeometry(QRect(0, 0, 1120, 700));
        lineFollowerButton = new QRadioButton(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(lineFollowerButton);
        lineFollowerButton->setObjectName(QString::fromUtf8("lineFollowerButton"));
        lineFollowerButton->setGeometry(QRect(1150, 360, 122, 20));
        lineFollowerButton->setChecked(true);
        greenHouseButton = new QRadioButton(centralWidget);
        buttonGroup->addButton(greenHouseButton);
        greenHouseButton->setObjectName(QString::fromUtf8("greenHouseButton"));
        greenHouseButton->setEnabled(true);
        greenHouseButton->setGeometry(QRect(1150, 400, 122, 23));
        radioButton = new QRadioButton(centralWidget);
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(1150, 490, 141, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1157, 319, 70, 18));
        radioButton_2 = new QRadioButton(centralWidget);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(1151, 444, 122, 23));
        LpushButton = new QPushButton(centralWidget);
        LpushButton->setObjectName(QString::fromUtf8("LpushButton"));
        LpushButton->setGeometry(QRect(1150, 150, 30, 27));
        FpushButton = new QPushButton(centralWidget);
        FpushButton->setObjectName(QString::fromUtf8("FpushButton"));
        FpushButton->setGeometry(QRect(1180, 120, 30, 27));
        leftSpinBox = new QDoubleSpinBox(centralWidget);
        leftSpinBox->setObjectName(QString::fromUtf8("leftSpinBox"));
        leftSpinBox->setGeometry(QRect(1259, 150, 62, 27));
        leftSpinBox->setMinimum(-300);
        leftSpinBox->setMaximum(300);
        leftSpinBox->setSingleStep(10);
        leftSpinBox->setValue(10);
        rightSpinBox = new QDoubleSpinBox(centralWidget);
        rightSpinBox->setObjectName(QString::fromUtf8("rightSpinBox"));
        rightSpinBox->setGeometry(QRect(1330, 150, 62, 27));
        rightSpinBox->setMinimum(-300);
        rightSpinBox->setMaximum(300);
        rightSpinBox->setSingleStep(10);
        rightSpinBox->setValue(10);
        BpushButton = new QPushButton(centralWidget);
        BpushButton->setObjectName(QString::fromUtf8("BpushButton"));
        BpushButton->setGeometry(QRect(1180, 180, 30, 27));
        RpushButton = new QPushButton(centralWidget);
        RpushButton->setObjectName(QString::fromUtf8("RpushButton"));
        RpushButton->setGeometry(QRect(1210, 150, 30, 27));
        leftSpinBox_2 = new QDoubleSpinBox(centralWidget);
        leftSpinBox_2->setObjectName(QString::fromUtf8("leftSpinBox_2"));
        leftSpinBox_2->setGeometry(QRect(1779, 830, 62, 27));
        leftSpinBox_2->setMinimum(-300);
        leftSpinBox_2->setMaximum(300);
        leftSpinBox_2->setSingleStep(10);
        leftSpinBox_2->setValue(10);
        FpushButton_2 = new QPushButton(centralWidget);
        FpushButton_2->setObjectName(QString::fromUtf8("FpushButton_2"));
        FpushButton_2->setGeometry(QRect(1700, 800, 30, 27));
        LpushButton_2 = new QPushButton(centralWidget);
        LpushButton_2->setObjectName(QString::fromUtf8("LpushButton_2"));
        LpushButton_2->setGeometry(QRect(1670, 830, 30, 27));
        rightSpinBox_2 = new QDoubleSpinBox(centralWidget);
        rightSpinBox_2->setObjectName(QString::fromUtf8("rightSpinBox_2"));
        rightSpinBox_2->setGeometry(QRect(1850, 830, 62, 27));
        rightSpinBox_2->setMinimum(-300);
        rightSpinBox_2->setMaximum(300);
        rightSpinBox_2->setSingleStep(10);
        rightSpinBox_2->setValue(10);
        RpushButton_2 = new QPushButton(centralWidget);
        RpushButton_2->setObjectName(QString::fromUtf8("RpushButton_2"));
        RpushButton_2->setGeometry(QRect(1730, 830, 30, 27));
        BpushButton_2 = new QPushButton(centralWidget);
        BpushButton_2->setObjectName(QString::fromUtf8("BpushButton_2"));
        BpushButton_2->setGeometry(QRect(1700, 860, 30, 27));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1408, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew_Load = new QMenu(menuFile);
        menuNew_Load->setObjectName(QString::fromUtf8("menuNew_Load"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(menuNew_Load->menuAction());
        menuNew_Load->addAction(actionEnviourmrnt);
        menuNew_Load->addAction(actionRobot);

        retranslateUi(MainWindow);
        QObject::connect(lineFollowerButton, SIGNAL(clicked(bool)), panelGL, SLOT(setLineFollowerCaseStudy()));
        QObject::connect(greenHouseButton, SIGNAL(clicked(bool)), panelGL, SLOT(setGreenHouseCaseStudy()));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), panelGL, SLOT(setParts()));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), panelGL, SLOT(setMazeSolverCaseStudy()));
        QObject::connect(menuBar, SIGNAL(triggered(QAction*)), MainWindow, SLOT(menuClicked(QAction*)));
        QObject::connect(MainWindow, SIGNAL(setEnvName(string)), panelGL, SLOT(getEnvName1(string)));
        QObject::connect(MainWindow, SIGNAL(setRobotName(string)), panelGL, SLOT(getRobotName(string)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Firbird", 0, QApplication::UnicodeUTF8));
        actionNew_Load_Robot->setText(QApplication::translate("MainWindow", "New/Load ", 0, QApplication::UnicodeUTF8));
        actionEnviourmrnt->setText(QApplication::translate("MainWindow", "Enviourment", 0, QApplication::UnicodeUTF8));
        actionRobot->setText(QApplication::translate("MainWindow", "Robot", 0, QApplication::UnicodeUTF8));
        lineFollowerButton->setText(QApplication::translate("MainWindow", "Line Follower", 0, QApplication::UnicodeUTF8));
        greenHouseButton->setText(QApplication::translate("MainWindow", "Green House", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "FireBird Model", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Mode :", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Maze Solver", 0, QApplication::UnicodeUTF8));
        LpushButton->setText(QApplication::translate("MainWindow", "L", 0, QApplication::UnicodeUTF8));
        FpushButton->setText(QApplication::translate("MainWindow", "F", 0, QApplication::UnicodeUTF8));
        BpushButton->setText(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        RpushButton->setText(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        FpushButton_2->setText(QApplication::translate("MainWindow", "F", 0, QApplication::UnicodeUTF8));
        LpushButton_2->setText(QApplication::translate("MainWindow", "L", 0, QApplication::UnicodeUTF8));
        RpushButton_2->setText(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        BpushButton_2->setText(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuNew_Load->setTitle(QApplication::translate("MainWindow", "New/Load", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
