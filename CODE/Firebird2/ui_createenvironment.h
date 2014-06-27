/********************************************************************************
** Form generated from reading UI file 'createenvironment.ui'
**
** Created: Fri Jun 27 12:54:12 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEENVIRONMENT_H
#define UI_CREATEENVIRONMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include "createenvironmentopenglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_createEnvironment
{
public:
    createEnvironmentOpenglWindow *widget;
    QListWidget *listWidget;
    QPushButton *deleteButton;
    QPushButton *newEnvButton;
    QPushButton *loadButton;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *editButton;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *sizeXspinBox;
    QLabel *label_6;
    QSpinBox *sizeYspinBox;
    QLabel *label_7;
    QSpinBox *sizeZspinBox;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *locationXspinBox;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *locationZspinBox;
    QSpinBox *locationYspinBox;
    QPushButton *addButton;
    QPushButton *sizeUndoButton;
    QPushButton *sizeResetButton;
    QPushButton *locationUndoButton;
    QPushButton *locationResetButton;
    QPushButton *saveDimentionButton;
    QLabel *label_13;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *exitButton;
    QLabel *label;
    QPushButton *browseButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *createEnvironment)
    {
        if (createEnvironment->objectName().isEmpty())
            createEnvironment->setObjectName(QString::fromUtf8("createEnvironment"));
        createEnvironment->setWindowModality(Qt::NonModal);
        createEnvironment->resize(1307, 721);
        createEnvironment->setFocusPolicy(Qt::NoFocus);
        widget = new createEnvironmentOpenglWindow(createEnvironment);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 850, 700));
        listWidget = new QListWidget(createEnvironment);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(881, 180, 258, 71));
        deleteButton = new QPushButton(createEnvironment);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(true);
        deleteButton->setGeometry(QRect(1020, 260, 120, 28));
        deleteButton->setFocusPolicy(Qt::StrongFocus);
        newEnvButton = new QPushButton(createEnvironment);
        newEnvButton->setObjectName(QString::fromUtf8("newEnvButton"));
        newEnvButton->setGeometry(QRect(880, 10, 170, 28));
        loadButton = new QPushButton(createEnvironment);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(1090, 10, 180, 28));
        label_1 = new QLabel(createEnvironment);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(880, 50, 161, 18));
        label_2 = new QLabel(createEnvironment);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(880, 80, 581, 18));
        label_3 = new QLabel(createEnvironment);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(880, 150, 201, 18));
        editButton = new QPushButton(createEnvironment);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(880, 260, 120, 28));
        label_4 = new QLabel(createEnvironment);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(880, 370, 70, 18));
        label_5 = new QLabel(createEnvironment);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(880, 510, 71, 18));
        sizeXspinBox = new QSpinBox(createEnvironment);
        sizeXspinBox->setObjectName(QString::fromUtf8("sizeXspinBox"));
        sizeXspinBox->setEnabled(false);
        sizeXspinBox->setGeometry(QRect(920, 390, 64, 28));
        sizeXspinBox->setMaximum(2700);
        sizeXspinBox->setSingleStep(10);
        label_6 = new QLabel(createEnvironment);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(890, 400, 21, 18));
        sizeYspinBox = new QSpinBox(createEnvironment);
        sizeYspinBox->setObjectName(QString::fromUtf8("sizeYspinBox"));
        sizeYspinBox->setEnabled(false);
        sizeYspinBox->setGeometry(QRect(1020, 390, 64, 28));
        sizeYspinBox->setMaximum(2700);
        sizeYspinBox->setSingleStep(10);
        label_7 = new QLabel(createEnvironment);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(990, 400, 21, 18));
        sizeZspinBox = new QSpinBox(createEnvironment);
        sizeZspinBox->setObjectName(QString::fromUtf8("sizeZspinBox"));
        sizeZspinBox->setEnabled(false);
        sizeZspinBox->setGeometry(QRect(1120, 390, 64, 28));
        sizeZspinBox->setMaximum(2700);
        sizeZspinBox->setSingleStep(10);
        label_8 = new QLabel(createEnvironment);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1090, 400, 21, 18));
        label_9 = new QLabel(createEnvironment);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1090, 550, 21, 18));
        locationXspinBox = new QSpinBox(createEnvironment);
        locationXspinBox->setObjectName(QString::fromUtf8("locationXspinBox"));
        locationXspinBox->setEnabled(false);
        locationXspinBox->setGeometry(QRect(920, 540, 64, 28));
        locationXspinBox->setMaximum(2700);
        locationXspinBox->setSingleStep(10);
        label_10 = new QLabel(createEnvironment);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(890, 550, 21, 18));
        label_11 = new QLabel(createEnvironment);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(990, 550, 21, 18));
        locationZspinBox = new QSpinBox(createEnvironment);
        locationZspinBox->setObjectName(QString::fromUtf8("locationZspinBox"));
        locationZspinBox->setEnabled(false);
        locationZspinBox->setGeometry(QRect(1120, 540, 64, 28));
        locationZspinBox->setMaximum(2700);
        locationZspinBox->setSingleStep(10);
        locationYspinBox = new QSpinBox(createEnvironment);
        locationYspinBox->setObjectName(QString::fromUtf8("locationYspinBox"));
        locationYspinBox->setEnabled(false);
        locationYspinBox->setGeometry(QRect(1020, 540, 64, 28));
        locationYspinBox->setMaximum(2700);
        locationYspinBox->setSingleStep(10);
        addButton = new QPushButton(createEnvironment);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(880, 300, 260, 28));
        sizeUndoButton = new QPushButton(createEnvironment);
        sizeUndoButton->setObjectName(QString::fromUtf8("sizeUndoButton"));
        sizeUndoButton->setEnabled(false);
        sizeUndoButton->setGeometry(QRect(920, 440, 60, 28));
        sizeResetButton = new QPushButton(createEnvironment);
        sizeResetButton->setObjectName(QString::fromUtf8("sizeResetButton"));
        sizeResetButton->setEnabled(false);
        sizeResetButton->setGeometry(QRect(1000, 440, 60, 28));
        locationUndoButton = new QPushButton(createEnvironment);
        locationUndoButton->setObjectName(QString::fromUtf8("locationUndoButton"));
        locationUndoButton->setEnabled(false);
        locationUndoButton->setGeometry(QRect(920, 590, 60, 28));
        locationResetButton = new QPushButton(createEnvironment);
        locationResetButton->setObjectName(QString::fromUtf8("locationResetButton"));
        locationResetButton->setEnabled(false);
        locationResetButton->setGeometry(QRect(1000, 590, 60, 28));
        saveDimentionButton = new QPushButton(createEnvironment);
        saveDimentionButton->setObjectName(QString::fromUtf8("saveDimentionButton"));
        saveDimentionButton->setEnabled(false);
        saveDimentionButton->setGeometry(QRect(1210, 360, 61, 260));
        label_13 = new QLabel(createEnvironment);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(880, 340, 650, 18));
        saveButton = new QPushButton(createEnvironment);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(true);
        saveButton->setGeometry(QRect(920, 670, 104, 28));
        cancelButton = new QPushButton(createEnvironment);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(1040, 670, 104, 28));
        exitButton = new QPushButton(createEnvironment);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(1160, 670, 104, 28));
        label = new QLabel(createEnvironment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(880, 120, 141, 17));
        browseButton = new QPushButton(createEnvironment);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setEnabled(false);
        browseButton->setGeometry(QRect(1180, 112, 90, 30));
        lineEdit = new QLineEdit(createEnvironment);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(972, 113, 191, 27));

        retranslateUi(createEnvironment);
        QObject::connect(listWidget, SIGNAL(currentRowChanged(int)), createEnvironment, SLOT(currentRowChanged(int)));
        QObject::connect(newEnvButton, SIGNAL(clicked()), createEnvironment, SLOT(newEnvButtonClicked()));
        QObject::connect(loadButton, SIGNAL(clicked()), createEnvironment, SLOT(loadEnvButtonClicked()));
        QObject::connect(editButton, SIGNAL(clicked()), createEnvironment, SLOT(editObjectButtonClicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), createEnvironment, SLOT(deleteObjectButtonClicked()));
        QObject::connect(addButton, SIGNAL(clicked()), createEnvironment, SLOT(addObjectButtonClicked()));
        QObject::connect(listWidget, SIGNAL(currentTextChanged(QString)), label_13, SLOT(setText(QString)));
        QObject::connect(sizeUndoButton, SIGNAL(clicked()), createEnvironment, SLOT(sizeUndoButtonClicked()));
        QObject::connect(sizeResetButton, SIGNAL(clicked()), createEnvironment, SLOT(sizeResetButtonClicked()));
        QObject::connect(locationUndoButton, SIGNAL(clicked()), createEnvironment, SLOT(locationUndoButtonClicked()));
        QObject::connect(locationResetButton, SIGNAL(clicked()), createEnvironment, SLOT(locationResetButtonClicked()));
        QObject::connect(saveDimentionButton, SIGNAL(clicked()), createEnvironment, SLOT(saveDimentionButtonClicked()));
        QObject::connect(createEnvironment, SIGNAL(objectUpdated(vector_envObjectType)), widget, SLOT(updateObject(vector_envObjectType)));
        QObject::connect(saveButton, SIGNAL(clicked()), createEnvironment, SLOT(saveButtonClicked()));
        QObject::connect(cancelButton, SIGNAL(clicked()), createEnvironment, SLOT(cancelButtonClicked()));
        QObject::connect(sizeXspinBox, SIGNAL(valueChanged(int)), createEnvironment, SLOT(sizeXspinBoxValueChanged(int)));
        QObject::connect(sizeYspinBox, SIGNAL(valueChanged(int)), createEnvironment, SLOT(sizeYspinBoxValueChanged(int)));
        QObject::connect(sizeZspinBox, SIGNAL(valueChanged(int)), createEnvironment, SLOT(sizeZspinBoxValueChanged(int)));
        QObject::connect(locationXspinBox, SIGNAL(valueChanged(int)), createEnvironment, SLOT(locationXspinBoxValueChanged(int)));
        QObject::connect(locationYspinBox, SIGNAL(valueChanged(int)), createEnvironment, SLOT(locationYspinBoxValueChanged(int)));
        QObject::connect(locationZspinBox, SIGNAL(valueChanged(int)), createEnvironment, SLOT(locationZspinBoxValueChanged(int)));
        QObject::connect(listWidget, SIGNAL(currentTextChanged(QString)), widget, SLOT(currentObject(QString)));
        QObject::connect(exitButton, SIGNAL(clicked()), createEnvironment, SLOT(exitButtonClicked()));
        QObject::connect(browseButton, SIGNAL(clicked()), createEnvironment, SLOT(browseButtonClicked()));

        QMetaObject::connectSlotsByName(createEnvironment);
    } // setupUi

    void retranslateUi(QWidget *createEnvironment)
    {
        createEnvironment->setWindowTitle(QApplication::translate("createEnvironment", "Create Environment", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("createEnvironment", "Delete", 0, QApplication::UnicodeUTF8));
        newEnvButton->setText(QApplication::translate("createEnvironment", "New Environment", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("createEnvironment", "Load Environment", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("createEnvironment", "Environment Name :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("createEnvironment", "..", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("createEnvironment", "Objects in Environment :", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("createEnvironment", "Edit", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("createEnvironment", "Size :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("createEnvironment", "Location :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("createEnvironment", "X :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("createEnvironment", "Y :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("createEnvironment", "Z :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("createEnvironment", "Z :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("createEnvironment", "X :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("createEnvironment", "Y :", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("createEnvironment", "Add Cuboid", 0, QApplication::UnicodeUTF8));
        sizeUndoButton->setText(QApplication::translate("createEnvironment", "Undo", 0, QApplication::UnicodeUTF8));
        sizeResetButton->setText(QApplication::translate("createEnvironment", "Reset", 0, QApplication::UnicodeUTF8));
        locationUndoButton->setText(QApplication::translate("createEnvironment", "Undo", 0, QApplication::UnicodeUTF8));
        locationResetButton->setText(QApplication::translate("createEnvironment", "Reset", 0, QApplication::UnicodeUTF8));
        saveDimentionButton->setText(QApplication::translate("createEnvironment", "Save", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        saveButton->setText(QApplication::translate("createEnvironment", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("createEnvironment", "Save as", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("createEnvironment", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("createEnvironment", "Floor Image :", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("createEnvironment", "Browse", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class createEnvironment: public Ui_createEnvironment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEENVIRONMENT_H
