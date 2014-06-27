/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "robotwindow.h"
#include "ui_robotwindow.h"

robotWindow::robotWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::robotWindow)
{
    ui->setupUi(this);
    ui->listWidget->setCurrentRow(0);

    string ss="Chassis";
    robotObjectType tempChassis={ss,0,0};
    objectList.push_back(tempChassis);

    QString item=QString::fromStdString(ss);
    ui->listWidget->addItem(item);

    emit robotObjectUpdated(objectList);
    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),SLOT(timerSlot()));
    count=0;
}
void robotWindow::startTimer(){
    timer->start(500);
}

void robotWindow::timerSlot(){
    cout<<count++<<endl;
    timer->start(500);
}

robotWindow::~robotWindow()
{
    delete ui;
}
void robotWindow::createNewRobot(){
    QString filename=QFileDialog::getSaveFileName(this, tr("Save File"),"/home/atul/Desktop/Robot/robot.txt",tr("Files (*.txt)"));
    robotName=filename.toStdString();
    ui->label_2->setText(QString::fromStdString(robotName));
    ui->saveButton->setEnabled(true);


}

void robotWindow::newRobotButtonClicked(){

    createNewRobot();
    emit robotObjectUpdated(objectList);


}
void robotWindow::loadRobot(){
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"/home/atul/Desktop/Robot",tr("Files (*.txt)"));

    robotName=filename.toStdString();
    string str;
    robotObjectType temp;
    ui->listWidget->clear();
    objectList.clear();
    fstream file;
    file.open(robotName.c_str(),ios::in);
    while(file>>str){
        temp.name=str;
        ui->listWidget->addItem(QString::fromStdString(str));
        file>>temp.distance>>temp.count;
        objectList.push_back(temp);

    }
    file.close();
    ui->label_2->setText(filename);
    ui->saveButton->setEnabled(true);

}

void robotWindow::loadRobotButtonClicked(){

    loadRobot();
    emit robotObjectUpdated(objectList);

}
void robotWindow::saveRobot(){

    fstream file;
    file.open(robotName.c_str(),ios::out);
    for(int i=0;i<objectList.size();i++){
        file<<objectList[i].name<<" "<<objectList[i].distance<<" "<<objectList[i].count<<"\n";
    }
    file.close();

}

void robotWindow::saveRobotButtonClicked(){
    //    emit robotObjectUpdated(objectList);
    saveRobot();
}
void robotWindow::addMotorButtonClicked(){

    string ss="Motors";
    QString item=QString::fromStdString(ss);
    ui->listWidget->addItem(item);
    int tp=ui->listWidget->count();
    ui->listWidget->setCurrentRow(tp-1);


    robotObjectType tempObject={ss,10,2};
    objectList.push_back(tempObject);

    emit robotObjectUpdated(objectList);

    ui->addMotorButton->setDisabled(true);
}
void robotWindow::addLineSensorButtonClicked(){

    string ss="Line_Sensors";
    QString item=QString::fromStdString(ss);
    ui->listWidget->addItem(item);
    int tp=ui->listWidget->count();
    ui->listWidget->setCurrentRow(tp-1);


    robotObjectType tempObject={ss,20,1};
    objectList.push_back(tempObject);

    emit robotObjectUpdated(objectList);

    ui->addLineSensorButton->setDisabled(true);
}
void robotWindow::addIRPSensorButtonClicked(){

    string ss="IR_Proximity_Sensors";
    QString item=QString::fromStdString(ss);
    ui->listWidget->addItem(item);
    int tp=ui->listWidget->count();
    ui->listWidget->setCurrentRow(tp-1);


    robotObjectType tempObject={ss,0,8};
    objectList.push_back(tempObject);

    emit robotObjectUpdated(objectList);

    ui->addIRPButton->setDisabled(true);
}
void robotWindow::addIRDSensorButtonClicked(){

    string ss="IR_Distance_Sensors";
    QString item=QString::fromStdString(ss);
    ui->listWidget->addItem(item);
    int tp=ui->listWidget->count();
    ui->listWidget->setCurrentRow(tp-1);


    robotObjectType tempObject={ss,0,8};
    objectList.push_back(tempObject);

    emit robotObjectUpdated(objectList);

    ui->addIRDButton->setDisabled(true);
}
void robotWindow::addSonarSensorButtonClicked(){

    string ss="Sonar_Sensors";
    QString item=QString::fromStdString(ss);
    ui->listWidget->addItem(item);
    int tp=ui->listWidget->count();
    ui->listWidget->setCurrentRow(tp-1);


    robotObjectType tempObject={ss,0,8};
    objectList.push_back(tempObject);

    emit robotObjectUpdated(objectList);

    ui->addSonarSensorButton->setDisabled(true);
}
void robotWindow::distanceSpinBoxValueChanged(int d){
    if(objectList[currentObjectIndex].count>1){
        objectList[currentObjectIndex].distance=d;
        emit robotObjectUpdated(objectList);
    }
}
void robotWindow::countSpinBoxValueChanged(int c){
    objectList[currentObjectIndex].count=c;

    if(objectList[currentObjectIndex].count>1)
        ui->distancespinBox->setEnabled(true);
    else
        ui->distancespinBox->setDisabled(true);
    emit robotObjectUpdated(objectList);
}

void robotWindow::currentRowChanged(int row){
    string tempObjName=ui->listWidget->currentItem()->text().toStdString();
    if(tempObjName=="Line_Sensors")
        ui->editButton->setEnabled(true);
    else
        ui->editButton->setDisabled(true);
}

void robotWindow::editButtonClicked(){

    currentObjectName=ui->listWidget->currentItem()->text().toStdString();
    currentObjectIndex=getObjectListIndex(currentObjectName);


//    ui->distancespinBox->setEnabled(true);
    ui->countspinBox->setEnabled(true);
    ui->saveDimentionButton->setEnabled(true);
}
void robotWindow::deleteButtonClicked(){

    string tempObjName=ui->listWidget->currentItem()->text().toStdString();
    delete ui->listWidget->item(ui->listWidget->currentRow());
    int tempIndex=getObjectListIndex(tempObjName);
    objectList.erase(objectList.begin()+tempIndex);

    emit robotObjectUpdated(objectList);

    if(tempObjName=="Motors")
        ui->addMotorButton->setEnabled(true);
    else if(tempObjName=="Line_Sensors")
        ui->addLineSensorButton->setEnabled(true);
    else if(tempObjName=="IR_Proximity_Sensors")
        ui->addIRPButton->setEnabled(true);
    else if(tempObjName=="IR_Distance_Sensors")
        ui->addIRDButton->setEnabled(true);
    else if(tempObjName=="Sonar_Sensors")
        ui->addSonarSensorButton->setEnabled(true);

}
int robotWindow::getObjectListIndex(string objName){
    for(int i=0;i<objectList.size();i++){
        if(objectList[i].name==objName)
            return i;
    }
}
void robotWindow::saveButtonClicked(){

    ui->distancespinBox->setDisabled(true);
    ui->countspinBox->setDisabled(true);
    ui->saveDimentionButton->setDisabled(true);
}
void robotWindow::exitButtonClicked(){

    emit roboName(robotName);
    this->close();
}

void robotWindow::cancelButtonClicked(){
    emit roboName(robotName);
}
