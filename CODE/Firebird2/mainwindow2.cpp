/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    ce=new createEnvironment();
    cr=new robotWindow();
    connect(ce,SIGNAL(envName(string)),this,SLOT(getEnvName(string)));
    connect(cr,SIGNAL(roboName(string)),this,SLOT(getRobotName(string)));

    robot.x=50;robot.y=10;robot.z=-20;
}
void MainWindow2::getEnvName(string str){
    cout<<"mAINWINDOW  "<<str<<endl;
    emit setEnvName(str);
}
void MainWindow2::getRobotName(string str){
    cout<<"mAINWINDOW  "<<str<<endl;
}

void MainWindow2::menuClicked(QAction* menu){
    cout<<menu->text().toStdString()<<endl;

    if(menu->text().toStdString()=="Enviourment"){
        //        cr->show();
        ce->show();
        //        ce->close();
        //        cr->startTimer();
        //        emit setEnvName("Atul");
    }
    else if(menu->text().toStdString()=="Robot"){
        //        cout<<eName<<endl;
                cr->show();
    }
    //    emit setEnvName("Atul");
}
void MainWindow2::browseEnvButtonClicked(){
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"Environment",tr("Files (*.txt)"));

    //    ui->envNameLable->setWordWrap(true);
    //    ui->envNameLable->setText(filename);
    ui->envNamelineEdit->setText(filename);
    emit setEnvName(filename.toStdString());
}

void MainWindow2::browseRobotButtonClicked(){
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"Robot",tr("Files (*.txt)"));
    //ui->robotNameLable->setText(filename);
    ui->robotNamelineEdit->setText(filename);
    emit setRobotName(filename.toStdString());
}

void MainWindow2::initRobotButtonClicked(){

    ui->locationXspinBox->setEnabled(true);
    ui->locationYspinBox->setEnabled(true);
    ui->locationZspinBox->setEnabled(true);
    ui->locationAnglespinBox->setEnabled(true);
    ui->locationUndoButton->setEnabled(true);
    ui->locationResetButton->setEnabled(true);

}

void MainWindow2::undoButtonClicked(){

}

void MainWindow2::resetButtonClicked(){

}

void MainWindow2::locationSaveButtonClicked(){

}
void MainWindow2::startButtonClicked(){

}

void MainWindow2::locationXspinBoxValueChanged(int x){
    robot.x=x;
    emit setRobotLocation(robot);

}

void MainWindow2::locationYspinBoxValueChanged(int y){

    robot.y=y;
    emit setRobotLocation(robot);
}

void MainWindow2::locationZspinBoxValueChanged(int z){
    robot.z=-z;
    emit setRobotLocation(robot);

}

void MainWindow2::locationAnglespinBoxValueChanged(int angle){
    robot.angle=angle;
    emit setRobotLocation(robot);

}

void MainWindow2::portNumberspinBoxValueChanged(int){

}

MainWindow2::~MainWindow2()
{
    delete ui;
}
