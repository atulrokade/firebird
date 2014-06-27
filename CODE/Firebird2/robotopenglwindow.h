/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef ROBOTOPENGLWINDOW_H
#define ROBOTOPENGLWINDOW_H

#include <QWidget>
#include <iostream>
#include <fstream>
#include <sstream>
#include "shape.h"

#include <QGLWidget>
#include <QtOpenGL>
#include "mydatatype.h"
#include "robot.h"
#include "texture.h"

#include <iostream>
#include <vector>
using namespace std;

class robotOpenGlWindow : public QGLWidget
{
    Q_OBJECT
public:
    robotOpenGlWindow(QWidget *parent = 0);

    texture tx;
    robot rb;
protected:
    void initializeGL();
    void resizeGL(int x, int h);
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
    void keyboardKey(unsigned char key);
    void specialKeyboard(int key);


    //We'll also need to declare the private variables :
private:
   GLfloat xRotated, yRotated, zRotated, zoom, speed;
   GLfloat xTrans, yTrans, zTrans;
   string cObject;
   vector_robotObjectType objectList;


    //As well as a pair of public methods :
public slots:
    void updateRobotObject(vector_robotObjectType prmObjectList);
    void currentObject(QString);

};

#endif // ROBOTOPENGLWINDOW_H
