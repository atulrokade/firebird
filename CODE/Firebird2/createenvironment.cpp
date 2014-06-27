/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "createenvironment.h"
#include "ui_createenvironment.h"


createEnvironment::createEnvironment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createEnvironment)
{

    ex=0;

    ui->setupUi(this);

    objectCount=0;
    ui->listWidget->setCurrentRow(0);

//    envObjectType tempFloor={"Floor",220,220,0,0,0,0};
//    objectList.push_back(tempFloor);

    editFloorFlag=false;
    emit objectUpdated(objectList);
    currentObjectIndex=0;
    currentObjectName="Floor";
    defaultObject.name="Cuboid";
    defaultObject.sizeX=10;
    defaultObject.sizeY=10;
    defaultObject.sizeZ=10;
    defaultObject.locationX=0;
    defaultObject.locationY=0;
    defaultObject.locationZ=0;


    //    if (std::regex_match ("Cuboid_", std::regex("(Cuboid_)(.*)") ))
    //       std::cout << "string literal matched\n";
}

createEnvironment::~createEnvironment()
{
    delete ui;
}
createEnvironment::createEnvironment(int a){}


void createEnvironment::currentRowChanged(int row){



    if(ui->listWidget->currentRow()==0)
        ui->deleteButton->setDisabled(true);
    else
        ui->deleteButton->setEnabled(true);




}
void createEnvironment::createNewEnvironment(){

    QString filename=QFileDialog::getSaveFileName(this, tr("Save File"),"/home/atul/Desktop/Environment/environment.txt",tr("Files (*.txt)"));
    environmentName=filename.toStdString();
    ui->label_2->setText(QString::fromStdString(environmentName));
    ui->saveButton->setEnabled(true);

}

void createEnvironment::newEnvButtonClicked(){
    createNewEnvironment();
    ui->lineEdit->setEnabled(true);
    ui->browseButton->setEnabled(true);
    emit objectUpdated(objectList);
}

void createEnvironment::loadEnvironment(){
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"/home/atul/Desktop/Environment",tr("Files (*.txt)"));

    environmentName=filename.toStdString();
    fstream file;
    file.open(environmentName.c_str());
    string str;
    envObjectType temp;
    objectList.clear();
    ui->listWidget->clear();
    while(file>>str){
        temp.name=str;
        if(str[0]=='/'){
            ui->listWidget->addItem(QString::fromStdString("Floor"));
            floorName=str;
            ui->lineEdit->setText(QString::fromStdString(floorName));
        }
        else{
            ui->listWidget->addItem(QString::fromStdString(str));
        }
        file>>temp.sizeX>>temp.sizeY>>temp.sizeZ>>temp.locationX>>temp.locationY>>temp.locationZ;
        objectList.push_back(temp);

        unsigned pos = str.find("_");
        objectCount  =atoi(str.substr (pos+1).c_str());
    }
    file.close();
    ui->label_2->setText(filename);
    ui->saveButton->setEnabled(true);

}
void createEnvironment::loadEnvButtonClicked(){
    loadEnvironment();
    emit objectUpdated(objectList);
    //    emit testSignal();

}

void createEnvironment::saveEnvironment(){
    fstream file;
    file.open(environmentName.c_str(),ios::out);
    for(int i=0;i<objectList.size();i++){
        file<<objectList[i].name<<" "<<objectList[i].sizeX<<" "<<objectList[i].sizeY<<" "<<objectList[i].sizeZ<<" "<<objectList[i].locationX<<" "<<objectList[i].locationY<<" "<<objectList[i].locationZ<<"\n";
    }
    file.close();

}
void createEnvironment::saveButtonClicked(){
    emit objectUpdated(objectList);
    saveEnvironment();
    cout<<floorImage->name<<" "<<floorImage->width<<" "<<floorImage->height<<" "<<floorImage->textureNumber<<endl;

}
void createEnvironment::browseButtonClicked(){
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"/home/atul/Desktop/Environment",tr("Files (*.png)"));
    ui->lineEdit->setText(filename);

        envObjectType tempFloor={"Floor",220,220,0,0,0,0};

        floorImage=new image(filename.toStdString());

        if(editFloorFlag==false){
        ui->listWidget->addItem("Floor");
        ui->listWidget->setCurrentRow(0);
        objectList.push_back(tempFloor);
        }
    objectList[currentObjectIndex].name=filename.toStdString();
    objectList[currentObjectIndex].sizeX=floorImage->width;
    objectList[currentObjectIndex].sizeY=floorImage->height;
//    ui->listWidget->addItem(filename);

    floorName=filename.toStdString();

    ui->lineEdit->setDisabled(true);
    ui->browseButton->setDisabled(true);
        emit objectUpdated(objectList);
}

void createEnvironment::cancelButtonClicked(){
    //    exit(0);
    emit envName(environmentName);
}

void createEnvironment::getenvironmentName(string *& str){
    //    return environmentName;
    cout<<&str<<endl;
    envn=&str;
    cout<<envn<<endl;

    cout<<*envn<<endl;

    //    *str=&envn;
}
void createEnvironment::exitButtonClicked(){
    //    exit(0);
    ex=1;
//    emit envName(environmentName);
    //    eName=environmentName;

    //    *envn=&this->environmentName;
    //    cout<<**envn<<endl;
    //    cout<<*envn<<endl;
    //    cout<<this->environmentName<<endl;
    this->close();
}
void createEnvironment::addObjectButtonClicked(){
    stringstream ss;
    ss <<"Cuboid_"<<++objectCount;
    QString item=QString::fromStdString(ss.str());
    ui->listWidget->addItem(item);
    int tp=ui->listWidget->count();
    ui->listWidget->setCurrentRow(tp-1);


    envObjectType tempObject={ss.str(),10,10,10,-20,0,0};
    objectList.push_back(tempObject);

    emit objectUpdated(objectList);
}
void createEnvironment::editObjectButtonClicked(){

    currentObjectName=ui->listWidget->currentItem()->text().toStdString();
    if(currentObjectName=="Floor"){
        currentObjectIndex=getObjectListIndex(floorName);
        ui->lineEdit->setEnabled(true);
        ui->browseButton->setEnabled(true);
        editFloorFlag=true;
    }
    else{
    currentObjectIndex=getObjectListIndex(currentObjectName);
    }
    currentObject=objectList[currentObjectIndex];

    ui->sizeXspinBox->setValue(objectList[currentObjectIndex].sizeX);
    ui->sizeYspinBox->setValue(objectList[currentObjectIndex].sizeY);
    ui->sizeZspinBox->setValue(objectList[currentObjectIndex].sizeZ);

    ui->locationXspinBox->setValue(objectList[currentObjectIndex].locationX);
    ui->locationYspinBox->setValue(objectList[currentObjectIndex].locationY);
    ui->locationZspinBox->setValue(objectList[currentObjectIndex].locationZ);






    ui->listWidget->setDisabled(true);
    ui->addButton->setDisabled(true);
    ui->deleteButton->setDisabled(true);

    ui->sizeXspinBox->setEnabled(true);
    ui->sizeYspinBox->setEnabled(true);

    ui->sizeUndoButton->setEnabled(true);
    ui->sizeResetButton->setEnabled(true);
    ui->saveDimentionButton->setEnabled(true);

    if(ui->listWidget->currentRow()){
        ui->sizeZspinBox->setEnabled(true);
        ui->locationXspinBox->setEnabled(true);
        ui->locationYspinBox->setEnabled(true);
        ui->locationZspinBox->setEnabled(true);
        ui->locationUndoButton->setEnabled(true);
        ui->locationResetButton->setEnabled(true);
    }
}
void createEnvironment::deleteObjectButtonClicked(){


    //    cout<<ui->listWidget->currentItem()->text().toStdString()<<" deleted"<<endl;
    string tempObjName=ui->listWidget->currentItem()->text().toStdString();
    delete ui->listWidget->item(ui->listWidget->currentRow());
    int tempIndex=getObjectListIndex(tempObjName);
    objectList.erase(objectList.begin()+tempIndex);

    emit objectUpdated(objectList);

    //    for(int i=0;i<objectList.size();i++){
    //        cout<<objectList[i].name<<" "<<objectList[i].sizeX<<" "<<objectList[i].sizeY<<" "<<objectList[i].sizeZ<<" "<<objectList[i].locationX<<" "<<objectList[i].locationY<<" "<<objectList[i].locationZ<<endl;
    //        }
}
int createEnvironment::getObjectListIndex(string objName){
    for(int i=0;i<objectList.size();i++){
        if(objectList[i].name==objName)
            return i;
    }
}

void createEnvironment::sizeUndoButtonClicked(){
    objectList[currentObjectIndex].sizeX=currentObject.sizeX;
    objectList[currentObjectIndex].sizeY=currentObject.sizeY;
    objectList[currentObjectIndex].sizeZ=currentObject.sizeZ;

    ui->sizeXspinBox->setValue(objectList[currentObjectIndex].sizeX);
    ui->sizeYspinBox->setValue(objectList[currentObjectIndex].sizeY);
    ui->sizeZspinBox->setValue(objectList[currentObjectIndex].sizeZ);
    //    emit objectUpdated(objectList);

}
void createEnvironment::sizeResetButtonClicked(){
    objectList[currentObjectIndex].sizeX=defaultObject.sizeX;
    objectList[currentObjectIndex].sizeY=defaultObject.sizeY;
    objectList[currentObjectIndex].sizeZ=defaultObject.sizeZ;

    ui->sizeXspinBox->setValue(objectList[currentObjectIndex].sizeX);
    ui->sizeYspinBox->setValue(objectList[currentObjectIndex].sizeY);
    ui->sizeZspinBox->setValue(objectList[currentObjectIndex].sizeZ);

}
void createEnvironment::sizeXspinBoxValueChanged(int x){
    objectList[currentObjectIndex].sizeX=x;
    emit objectUpdated(objectList);

}
void createEnvironment::sizeYspinBoxValueChanged(int y){
    objectList[currentObjectIndex].sizeY=y;
    emit objectUpdated(objectList);

}
void createEnvironment::sizeZspinBoxValueChanged(int z){
    objectList[currentObjectIndex].sizeZ=z;
    emit objectUpdated(objectList);

}
void createEnvironment::locationUndoButtonClicked(){
    objectList[currentObjectIndex].locationX=currentObject.locationX;
    objectList[currentObjectIndex].locationY=currentObject.locationY;
    objectList[currentObjectIndex].locationZ=currentObject.locationZ;



    ui->locationXspinBox->setValue(objectList[currentObjectIndex].locationX);
    ui->locationYspinBox->setValue(objectList[currentObjectIndex].locationY);
    ui->locationZspinBox->setValue(objectList[currentObjectIndex].locationZ);

}
void createEnvironment::locationResetButtonClicked(){

    objectList[currentObjectIndex].locationX=defaultObject.locationX;
    objectList[currentObjectIndex].locationY=defaultObject.locationY;
    objectList[currentObjectIndex].locationZ=defaultObject.locationZ;



    ui->locationXspinBox->setValue(objectList[currentObjectIndex].locationX);
    ui->locationYspinBox->setValue(objectList[currentObjectIndex].locationY);
    ui->locationZspinBox->setValue(objectList[currentObjectIndex].locationZ);
}
void createEnvironment::locationXspinBoxValueChanged(int x){
    objectList[currentObjectIndex].locationX=x;
    emit objectUpdated(objectList);

}
void createEnvironment::locationYspinBoxValueChanged(int y){
    objectList[currentObjectIndex].locationY=y;
    emit objectUpdated(objectList);

}
void createEnvironment::locationZspinBoxValueChanged(int z){
    objectList[currentObjectIndex].locationZ=z;
    emit objectUpdated(objectList);

}
void createEnvironment::saveDimentionButtonClicked(){

    ui->sizeXspinBox->setDisabled(true);
    ui->sizeYspinBox->setDisabled(true);
    ui->sizeZspinBox->setDisabled(true);
    ui->locationXspinBox->setDisabled(true);
    ui->locationYspinBox->setDisabled(true);
    ui->locationZspinBox->setDisabled(true);
    ui->sizeUndoButton->setDisabled(true);
    ui->sizeResetButton->setDisabled(true);
    ui->locationUndoButton->setDisabled(true);
    ui->locationResetButton->setDisabled(true);
    ui->saveDimentionButton->setDisabled(true);

    ui->listWidget->setEnabled(true);

    ui->addButton->setEnabled(true);

}
