/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef TEXTURE_H
#define TEXTURE_H
#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "iostream"
#include "string.h"
#include "fstream"
#include "vector"
#include "loadpng.h"
#include "mydatatype.h"
class texture
{
public:
    texture();
    GLubyte* read_PPM(const char* filename, int* width, int* height);
    GLubyte* read_bmp(const char* filename, int* width, int* height);
    void textureInitialisation(const char** fn, const int size) ;
    void enableTexture(GLuint texInt);
    void disableTexture();
};

#endif // TEXTURE_H
