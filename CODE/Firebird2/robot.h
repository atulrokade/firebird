/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */


#ifndef ROBOT_H
#define ROBOT_H
#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "shape.h"
class robot
{
    float scale;
    double leftSpeed,rightSpeed;
public:
    int mototDistance;
    int lineSensorDistance,lineSensorCount;
    int irProximitySensorCount;
    int irDistanceSensorCount;
    robot();
    robot(float s);
    void drawRobot(float s, double leftSpeed_prm, double rightSpeed_prm);

    void drawChassis();
    void drawMotors();

    void drawMotor(int velocity);
    void drawWheel();
    void drawClamp();
    void drawBottomDisk(double height);

    void drawLineSensors();
    void drawLineSensor();

    void drawIRProximitySensors();
    void drawIRProximitySensor();
    void drawIRDistanceSensors();
    void drawIRDistanceSensor();
    void drawSonarSensors();
    void drawSonarSensor();


};

#endif // ROBOT_H
