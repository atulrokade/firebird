#ifndef TESTOPENGLWINDOW_H
#define TESTOPENGLWINDOW_H

#include <QGLWidget>
#include <iostream>
using namespace std;
class testOpenglWindow : public QGLWidget
{
    Q_OBJECT
public:
    testOpenglWindow(QWidget *parent = 0);
    
signals:
    

public slots:
    void getEnvName(string str);
    
};

#endif // TESTOPENGLWINDOW_H
