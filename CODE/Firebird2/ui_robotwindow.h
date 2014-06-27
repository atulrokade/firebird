/********************************************************************************
** Form generated from reading UI file 'robotwindow.ui'
**
** Created: Fri Jun 27 12:54:12 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTWINDOW_H
#define UI_ROBOTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include "robotopenglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_robotWindow
{
public:
    robotOpenGlWindow *widget;
    QLabel *label_5;
    QLabel *label_1;
    QPushButton *newRobotButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QPushButton *saveDimentionButton;
    QPushButton *addMotorButton;
    QSpinBox *countspinBox;
    QSpinBox *distancespinBox;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_2;
    QPushButton *loadRobotButton;
    QLabel *label_3;
    QPushButton *addLineSensorButton;
    QLabel *label;
    QPushButton *addIRPButton;
    QPushButton *addIRDButton;
    QPushButton *addSonarSensorButton;
    QPushButton *exitButton;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QListWidget *listWidget;
    QPushButton *sizeResetButton;
    QPushButton *sizeUndoButton;

    void setupUi(QWidget *robotWindow)
    {
        if (robotWindow->objectName().isEmpty())
            robotWindow->setObjectName(QString::fromUtf8("robotWindow"));
        robotWindow->resize(1300, 720);
        widget = new robotOpenGlWindow(robotWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 850, 700));
        label_5 = new QLabel(robotWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(890, 400, 90, 18));
        label_1 = new QLabel(robotWindow);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(880, 50, 161, 18));
        newRobotButton = new QPushButton(robotWindow);
        newRobotButton->setObjectName(QString::fromUtf8("newRobotButton"));
        newRobotButton->setGeometry(QRect(880, 10, 220, 28));
        deleteButton = new QPushButton(robotWindow);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(true);
        deleteButton->setGeometry(QRect(997, 300, 106, 28));
        deleteButton->setFocusPolicy(Qt::StrongFocus);
        editButton = new QPushButton(robotWindow);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(880, 300, 106, 28));
        saveDimentionButton = new QPushButton(robotWindow);
        saveDimentionButton->setObjectName(QString::fromUtf8("saveDimentionButton"));
        saveDimentionButton->setEnabled(false);
        saveDimentionButton->setGeometry(QRect(1150, 400, 140, 110));
        addMotorButton = new QPushButton(robotWindow);
        addMotorButton->setObjectName(QString::fromUtf8("addMotorButton"));
        addMotorButton->setGeometry(QRect(1110, 140, 180, 28));
        countspinBox = new QSpinBox(robotWindow);
        countspinBox->setObjectName(QString::fromUtf8("countspinBox"));
        countspinBox->setEnabled(false);
        countspinBox->setGeometry(QRect(1030, 430, 64, 28));
        countspinBox->setMinimum(1);
        countspinBox->setMaximum(11);
        countspinBox->setSingleStep(2);
        distancespinBox = new QSpinBox(robotWindow);
        distancespinBox->setObjectName(QString::fromUtf8("distancespinBox"));
        distancespinBox->setEnabled(false);
        distancespinBox->setGeometry(QRect(890, 430, 64, 28));
        distancespinBox->setMinimum(20);
        distancespinBox->setMaximum(60);
        distancespinBox->setSingleStep(5);
        distancespinBox->setValue(20);
        label_11 = new QLabel(robotWindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1030, 400, 60, 18));
        label_13 = new QLabel(robotWindow);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(880, 340, 410, 18));
        label_2 = new QLabel(robotWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(880, 80, 581, 18));
        loadRobotButton = new QPushButton(robotWindow);
        loadRobotButton->setObjectName(QString::fromUtf8("loadRobotButton"));
        loadRobotButton->setGeometry(QRect(1110, 10, 180, 28));
        label_3 = new QLabel(robotWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(880, 110, 201, 18));
        addLineSensorButton = new QPushButton(robotWindow);
        addLineSensorButton->setObjectName(QString::fromUtf8("addLineSensorButton"));
        addLineSensorButton->setGeometry(QRect(1110, 170, 180, 28));
        label = new QLabel(robotWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1110, 110, 70, 18));
        addIRPButton = new QPushButton(robotWindow);
        addIRPButton->setObjectName(QString::fromUtf8("addIRPButton"));
        addIRPButton->setGeometry(QRect(1110, 200, 180, 28));
        addIRDButton = new QPushButton(robotWindow);
        addIRDButton->setObjectName(QString::fromUtf8("addIRDButton"));
        addIRDButton->setGeometry(QRect(1110, 230, 180, 28));
        addSonarSensorButton = new QPushButton(robotWindow);
        addSonarSensorButton->setObjectName(QString::fromUtf8("addSonarSensorButton"));
        addSonarSensorButton->setGeometry(QRect(1110, 260, 180, 28));
        exitButton = new QPushButton(robotWindow);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(1180, 680, 104, 28));
        cancelButton = new QPushButton(robotWindow);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(1060, 680, 104, 28));
        saveButton = new QPushButton(robotWindow);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(true);
        saveButton->setGeometry(QRect(940, 680, 104, 28));
        listWidget = new QListWidget(robotWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(880, 142, 222, 140));
        sizeResetButton = new QPushButton(robotWindow);
        sizeResetButton->setObjectName(QString::fromUtf8("sizeResetButton"));
        sizeResetButton->setEnabled(true);
        sizeResetButton->setGeometry(QRect(1030, 480, 110, 28));
        sizeUndoButton = new QPushButton(robotWindow);
        sizeUndoButton->setObjectName(QString::fromUtf8("sizeUndoButton"));
        sizeUndoButton->setEnabled(true);
        sizeUndoButton->setGeometry(QRect(890, 480, 110, 28));

        retranslateUi(robotWindow);
        QObject::connect(newRobotButton, SIGNAL(clicked()), robotWindow, SLOT(newRobotButtonClicked()));
        QObject::connect(loadRobotButton, SIGNAL(clicked()), robotWindow, SLOT(loadRobotButtonClicked()));
        QObject::connect(addMotorButton, SIGNAL(clicked()), robotWindow, SLOT(addMotorButtonClicked()));
        QObject::connect(addLineSensorButton, SIGNAL(clicked()), robotWindow, SLOT(addLineSensorButtonClicked()));
        QObject::connect(addIRPButton, SIGNAL(clicked()), robotWindow, SLOT(addIRPSensorButtonClicked()));
        QObject::connect(addIRDButton, SIGNAL(clicked()), robotWindow, SLOT(addIRDSensorButtonClicked()));
        QObject::connect(addSonarSensorButton, SIGNAL(clicked()), robotWindow, SLOT(addSonarSensorButtonClicked()));
        QObject::connect(editButton, SIGNAL(clicked()), robotWindow, SLOT(editButtonClicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), robotWindow, SLOT(deleteButtonClicked()));
        QObject::connect(saveDimentionButton, SIGNAL(clicked()), robotWindow, SLOT(saveButtonClicked()));
        QObject::connect(saveButton, SIGNAL(clicked()), robotWindow, SLOT(saveRobotButtonClicked()));
        QObject::connect(cancelButton, SIGNAL(clicked()), robotWindow, SLOT(cancelButtonClicked()));
        QObject::connect(exitButton, SIGNAL(clicked()), robotWindow, SLOT(exitButtonClicked()));
        QObject::connect(robotWindow, SIGNAL(robotObjectUpdated(vector_robotObjectType)), widget, SLOT(updateRobotObject(vector_robotObjectType)));
        QObject::connect(listWidget, SIGNAL(currentTextChanged(QString)), widget, SLOT(currentObject(QString)));
        QObject::connect(distancespinBox, SIGNAL(valueChanged(int)), robotWindow, SLOT(distanceSpinBoxValueChanged(int)));
        QObject::connect(countspinBox, SIGNAL(valueChanged(int)), robotWindow, SLOT(countSpinBoxValueChanged(int)));

        QMetaObject::connectSlotsByName(robotWindow);
    } // setupUi

    void retranslateUi(QWidget *robotWindow)
    {
        robotWindow->setWindowTitle(QApplication::translate("robotWindow", "Create Robot", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("robotWindow", "Distance :", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("robotWindow", "Robot File Name :", 0, QApplication::UnicodeUTF8));
        newRobotButton->setText(QApplication::translate("robotWindow", "New Robot", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("robotWindow", "Delete", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("robotWindow", "Edit", 0, QApplication::UnicodeUTF8));
        saveDimentionButton->setText(QApplication::translate("robotWindow", "Save", 0, QApplication::UnicodeUTF8));
        addMotorButton->setText(QApplication::translate("robotWindow", "Motors", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("robotWindow", "Count :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        label_2->setText(QApplication::translate("robotWindow", "..", 0, QApplication::UnicodeUTF8));
        loadRobotButton->setText(QApplication::translate("robotWindow", "Load Robot", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("robotWindow", "Parts of Robot :", 0, QApplication::UnicodeUTF8));
        addLineSensorButton->setText(QApplication::translate("robotWindow", "Line Sensors", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("robotWindow", "Add :", 0, QApplication::UnicodeUTF8));
        addIRPButton->setText(QApplication::translate("robotWindow", "IR Proximity Sensors", 0, QApplication::UnicodeUTF8));
        addIRDButton->setText(QApplication::translate("robotWindow", "IR Distance Sensors", 0, QApplication::UnicodeUTF8));
        addSonarSensorButton->setText(QApplication::translate("robotWindow", "Sonar Sensors", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("robotWindow", "Exit", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("robotWindow", "Save as", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("robotWindow", "Save", 0, QApplication::UnicodeUTF8));
        sizeResetButton->setText(QApplication::translate("robotWindow", "Reset", 0, QApplication::UnicodeUTF8));
        sizeUndoButton->setText(QApplication::translate("robotWindow", "Undo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class robotWindow: public Ui_robotWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTWINDOW_H
