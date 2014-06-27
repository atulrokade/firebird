/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "shape.h"

void myDrawRectangulatPrism(double length, double height, double width){

    if(height>0){
        glBegin(GL_POLYGON);{
//front
//            glNormal3f(0,0,0);glVertex3f(0,0,0);//1
//            glNormal3f(0,height,0);glVertex3f(0,height,0);//2
//            glNormal3f(length,height,0);glVertex3f(length,height,0);//3
//            glNormal3f(length,0,0);glVertex3f(length,0,0);//4

            glNormal3f(0,0,1);glVertex3f(0,0,0);//1
            glNormal3f(0,0,1);glVertex3f(0,height,0);//2
            glNormal3f(0,0,1);glVertex3f(length,height,0);//3
            glNormal3f(0,0,1);glVertex3f(length,0,0);//4
        }glEnd();
        glBegin(GL_POLYGON);{
//right
//            glNormal3f(length,height,0);glVertex3f(length,height,0);//3
//            glNormal3f(length,height,-width);glVertex3f(length,height,-width);//33
//            glNormal3f(length,0,-width);glVertex3f(length,0,-width);//44
//            glNormal3f(length,0,0);glVertex3f(length,0,0);//4

            glNormal3f(1,0,0);glVertex3f(length,height,0);//3
            glNormal3f(1,0,0);glVertex3f(length,height,-width);//33
            glNormal3f(1,0,0);glVertex3f(length,0,-width);//44
            glNormal3f(1,0,0);glVertex3f(length,0,0);//4
        }glEnd();
        glBegin(GL_POLYGON);{
//back
//            glNormal3f(length,0,-width);glVertex3f(length,0,-width);//44
//            glNormal3f(length,height,-width);glVertex3f(length,height,-width);//33
//            glNormal3f(0,height,-width);glVertex3f(0,height,-width);//22
//            glNormal3f(0,0,-width);glVertex3f(0,0,-width);//11

            glNormal3f(0,0,-1);glVertex3f(length,0,-width);//44
            glNormal3f(0,0,-1);glVertex3f(length,height,-width);//33
            glNormal3f(0,0,-1);glVertex3f(0,height,-width);//22
            glNormal3f(0,0,-1);glVertex3f(0,0,-width);//11
        }glEnd();
        glBegin(GL_POLYGON);{
//left

//            glNormal3f(0,0,-width);glVertex3f(0,0,-width);//11
//            glNormal3f(0,0,0);glVertex3f(0,0,0);//1
//            glNormal3f(0,height,0);glVertex3f(0,height,0);//2
//            glNormal3f(0,height,-width);glVertex3f(0,height,-width);//22

            glNormal3f(-1,0,0);glVertex3f(0,0,-width);//11
            glNormal3f(-1,0,0);glVertex3f(0,0,0);//1
            glNormal3f(-1,0,0);glVertex3f(0,height,0);//2
            glNormal3f(-1,0,0);glVertex3f(0,height,-width);//22
        }glEnd();
        glBegin(GL_POLYGON);{
//top
//            glNormal3f(0,height,0);glVertex3f(0,height,0);//2
//            glNormal3f(0,height,-width);glVertex3f(0,height,-width);//22
//            glNormal3f(length,height,-width);glVertex3f(length,height,-width);//33
//            glNormal3f(length,height,0);glVertex3f(length,height,0);//3

            glNormal3f(0,1,0);glVertex3f(0,height,0);//2
            glNormal3f(0,1,0);glVertex3f(0,height,-width);//22
            glNormal3f(0,1,0);glVertex3f(length,height,-width);//33
            glNormal3f(0,1,0);glVertex3f(length,height,0);//3
        }glEnd();
    }
    glBegin(GL_POLYGON);{

//base
//        glNormal3f(length,0,0);glVertex3f(length,0,0);//4
//        glNormal3f(length,0,-width);glVertex3f(length,0,-width);//44
//        glNormal3f(0,0,-width);glVertex3f(0,0,-width);//11
//        glNormal3f(0,0,0);glVertex3f(0,0,0);//1

        glNormal3f(0,-1,0);glVertex3f(length,0,0);//4
        glNormal3f(0,-1,0);glVertex3f(length,0,-width);//44
        glNormal3f(0,-1,0);glVertex3f(0,0,-width);//11
        glNormal3f(0,-1,0);glVertex3f(0,0,0);//1
    }glEnd();

}

void myDrawDiskWithTexture(double baseRadius, double topRadius, double height, int stacks){
    //baseRadius=0;topRadius=0;height=0;stacks=0;angle=0;

    double increment=360/(float)stacks;

    double xTop = topRadius, yTop = 0, pxTop = topRadius, pyTop = 0;
    //    double xBase = baseRadius, yBase = 0, pxBase = baseRadius, pyBase = 0;

    if(topRadius>0){
    glBegin(GL_POLYGON);{
        glTexCoord2f((topRadius + xTop) / (2*topRadius), 1 - (topRadius + yTop) / (2*topRadius));
        glNormal3f(0,0, -1); //center//1
        glVertex3f(xTop, yTop, 0);
        for (int i = 1; i <= stacks+1; i ++) {
            if (i==stacks+1) {
                xTop = topRadius;
                yTop = 0;
            } else {
                xTop = topRadius * cos(i*increment * 0.01745);
                yTop = topRadius * sin(i*increment * 0.01745);
            }

            glTexCoord2f((topRadius + xTop) / (2*topRadius), 1 - (topRadius + yTop) / (2*topRadius));
            glNormal3f(0,0, -1); //center//1
            glVertex3f(xTop, yTop, 0);
        }
    }glEnd();
    }
    double xBase = baseRadius, yBase = 0, pxBase = baseRadius, pyBase = 0;
    if(baseRadius>0){
        glBegin(GL_POLYGON);{

            glTexCoord2f((baseRadius + xBase) / (2*baseRadius), 1 - (baseRadius + yBase) / (2*baseRadius));
            //            glNormal3f(xBase, yBase, height); //center//1
            glNormal3f(0,0,1); //center//1
            glVertex3f(xBase, yBase, height);
            for (int i = stacks+1; i >=1; i --) {
                if (i==stacks+1) {
                    xBase = baseRadius;
                    yBase = 0;
                } else {
                    xBase = baseRadius * cos(i*increment * 0.01745);
                    yBase = baseRadius * sin(i*increment * 0.01745);
                }

                glTexCoord2f((baseRadius + xBase) / (2*baseRadius), 1 - (baseRadius + yBase) / (2*baseRadius));
//                glNormal3f(xBase,yBase, height); //center//1
                glNormal3f(0,0,1); //center//1
                glVertex3f(xBase, yBase, height);
            }
        }glEnd();
    }
    xTop = baseRadius; yTop = 0; pxTop = baseRadius; pyTop = 0;
    xBase = topRadius; yBase = 0; pxBase = topRadius; pyBase = 0;

    if(height>0){
        for (int i = 1; i <= stacks+1; i ++) {
            pxTop = xTop;
            pyTop = yTop;

            pxBase = xBase;
            pyBase = yBase;
            if (i==stacks+1) {
                xTop = baseRadius;
                yTop = 0;

                xBase = topRadius;
                yBase = 0;
            } else {
                xTop = baseRadius * cos(i*increment * 0.01745);
                yTop = baseRadius * sin(i*increment * 0.01745);

                xBase = topRadius * cos(i*increment * 0.01745);
                yBase = topRadius * sin(i*increment * 0.01745);
            }

            glBegin(GL_POLYGON);
            ////glBegin(GL_LINES);
            glNormal3f(pxBase, pyBase, 0);
            glVertex3f(pxBase, pyBase, 0);
            glNormal3f(xBase, yBase, 0);
            glVertex3f(xBase, yBase, 0);
            glNormal3f(xTop, yTop, height);
            glVertex3f(xTop, yTop, height);
            glNormal3f(pxTop, pyTop, height);
            glVertex3f(pxTop, pyTop, height);

            glEnd();
        }
    }

}

void myDrawDisk(double baseRadius, double topRadius, double height, int stacks){
    //baseRadius=0;topRadius=0;height=0;stacks=0;angle=0;

    double increment=360/(float)stacks;

    double xTop = topRadius, yTop = 0, pxTop = topRadius, pyTop = 0;
    //    double xBase = baseRadius, yBase = 0, pxBase = baseRadius, pyBase = 0;

    if(topRadius>0){
    glBegin(GL_POLYGON);{
//        glTexCoord2f((topRadius + xTop) / (2*topRadius), 1 - (topRadius + yTop) / (2*topRadius));
//        glNormal3f(xTop, yTop, 0); //center//1
        glNormal3f(0, 0, -1);
        glVertex3f(xTop, yTop, 0);
        for (int i = 1; i <= stacks+1; i ++) {
            if (i==stacks+1) {
                xTop = topRadius;
                yTop = 0;
            } else {
                xTop = topRadius * cos(i*increment * 0.01745);
                yTop = topRadius * sin(i*increment * 0.01745);
            }

//            glTexCoord2f((topRadius + xTop) / (2*topRadius), 1 - (topRadius + yTop) / (2*topRadius));
//            glNormal3f(xTop, yTop, 0); //center//1
            glNormal3f(0, 0, -1);
            glVertex3f(xTop, yTop, 0);
        }
    }glEnd();
    }
    double xBase = baseRadius, yBase = 0, pxBase = baseRadius, pyBase = 0;
    if(baseRadius>0){
        glBegin(GL_POLYGON);{

//            glTexCoord2f((baseRadius + xBase) / (2*baseRadius), 1 - (baseRadius + yBase) / (2*baseRadius));
//            glNormal3f(xBase, yBase, height); //center//1
            glNormal3f(0, 0, 1);
            glVertex3f(xBase, yBase, height);
            for (int i = stacks+1; i >=1; i --) {
                if (i==stacks+1) {
                    xBase = baseRadius;
                    yBase = 0;
                } else {
                    xBase = baseRadius * cos(i*increment * 0.01745);
                    yBase = baseRadius * sin(i*increment * 0.01745);
                }

//                glTexCoord2f((baseRadius + xBase) / (2*baseRadius), 1 - (baseRadius + yBase) / (2*baseRadius));
//                glNormal3f(xBase,yBase, height); //center//1
                glNormal3f(0, 0, 1);
                glVertex3f(xBase, yBase, height);
            }
        }glEnd();
    }
    xTop = baseRadius; yTop = 0; pxTop = baseRadius; pyTop = 0;
    xBase = topRadius; yBase = 0; pxBase = topRadius; pyBase = 0;

    if(height>0){
        for (int i = 1; i <= stacks+1; i ++) {
            pxTop = xTop;
            pyTop = yTop;

            pxBase = xBase;
            pyBase = yBase;
            if (i==stacks+1) {
                xTop = baseRadius;
                yTop = 0;

                xBase = topRadius;
                yBase = 0;
            } else {
                xTop = baseRadius * cos(i*increment * 0.01745);
                yTop = baseRadius * sin(i*increment * 0.01745);

                xBase = topRadius * cos(i*increment * 0.01745);
                yBase = topRadius * sin(i*increment * 0.01745);
            }

            glBegin(GL_POLYGON);
            ////glBegin(GL_LINES);
            glNormal3f(pxBase, pyBase, 0);
            glVertex3f(pxBase, pyBase, 0);
            glNormal3f(xBase, yBase, 0);
            glVertex3f(xBase, yBase, 0);
            glNormal3f(xTop, yTop, height);
            glVertex3f(xTop, yTop, height);
            glNormal3f(pxTop, pyTop, height);
            glVertex3f(pxTop, pyTop, height);

            glEnd();
        }
    }

}

void myDrawCylinder(double baseRadius, double topRadius, double height, int stacks, double angle){
    //baseRadius=0;topRadius=0;height=0;stacks=0;angle=0;
    double xTop = topRadius, yTop = 0, pxTop = topRadius, pyTop = 0;
    double xBase = baseRadius, yBase = 0, pxBase = baseRadius, pyBase = 0;

    double increment=angle/(float)stacks;
    for (int i = 1; i <= stacks+1; i ++) {
        pxTop = xTop;
        pyTop = yTop;

        pxBase = xBase;
        pyBase = yBase;
        if (i==stacks+1) {
            xTop = topRadius;
            yTop = 0;

            xBase = baseRadius;
            yBase = 0;
        } else {
            xTop = topRadius * cos(i*increment * 0.01745);
            yTop = topRadius * sin(i*increment * 0.01745);

            xBase = baseRadius * cos(i*increment * 0.01745);
            yBase = baseRadius * sin(i*increment * 0.01745);
        }
        glBegin (GL_TRIANGLES);
        //glBegin(GL_LINES);
        glNormal3f(0, 0, height); //center//1
        glVertex3f(0, 0, height);
        glNormal3f(xTop, yTop, height); //3
        glVertex3f(xTop, yTop, height); //3
        glNormal3f(pxTop, pyTop, height); //2
        glVertex3f(pxTop, pyTop, height); //2




        glNormal3f(0, 0, 0); //center//1
        glVertex3f(0, 0, 0); //center//1
        glNormal3f(pxBase, pyBase, 0); //102
        glVertex3f(pxBase, pyBase, 0); //102
        glNormal3f(xBase, yBase, 0); //103
        glVertex3f(xBase, yBase, 0); //103
        /**/    glEnd();

        glBegin(GL_POLYGON);
        ////glBegin(GL_LINES);
        glNormal3f(pxBase, pyBase, 0);
        glVertex3f(pxBase, pyBase, 0);
        glNormal3f(xBase, yBase, 0);
        glVertex3f(xBase, yBase, 0);
        glNormal3f(xTop, yTop, height);
        glVertex3f(xTop, yTop, height);
        glNormal3f(pxTop, pyTop, height);
        glVertex3f(pxTop, pyTop, height);

        glEnd();
    }


}

void myDrawRing(double baseInnerRadius,double topInnerRadius,double baseOuterRadius,double topOuterRadius, double height, int stacks, double angle){
    //baseRadius=0;topRadius=0;height=0;stacks=0;angle=0;
    double xInnerTop = topInnerRadius, yInnerTop = 0, pxInnerTop = topInnerRadius, pyInnerTop = 0;
    double xInnerBase = baseInnerRadius, yInnerBase = 0, pxInnerBase = baseInnerRadius, pyInnerBase = 0;
    double xOuterTop = topOuterRadius, yOuterTop = 0, pxOuterTop = topOuterRadius, pyOuterTop = 0;
    double xOuterBase = baseOuterRadius, yOuterBase = 0, pxOuterBase = baseOuterRadius, pyOuterBase = 0;

    double increment=angle/(float)stacks;
    for (int i = 0; i <= stacks+1; i ++) {
        pxInnerTop = xInnerTop;
        pyInnerTop = yInnerTop;

        pxInnerBase = xInnerBase;
        pyInnerBase = yInnerBase;

        pxOuterTop = xOuterTop;
        pyOuterTop = yOuterTop;

        pxOuterBase = xOuterBase;
        pyOuterBase = yOuterBase;


        xInnerTop = topInnerRadius * cos(i*increment * 0.01745);
        yInnerTop = topInnerRadius * sin(i*increment * 0.01745);

        xInnerBase = baseInnerRadius * cos(i*increment * 0.01745);
        yInnerBase = baseInnerRadius * sin(i*increment * 0.01745);

        xOuterTop = topOuterRadius * cos(i*increment * 0.01745);
        yOuterTop = topOuterRadius * sin(i*increment * 0.01745);

        xOuterBase = baseOuterRadius * cos(i*increment * 0.01745);
        yOuterBase = baseOuterRadius * sin(i*increment * 0.01745);

        glBegin(GL_QUADS);

        if(angle!=360 && i==0){

            glNormal3f(pxInnerTop,pyInnerTop,height);
            glVertex3f(pxInnerTop,pyInnerTop,height);
            glNormal3f(pxOuterTop,pyOuterTop,height);
            glVertex3f(pxOuterTop,pyOuterTop,height);
            glNormal3f(pxOuterBase,pyOuterBase,0);
            glVertex3f(pxOuterBase,pyOuterBase,0);
            glNormal3f(pxInnerBase,pyInnerBase,0);
            glVertex3f(pxInnerBase,pyInnerBase,0);
        }
        if(angle!=360 && i==stacks+1){

            glNormal3f(pxOuterTop,pyOuterTop,height);
            glVertex3f(pxOuterTop,pyOuterTop,height);
            glNormal3f(pxInnerTop,pyInnerTop,height);
            glVertex3f(pxInnerTop,pyInnerTop,height);
            glNormal3f(pxInnerBase,pyInnerBase,0);
            glVertex3f(pxInnerBase,pyInnerBase,0);
            glNormal3f(pxOuterBase,pyOuterBase,0);
            glVertex3f(pxOuterBase,pyOuterBase,0);

        }
        else{
            glNormal3f(pxInnerTop,pyInnerTop,height);
            glVertex3f(pxInnerTop,pyInnerTop,height);
            glNormal3f(xInnerTop,yInnerTop,height);
            glVertex3f(xInnerTop,yInnerTop,height);
            glNormal3f(xOuterTop,yOuterTop,height);
            glVertex3f(xOuterTop,yOuterTop,height);
            glNormal3f(pxOuterTop,pyOuterTop,height);
            glVertex3f(pxOuterTop,pyOuterTop,height);

            glNormal3f(pxOuterBase,pyOuterBase,0);
            glVertex3f(pxOuterBase,pyOuterBase,0);
            glNormal3f(xOuterBase,yOuterBase,0);
            glVertex3f(xOuterBase,yOuterBase,0);
            glNormal3f(xInnerBase,yInnerBase,0);
            glVertex3f(xInnerBase,yInnerBase,0);
            glNormal3f(pxInnerBase,pyInnerBase,0);
            glVertex3f(pxInnerBase,pyInnerBase,0);


            glNormal3f(pxOuterTop,pyOuterTop,height);
            glVertex3f(pxOuterTop,pyOuterTop,height);
            glNormal3f(xOuterTop,yOuterTop,height);
            glVertex3f(xOuterTop,yOuterTop,height);
            glNormal3f(xOuterBase,yOuterBase,0);
            glVertex3f(xOuterBase,yOuterBase,0);
            glNormal3f(pxOuterBase,pyOuterBase,0);
            glVertex3f(pxOuterBase,pyOuterBase,0);

            glNormal3f(pxInnerBase,pyInnerBase,0);
            glVertex3f(pxInnerBase,pyInnerBase,0);
            glNormal3f(xInnerBase,yInnerBase,0);
            glVertex3f(xInnerBase,yInnerBase,0);
            glNormal3f(xInnerTop,yInnerTop,height);
            glVertex3f(xInnerTop,yInnerTop,height);
            glNormal3f(pxInnerTop,pyInnerTop,height);
            glVertex3f(pxInnerTop,pyInnerTop,height);
        }
        glEnd();
    }
}

/*
void drawTroughts(){
    GLfloat tl;
    tl=(greenHouseLength/(troughtsColums+2));
    GLfloat tb;
    tb=(greenHouseBreadth/(troughtsRows*1.5+1));
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

//void drawGreenHouse(){}


*/

