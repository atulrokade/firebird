/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "createenvironmentopenglwindow.h"

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

createEnvironmentOpenglWindow::createEnvironmentOpenglWindow(QWidget *parent) :QGLWidget(parent)
{
    //    createEnvironment *cE;cE=new createEnvironment();
    //    createEnvironment cE;//=new createEnvironment();
    //    createEnvironment *cE=new createEnvironment();
    //    QObject qo;
    //    createEnvironment cc;
    //    QObject::connect(&cc,SIGNAL(testSignal()),this,SLOT(testSlot()));
    //    delete cE;
    //    QObject::connect(&cE,SIGNAL(objectUpdated(vector <envObjectType>)),this,SLOT(updateObject(vector <envObjectType>)));

    //    connect(&cE,&createEnvironment::objectUpdated,this,&createEnvironmentOpenglWindow::updateObject);
    setFocusPolicy(Qt::ClickFocus);
    // glutKeyboardFunc(keyboardKey);
    //glutSpecialFunc(specialKeyboard);

    envObjectType tempFloor={"_",0,0,0,0,0,0};
    objectList.push_back(tempFloor);
    floorTextureNumber=1;

    floorImage=new image();
    xRotated=25;yRotated=30;zRotated=0;zoom=1;
    xTrans=-40;yTrans=-40;zTrans=0;
}
void createEnvironmentOpenglWindow::currentObject(QString str){
    cObject=str.toStdString();
    //    cout<<cObject<<endl;
    updateGL();
}

void createEnvironmentOpenglWindow::updateObject(vector_envObjectType prmObjectList){
//    cout<<"before"<<endl;
    for(int i=0;i<objectList.size();i++){
        cout<<objectList  [i].name<<" "<<objectList[i].sizeX<<" "<<objectList[i].sizeY<<" "<<objectList[i].sizeZ<<" "<<objectList[i].locationX<<" "<<objectList[i].locationY<<" "<<objectList[i].locationZ<<endl;
    }
    if(prmObjectList.size()>0)
    if(objectList[0].name!=prmObjectList[0].name){
//        cout<<"in"<<endl;
        floorImage->name=prmObjectList[0].name;
        floorTextureNumber=floorImage->createImageTexture();
//        cout<<floorTextureNumber<<endl;
    }
    objectList=prmObjectList;
//    cout<<"after"<<endl;
        for(int i=0;i<objectList.size();i++){
            cout<<objectList  [i].name<<" "<<objectList[i].sizeX<<" "<<objectList[i].sizeY<<" "<<objectList[i].sizeZ<<" "<<objectList[i].locationX<<" "<<objectList[i].locationY<<" "<<objectList[i].locationZ<<endl;
        }
    updateGL();
}

void createEnvironmentOpenglWindow::keyPressEvent(QKeyEvent *event){
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
    case Qt::Key_A:			// a = 97
        yRotated--;
        break;
    case Qt::Key_D:
        yRotated++;
        break;

    case Qt::Key_W:
        xRotated--;
        break;
    case Qt::Key_S:
        xRotated++;
        break;

    case Qt::Key_X:
        zRotated--;
        break;
    case Qt::Key_Z:
        zRotated++;
        break;

    case Qt::Key_R:
        xRotated=20;
        yRotated=15;
        zRotated=0;
        break;
    }
    updateGL();
}
void createEnvironmentOpenglWindow::initializeGL(){
    GLfloat material_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 80 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable (GL_BLEND);
    //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 30.0 };
    GLfloat light0_position[] = { 1.0, 1.0, 1.0, 0.0 };
    //GLfloat light1_position[] = { -1.0, -1.0, -1.0, 0.0 };
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    //glLightfv(GL_LIGHT0, GL_POSITION, light1_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);



    glShadeModel(GL_SMOOTH);
    glClearColor(1,1,1,0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}
void createEnvironmentOpenglWindow::resizeGL(int width, int height){

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
    glOrtho(-194.0, 194.0, -160.0, 160.0,-5000,2000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}
void createEnvironmentOpenglWindow::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(xTrans,yTrans,zTrans);
    glScalef(zoom,zoom,zoom);
    glRotatef(xRotated,1.0,0.0,0.0); // rotation about X axis
    glRotatef(yRotated,0.0,1.0,0.0);// rotation about Y axis
    glRotatef(zRotated,0.0,0.0,1.0);  // rotation about Z axis


//    glRotatef(45,1,0,0);
//    glRotatef(45,0,1,0);
//    glTranslatef(0,-200,0);
glTranslatef(-objectList[0].sizeX/2,0,objectList[0].sizeY/2);
    for(int i=0;i<objectList.size();i++){
        if(objectList[i].name[0]=='/'){
            glColor4f(1, 1, 1,1);

            tx.enableTexture(floorTextureNumber);
            glPushMatrix();{
//
                glBegin(GL_POLYGON);
                glTexCoord2f(0,1);glNormal3f(0,1,0);glVertex3f(0,0,0);
                glTexCoord2f(1,1);glNormal3f(0,1,0);glVertex3f(objectList[i].sizeX,0,0);
                glTexCoord2f(1,0);glNormal3f(0,1,0);glVertex3f(objectList[i].sizeX,0,-objectList[i].sizeY);
                glTexCoord2f(0,0);glNormal3f(0,1,0);glVertex3f(0,0,-objectList[i].sizeY);
                glEnd();
            }glPopMatrix();

            tx.disableTexture();




        }
        else {
            if(objectList[i].name==cObject){
                glColor3f(0, 0.7f, 0.7f);
                glPushMatrix();{
                    glTranslatef(objectList[i].locationX-1,objectList[i].locationZ-1,-objectList[i].locationY+1);
                    myDrawRectangulatPrism(objectList[i].sizeX+2,objectList[i].sizeZ+2,objectList[i].sizeY+2);
                }glPopMatrix();
            }
            else{
                glColor3f(0.9f, 0.9f, 0.9f);
                glPushMatrix();{
                    glTranslatef(objectList[i].locationX,objectList[i].locationZ,-objectList[i].locationY);
                    myDrawRectangulatPrism(objectList[i].sizeX,objectList[i].sizeZ,objectList[i].sizeY);
                }glPopMatrix();
            }
        }

    }




    //    glBegin(GL_POLYGON);
    //    glVertex3f(0,0,0);
    //    glVertex3f(100,0,0);
    //    glVertex3f(100,100,0);
    //    glVertex3f(0,100,0);

    glEnd();
}
void createEnvironmentOpenglWindow::keyboardKey(unsigned char key){
    //cout<<key;
    switch(key){
    case 'A':			// a = 97
        yRotated--;
        break;
    case 'D':
        yRotated++;
        break;

    case 'W':
        xRotated--;
        break;
    case 'S':
        xRotated++;
        break;

    case 'X':
        zRotated--;
        break;
    case 'Z':
        zRotated++;
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
void createEnvironmentOpenglWindow::specialKeyboard(int key) {
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
        zoom=zoom+0.1;
        break;
    case GLUT_KEY_PAGE_DOWN:
        zoom=zoom-0.1;
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
