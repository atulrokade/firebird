/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef MAINOPENGLWINDOW2_H
#define MAINOPENGLWINDOW2_H

#include <QGLWidget>
#include <QtOpenGL>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <QTimer>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "shape.h"
#include "mydatatype.h"
#include "image.h"
#include "texture.h"
#include "robot.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h> //write
#include "communicate.h"
using namespace std;
class mainOpenglWindow2 : public QGLWidget
{
    Q_OBJECT
private:
   GLfloat xRotated, yRotated, zRotated, zoom, speed;
   GLfloat xTrans, yTrans, zTrans;
   robotLocation robotInit,robotCurrent,robotPrev;
   robotParameter robotPrm;
   point *lineSensors;
   point *irProximitySensors;
   point *irDistanceSensors;
   point *sonarSensors;

   string command,motionCommand;
   vector<string> arguments;
   point axis;


   int portNumber;
   vector_envObjectType envObjectList;
   vector_robotObjectType robotObjectList;
   image *floorImg;
   int floorTextureNumber,robotTextureNumber;
   texture tx;
   robot rb;
   bool envFlag,robotFlag;
   //sensor status

   bool lineSensorStatus,irProximitySensorsStatus,irDistanceSensorStatus,sonarSensorSatus;
//socket programming-----------------------------------------------------------------------------
   int socket_desc , client_sock , c , read_size;
   struct sockaddr_in server , client;
   char client_message[100],msg[100];
//-----------------------------------------------------------------------------
public:
    mainOpenglWindow2(QWidget *parent = 0);
    void send(string str);
    communicate *cm;
    QTimer *readCommandTimer;

    void mRead();
    void mWrite();
    void sRead();
    void sWrite();
    void semRead();
    void semWrite();
    void readCommand();
    void writeCommand();
    void writeResult();
    ofstream fout;
    ifstream fin;
    fstream fshare;
    fstream fsem;
    int sSignal;
    int semaphore;
    int prvmSignal,mSignal;
    string inputString,results;


    void calcSensorsLocation();
    void calcLineSensorsValues();
    void calcIRProximitySensorsValues();
    void calcIRDistanceSensorsValues();
    void calcSonarSensorsValues();


protected:
    void initializeGL();
    void resizeGL(int x, int h);
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
    void drawEnv();
    void drawRobot();
signals:


public slots:
    void getEnvName(string strPrm);
    void getRobotName(string strPrm);
    void getPortNumber(int portnum);
    void updateRobotLocation(robotLocation r);
    void start();
    void reset();
    void receive();

    void forward();
    void backward();
    void right();
    void left();
    void stop();
    void stops();
    void setVelocityLeft(double v);
    void setVelocityRight(double v);
    void setVelocity(double v);
    void move();
};

#endif // MAINOPENGLWINDOW2_H
