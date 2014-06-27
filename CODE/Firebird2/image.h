/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <QGLWidget>
#include <QtOpenGL>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "loadpng.h"
using namespace std;
class image
{



public:
    string name;
    int width,height;
    int textureNumber;
    GLuint * texInt;

    float **imgdata;
    image();
    image(string);
    int createImageTexture();
    int createImageTexture1();
};

#endif // IMAGE_H
