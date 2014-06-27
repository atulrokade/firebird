/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QLineEdit>
#include "createenvironment.h"
#include "robotwindow.h"
#include "mydatatype.h"
#include <iostream>
using namespace std;
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow2 *ui;
    robotLocation robot;

public:

    createEnvironment *ce;
    robotWindow *cr;

    MainWindow2(QWidget *parent = 0);
    ~MainWindow2();
    



signals:
    void setEnvName(string str);
    void setRobotName(string str);
    void setRobotLocation(robotLocation);
public slots:
    void menuClicked(QAction * menu);
    void getEnvName(string str);
    void getRobotName(string str);

    void browseEnvButtonClicked();
    void browseRobotButtonClicked();
    void initRobotButtonClicked();
    void undoButtonClicked();
    void resetButtonClicked();
    void locationSaveButtonClicked();
    void startButtonClicked();

    void portNumberspinBoxValueChanged(int portNumber);
    void locationXspinBoxValueChanged(int x);
    void locationYspinBoxValueChanged(int y);
    void locationZspinBoxValueChanged(int z);
    void locationAnglespinBoxValueChanged(int angle);
};

#endif // MAINWINDOW2_H
