#include "greenHouse.h"
void drawTroughts(){
    GLfloat tl=(greenHouseLength/(troughtsColums+2));
    GLfloat tb=(greenHouseBreadth/(troughtsRows*1.5+1));
    glColor3f(0,0,0);
    glBegin(GL_QUADS);{
        //front
        glNormal3f(0,0,0);glVertex3f(0,0,0);//1
        glNormal3f(0,30,0);glVertex3f(0,30,0);//2
        glNormal3f(tl*troughtsColums,30,0);glVertex3f(tl*troughtsColums,30,0);//3
        glNormal3f(tl*troughtsColums,0,0);glVertex3f(tl*troughtsColums,0,0);//4

        //right side
        glNormal3f(tl*troughtsColums,30,0);glVertex3f(tl*troughtsColums,30,0);//3
        glNormal3f(tl*troughtsColums,30,-tb);glVertex3f(tl*troughtsColums,30,-tb);//5
        glNormal3f(tl*troughtsColums,0,-tb);glVertex3f(tl*troughtsColums,0,-tb);//6
        glNormal3f(tl*troughtsColums,0,0);glVertex3f(tl*troughtsColums,0,0);//4

        //back
        glNormal3f(tl*troughtsColums,30,-tb);glVertex3f(tl*troughtsColums,30,-tb);//5
        glNormal3f(0,30,-tb);glVertex3f(0,30,-tb);//7
        glNormal3f(0,0,-tb);glVertex3f(0,0,-tb);//8
        glNormal3f(tl*troughtsColums,0,-tb);glVertex3f(tl*troughtsColums,0,-tb);//6

        //left
        glNormal3f(0,30,-tb);glVertex3f(0,30,-tb);//7
        glNormal3f(0,30,0);glVertex3f(0,30,0);//2
        glNormal3f(0,0,0);glVertex3f(0,0,0);//1
        glNormal3f(0,0,-tb);glVertex3f(0,0,-tb);//8


    }glEnd();


}

void drawGreenHouse(){

}


