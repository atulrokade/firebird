/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ce=new createEnvironment();
    cr=new robotWindow();

    connect(ce,SIGNAL(envName(string)),this,SLOT(getEnvName(string)));

    //ui->textEdit->setText("atul");
}
void MainWindow::set(){
    //ui->textEdit->setText("atul");
}

MainWindow::~MainWindow()
{
    delete ce;
    delete cr;
    delete ui;
}
MainWindow * MainWindow::getPointer(){
    return this;
}
void MainWindow::getEnvName(string str){
    cout<<"mAINWINDOW  "<<str<<endl;
    emit setEnvName(str);

}
void MainWindow::getRobotName(string str){
    cout<<str<<endl;
}

void MainWindow::menuClicked(QAction * menu){
    cout<<menu->text().toStdString()<<endl;

    if(menu->text().toStdString()=="Enviourment"){
//        ce->show();
        emit setEnvName("Atul");
    }
//    else if(menu->text().toStdString()=="Robot"){
//        cr->show();
//    }
//    emit setEnvName("Atul");
}
