/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef ROBOTWINDOW_H
#define ROBOTWINDOW_H

#include <QWidget>
#include <iostream>
#include <vector>
#include "mydatatype.h"
#include <QTimer>
using namespace std;
namespace Ui {
class robotWindow;
}

class robotWindow : public QWidget
{
    Q_OBJECT

private:
    Ui::robotWindow *ui;
    QTimer *timer;


    vector_robotObjectType objectList;
    string currentObjectName;
    int currentObjectIndex;

public:
    robotWindow(QWidget *parent = 0);
    ~robotWindow();
    robotWindow(int a);
    string robotName;
    int getObjectListIndex(string objName);
    void createNewRobot();
    void loadRobot();
    void saveRobot();
    void startTimer();
    int count;


public slots:
    void timerSlot();
    void newRobotButtonClicked();
    void loadRobotButtonClicked();

    void addMotorButtonClicked();
    void addLineSensorButtonClicked();
    void addIRPSensorButtonClicked();
    void addIRDSensorButtonClicked();
    void addSonarSensorButtonClicked();

    void editButtonClicked();
    void deleteButtonClicked();
    void saveButtonClicked();

    void saveRobotButtonClicked();
    void cancelButtonClicked();
    void exitButtonClicked();

    void currentRowChanged(int row);

    void distanceSpinBoxValueChanged(int d);
    void countSpinBoxValueChanged(int c);

signals:
    void robotObjectUpdated(vector_robotObjectType);
    void roboName(string);

};

#endif // ROBOTWINDOW_H
