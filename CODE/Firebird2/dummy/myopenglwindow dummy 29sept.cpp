#include "myopenglwindow.h"

MyOpenGLWindow::MyOpenGLWindow(QWidget *parent) :
    QGLWidget(parent)
{

    xRotated=90; yRotated=0; zRotated=0; zoom=0.6; leftSpeed=0;rightSpeed=0;
    angle=0;
    trans=0;
    stop=0;
    forwardTrans=50;
    backwardTrans=50;
    rightAngle=30;
    leftAngle=30;
    velocityLeft=0;
    velocityRight=0;
    time=1;

    co_X=0;    co_Y=0;    co_Z=0;
    prev_co_X=0;  prev_co_Y=0; prev_co_Z=0;prev_angle=0;

    rows=4;columns=10;ghlength=800;ghbreadth=600;ghheight=300;
    rows*=2;
    g= new greenHouse(ghlength,ghbreadth,ghheight,rows,columns);

    g->initFloor();

    robot_x=g->tl/2.0;
    robot_y=0;
    robot_z=-g->tb/2.0;robot_angle=0;

    x=-g->tl/2.0;
    y=0;    z=g->tb/2.0;

    ix=0;iy=0;rR=0;rC=0;rD=1;
    g->createFloorImage();
    //    cout<<x<<z;

    robotScale=1;
    rb=new robot(robotScale);

    //creating objects in green house---------------------------
    object = new double*[(int)100];
    for(int i = 0; i < 100; i++)
        object[i] = new double[(int)5];

    objectCount=0;
    //walls---------
    {
        object[objectCount][0]=0;//0 for rectangle
        object[objectCount][1]=-500;//x1
        object[objectCount][2]=0;//y1
        object[objectCount][3]=0;//x2
        object[objectCount][4]=-g->greenHouseBreadth;//y2
        objectCount++;

        object[objectCount][0]=0;//0 for rectangle
        object[objectCount][1]=-500;//x1
        object[objectCount][2]=-g->greenHouseBreadth;//y1
        object[objectCount][3]=g->greenHouseLength+500;//x2
        object[objectCount][4]=-(g->greenHouseBreadth+500);//y2
        objectCount++;

        object[objectCount][0]=0;//0 for rectangle
        object[objectCount][1]=g->greenHouseLength;//x1
        object[objectCount][2]=0;//y1
        object[objectCount][3]=g->greenHouseLength+500;//x2
        object[objectCount][4]=-g->greenHouseBreadth;//y2
        objectCount++;

        object[objectCount][0]=0;//0 for rectangle
        object[objectCount][1]=-500;//x1
        object[objectCount][2]=500;//y1
        object[objectCount][3]=g->greenHouseLength+500;//x2
        object[objectCount][4]=0;//y2
        objectCount++;


        for(int i=0;i<rows/2;i++){
            object[objectCount][0]=0;//0 for rectangle
            object[objectCount][1]=g->tl;//x1
            object[objectCount][2]=-(i*3+1)*g->tb;//y1
            object[objectCount][3]=g->tl*g->troughtsColums;//x2
            object[objectCount][4]=-((i*3+1)*g->tb+g->tb);//y2
            objectCount++;

            object[objectCount][0]=0;//0 for rectangle
            object[objectCount][1]=g->tl;//x1
            object[objectCount][2]=-(i*3+2)*g->tb;//y1
            object[objectCount][3]=g->tl*g->troughtsColums;//x2
            object[objectCount][4]=-((i*3+2)*g->tb+g->tb);//y2
            objectCount++;

        }
    }
    printObjects();

    irSensor=new double[10];

    setFocusPolicy(Qt::ClickFocus);


}

void MyOpenGLWindow::printObjects(){
    cout<<"----------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<objectCount;i++){
        switch((int)object[i][0]){
        case 0:
            cout<<"Reactangle--> ( "<<object[i][1]<<" , "<<object[i][2]<<" )-----( "<<object[i][3]<<" , "<<object[i][4]<<" )"<<endl;
            break;
        case 1:
            break;
        }
    }
    cout<<"----------------------------------------------------------------------------------"<<endl;
}
int MyOpenGLWindow::isInsideObject(double x_, double y_){
    for(int i=0;i<objectCount;i++){
        switch((int)object[i][0]){
        case 0:
            if((x_>=object[i][1])&&(x_<=object[i][3])&&(y_<=object[i][2])&&(y_>=object[i][4]))
                return 1;
            break;
        case 1:
            break;
        }
    }
    return 0;
}

void MyOpenGLWindow::setCommand(QString str){
    command=str.toStdString();

    cout<<"command = "<<command<<endl;
}
void MyOpenGLWindow::run1(){
    emit releasedRun();
    run();
}

void MyOpenGLWindow::run(){

    int tempp=50;
    bool stp=1;

    while(tempp--){
        if(command=="forward"){
            velocityLeft=abs((int)velocityLeft)*1;
            velocityRight=abs((int)velocityRight)*1;
            time=100;
            start();
        }
        else if(command=="backward"){
            velocityLeft=abs((int)velocityLeft)*-1;
            velocityRight=abs((int)velocityRight)*-1;
            time=100;
            start();
        }
        else if(command=="left"){
            velocityLeft=abs((int)velocityLeft)*1;
            velocityRight=abs((int)velocityRight)*-1;
            time=100;
            start();
        }
        else if(command=="right"){
            velocityLeft=abs((int)velocityLeft)*-1;
            velocityRight=abs((int)velocityRight)*1;
            time=100;
            start();
        }
        else if(command=="stop"){
            stp=0;
        }

        //        updateGL();
    }
}

void MyOpenGLWindow::paintGL(){

    //background initialisation
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glScalef(zoom,zoom,zoom);
        glRotatef(xRotated,1.0,0.0,0.0); // rotation about X axis
        glRotatef(yRotated,0.0,1.0,0.0);// rotation about Y axis
        glRotatef(zRotated,0.0,0.0,1.0);  // rotation about Z axis

        glTranslatef(-400,0,250);
    }

    //    //    drawing troughts
        for(int i=0;i<rows/2;i++){

            glPushMatrix();{
                glPushMatrix();{
                    glTranslatef(g->tl,0,-(i*3+1)*g->tb);
                    g->drawTroughts();
                }glPopMatrix();
                glPushMatrix();{
                    glTranslatef(g->tl,0,-(i*3+2)*g->tb);
                    g->drawTroughts();
                }glPopMatrix();

            }glPopMatrix();
        }

    //    printObjects();
    //drawing floor
    g->drawFloor();

    //--------------draw robot---------------
    robotScale=0.15;
    //    robotScale=1;
    glPushMatrix();{
        //        glTranslatef(-x,0,-z);
        //        glRotatef(angle,0,1,0);
        glTranslated(robot_x,robot_y,robot_z);
        glRotated(robot_angle,0,1,0);
        //        cout<<"robo x="<<robot_x<<"  robo y="<<robot_z<<" Robo angle="<<robot_angle*1000<<endl;
        rb->drawRobot(robotScale,leftSpeed,rightSpeed);
    }glPopMatrix();


    //--------------draw bitmap--------------
    /*
    {
    glPushMatrix();{
        glTranslatef(0,-32,0);
        drawBitmap(20);

    }glPopMatrix();
}
*/


    //    calclineSensorCoOrdinate(angle,-x,z);
    calclineSensorCoOrdinate(robot_angle,robot_x,-robot_z);
    //        cout<<setprecision(2);
    //        cout<<leftLineSensorX<<" <--> "<<leftLineSensorY<<" |-----| "<<middleLineSensorX<<" <--> "<<middleLineSensorY<<" |-----| "<<rightLineSensorX<<" <--> "<<rightLineSensorY<<"\t................. ";
    char temp=getlineSensorArray();
    char rr=temp&1;
    char ll=temp&4;
    char mm=temp&2;
    //        cout<<(int)ll/4<<" |-------| "<<(int)mm/2<<" |-------| "<<(int)rr;
    //        if(temp>0)cout<<"---------------------------------------------------";
    //        cout<<endl;

    //    irSensor[1]=getIRDistanceSensor(1,-x,-z,angle);
    //    irSensor[2]=getIRDistanceSensor(2,-x,-z,angle);
    //    irSensor[3]=getIRDistanceSensor(3,-x,-z,angle);
    //    irSensor[4]=getIRDistanceSensor(4,-x,-z,angle);
    //    irSensor[5]=getIRDistanceSensor(5,-x,-z,angle);

    //    cout<<z<<" "<<robot_z<<endl;
    irSensor[1]=getIRDistanceSensor(1,robot_x,robot_z,robot_angle);
    irSensor[2]=getIRDistanceSensor(2,robot_x,robot_z,robot_angle);
    irSensor[3]=getIRDistanceSensor(3,robot_x,robot_z,robot_angle);
    irSensor[4]=getIRDistanceSensor(4,robot_x,robot_z,robot_angle);
    irSensor[5]=getIRDistanceSensor(5,robot_x,robot_z,robot_angle);


    //    cout<<irSensor[1]<<"|-|";
    //    cout<<irSensor[2]<<"|-|";
    //    cout<<irSensor[3]<<"|-|";
    //    cout<<irSensor[4]<<"|-|";
    //    cout<<irSensor[5];
    //    cout<<endl;

    //    g->drawWalls(5);
    //    g->drawRoof(5,5);

    glFlush();

}
void MyOpenGLWindow::calclineSensorCoOrdinate(double angle_, double x_, double y_){
    double a=100;
    double b=50;
    double theta=30;

    double c=sqrt((pow(a,2))+((pow(b,2))));
    c*=robotScale;

    leftLineSensorX=x_-(c*sin((angle_+theta)*0.01745329251));
    leftLineSensorY=y_+(c*cos((angle_+theta)*0.01745329251));

    rightLineSensorX=x_-(c*sin((angle_-theta)*0.01745329251));
    rightLineSensorY=y_+(c*cos((angle_-theta)*0.01745329251));

    a*=robotScale;
    middleLineSensorX=x_-(a*sin((angle_)*0.01745329251));
    middleLineSensorY=y_+(a*cos((angle_)*0.01745329251));

}
int MyOpenGLWindow::getIRDistanceSensor(int sNo, double xParam, double yParam,double angleParam){
    double theta;
    switch(sNo){
    case 1:
        theta=-90;
        break;
    case 2:
        theta=-135;
        break;
    case 3:
        theta=-180;
        break;
    case 4:
        theta=135;
        break;
    case 5:
        theta=90;
        break;
    }
    int r_=0*robotScale;
    double x_=(xParam+(r_*sin((angleParam+theta)*0.01745329251)));
    double y_=(yParam+(r_*cos((angleParam+theta)*0.01745329251)));

    double prx=x_,pry=y_;
    //    cout<<" ("<<x_<<" , "<<y_<<" ) ";
    int test=isInsideObject(x_,y_);
    while(test==0 && r_<=1000){

        //        cout<<" ("<<x_<<" , "<<y_<<" ) "<<r_<<endl;


        r_=r_+1;
        x_=(xParam+(r_*sin((angleParam+theta)*0.01745329251)));
        y_=(yParam+(r_*cos((angleParam+theta)*0.01745329251)));
        test=isInsideObject(x_,y_);


    }

    //    cout<<" ("<<x_<<" , "<<y_<<" ) ";


    glLineWidth(5);
    glBegin(GL_LINES);{
        glColor3f(1,0,0);
        glVertex3f(prx,5,pry);
        glVertex3f(x_,5,y_);

    }glEnd();


    return (r_-0*robotScale);

}


void MyOpenGLWindow::setVelocityLeft(double v){
    velocityRight=v*100;

}
void MyOpenGLWindow::setVelocityRight(double v){
    velocityLeft=v*100;

}
void MyOpenGLWindow::setTime(double t){
    time=t;

}
void MyOpenGLWindow::forward(){

    int n=0;
    while(n<forwardTrans){
        //        trans--;
        leftSpeed-=1.57969171135;
        rightSpeed-=1.57969171135;

        x=x+sin(angle*0.01745329251);
        z=z+cos(angle*0.01745329251);
        updateGL();
        n++;

    }

}
void MyOpenGLWindow::backward(){

    int n=0;
    while(n<backwardTrans){
        //        trans++;
        leftSpeed+=1.57969171135;
        rightSpeed+=1.57969171135;

        x=x-sin(angle*0.01745329251);
        z=z-cos(angle*0.01745329251);

        updateGL();
        n++;
    }

}
void MyOpenGLWindow::right(){

    for(int i=0;i<0.5*rightAngle;i++){
        leftSpeed-=1.57969171135;
        rightSpeed+=1.57969171135;
        angle=angle-1/0.5;
        updateGL();
    }


}
void MyOpenGLWindow::left(){

    for(int i=0;i<0.5*leftAngle;i++){
        leftSpeed+=1.57969171135;
        rightSpeed-=1.57969171135;
        angle=angle+1/0.5;
        updateGL();
    }
}
void MyOpenGLWindow::stops(){
    stop=1;
    updateGL();

}
void MyOpenGLWindow::forwardTranslate(int translate){
    forwardTrans=translate;
}
void MyOpenGLWindow::backwardTranslate(int translate){
    backwardTrans=translate;
}
void MyOpenGLWindow::rightTurn(int turn){
    rightAngle=turn;
}
void MyOpenGLWindow::leftTurn(int turn){
    leftAngle=turn;
}
void MyOpenGLWindow::reset(){

    angle=0;
    trans=0;
    x=0;    y=0;    z=0;
    co_X=0;    co_Y=0;    co_Z=0;
    prev_co_X=0;  prev_co_Y=0; prev_co_Z=0;prev_angle=0;
    //    robot_x=0;robot_y=0;robot_z=0;robot_angle=0;
    updateGL();
}
void MyOpenGLWindow::start(){

    angle=0;

    distanceLeft=velocityLeft*time;
    distanceRight=velocityRight*time;

    double tempAngle=0,radia=0;
    if(velocityLeft!=velocityRight){
        radia=((200*distanceRight)/(distanceLeft-distanceRight));
        //        co_X=(radia);
    }
    else{
        radia=100000;
    }
    if(distanceRight!=0)
        tempAngle=(distanceRight/radia);//*0.01745329251;
    else if(distanceLeft!=0)
        tempAngle=(distanceLeft/(radia+200));
    radia+=100;
    radia*=robotScale;
    co_X=radia;
    co_Z=0;

    angleStep=tempAngle/(time*10);
    //    double rangle=robot_angle;
    //    for(int i=0;i<(time*1);i++){
    for(int i=0;i<(1);i++){
        angle=angle+angleStep;
        double si=0,d=0;
        si=(90-(angle/2.0))-(robot_angle);//+angle-angleStep);
        d=(2*radia*sin((angle/2.0)*22/1260.0));

        robot_x=robot_x-(d*cos(si*22/1260.0));
        robot_z=robot_z-(d*sin(si*22/1260.0));
        //        rangle=(rangle+angle);
        robot_angle=(robot_angle+angle);//Step);

        updateGL();
    }
    angle=0;
    co_X=0;
    co_Z=0;

    //    updateGL();

    /*
    angle=0;

    distanceLeft=velocityLeft*time;
    distanceRight=velocityRight*time;

    double tempAngle=0,radia=0;
    //    prev_x=co_X;
    //    prev_z=co_Z;
    if(velocityLeft!=velocityRight){
        radia=(200*distanceRight)/(distanceLeft-distanceRight);
        co_X=(radia);
    }
    else{
        co_X=100000;
    }
    if(distanceRight!=0)
        tempAngle=(distanceRight/co_X);//*0.01745329251;
    else if(distanceLeft!=0)
        tempAngle=(distanceLeft/(co_X+200));
    co_X+=100;

    //    double temp;
    //    temp=(co_X-prev_x);
    //    co_X=temp*cos(angle);
    //    co_Z=-(temp)*sin(angle);
    angleStep=tempAngle/(time*10);
    for(int i=0;i<(time*10);i++){
        angle=angle-angleStep;
        updateGL();
    }
    prev_co_X=co_X;
    prev_co_Y=co_Y;
    prev_co_Z=co_Z;
    prev_angle=angle;

    robot_x=co_X*cos(angle*22/1260)-co_X-robot_x;
    robot_y=0;
    robot_z=co_X*sin(angle*22/1260)-robot_z;
    robot_angle=(robot_angle+angle);

    angle=0;
    co_X=0;
    co_Z=0;

    cout<<robot_x<<robot_z;
    updateGL();

*/

}

void MyOpenGLWindow::setTroughtRow(int r){
    ix=r;
}
void MyOpenGLWindow::setTroughtColumn(int c){
    iy=c;
}
void MyOpenGLWindow::goToTrought(){
    int r,c;
    //up=1 down=2 left=3 right=4

    rightAngle=90;
    leftAngle=90;
    g->floor[int((g->troughtsRows*3)/2-rR)][rC]=3;

    g->printFloor();
    if((ix>0 && ix<= g->troughtsRows)&&(iy>0 && iy<= g->troughtsColums)){
        r=(ceil(ix/2.0)*3)-(ix%2)-1;
        c=iy;
        //        cout<<r<<" " <<c;
        g->floor[int((g->troughtsRows*3)/2-r)][c]=2;
        g->printFloor();
        if(ix%2==0)r=r+1;
        else r=r-1;
        //    cout<<(rC+c)<<" "<<(2*(g->troughtsColums+2)-rC-c)<<" ";
        //    cout<<" ix="<<ix<<" iy="<<iy<<" rR="<<rR<<" rC="<<rC<<" r="<<r<<" c="<<c<<" rD="<<rD<<endl;
        if(rR==r){
            if(c<rC){
                while(rC>c){
                    if(rD==1){
                        left();
                        rD=3;
                    }
                    else if(rD==2){
                        right();
                        rD=3;
                    }
                    else if(rD==3){
                        forwardTrans=g->tl;forward();
                        rC--;
                    }
                }
                //~ if(ix%2==0){right();rD=2;}
                //~ else {left();rD=1;}
            }
            else{
                while(rC<c){
                    if(rD==1){
                        right();
                        rD=4;
                    }
                    else if(rD==2){
                        left();
                        rD=4;
                    }
                    else if(rD==4){
                        forwardTrans=g->tl;forward();
                        rC++;
                    }
                }
                //~ if(ix%2==1){right();rD=1;}
                //~ else {left();rD=2;}
            }
        }
        else if((rC+c)<(2*(g->troughtsColums+2)-rC-c))//left
        {
            while(rC>0){
                if(rD==1){
                    left();
                    rD=3;
                }
                else if(rD==2){
                    right();
                    rD=3;
                }
                else if(rD==3){
                    forwardTrans=g->tl;forward();
                    rC--;
                }
            }
            if(rR<r){
                if (rD==3)right();
                rD=1;
                while(rR<r){
                    forwardTrans=g->tb;forward();
                    rR++;
                }
                right();rD=4;
                while(rC<c){
                    forwardTrans=g->tl;forward();
                    rC++;
                }
            }
            else{
                if (rD==3)left();
                rD=2;
                while(rR>r){
                    forwardTrans=g->tb;forward();
                    rR--;
                }
                left();rD=4;
                while(rC<c){
                    forwardTrans=g->tl;forward();
                    rC++;
                }
            }

        }
        else //right
        {
            while(rC<g->troughtsColums+1){
                if(rD==1){
                    right();
                    rD=4;
                }
                else if(rD==2){
                    left();
                    rD=4;
                }
                else if(rD==4){
                    forwardTrans=g->tl;forward();
                    rC++;
                }
            }
            if(rR<r){
                if (rD==4)left();
                rD=1;
                while(rR<r){
                    forwardTrans=g->tb;forward();
                    rR++;
                }
                left();rD=3;
                while(rC>c){
                    forwardTrans=g->tl;forward();
                    rC--;
                }
            }
            else{
                if (rD==4)right();
                rD=2;
                while(rR>r){
                    forwardTrans=g->tb;forward();
                    rR--;
                }
                right();rD=3;
                while(rC>c){
                    forwardTrans=g->tl;forward();
                    rC--;
                }
            }
        }

        if(rD==3){
            if(ix%2==1){right();rD=1;}
            else {left();rD=2;}
        }
        else if (rD==4){
            if(ix%2==0){right();rD=2;}
            else {left();rD=1;}
        }

        //    g->floor[int((g->troughtsRows*3)/2-rR)][rC]=3;
        //    g->printFloor();
    }

}
char MyOpenGLWindow::getlineSensorArray(){
    char sensorVal=0;
    //    set bits of char
    //    1-whight color pixel
    //    0-black color pixel

    CvScalar leftPix = g->getPixelValue(g->floorImageCanvas,leftLineSensorX,leftLineSensorY);
    if(leftPix.val[0]>200)
        sensorVal|=4; //set bit 2=1 whight
    else
        sensorVal&=251; // set bit 2=0 black

    CvScalar rightPix = g->getPixelValue(g->floorImageCanvas,rightLineSensorX,rightLineSensorY);
    if(rightPix.val[0]>200)
        sensorVal|=1; //set bit 0=1 whight
    else
        sensorVal&=254; // set bit 0=0 black

    CvScalar middlePix = g->getPixelValue(g->floorImageCanvas,middleLineSensorX,middleLineSensorY);
    if(middlePix.val[0]>200)
        sensorVal|=2; //set bit 1= whight
    else
        sensorVal&=253; // set bit 1= black

    //    cout << "Red=" << pix.val[0] << "\tGreen=" << pix.val[1] << "\tBlue=" << pix.val[2] << endl;

    return sensorVal;

}

void MyOpenGLWindow::drawBitmap(int n){
    n=n*20;

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);

    glNormal3f(n,0, n);
    glVertex3f(n,0, n);
    glNormal3f(-n,0, n);
    glVertex3f(-n,0, n);
    glNormal3f(-n,0, -n);
    glVertex3f(-n,0, -n);
    glNormal3f(n,0, -n);
    glVertex3f(n,0, -n);

    glEnd();
    glColor3f(1,1,1);

    for(int i=-n;i<=n;i+=(n/10)){
        if(i==0)
            glLineWidth(7);
        else
            glLineWidth(2);

        glBegin(GL_LINES);
        glNormal3f(-n,0, i);
        glVertex3f(-n,0, i);
        glNormal3f(n,0, i);
        glVertex3f(n,0, i);

        glNormal3f(i,0, -n);
        glVertex3f(i,0, -n);
        glNormal3f(i,0, n);
        glVertex3f(i,0, n);
        glEnd();
    }

}

void MyOpenGLWindow::keyPressEvent(QKeyEvent *event){
    //char ch= event->key();
    //keyboardKey(ch);
    //MainWindow *m= MainWindow::instance();
    //m= new MainWindow();
    switch(event->key()){
    case Qt::Key_A:			// a = 97
        yRotated--;
        break;
    case Qt::Key_D:
        yRotated++;
        break;

    case Qt::Key_W:
        xRotated--;
        break;
    case Qt::Key_S:
        xRotated++;
        break;

    case Qt::Key_X:
        zRotated--;
        break;
    case Qt::Key_Z:
        zRotated++;
        break;

    case Qt::Key_R:

        xRotated=90; yRotated=0; zRotated=0; zoom=0.6; leftSpeed=0;rightSpeed=0;
        angle=0;
        trans=0;
        stop=0;
        forwardTrans=50;
        backwardTrans=50;
        rightAngle=30;
        leftAngle=30;
        velocityLeft=0;
        velocityRight=0;
        time=10;

        co_X=0;    co_Y=0;    co_Z=0;
        prev_co_X=0;  prev_co_Y=0; prev_co_Z=0;prev_angle=0;
        robot_x=0;robot_y=0;robot_z=0;robot_angle=0;

        rows=4;columns=10;ghlength=800;ghbreadth=600;ghheight=300;
        rows*=2;
        x=-g->tl/2.0;
        y=0;    z=g->tb/2.0;

        ix=0;iy=0;rR=0;rC=0;rD=1;

        robotScale=1;

        break;

    case Qt::Key_PageUp:
        zoom=zoom+0.1;
        //m->set();
        break;
    case Qt::Key_PageDown:
        if(zoom>0.1)
            zoom=zoom-0.1;
        break;
    case Qt::Key_End:
        zoom=1;
        break;
    case Qt::Key_Up:
        //        speed-=20;
        break;
    case Qt::Key_Down:
        //        speed+=20;
        break;

    case Qt::Key_Escape:
        exit(0);
        break;
    }





    updateGL();
    //delete(m);
}
void MyOpenGLWindow::initializeGL(){
    GLfloat material_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 80 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable (GL_BLEND);
    //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    //    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //    GLfloat mat_shininess[] = { 30.0 };
    GLfloat light0_position[] = { 1.0, 1.0, 1.0, 0.0 };
    //GLfloat light1_position[] = { -1.0, -1.0, -1.0, 0.0 };
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    //    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    //glLightfv(GL_LIGHT0, GL_POSITION, light1_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);



    glShadeModel(GL_SMOOTH);
    glClearColor(1,1,1,0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}
void MyOpenGLWindow::resizeGL(int width, int height){

    double xMin = 0, xMax = 10, yMin = 0, yMax = 10;
    glViewport(0,0,(GLint)width, (GLint)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D            (-1,1,-1,1);
    if (width > height){
        height = height?height:1;
        double newWidth = (xMax - xMin) * width / height;
        double difWidth = newWidth - (xMax - xMin);
        xMin = 0.0 + difWidth / 2.0;
        xMax = 10 + difWidth / 2.0;
    } else {
        width = width?width:1;
        double newHeight = (yMax - yMin) * width / height;
        double difHeight = newHeight - (yMax - yMin);
        yMin = 0.0 + difHeight / 2.0;
        yMax = 10 + difHeight / 2.0;
    }
    //gluOrtho2D(xMin, xMax, yMin, yMax);
    glOrtho(-280.0, 280.0, -175.0, 175.0,-1500,1500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}
void MyOpenGLWindow:: myRotate(GLfloat angle, GLfloat X, GLfloat Y, GLfloat Z, GLfloat co_X, GLfloat co_Y, GLfloat co_Z){
    glTranslatef(co_X,co_Y,co_Z);
    glRotatef(angle,X,Y,Z);
    glTranslatef(-co_X,-co_Y,-co_Z);
}
