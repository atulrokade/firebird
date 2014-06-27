/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "robotopenglwindow.h"

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

robotOpenGlWindow::robotOpenGlWindow(QWidget *parent) :QGLWidget(parent)
{
    setFocusPolicy(Qt::ClickFocus);
    xRotated=15;yRotated=208;zRotated=0;zoom=1;
    xTrans=-40;yTrans=-40;zTrans=0;


}
void robotOpenGlWindow::currentObject(QString str){
    cObject=str.toStdString();
    if(cObject=="Chassis"){
        xRotated=15;yRotated=208;zRotated=0;zoom=1;
        xTrans=-40;yTrans=-40;zTrans=0;
    }
    else if(cObject=="Motors"){
        xRotated=15;yRotated=338;zRotated=0;zoom=1;
        xTrans=-20;yTrans=-40;zTrans=0;
    }
    else if(cObject=="Line_Sensors"){
        xRotated=15;yRotated=208;zRotated=0;zoom=1;
        xTrans=-40;yTrans=-40;zTrans=0;
    }
    else if(cObject=="IR_Proximity_Sensors"){
        xRotated=15;yRotated=208;zRotated=0;zoom=1;
        xTrans=-40;yTrans=-40;zTrans=0;
    }
    else if(cObject=="IR_Distance_Sensors"){
        xRotated=15;yRotated=208;zRotated=0;zoom=1;
        xTrans=-40;yTrans=-40;zTrans=0;
    }
    else if(cObject=="Sonar_Sensors"){
        xRotated=15;yRotated=208;zRotated=0;zoom=1;
        xTrans=-40;yTrans=-40;zTrans=0;
    }
    updateGL();
}

void robotOpenGlWindow::updateRobotObject(vector_robotObjectType prmObjectList){
    objectList=prmObjectList;
//            cout<<"received-----------------------------------"<<endl;
//            for(int i=0;i<objectList.size();i++){
//                cout<<objectList  [i].name<<" "<<objectList[i].distance<<" "<<objectList[i].count<<endl;
//            }
    updateGL();
}

void robotOpenGlWindow::keyPressEvent(QKeyEvent *event){
    char ch= event->key();
    switch(event->key()){
    case Qt::Key_Escape:
        exit(0);
        break;
    case Qt::Key_PageUp:
        zoom+=0.1;
        break;
    case Qt::Key_PageDown:
        zoom-=0.1;
        break;
    case Qt::Key_End:
        zoom=1;
        break;
    case Qt::Key_Right:
        xTrans+=5;
        break;
    case Qt::Key_Left:
        xTrans-=5;
        break;
    case Qt::Key_Up:
        yTrans+=5;
        break;
    case Qt::Key_Down:
        yTrans-=5;
        break;

    }

    keyboardKey(ch);
    updateGL();
}
void robotOpenGlWindow::initializeGL(){

    //    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ACCUM | GLUT_DEPTH);

    const char* file_name[] = { "top1.png","top1.ppm"};
    tx.textureInitialisation(file_name,  1);

    GLfloat material_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 100 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable (GL_BLEND);
    //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    //    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //    GLfloat mat_shininess[] = { 30.0 };
    GLfloat light0_position[] = { 1000.0, 1000.0, 1000.0, 0.0 };
    GLfloat light1_position[] = { 10000.0, 10000.0, 10000.0, 0.0 };
    GLfloat light2_position[] = { -1000.0, 1000.0, 1000.0, 0.0 };
    GLfloat light3_position[] = { 1000.0, 1000.0, -1000.0, 0.0 };

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    //    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
    glLightfv(GL_LIGHT3, GL_POSITION, light3_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);



    glShadeModel(GL_SMOOTH);
    glClearColor(1,1,1,0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    //    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}
void robotOpenGlWindow::resizeGL(int width, int height){

    double xMin = 0, xMax = 10, yMin = 0, yMax = 10;
    glViewport(0,0,(GLint)width, (GLint)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D            (-1,1,-1,1);
    if (width > height){
        height = height?height:1;
        double newWidth = (xMax - xMin) * width / height;
        double difWidth = newWidth - (xMax - xMin);
        xMin = 0.0 + difWidth / 2.0;
        xMax = 10 + difWidth / 2.0;
    } else {
        width = width?width:1;
        double newHeight = (yMax - yMin) * width / height;
        double difHeight = newHeight - (yMax - yMin);
        yMin = 0.0 + difHeight / 2.0;
        yMax = 10 + difHeight / 2.0;
    }
    //gluOrtho2D(xMin, xMax, yMin, yMax);
    glOrtho(-194.0, 194.0, -160.0, 160.0,-500,2000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}
void robotOpenGlWindow::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(xTrans,yTrans,zTrans);
    glScalef(zoom,zoom,zoom);
    glRotatef(xRotated,1.0,0.0,0.0); // rotation about X axis
    glRotatef(yRotated,0.0,1.0,0.0);// rotation about Y axis
    glRotatef(zRotated,0.0,0.0,1.0);  // rotation about Z axis

//    cout<<xRotated<<" "<<yRotated<<" "<<zRotated<<endl;


//    glPushMatrix();{
//        //        glTranslatef(-50,-50,0);
//        tx.enableTexture(textureNum[0]);        {
//            rb.drawRobot(1,50,50);
//        }
//        tx.disableTexture();
//    }glPopMatrix();


    glTranslatef(0,32,0);
    glPushMatrix();{
        for(int i=0;i<objectList.size();i++){
            if(objectList[i].name=="Chassis"){
                tx.enableTexture(1);
                rb.drawChassis();
                tx.disableTexture();
            }
            else if(objectList[i].name=="Motors"){
                rb.mototDistance=objectList[i].distance;
                rb.drawMotors();
            }
            else if(objectList[i].name=="Line_Sensors"){
                rb.lineSensorDistance=objectList[i].distance;
                rb.lineSensorCount=objectList[i].count;
                rb.drawLineSensors();
            }
            else if(objectList[i].name=="IR_Proximity_Sensors"){
                rb.drawIRProximitySensors();
            }
            else if(objectList[i].name=="IR_Distance_Sensors"){
                rb.drawIRDistanceSensors();
            }
            else if(objectList[i].name=="Sonar_Sensors"){
                rb.drawSonarSensors();
            }

        }
    }glPopMatrix();

}
void robotOpenGlWindow::keyboardKey(unsigned char key){
    //cout<<key;
    switch(key){
    case 'A':			// a = 97
        yRotated-=5;
        break;
    case 'D':
        yRotated+=5;
        break;

    case 'W':
        xRotated-=5;
        break;
    case 'S':
        xRotated+=5;
        break;

    case 'X':
        zRotated-=5;
        break;
    case 'Z':
        zRotated+=5;
        break;

    case 'R':
        xRotated=20;
        yRotated=15;
        zRotated=0;
        break;
    case 27:
        exit(0);
        break;

    case Qt::Key_Escape:
        exit(0);
        break;
    }

}
void robotOpenGlWindow::specialKeyboard(int key) {
    /*
     *
     *
     * 	GLUT_KEY_F1
     GLUT_KEY_LEFT
     GLUT_KEY_UP
     GLUT_KEY_RIGHT
     GLUT_KEY_DOWN
     GLUT_KEY_PAGE_UP
     GLUT_KEY_PAGE_DOWN
     GLUT_KEY_HOME
     GLUT_KEY_END
     GLUT_KEY_INSERT
     */


    switch (key) {
    case GLUT_KEY_PAGE_UP:
        zoom+=0.1;
        break;
    case GLUT_KEY_PAGE_DOWN:
        zoom-=0.1;
        break;
    case GLUT_KEY_END:
        zoom=1;
        break;
    case GLUT_KEY_UP:
        speed-=20;
        break;
    case GLUT_KEY_DOWN:
        speed+=20;
        break;


    }
}
