/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef MYDATATYPE_H
#define MYDATATYPE_H
#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
using namespace std;
struct envObjectType {
    string name;
    int sizeX,sizeY,sizeZ;
    int locationX,locationY,locationZ;
};

typedef vector <envObjectType> vector_envObjectType;


struct robotObjectType {
    string name;
    int distance,count;
};

typedef vector <robotObjectType> vector_robotObjectType;

struct robotLocation{
    double x,y,z,angle;

};
struct point{
    double x,y,z;
    double value;
};

struct robotParameter{
    double scale;
    int lineSensorDistance,lineSensorCount,
    irProximitySensorCount,irDistanceSensorCount,sonarSensorCount;
    double velocityRight,velocityLeft;
};

extern string eName;
extern GLuint *textureNum;
#endif // MYDATATYPE_H
