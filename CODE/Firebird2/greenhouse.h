/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef GREENHOUSE_H
#define GREENHOUSE_H

//#include <cv.h>
//#include <highgui.h>

#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "shape.h"
using namespace std;

class greenHouse
{
public:
    greenHouse();
    ~greenHouse();
    greenHouse(int greenHouseL,int greenHouseB,int greenHouseH,int troughtsRow,int troughtsColum);

    GLfloat troughtsRows;
    GLfloat troughtsColums;
    GLfloat greenHouseLength;
    GLfloat greenHouseBreadth;
    GLfloat greenHouseHeight;


//    int **floor;
    void initFloor();
    void printFloor();

    double tl,tb;
//    IplImage *floorImageCanvas;
    void createFloorImage();
//    uchar& pixel (IplImage* canvas, int row, int col, int channel);
//    CvScalar getPixelValue(IplImage* canvas, int x, int y);

    void drawTroughts();
    void drawFloor();
    void drawFloorImage();
    void setFloorImage(string);
    void drawGreenHouse();
    void drawWalls(int alpha);
    void drawRoof(int alpha, int stacks);

    void drawMaze();
    void createMazeFloorImage();

};

#endif // GREENHOUSE_H
