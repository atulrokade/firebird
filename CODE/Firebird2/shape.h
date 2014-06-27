/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef SHAPE_H
#define SHAPE_H
#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//#include "greenhouse.h"

void myDrawCylinder(double baseRadius, double topRadius, double height, int stacks, double angle);
void myDrawRing(double baseInnerRadius,double topInnerRadius,double baseOuterRadius,double topOuterRadius, double height, int stacks, double angle);
void myDrawRectangulatPrism(double length, double height,double width);
void myDrawDisk(double baseRadius, double topRadius, double height, int stacks);
void myDrawDiskWithTexture(double baseRadius, double topRadius, double height, int stacks);


//GLfloat troughtsRows=8;
//GLfloat troughtsColums=10;
//GLfloat greenHouseLength=600;
//GLfloat greenHouseBreadth=100;
//void drawTroughts();
//void drawGreenHouse();

#endif // SHAPE_H
