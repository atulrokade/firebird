#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QLineEdit>
#include "createenvironment.h"
#include "robotwindow.h"
#include <iostream>
using namespace std;
namespace Ui {
class test;
}

class test : public QMainWindow
{
    Q_OBJECT

private:
    Ui::test *ui;

public:
        createEnvironment *ce;
     test(QWidget *parent = 0);
    ~test();


signals:
    void setEnvName(string str);
public slots:
    void menuClicked(QAction * menu);
    void getEnvName(string str);
//    void getRobotName(string str);
};

#endif // TEST_H
