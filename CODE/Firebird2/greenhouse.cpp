/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "greenhouse.h"

greenHouse::greenHouse(){
    troughtsRows=8;
    troughtsColums=10;
    greenHouseLength=600;
    greenHouseBreadth=300;
    greenHouseHeight=600;

//    floor = new int*[(int)troughtsRows];
//    for(int i = 0; i < troughtsRows; i++)
//        floor[i] = new int[(int)troughtsColums];

//    for(int i = 0; i < troughtsRows; i++)
//        for(int j = 0; j < troughtsColums; j++)
//            floor[i][j]=0;

    tl=(greenHouseLength/(troughtsColums+2));
    tb=(greenHouseBreadth/(troughtsRows*1.5+1));

    //    floorImageCanvas=cvLoadImage("linefollowerfloor.jpg");
    //    floorImage=new char[100];
    //    floorImage="greenhousefloor.jpg";
    //    floorImageCanvas=cvLoadImage("greenhousefloor.jpg");

}
greenHouse::greenHouse(int greenHouseL,int greenHouseB,int greenHouseH,int troughtsRow,int troughtsColum){

    troughtsRows=troughtsRow;
    troughtsColums=troughtsColum;
    greenHouseLength=greenHouseL;
    greenHouseBreadth=greenHouseB;
    greenHouseHeight=greenHouseH;

//    floor = new int*[(int)(troughtsRows*1.5+1)];
//    for(int i = 0; i < (troughtsRows*1.5+1); i++)
//        floor[i] = new int[(int)troughtsColums+2];

//    for(int i = 0; i < (troughtsRows*1.5+1); i++)
//        for(int j = 0; j < troughtsColums+2; j++)
//            floor[i][j]=0;



    tl=(greenHouseLength/(troughtsColums+2));
    tb=(greenHouseBreadth/(troughtsRows*1.5+1));


    //    floorImageCanvas=cvLoadImage("linefollowerfloor.jpg");
    string floorImage="greenhousefloor.jpg";
//    floorImageCanvas=cvLoadImage(floorImage.c_str());

}
void greenHouse::setFloorImage(string str){
//    floorImageCanvas=cvLoadImage(str.c_str());
}

greenHouse::~greenHouse(){
//    for(int i = 0; i < (troughtsRows*1.5+1); i++)
//    {
//        delete[] floor[i];
//    }

//    delete[] floor;

}
void greenHouse::initFloor(){
//    for(int i = 0; i < (troughtsRows*1.5+1); i++){

//        for(int j = 0; j < troughtsColums+2; j++){
//            if(i%3==0 || j==0 || j==(int)troughtsColums+1)
//                floor[i][j]=0;
//            else
//                floor[i][j]=1;
//        }
//    }

}

void greenHouse::printFloor(){
//    cout<<endl<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
//    for(int i = 0; i < (troughtsRows*1.5+1); i++){
//        for(int j = 0; j < troughtsColums+2; j++){
//            cout<<floor[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}
void greenHouse::drawTroughts(){
    glColor3f(0.1,0.1,0.1);
    GLfloat h=tb/2;
    GLfloat b=tb*0.99;
    glBegin(GL_QUADS);{
        //front
        glNormal3f(0,0,0);glVertex3f(0,0,0);//1
        glNormal3f(0,h,0);glVertex3f(0,h,0);//2
        glNormal3f(tl*troughtsColums,h,0);glVertex3f(tl*troughtsColums,h,0);//3
        glNormal3f(tl*troughtsColums,0,0);glVertex3f(tl*troughtsColums,0,0);//4

        //right side
        glNormal3f(tl*troughtsColums,h,0);glVertex3f(tl*troughtsColums,h,0);//3
        glNormal3f(tl*troughtsColums,h,-b);glVertex3f(tl*troughtsColums,h,-b);//5
        glNormal3f(tl*troughtsColums,0,-b);glVertex3f(tl*troughtsColums,0,-b);//6
        glNormal3f(tl*troughtsColums,0,0);glVertex3f(tl*troughtsColums,0,0);//4

        //back
        glNormal3f(tl*troughtsColums,h,-b);glVertex3f(tl*troughtsColums,h,-b);//5
        glNormal3f(0,h,-b);glVertex3f(0,h,-b);//7
        glNormal3f(0,0,-b);glVertex3f(0,0,-b);//8
        glNormal3f(tl*troughtsColums,0,-b);glVertex3f(tl*troughtsColums,0,-b);//6

        //left
        for(int i=0;i<troughtsColums;i++){
            glNormal3f(i*tl,h,-b);glVertex3f(i*tl,h,-b);//7
            glNormal3f(i*tl,h,0);glVertex3f(i*tl,h,0);//2
            glNormal3f(i*tl,0,0);glVertex3f(i*tl,0,0);//1
            glNormal3f(i*tl,0,-b);glVertex3f(i*tl,0,-b);//8
        }

        //floor
        glColor3f(0.139,0.69,0.19);
        GLfloat fh=h*0.5;
        glNormal3f(0,fh,0);glVertex3f(0,fh,0);//1
        glNormal3f(0,fh,-b);glVertex3f(0,fh,-b);//8
        glNormal3f(tl*troughtsColums,fh,-b);glVertex3f(tl*troughtsColums,fh,-b);//6
        glNormal3f(tl*troughtsColums,fh,0);glVertex3f(tl*troughtsColums,fh,0);//4


    }glEnd();


}
void greenHouse::drawFloorImage(){

    glBegin(GL_POLYGON);{

        //front
        glTexCoord2f(0,1);
        //        glNormal3f(0,0,0);
        glVertex3f(0,0,0);

        glTexCoord2f(0,0);
        //        glNormal3f(0,0,-greenHouseBreadth);
        glVertex3f(0,0,-greenHouseBreadth);

        glTexCoord2f(1,0);
        //        glNormal3f(greenHouseLength,0,-greenHouseBreadth);
        glVertex3f(greenHouseLength,0,-greenHouseBreadth);


        glTexCoord2f(1,1);
        //        glNormal3f(greenHouseLength,0,0);
        glVertex3f(greenHouseLength,0,0);
    }glEnd();

}

void greenHouse::drawFloor(){
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);{

        //front
        glNormal3f(0,0,0);glVertex3f(0,0,0);
        glNormal3f(0,0,-greenHouseBreadth);glVertex3f(0,0,-greenHouseBreadth);
        glNormal3f(greenHouseLength,0,-greenHouseBreadth);glVertex3f(greenHouseLength,0,-greenHouseBreadth);
        glNormal3f(greenHouseLength,0,0);glVertex3f(greenHouseLength,0,0);
    }glEnd();


    //draw horizontal lines
    for(int i=0;i<=troughtsRows/2;i++){
        glPushMatrix();{
            glColor3f(1,1,1);
            glLineWidth(tb/5);
            glBegin(GL_LINES);{
                glNormal3f(tl/2.0,1,-((i*3+1)*tb-tb/2.0));glVertex3f(tl/2.0,1,-((i*3+1)*tb-tb/2.0));
                glNormal3f(tl*(troughtsColums+1)+tl/2.0,1,-((i*3+1)*tb-tb/2.0));glVertex3f(tl*(troughtsColums+1)+tl/2.0,1,-((i*3+1)*tb-tb/2.0));
            }glEnd();
        }glPopMatrix();
    }

    //draw Verticall lines
    for(int i=0;i<=troughtsColums+1;i++){
        glPushMatrix();{
            glBegin(GL_LINES);{
                glNormal3f((i*tl)+tl/2.0,.1,-tb/2.0);
                glVertex3f((i*tl)+tl/2.0,.1,-tb/2.0);
                glNormal3f((i*tl)+tl/2.0,.1,-((troughtsRows*3/2.0+1)*tb-tb/2.0));
                glVertex3f((i*tl)+tl/2.0,.1,-((troughtsRows*3/2.0+1)*tb-tb/2.0));
            }glEnd();
        }glPopMatrix();
    }
}
/*
uchar& greenHouse::pixel(IplImage *canvas, int row, int col, int channel){

    //Function that helps us to access pixel data
    return ((uchar*)(canvas->imageData + canvas->widthStep*row))
            [col*canvas->nChannels+channel] ;

}
CvScalar greenHouse::getPixelValue(IplImage *canvas, int x, int y){
    //Returns an int array of size 3. First=Red Value, Second=Green Value, Third=Blue Value
    //Creating a CvMat from the image
    CvMat *mat, temp;
    mat = cvGetMat(canvas, &temp, 0, 0);

    //Getting pixel values of the CvMat into CvScalar object
    CvSize size=cvGetSize(canvas);
    CvScalar pix;
    pix = cvGet2D(mat, size.height-y,x);
    return pix;

}

void greenHouse::createFloorImage(){
//    IplImage *canvas;
//    canvas = cvCreateImage(cvSize(greenHouseLength, greenHouseBreadth), IPL_DEPTH_8U,	1);

    for (int row = 0; row < greenHouseBreadth; row ++){
        for (int col = 0; col < greenHouseLength; col ++){
            pixel(canvas, row, col, 0) = (uchar)(0);//black
            //            pixel(canvas, row, col, 1) = (uchar)(0);//green
            //            pixel(canvas, row, col, 2) = (uchar)(0);//red
        }
    }
    int x1,y1,x2,y2;

    //draw horizontal lines
    for(int i=0;i<=troughtsRows/2;i++){
        //        x1=tl/2.0;
        x1=0;
        y1=((i*3+1)*tb-tb/2.0);

        //        x2=tl*(troughtsColums+1)+tl/2.0;
        x2=tl*(troughtsColums+1)+tl;
        y2=((i*3+1)*tb-tb/2.0);

        for(int j=x1;j<=x2;j++){
            for(int k=0;k<5;k++)
                pixel(canvas,  y1+k,j, 0) = (uchar)(255);//blue
            //            pixel(canvas,  y1,j, 1) = (uchar)(255);//green
            //            pixel(canvas,  y1,j, 2) = (uchar)(255);//red
        }
    }

    //draw Verticall lines
    for(int i=0;i<=troughtsColums+1;i++){
        x1=(i*tl)+tl/2.0;
        //        y1=tb/2.0;
        y1=0;

        x2=(i*tl)+tl/2.0;
        //        y2=((troughtsRows*3/2.0+1)*tb-tb/2.0);
        y2=((troughtsRows*3/2.0+1)*tb);

        for(int j=y1;j<=y2;j++){
            for(int k=0;k<5;k++)
                pixel(canvas, j,x1+k, 0) = (uchar)(255);//blue
            //            pixel(canvas, j,x1, 1) = (uchar)(255);//green
            //            pixel(canvas, j,x1, 2) = (uchar)(255);//red
        }
    }
    cvSaveImage("greenhousefloor.jpg", canvas);
    cvReleaseImage(&canvas);

}
*/
void greenHouse::drawWalls(int alpha=10){

    glColor4f(0.5,0.5,0.5,alpha*0.1);
    glBegin(GL_QUADS);{

        //front with door
        glNormal3f(greenHouseLength*2/troughtsColums,0,0);glVertex3f(greenHouseLength*2/troughtsColums,0,0);
        glNormal3f(greenHouseLength*2/troughtsColums,greenHouseHeight,0);glVertex3f(greenHouseLength*2/troughtsColums,greenHouseHeight,0);
        glNormal3f(greenHouseLength,greenHouseHeight,0);glVertex3f(greenHouseLength,greenHouseHeight,0);
        glNormal3f(greenHouseLength,0,0);glVertex3f(greenHouseLength,0,0);

        //right
        glNormal3f(greenHouseLength,0,0);glVertex3f(greenHouseLength,0,0);
        glNormal3f(greenHouseLength,greenHouseHeight,0);glVertex3f(greenHouseLength,greenHouseHeight,0);
        glNormal3f(greenHouseLength,greenHouseHeight,-greenHouseBreadth);glVertex3f(greenHouseLength,greenHouseHeight,-greenHouseBreadth);
        glNormal3f(greenHouseLength,0,-greenHouseBreadth);glVertex3f(greenHouseLength,0,-greenHouseBreadth);

        //back
        glNormal3f(greenHouseLength,0,-greenHouseBreadth);glVertex3f(greenHouseLength,0,-greenHouseBreadth);
        glNormal3f(greenHouseLength,greenHouseHeight,-greenHouseBreadth);glVertex3f(greenHouseLength,greenHouseHeight,-greenHouseBreadth);
        glNormal3f(0,greenHouseHeight,-greenHouseBreadth);glVertex3f(0,greenHouseHeight,-greenHouseBreadth);
        glNormal3f(0,0,-greenHouseBreadth);glVertex3f(0,0,-greenHouseBreadth);

        //left
        glNormal3f(0,0,-greenHouseBreadth);glVertex3f(0,0,-greenHouseBreadth);
        glNormal3f(0,greenHouseHeight,-greenHouseBreadth);glVertex3f(0,greenHouseHeight,-greenHouseBreadth);
        glNormal3f(0,greenHouseHeight,0);glVertex3f(0,greenHouseHeight,0);
        glNormal3f(0,0,0);glVertex3f(0,0,0);

    }glEnd();
}
void greenHouse::drawRoof(int alpha, int stacks){
    glColor4f(0.5,0.5,0.5,alpha*0.1);
    double r=greenHouseBreadth/2.0;
    double xLeft = r, yLeft = 0, pxLeft = r, pyLeft = 0;
    double xRight = r, yRight = 0, pxRight = r, pyRight = 0;
    double increment=180/(float)stacks;
    glPushMatrix();{
        glTranslatef(0,greenHouseHeight,-r);
        glRotatef(270,0,1,0);

        for (int i = 1; i <= stacks+1; i ++) {
            pxLeft = xLeft;
            pyLeft = yLeft;

            pxRight = xRight;
            pyRight = yRight;
            if (i==stacks+1) {
                xLeft = r;
                yLeft = 0;

                xRight = r;
                yRight = 0;
            } else {
                xLeft = r * cos(i*increment * 0.01745);
                yLeft = r * sin(i*increment * 0.01745);

                xRight = r * cos(i*increment * 0.01745);
                yRight = r * sin(i*increment * 0.01745);
            }
            glBegin (GL_TRIANGLES);{
                //glBegin(GL_LINES);
                glNormal3f(0, 0, 0); //center//1
                glVertex3f(0, 0, 0);
                glNormal3f(xLeft, yLeft, 0); //3
                glVertex3f(xLeft, yLeft, 0); //3
                glNormal3f(pxLeft, pyLeft, 0); //2
                glVertex3f(pxLeft, pyLeft, 0); //2


            }glEnd();

            glBegin (GL_TRIANGLES);{
                glNormal3f(0, 0, -greenHouseLength); //center//1
                glVertex3f(0, 0, -greenHouseLength); //center//1
                glNormal3f(pxRight, pyRight, -greenHouseLength); //102
                glVertex3f(pxRight, pyRight, -greenHouseLength); //102
                glNormal3f(xRight, yRight, -greenHouseLength); //103
                glVertex3f(xRight, yRight, -greenHouseLength); //103
            }   glEnd();
        }


        xLeft = r; yLeft = 0; pxLeft = r; pyLeft = 0;
        xRight = r; yRight = 0; pxRight = r; pyRight = 0;


        for (int i = 1; i <= stacks+1; i ++) {
            pxLeft = xLeft;
            pyLeft = yLeft;

            pxRight = xRight;
            pyRight = yRight;
            if (i==stacks+1) {
                xLeft = r;
                yLeft = 0;

                xRight = r;
                yRight = 0;
            } else {
                xLeft = r * cos(i*increment * 0.01745);
                yLeft = r * sin(i*increment * 0.01745);

                xRight = r * cos(i*increment * 0.01745);
                yRight = r * sin(i*increment * 0.01745);
            }

            glBegin(GL_POLYGON);
            ////glBegin(GL_LINES);
            glNormal3f(pxLeft, pyLeft, 0);
            glVertex3f(pxLeft, pyLeft, 0);
            glNormal3f(xLeft, yLeft, 0);
            glVertex3f(xLeft, yLeft, 0);
            glNormal3f(xRight, yRight, -greenHouseLength);
            glVertex3f(xRight, yRight, -greenHouseLength);
            glNormal3f(pxRight, pyRight, -greenHouseLength);
            glVertex3f(pxRight, pyRight, -greenHouseLength);

            glEnd();
        }
    }glPopMatrix();
}

void greenHouse::drawMaze(){

    glDisable(GL_BLEND);
    glColor3f(1,1,1);
    glPushMatrix();{
        glPushMatrix();{
            glTranslatef(100,0,10);
            myDrawRectangulatPrism(greenHouseLength-90,50,10);
        }glPopMatrix();
        glPushMatrix();{
            glTranslatef(greenHouseLength,0,0);
            myDrawRectangulatPrism(10,50,(greenHouseBreadth-100));
        }glPopMatrix();
        glPushMatrix();{
            glTranslatef(-10,0,-greenHouseBreadth);
            myDrawRectangulatPrism(greenHouseLength+20,50,10);
        }glPopMatrix();
        glPushMatrix();{
            glTranslatef(-10,0,10);
            myDrawRectangulatPrism(10,50,greenHouseBreadth+10);
        }glPopMatrix();
        //5 left
        {
            glPushMatrix();{
                glTranslatef(0,0,-200);
                myDrawRectangulatPrism(700,50,10);
            }glPopMatrix();
        }
        //6 left
        {
            glPushMatrix();{
                glTranslatef(200,0,-300);
                myDrawRectangulatPrism(10,50,300);
            }glPopMatrix();

        }
        //7 left
        {
            glPushMatrix();{
                glTranslatef(300,0,-400);
                myDrawRectangulatPrism(500,50,10);
            }glPopMatrix();

        }


    }glPopMatrix();

}
/*
void greenHouse::createMazeFloorImage(){
    IplImage *canvas;
    canvas = cvCreateImage(cvSize(greenHouseLength, greenHouseBreadth), IPL_DEPTH_8U,	1);

    for (int row = 0; row < greenHouseBreadth; row ++){
        for (int col = 0; col < greenHouseLength; col ++){
            pixel(canvas, row, col, 0) = (uchar)(0);//black
        }
    }
    int x1,y1,x2,y2;

    //draw horizontal lines
    for(int i=50;i<=greenHouseBreadth;i+=100){
        x1=0;
        y1=i;

        x2=greenHouseLength;
        y2=i;

        for(int j=x1;j<=x2;j++){
            for(int k=0;k<5;k++)
                pixel(canvas,  y1+k,j, 0) = (uchar)(255);//blue
        }
    }

    //draw Verticall lines
    for(int i=50;i<=greenHouseLength;i+=100){
        x1=i;
        y1=0;

        x2=i;
        y2=greenHouseBreadth;

        for(int j=y1;j<=y2;j++){
            for(int k=0;k<5;k++)
                pixel(canvas, j,x1+k, 0) = (uchar)(255);//blue
        }
    }
    cvSaveImage("mazefloor.jpg", canvas);
    cvReleaseImage(&canvas);

}
*/
