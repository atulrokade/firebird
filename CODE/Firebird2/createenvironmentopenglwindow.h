/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef CREATEENVIRONMENTOPENGLWINDOW_H
#define CREATEENVIRONMENTOPENGLWINDOW_H

#include <QGLWidget>
#include <QtOpenGL>
#include "mydatatype.h"
#include "createenvironment.h"
#include "texture.h"
class createEnvironmentOpenglWindow : public QGLWidget
{
    Q_OBJECT
public:
    createEnvironmentOpenglWindow(QWidget *parent = 0);
    image *floorImage;
    int floorTextureNumber;
    texture tx;

//    createEnvironment *cE;


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
   vector_envObjectType objectList;


    //As well as a pair of public methods :
public slots:
    void updateObject(vector_envObjectType prmObjectList);
    void currentObject(QString);
    
};

#endif // CREATEENVIRONMENTOPENGLWINDOW_H
