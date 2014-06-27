/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef MYOPENGLWINDOW_H
#define MYOPENGLWINDOW_H
#include "dialog.h"

#include "createenvironment.h"
#include "robotwindow.h"
#include <QGLWidget>
#include <QtOpenGL>
#include <QLineEdit>
#include <QTimer>
#include "iostream"
#include "string.h"
#include "fstream"
#include "vector"

#include "shape.h"
#include "greenhouse.h"
#include "mainwindow.h"
#include "robot.h"
//#include "texture.h"
using namespace std;
class MyOpenGLWindow : public QGLWidget
{
    Q_OBJECT
public:
    MyOpenGLWindow(QWidget *parent = 0);
    greenHouse *g;
    robot *rb;

    createEnvironment *ce;
    robotWindow *cr;
protected:
    void initializeGL();
    void resizeGL(int x, int h);
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
    void keyboardKey(unsigned char key);
    void specialKeyboard(int key);

    void myRotate(GLfloat angle,GLfloat X,GLfloat Y, GLfloat Z,GLfloat co_X,GLfloat co_Y, GLfloat co_Z  );

    void drawBitmap(int n);



private:

//    Dialog d;
    int caseStudy;
    double xt,yt;
    double xRotated, yRotated, zRotated, zoom, leftSpeed,rightSpeed;
    double trans,angle;
    int stop;
    int forwardTrans,backwardTrans,rightAngle,leftAngle;
    int n_forwardTrans,n_backwardTrans,n_rightAngle,n_leftAngle;
    double x,y,z;
    double co_X, co_Y, co_Z;
    double prev_co_X, prev_co_Y, prev_co_Z,prev_angle;
    double velocityLeft,velocityRight,time;
    double distanceLeft,distanceRight;
    double angleStep;
    double robot_x,robot_y,robot_z,robot_angle;
    int ix,iy;
    int rR,rC,rD;
    double robotScale;

    int rows,columns,ghlength,ghbreadth,ghheight;

    bool lineSensorStatus;
    double leftLineSensorX,leftLineSensorY,rightLineSensorX,rightLineSensorY,middleLineSensorX,middleLineSensorY;
    double leftleftLineSensorX,leftleftLineSensorY,rightrightLineSensorX,rightrightLineSensorY;
    bool irDistanceSensorStatus;
    bool irProximitySensorStatus;
    int *lineSensor;
    double *irDistanceSensor;
    int *irProximitySensor;

    double **object2;
    int object2Count;
    double **object3;
    int object3Count;

    bool startFlag;
    ofstream fout;
    ifstream fin;
    fstream fshare;
    fstream fsem;
    int sSignal;
    int semaphore;
    int prvmSignal,mSignal;
    string inputString,command,motionCommand,result;
    vector<string> arguments;

    QTimer *timer;



    GLuint *textureNum;
//    texture tx;

signals:
    void releasedRun();
    void printCommand(QString);
    
public slots:

    void getEnvName1(string str);
    void getRobotName(string);

    void mRead();
    void mWrite();
    void sRead();
    void sWrite();
    void semRead();
    void semWrite();
    void readCommand();
    void writeCommand();
    void writeResult();

    void lcdPrint(string);

    void SetLeftMotorVelocity(string);
    void SetRightMotorVelocity(string);
    void SetVelocity(string,string);

    string GetLeftMotorVelocity();
    string GetRightMotorVelocity();
    string GetVelocity();

    void run();
    void run1();

    void forward();
    void backward();
    void right();
    void left();
    void stops();

    void forwardTranslate(int translate);
    void backwardTranslate(int translate);
    void rightTurn(int turn);
    void leftTurn(int turn);
    void reset();

    void setVelocityLeft(double v);
    void setVelocityRight(double v);
    void setTime(double t);
    void start();

    void setTroughtRow(int r);
    void setTroughtColumn(int c);
    void goToTrought();

    void calclineSensorCoOrdinate(double angle_,double x_,double y_);
    int getlineSensorArray();
    string getlineSensorValues();
    void setLineSensorStatus(string str);
    string getLineSensorStatus();

    int getIRProximitySensor(int sNo,double xParam,double yParam, double angleParam);
    void setIRProximitySensorStatus(string str);
    string getIRProximitySensorStatus();
    string getIRProximitySensorValues();


    int getIRDistanceSensor(int sNo,double xParam,double yParam, double angleParam);
    void setIRDistanceSensorStatus(string str);
    string getIRDistanceSensorStatus();
    string getIRDistanceSensorValues();

    void printObject2s();
    int isInsideObject(double x_,double y_);

    void setCommand(QString qstr);

    void setLineFollowerCaseStudy();
    void setGreenHouseCaseStudy();
    void setMazeSolverCaseStudy();
    void setParts();


};

#endif // MYOPENGLWINDOW_H
