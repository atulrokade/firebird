/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QLineEdit>
#include <iostream>
#include "createenvironment.h"
#include "robotwindow.h"
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
public:
    MainWindow(QWidget *parent = 0);
    MainWindow * getPointer();
    ~MainWindow();
    void set();
    createEnvironment *ce;
    robotWindow *cr;


signals:
    void setEnvName(string str);
    void setRobotName(string str);

public slots:
    void menuClicked(QAction * menu);
    void getEnvName(string str);
    void getRobotName(string str);
};

#endif // MAINWINDOW_H
