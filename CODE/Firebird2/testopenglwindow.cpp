#include "testopenglwindow.h"

testOpenglWindow::testOpenglWindow(QWidget *parent) :
    QGLWidget(parent)
{
}
void testOpenglWindow::getEnvName(string str){
    cout<<"MyOpenGLWindow "<<str<<endl;

}
