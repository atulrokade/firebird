/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include <QtGui/QApplication>
#include "mainwindow.h"
#include "createenvironment.h"
#include "robotwindow.h"
#include "dialog.h"
#include "test.h"
#include "mainwindow2.h"
#include "image.h"
#include "communicate.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;    w.show();
//    robotWindow r;    r.show();
//    createEnvironment ce;    ce.show();
//    test t;t.show();
//    MainWindow2 mw2;mw2.show();
//    communicate cm;
    MainWindow2 *mw2;    mw2=new MainWindow2();    mw2->show();


//    image ii; ii.read();
    //    Dialog d;
    //    d.show();

    return a.exec();
}
