/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef CREATEENVIRONMENT_H
#define CREATEENVIRONMENT_H

#include <QWidget>
#include <iostream>
#include <fstream>
#include <sstream>
#include "shape.h"
#include "mydatatype.h"
#include "image.h"

using namespace std;
namespace Ui {
class createEnvironment;
}

class createEnvironment : public QWidget
{
    Q_OBJECT

    
private:
    Ui::createEnvironment *ui;



    int objectCount;
    vector_envObjectType objectList;
    string currentObjectName;
    int currentObjectIndex;
    envObjectType currentObject;
    envObjectType defaultObject;

public:

    image *floorImage;
    string environmentName;
    string floorName;
    bool editFloorFlag;
    createEnvironment(QWidget *parent = 0);
    void createNewEnvironment();
    void loadEnvironment();
    void saveEnvironment();

    int getObjectListIndex(string);
    ~createEnvironment();
    createEnvironment(int a);
    void getenvironmentName(string *&str);
    string **envn;
    int ex;
public slots:
    void currentRowChanged(int);

    void newEnvButtonClicked();
    void loadEnvButtonClicked();
    void browseButtonClicked();



    void addObjectButtonClicked();
    void editObjectButtonClicked();
    void deleteObjectButtonClicked();

    void sizeUndoButtonClicked();
    void sizeResetButtonClicked();
    void locationUndoButtonClicked();
    void locationResetButtonClicked();
    void saveDimentionButtonClicked();
    void saveButtonClicked();
    void cancelButtonClicked();
    void exitButtonClicked();

    void sizeXspinBoxValueChanged(int x);
    void sizeYspinBoxValueChanged(int y);
    void sizeZspinBoxValueChanged(int z);
    void locationXspinBoxValueChanged(int x);
    void locationYspinBoxValueChanged(int y);
    void locationZspinBoxValueChanged(int z);

signals:
    void objectUpdated(vector_envObjectType);
    void envName(string);
};

#endif // CREATEENVIRONMENT_H
