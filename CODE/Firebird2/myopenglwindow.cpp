/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "myopenglwindow.h"

MyOpenGLWindow::MyOpenGLWindow(QWidget *parent) :
    QGLWidget(parent)
{

    //    ce=new createEnvironment();

    //    createEnvironment ce1;
    //    connect(ce,SIGNAL(envName(string)),this,SLOT(getEnvName(string)));


    //    cr=new robotWindow();

    //    connect(cr,SIGNAL(roboName(string)),this,SLOT(getRobotName(string)));

    //    ce =new createEnvironment();

    caseStudy=4;
    startFlag=false;

    xt=0;yt=0;
    xRotated=40; yRotated=40; zRotated=0; zoom=0.6; leftSpeed=0;rightSpeed=0;
    angle=0;
    trans=0;
    stop=0;
    forwardTrans=50;
    backwardTrans=50;
    rightAngle=30;
    leftAngle=30;
    velocityLeft=20*100;
    velocityRight=20*100;
    time=1;

    co_X=0;    co_Y=0;    co_Z=0;
    prev_co_X=0;  prev_co_Y=0; prev_co_Z=0;prev_angle=0;

    rows=4;columns=10;ghlength=800;ghbreadth=600;ghheight=300;
    rows*=2;
    g= new greenHouse(ghlength,ghbreadth,ghheight,rows,columns);
    //    g->setFloorImage("linefollowerfloor.jpg");


    //    g->setFloorImage("greenhousefloor.jpg");

    g->initFloor();

    robot_x=g->tl/2.0;
    robot_y=0;
    robot_z=-g->tb/2.0;robot_angle=0;

    x=-g->tl/2.0;
    y=0;    z=g->tb/2.0;

    ix=0;iy=0;rR=0;rC=0;rD=1;
    //    g->createFloorImage();
    //    g->createMazeFloorImage();
    //    cout<<x<<z;

    robotScale=1;
    rb=new robot(robotScale);
    robotScale=0.15;

    //creating object2s in green house---------------------------
    object2 = new double*[(int)100];
    for(int i = 0; i < 100; i++)
        object2[i] = new double[(int)5];

    object2Count=0;

    object3 = new double*[(int)100];
    for(int i = 0; i < 100; i++)
        object3[i] = new double[(int)5];
    object3Count=0;
    //walls object2 initialisation---------
    {
        object2[object2Count][0]=0;//0 for rectangle
        object2[object2Count][1]=-500;//x1
        object2[object2Count][2]=0;//y1
        object2[object2Count][3]=0;//x2
        object2[object2Count][4]=-g->greenHouseBreadth;//y2
        object2Count++;

        object2[object2Count][0]=0;//0 for rectangle
        object2[object2Count][1]=-500;//x1
        object2[object2Count][2]=-g->greenHouseBreadth;//y1
        object2[object2Count][3]=g->greenHouseLength+500;//x2
        object2[object2Count][4]=-(g->greenHouseBreadth+500);//y2
        object2Count++;

        object2[object2Count][0]=0;//0 for rectangle
        object2[object2Count][1]=g->greenHouseLength;//x1
        object2[object2Count][2]=0;//y1
        object2[object2Count][3]=g->greenHouseLength+500;//x2
        object2[object2Count][4]=-g->greenHouseBreadth;//y2
        object2Count++;

        object2[object2Count][0]=0;//0 for rectangle
        object2[object2Count][1]=-500;//x1
        object2[object2Count][2]=500;//y1
        object2[object2Count][3]=g->greenHouseLength+500;//x2
        object2[object2Count][4]=0;//y2
        object2Count++;


        for(int i=0;i<rows/2;i++){
            object2[object2Count][0]=0;//0 for rectangle
            object2[object2Count][1]=g->tl;//x1
            object2[object2Count][2]=-(i*3+1)*g->tb;//y1
            object2[object2Count][3]=g->tl*g->troughtsColums;//x2
            object2[object2Count][4]=-((i*3+1)*g->tb+g->tb);//y2
            object2Count++;

            object2[object2Count][0]=0;//0 for rectangle
            object2[object2Count][1]=g->tl;//x1
            object2[object2Count][2]=-(i*3+2)*g->tb;//y1
            object2[object2Count][3]=g->tl*g->troughtsColums;//x2
            object2[object2Count][4]=-((i*3+2)*g->tb+g->tb);//y2
            object2Count++;

        }
    }
    //    printobject2s();

    //object 3 initialisation------------
    {
        //1 bottom
        {
            object3[object3Count][0]=0;//0 for rectangle
            object3[object3Count][1]=100;//x1
            object3[object3Count][2]=10;//y1
            object3[object3Count][3]=(g->greenHouseLength+10);//x2
            object3[object3Count][4]=0;//y2
            object3Count++;
        }
        //2 right
        {
            object3[object3Count][0]=0;//0 for rectangle
            object3[object3Count][1]=g->greenHouseLength;//x1
            object3[object3Count][2]=0;//y1
            object3[object3Count][3]=g->greenHouseLength+10;//x2
            object3[object3Count][4]=-(g->greenHouseBreadth-100);//y2
            object3Count++;
        }
        //3 top
        {
            object3[object3Count][0]=0;//0 for rectangle
            object3[object3Count][1]=-10;//x1
            object3[object3Count][2]=-g->greenHouseBreadth;//y1
            object3[object3Count][3]=g->greenHouseLength+20-10;//x2
            object3[object3Count][4]=-(g->greenHouseBreadth+10);//y2
            object3Count++;
        }
        //4 left
        {
            object3[object3Count][0]=0;//0 for rectangle
            object3[object3Count][1]=-10;//x1
            object3[object3Count][2]=10;//y1
            object3[object3Count][3]=0;//x2
            object3[object3Count][4]=-g->greenHouseBreadth;//y2
            object3Count++;
        }
        //5 left
        {
            object3[object3Count][0]=0;//0 for rectangle
            object3[object3Count][1]=0;//x1
            object3[object3Count][2]=-200;//y1
            object3[object3Count][3]=700;//x2
            object3[object3Count][4]=-210;//y2
            object3Count++;
        }
        //6 left
        {
            object3[object3Count][0]=0;//0 for rectangle
            object3[object3Count][1]=200;//x1
            object3[object3Count][2]=-300;//y1
            object3[object3Count][3]=210;//x2
            object3[object3Count][4]=-600;//y2
            object3Count++;
        }
        //7 left
        {
            object3[object3Count][0]=0;//0 for rectangle
            object3[object3Count][1]=300;//x1
            object3[object3Count][2]=-400;//y1
            object3[object3Count][3]=800;//x2
            object3[object3Count][4]=-410;//y2
            object3Count++;
        }

    }
    lineSensorStatus=true;
    lineSensor=new int[10];
    irDistanceSensorStatus=true;
    irProximitySensorStatus=true;
    irDistanceSensor=new double[10];
    irProximitySensor=new int[10];

    setFocusPolicy(Qt::ClickFocus);


    //    sRead();
    //    mRead();
    //    prvmSignal=sSignal;
    semaphore=0;
    semWrite();

    command="stop";
    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),SLOT(run()));
    timer->start(1000);
    //    run();

    textureNum= new GLuint[10];
//    cout<<"here"<<endl;
}

void MyOpenGLWindow::paintGL(){

    //    if(robot_x<0 || robot_x>800 || robot_z>0 || robot_z>600){
    //        motionCommand="stop";
    //        command="stop";
    //    }

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    /*

{
    glTranslatef(xt,yt,0);
    //background initialisation
    {
        glScalef(zoom,zoom,zoom);
        glRotatef(xRotated,1.0,0.0,0.0); // rotation about X axis
        glRotatef(yRotated,0.0,1.0,0.0);// rotation about Y axis
        glRotatef(zRotated,0.0,0.0,1.0);  // rotation about Z axis

        if(caseStudy!=4)
            glTranslatef(-400,0,250);
    }

    if(caseStudy!=4){
        glColor4f(.9,.9,.9,1);
//        tx.enableTexture(textureNum[caseStudy]);
        {
            g->drawFloorImage();
        }
    }


    //    drawing floor
    //    g->drawFloor();

    //--------------draw robot---------------
    glPushMatrix();{

        //        glTranslatef(-x,0,-z);
        //        glRotatef(angle,0,1,0);
        if(caseStudy!=4){
            glTranslated(robot_x,robot_y,robot_z);
            glRotated(robot_angle,0,1,0);
        }
        //        cout<<"robo x="<<robot_x<<"  robo y="<<robot_z<<" Robo angle="<<robot_angle*1000<<endl;
//        tx.enableTexture(textureNum[0]);
        {
            rb->drawRobot(robotScale,leftSpeed,rightSpeed);
        }
//        tx.disableTexture();
    }glPopMatrix();

    //draw ir proximity sensor------------------------------
    //    rb->drawIRProximitySensor();

    //drawIR distance sensor
    //    rb->drawIRDistanceSensor();

    //draw sonar sensor
    //    rb->drawSonarSensor();

    //--------------draw bitmap--------------
    /*
    {
    glPushMatrix();{
        glTranslatef(0,-32,0);
        drawBitmap(20);

    }glPopMatrix();
}
*
    if(caseStudy!=4){
        if(lineSensorStatus && robot_x>0 && robot_x<800 && robot_z>0 && robot_z<600){
            //        cout<<getlineSensorValues()<<endl;
            calclineSensorCoOrdinate(robot_angle,robot_x,-robot_z);
            //                cout<<leftLineSensorX<<" <--> "<<leftLineSensorY<<" |-----| "<<middleLineSensorX<<" <--> "<<middleLineSensorY<<" |-----| "<<rightLineSensorX<<" <--> "<<rightLineSensorY<<"\t................. ";
            //        cout<<leftleftLineSensorX<<" <--> "<<leftleftLineSensorY<<" |-----| "
            //           <<leftLineSensorX<<" <--> "<<leftLineSensorY<<" |-----| "
            //          <<middleLineSensorX<<" <--> "<<middleLineSensorY<<" |-----| "
            //         <<rightLineSensorX<<" <--> "<<rightLineSensorY<<" |-----| "
            //        <<rightrightLineSensorX<<" <--> "<<rightrightLineSensorY<<"\t................. "<<endl;
            //    char temp=getlineSensorArray();
            //    char rr=temp&1;
            //    char ll=temp&4;
            //    char mm=temp&2;
            int temp=getlineSensorArray();
            lineSensor[0]=(temp&1)/1;//rightleft

            lineSensor[1]=(temp&2)/2;//right
            lineSensor[2]=(temp&4)/4;//middle
            lineSensor[3]=(temp&8)/8;//left

            lineSensor[4]=(temp&16)/16;//leftleft

            //        cout<<getlineSensorValues();
            //        cout<<(int)ll/4<<" |-------| "<<(int)mm/2<<" |-------| "<<(int)rr;
            //        cout<<lineSensor[2]<<" |-------| "<<lineSensor[1]<<" |-------| "<<lineSensor[0];
            //                if(temp>0)cout<<"---------------------------------------------------";
            //                cout<<endl;
        }
        if(irDistanceSensorStatus){
            for(int i=1;i<=5;i++){
                irDistanceSensor[i]=getIRDistanceSensor(i,robot_x,robot_z,robot_angle);
            }
        }

        if(irProximitySensorStatus){
            for(int i=1;i<=8;i++){
                irProximitySensor[i]=getIRProximitySensor(i,robot_x,robot_z,robot_angle);
            }
        }
    }
    //            drawing troughts
    if(caseStudy==2)
    {
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
        g->drawWalls(2);
        g->drawRoof(2,15);
    }
    else if(caseStudy==3){
        glPushMatrix();{
            g->drawMaze();
        }
        glPopMatrix();
    }

    glFlush();
    //    updateGL();
    }
*/
}

void MyOpenGLWindow::run(){


    //    cout<<motionCommand<<" "<<caseStudy<<"";

    //    int tempp=50;
    bool stp=1;
    sRead();
    mRead();
    prvmSignal=sSignal;

    //    while(1)
    {
        mRead();
        if(prvmSignal!=mSignal){
            prvmSignal=mSignal;
            semRead();
            while(semaphore){semRead();}
            semaphore=1;sWrite();
            readCommand();
            semaphore=0;semWrite();

            istringstream iss(inputString);

            arguments.clear();
            bool sflag=true;
            do
            {
                string tempSub;
                iss >> tempSub;
                if(sflag){
                    command=tempSub;sflag=false;
                    if(command=="lcdPrint"){
                        getline(iss,tempSub);
                        arguments.push_back(tempSub);
                        break;
                    }
                }
                else
                    arguments.push_back(tempSub);
            }while(iss);
            //            cout<<"\nCommand="<<command<<endl;
            //            cout<<"\narguments=";
            //            for(int i=0;i<arguments.size();i++){
            //                cout<<arguments[i]<<" ";
            //            }
            //            cout<<endl;
            if(command=="forward" || command=="backward" ||command=="left"||command=="right"||command=="stop")
            {
                if(caseStudy==3){
                    if(command=="forward")
                    {
                        motionCommand="mforward";
                    }
                    else if( command=="backward"){
                        motionCommand="mbackward";
                    }
                    else if(command=="left"){
                        motionCommand="mleft";
                    }
                    else if(command=="right"){
                        motionCommand="mright";
                    }
                    else if(command=="stop"){
                        motionCommand="mstop";
                    }
                    if(robot_x>800){
                        motionCommand="mstop";
                    }
                    if(motionCommand=="mforward"){
                        forwardTrans=100;
                        forward();
                    }
                    else if(motionCommand=="mbackward"){
                        backwardTrans=100;
                        backward();
                    }
                    else if(motionCommand=="mleft"){
                        leftAngle=90;
                        left();
                    }
                    else if(motionCommand=="mright"){
                        rightAngle=90;
                        right();
                    }
                    else if(motionCommand=="mstop"){
                        stp=0;
                    }

                }
                else if(caseStudy==1)
                    motionCommand=command;
            }

            if(caseStudy==2){
                //                if(command=="left"){
                //                    left();
                //                }
                //                else if(command=="right"){
                //                    right();
                //                }
                //                command="stop";
                motionCommand="stop";
            }

            //     cout<<command<<endl;

            //            semRead();
            //            while(semaphore){semRead();}
            //            semaphore=1;sWrite();
            //            result="read_kar_liyi--";
            //            writeResult();
            //            semaphore=0;semWrite();

            //            sSignal=!sSignal;
            //            sWrite();
            result="";bool ret=false;
            if(command=="gl"){
                result=GetLeftMotorVelocity();
                ret=true;
            }
            else if(command=="gr"){
                result=GetRightMotorVelocity();
                ret=true;
            }
            else if(command=="gv"){
                result=GetVelocity();
                ret=true;
            }
            else if(command=="gls"){
                result=getlineSensorValues();
                //                cout<<result;
                ret=true;
            }
            else if(command=="girds"){
                result=getIRDistanceSensorValues();
                ret=true;
            }
            else if(command=="girps"){
                result=getIRProximitySensorValues();
                ret=true;
            }
            else if(command=="glss"){
                result=getLineSensorStatus();
                ret=true;
            }
            else if(command=="girdss"){
                result=getIRDistanceSensorStatus();
                ret=true;
            }
            else if(command=="girpss"){
                result=getIRProximitySensorStatus();
                ret=true;
            }
            else if(command=="goto")
            {
                ix=atoi(arguments[0].c_str());
                iy=atoi(arguments[1].c_str());
                goToTrought();
            }
            //            if(command=="d"){
            //                delaymSec(arguments[0]);
            ////                result="timer_over";
            //                ret=true;
            //            }
            if(ret){
                semRead();
                while(semaphore){semRead();}
                semaphore=1;sWrite();
                writeResult();
                semaphore=0;semWrite();
            }
            //            if(dtt>0){dtt--;}
            //            else{
            sRead();
            sSignal=!sSignal;
            sWrite();


        }
        //if(command!="stop")cout<<command<<endl;
        if(caseStudy==1){
            //            motionCommand="stop";
            if(motionCommand=="forward"){
                velocityLeft=abs((int)velocityLeft)*1;
                velocityRight=abs((int)velocityRight)*1;
                time=100;
                start();
            }
            else if(motionCommand=="backward"){
                velocityLeft=abs((int)velocityLeft)*-1;
                velocityRight=abs((int)velocityRight)*-1;
                time=100;
                start();
            }
            else if(motionCommand=="left"){
                velocityLeft=abs((int)velocityLeft)*1;
                velocityRight=abs((int)velocityRight)*-1;
                time=100;
                start();
            }
            else if(motionCommand=="right"){
                velocityLeft=abs((int)velocityLeft)*-1;
                velocityRight=abs((int)velocityRight)*1;
                time=100;
                start();
            }
            else if(motionCommand=="stop"){
                stp=0;
            }
        }

        if(command=="lcdPrint"){
            lcdPrint(arguments[0]);
        }else if(command=="sl"){
            SetLeftMotorVelocity(arguments[0]);

        }else if(command=="sr"){
            SetRightMotorVelocity(arguments[0]);

        }else if(command=="sv"){
            SetVelocity(arguments[0],arguments[1]);
        }else if(command=="slss"){
            setLineSensorStatus(arguments[0]);
        }else if(command=="sirdss"){
            setIRDistanceSensorStatus(arguments[0]);
        }else if(command=="sirpss"){
            setIRProximitySensorStatus(arguments[0]);
        }

    }

    timer->start(1);
    //    return;

}
void MyOpenGLWindow::getEnvName1(string str){
    cout<<"MyOpenGLWindow "<<str<<endl;

}
void MyOpenGLWindow::getRobotName(string str){
    cout<<str<<endl;
}

void MyOpenGLWindow::setLineFollowerCaseStudy(){

    //    QString fileName1 = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
    //    cout<<fileName1.toStdString()<<endl;

    //    d.show();

    //    QString ff=QFileDialog::getSaveFileName(this, tr("Save File"),"/home/Desktop/temp.txt");
    //    cout<<ff.toStdString()<<endl;

    //        ce=new createEnvironment();
    //        string *temp;
    //        cout<<&temp<<endl;
    //        ce->getenvironmentName(temp);
    ce->show();
    //        while(ce->ex!=1);
    //        cout<<"env name is : "<<ce->environmentName<<endl;
    //        cout<<"env name is : "<<*temp<<endl;

    //        delete ce;



    lineSensorStatus=true;
    caseStudy=1;
    robotScale=0.15;
    yRotated=40;
    robot_x=g->tl/2.0;
    robot_y=0;
    robot_z=-g->tb/2.0;robot_angle=0;
    g->setFloorImage("linefollowerfloor1.jpg");
    updateGL();
}
void MyOpenGLWindow::setGreenHouseCaseStudy(){
    lineSensorStatus=false;
    caseStudy=2;
    robotScale=0.15;
    yRotated=40;
    robot_x=g->tl/2.0;
    robot_y=0;
    robot_z=-g->tb/2.0;robot_angle=0;
    g->setFloorImage("greenhousefloor.jpg");
    motionCommand="stop";
    updateGL();

}
void MyOpenGLWindow::setMazeSolverCaseStudy(){
    lineSensorStatus=false;
    caseStudy=3;
    robotScale=0.30;
    yRotated=40;
    robot_x=53;
    robot_y=0;
    robot_z=-46;robot_angle=0;
    g->setFloorImage("mazefloor.jpg");
    motionCommand="stop";
    updateGL();

}
void MyOpenGLWindow::setParts(){
    caseStudy=4;
    robotScale=1.5;
    yRotated=220;
    updateGL();
}

void MyOpenGLWindow::printObject2s(){
    cout<<"----------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<object2Count;i++){
        switch((int)object2[i][0]){
        case 0:
            cout<<"Reactangle--> ( "<<object2[i][1]<<" , "<<object2[i][2]<<" )-----( "<<object2[i][3]<<" , "<<object2[i][4]<<" )"<<endl;
            break;
        case 1:
            break;
        }
    }
    cout<<"----------------------------------------------------------------------------------"<<endl;
}
int MyOpenGLWindow::isInsideObject(double x_, double y_){
    if(caseStudy==2){
        for(int i=0;i<object2Count;i++){
            switch((int)object2[i][0]){
            case 0:
                if((x_>=object2[i][1])&&(x_<=object2[i][3])&&(y_<=object2[i][2])&&(y_>=object2[i][4]))
                    return 1;
                break;
            case 1:
                break;
            }
        }
    }
    else if(caseStudy==3){
        for(int i=0;i<object3Count;i++){
            switch((int)object3[i][0]){
            case 0:
                if((x_>=object3[i][1])&&(x_<=object3[i][3])&&(y_<=object3[i][2])&&(y_>=object3[i][4]))
                    return 1;
                break;
            case 1:
                break;
            }
        }
    }
    return 0;
}

void MyOpenGLWindow::setCommand(QString qstr){
    command=qstr.toStdString();

    cout<<"command = "<<command<<endl;
}
void MyOpenGLWindow::run1(){
    //    emit releasedRun();
    //    run();
}
void MyOpenGLWindow::lcdPrint(string str){
    string temp;
    for(int i=0;i<str.length();i++){
        if(str[i]=='\\' ){
            if(str[i+1]=='n' ){
                temp.append("\n");
                i++;
            }
        }
        else if(str[i]==' ' ){
            temp.append(" ");
        }
        else{
            stringstream sst;
            string ss;
            sst << str[i];
            sst >> ss;
            temp.append(ss);
        }
    }
    //    temp.append("\n");
    //    temp.append(str);
    //    cout<<temp<<endl;
    cout<<temp<<endl;
    emit printCommand(QString::fromStdString(temp));
    //    emit printCommand(QString::fromStdString(command));

}

void MyOpenGLWindow::SetLeftMotorVelocity(string left){
    velocityLeft=atoi(left.c_str())*100;
}
void MyOpenGLWindow::SetRightMotorVelocity(string right){
    velocityRight=atoi(right.c_str())*100;
}
void MyOpenGLWindow::SetVelocity(string left, string right){

    velocityLeft=atoi(left.c_str())*100;
    velocityRight=atoi(right.c_str())*100;
}
string MyOpenGLWindow::GetLeftMotorVelocity(){
    stringstream ss;
    ss <<abs((int)velocityLeft)/100;
    return(ss.str());
}
string MyOpenGLWindow::GetRightMotorVelocity(){
    stringstream ss;
    ss <<abs((int)velocityRight)/100;
    return(ss.str());

}
string MyOpenGLWindow::GetVelocity(){
    stringstream ss;
    ss <<abs((int)velocityLeft)/100<<" "<<abs((int)velocityRight)/100;
    return(ss.str());

}

void MyOpenGLWindow::calclineSensorCoOrdinate(double angle_, double x_, double y_){
    double a=170,aa=170;
    double b=50,bb=100;
    //    double theta=20;

    double c=sqrt((pow(a,2))+((pow(b,2))));

    double theta=asin(b/c) *(57.295779546);
    //    cout<<a<<" "<<b<<" "<<c<<" "<<theta<<endl;
    c*=robotScale;

    leftLineSensorX=x_-(c*sin((angle_+theta)*0.01745329251));
    leftLineSensorY=y_+(c*cos((angle_+theta)*0.01745329251));

    rightLineSensorX=x_-(c*sin((angle_-theta)*0.01745329251));
    rightLineSensorY=y_+(c*cos((angle_-theta)*0.01745329251));

    a*=robotScale;
    middleLineSensorX=x_-(a*sin((angle_)*0.01745329251));
    middleLineSensorY=y_+(a*cos((angle_)*0.01745329251));

    //    b*=2;
    //    theta*=2;
    c=sqrt((pow(aa,2))+((pow(bb,2))));
    theta=asin(bb/c) *((180.0*7.0)/22.0);
    //    cout<<aa<<" "<<bb<<" "<<c<<" "<<theta<<endl;
    c*=robotScale;

    leftleftLineSensorX=x_-(c*sin((angle_+theta)*0.01745329251));
    leftleftLineSensorY=y_+(c*cos((angle_+theta)*0.01745329251));

    rightrightLineSensorX=x_-(c*sin((angle_-theta)*0.01745329251));
    rightrightLineSensorY=y_+(c*cos((angle_-theta)*0.01745329251));



}

int MyOpenGLWindow::getlineSensorArray(){
    int sensorVal=0;
    //    set bits of char
    //    1-whight color pixel
    //    0-black color pixel
    //    sensors-   4 3 2 1 0 >>>>
    //              16 8 4 2 1

    int sum=0;

    sum=0;
    for(double i=leftLineSensorY-1;i<=leftLineSensorY+1;i++){
        for(double j=leftLineSensorX-1;j<=leftLineSensorX+1;j++){
            //            CvScalar leftPix = g->getPixelValue(g->floorImageCanvas,j,i);
            //            sum+=leftPix.val[0];
        }
    }
    if(sum>200)
        sensorVal|=8; //set bit 3=1 whight
    else
        sensorVal&=247; // set bit 2=0 black

    sum=0;
    for(double i=rightLineSensorY-1;i<=rightLineSensorY+1;i++){
        for(double j=rightLineSensorX-1;j<=rightLineSensorX+1;j++){
            //            CvScalar rightPix = g->getPixelValue(g->floorImageCanvas,j,i);
            //            sum+=rightPix.val[0];
        }
    }
    if(sum>200)
        sensorVal|=2; //set bit 1=1 whight
    else
        sensorVal&=253; // set bit 1=0 black

    sum=0;
    for(double i=middleLineSensorY-1;i<=middleLineSensorY+1;i++){
        for(double j=middleLineSensorX-1;j<=middleLineSensorX+1;j++){
            //            CvScalar middlePix = g->getPixelValue(g->floorImageCanvas,j,i);
            //            sum+=middlePix.val[0];
        }
    }
    if(sum>200)
        sensorVal|=4; //set bit 2= whight
    else
        sensorVal&=251; // set bit 2=0 black


    sum=0;
    for(double i=leftleftLineSensorY-1;i<=leftleftLineSensorY+1;i++){
        for(double j=leftleftLineSensorX-1;j<=leftleftLineSensorX+1;j++){
            //            CvScalar leftleftPix = g->getPixelValue(g->floorImageCanvas,j,i);
            //            sum+=leftleftPix.val[0];
        }
    }
    if(sum>200)
        sensorVal|=16; //set bit 4=1 whight
    else
        sensorVal&=239; // set bit 4=0 black

    sum=0;
    for(double i=rightrightLineSensorY-1;i<=rightrightLineSensorY+1;i++){
        for(double j=rightrightLineSensorX-1;j<=rightrightLineSensorX+1;j++){
            //            CvScalar rightrightPix = g->getPixelValue(g->floorImageCanvas,j,i);
            //            sum+=rightrightPix.val[0];
        }
    }
    if(sum>200)
        sensorVal|=1; //set bit 0=1 whight
    else
        sensorVal&=254; // set bit 0=0 black

    //    cout << "Red=" << pix.val[0] << "\tGreen=" << pix.val[1] << "\tBlue=" << pix.val[2] << endl;

    return sensorVal;

}


void MyOpenGLWindow::setLineSensorStatus(string str){
    if(str=="on"){
        lineSensorStatus=true;
    }
    else if(str=="off"){
        lineSensorStatus=false;
    }
    return;
}
string MyOpenGLWindow::getLineSensorStatus(){
    if(lineSensorStatus){
        return("on");
    }
    else{
        return("off");
    }
}
string MyOpenGLWindow::getlineSensorValues(){
    stringstream ss;
    ss <<lineSensor[4]<<" "<<lineSensor[3]<<" "<<lineSensor[2]<<" "<<lineSensor[1]<<" "<<lineSensor[0]<<endl;
    return(ss.str());
}
string MyOpenGLWindow::getIRDistanceSensorValues(){
    stringstream ss;
    ss <<irDistanceSensor[1]<<" "<<irDistanceSensor[2]<<" "<<irDistanceSensor[3]<<" "<<irDistanceSensor[4]<<" "<<irDistanceSensor[5];
    return(ss.str());

}

void MyOpenGLWindow::setIRDistanceSensorStatus(string str){
    if(str=="on"){
        irDistanceSensorStatus=true;
    }
    else if(str=="off"){
        irDistanceSensorStatus=false;
    }
}
string MyOpenGLWindow::getIRDistanceSensorStatus(){
    if(irDistanceSensorStatus){
        return("on");
    }
    else{
        return("off");
    }
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
    int r_=50*robotScale;
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


    //    glLineWidth(5);
    //    glBegin(GL_LINES);{
    //        glColor3f(1,0,0);
    //        glVertex3f(prx,5,pry);
    //        glVertex3f(x_,5,y_);

    //    }glEnd();


    return (r_-0*robotScale);

}

int MyOpenGLWindow::getIRProximitySensor(int sNo, double xParam, double yParam, double angleParam){
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
    case 6:
        theta=45;
        break;
    case 7:
        theta=0;
        break;
    case 8:
        theta=-45;
        break;
    }
    int r_=50*robotScale;
    double x_=(xParam+(r_*sin((angleParam+theta)*0.01745329251)));
    double y_=(yParam+(r_*cos((angleParam+theta)*0.01745329251)));

    double prx=x_,pry=y_,prr=r_;
    //    cout<<" ("<<x_<<" , "<<y_<<" ) ";
    int test=isInsideObject(x_,y_);
    while(test==0 && r_<=prr+15){
        //        cout<<" ("<<x_<<" , "<<y_<<" ) "<<r_<<endl;
        r_=r_+1;
        x_=(xParam+(r_*sin((angleParam+theta)*0.01745329251)));
        y_=(yParam+(r_*cos((angleParam+theta)*0.01745329251)));
        test=isInsideObject(x_,y_);


    }
    //    cout<<" ("<<x_<<" , "<<y_<<" ) ";
    //    glLineWidth(5);
    //    glBegin(GL_LINES);{
    //        glColor3f(0,1,1);
    //        glVertex3f(prx,5,pry);
    //        glVertex3f(x_,5,y_);
    //    }glEnd();
    if(r_>=(prr+15))
        return 1;
    else
        return 0;


}


void MyOpenGLWindow::setIRProximitySensorStatus(string str){
    if(str=="on"){
        irProximitySensorStatus=true;
    }
    else if(str=="off"){
        irProximitySensorStatus=false;
    }
}
string MyOpenGLWindow::getIRProximitySensorStatus(){
    if(irProximitySensorStatus){
        return("on");
    }
    else{
        return("off");
    }
}
string MyOpenGLWindow::getIRProximitySensorValues(){
    stringstream ss;
    ss <<irProximitySensor[1]<<" "<<irProximitySensor[2]<<" "<<irProximitySensor[3]<<" "<<irProximitySensor[4]<<" "<<irProximitySensor[5];
    return(ss.str());

}
void MyOpenGLWindow::start(){
    if(caseStudy!=2){

        angle=0;

        distanceLeft=velocityLeft*time;
        distanceRight=velocityRight*time;

        double tempAngle=0,radia=0;
        if(velocityLeft==velocityRight){

            robot_x=robot_x-sin(robot_angle*0.01745329251);
            robot_z=robot_z-cos(robot_angle*0.01745329251);
            updateGL();
        }
        else
        {
            if(velocityLeft!=velocityRight){
                radia=((200*distanceRight)/(distanceLeft-distanceRight));
                //        co_X=(radia);
            }
            //    else{
            //        radia=9999999999999;//100000000;
            //    }
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
        }
    }
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


void MyOpenGLWindow::mRead(){
    fin.open("/home/atul/shared_files/microcontrollerSignal.txt");
    fin>>mSignal;
    fin.close();
}
void MyOpenGLWindow::mWrite(){
    fout.open("/home/atul/shared_files/microcontrollerSignal.txt");
    fout<<mSignal;
    fout.close();
}
void MyOpenGLWindow::sRead(){
    fin.open("/home/atul/shared_files/simulatorSignal.txt");
    fin>>sSignal;
    fin.close();
}
void MyOpenGLWindow::sWrite(){
    fout.open("/home/atul/shared_files/simulatorSignal.txt");
    fout<<sSignal;
    fout.close();
}
void MyOpenGLWindow::semRead(){
    fin.open("/home/atul/shared_files/semaphore.txt");
    fin>>semaphore;
    fin.close();
}
void MyOpenGLWindow::semWrite(){
    fout.open("/home/atul/shared_files/semaphore.txt");
    fout<<semaphore;
    fout.close();
}
void MyOpenGLWindow::readCommand(){
    fin.open("/home/atul/shared_files/share.txt");
    getline(fin,inputString);
    fin.close();
}
void MyOpenGLWindow::writeCommand(){
    fout.open("/home/atul/shared_files/share.txt");
    fout<<command<<endl;
    fout.close();
}
void MyOpenGLWindow::writeResult(){
    fout.open("/home/atul/shared_files/share.txt");
    fout<<result<<endl;
    fout.close();
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
    //    if(robot_x>0 && robot_x<800 && robot_z<0 && robot_z>-600)
    {
        x=-robot_x;
        y=-robot_y;
        z=-robot_z;
        angle=robot_angle;
        while(n<forwardTrans){
            //        trans--;
            leftSpeed-=1.57969171135;
            rightSpeed-=1.57969171135;

            x=x+sin(angle*0.01745329251);
            z=z+cos(angle*0.01745329251);

            robot_x=-x;
            robot_y=-y;
            robot_z=-z;
            robot_angle=angle;
            updateGL();
            n++;

        }
    }
}
void MyOpenGLWindow::backward(){

    int n=0;
    //    if(robot_x>0 && robot_x<800 && robot_z<0 && robot_z>-600)
    {
        x=-robot_x;
        y=-robot_y;
        z=-robot_z;
        angle=robot_angle;

        while(n<backwardTrans){
            //        trans++;
            leftSpeed+=1.57969171135;
            rightSpeed+=1.57969171135;

            x=x-sin(angle*0.01745329251);
            z=z-cos(angle*0.01745329251);

            robot_x=-x;
            robot_y=-y;
            robot_z=-z;
            robot_angle=angle;
            updateGL();
            n++;
        }
    }
}
void MyOpenGLWindow::right(){

    //    rightAngle=90;
    //    double pa=robot_angle;
    //    for(;robot_angle>=pa-90;robot_angle--){
    //        updateGL();
    //    }
    //    if(robot_x>0 && robot_x<800 && robot_z<0 && robot_z>-600)
    {
        x=-robot_x;
        y=-robot_y;
        z=-robot_z;
        angle=robot_angle;

        for(int i=0;i<0.5*rightAngle;i++){
            leftSpeed-=1.57969171135;
            rightSpeed+=1.57969171135;
            angle=angle-2;
            robot_angle=angle;
            updateGL();
        }
    }

}
void MyOpenGLWindow::left(){


    //    leftAngle=90;
    //    for(int i=0;i<leftAngle;i++){
    //        robot_angle+=i;
    //        updateGL();
    //    }
    //    if(robot_x>0 && robot_x<800 && robot_z>0 && robot_z<600)
    {
        x=-robot_x;
        y=-robot_y;
        z=-robot_z;
        angle=robot_angle;

        for(int i=0;i<0.5*leftAngle;i++){
            leftSpeed+=1.57969171135;
            rightSpeed-=1.57969171135;
            angle=angle+2;
            robot_angle=angle;
            updateGL();
        }
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
    //    g->floor[int((g->troughtsRows*3)/2-rR)][rC]=3;

    g->printFloor();
    if((ix>0 && ix<= g->troughtsRows)&&(iy>0 && iy<= g->troughtsColums)){
        r=(ceil(ix/2.0)*3)-(ix%2)-1;
        c=iy;
        //        cout<<r<<" " <<c;
        //        g->floor[int((g->troughtsRows*3)/2-r)][c]=2;
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

    case Qt::Key_J:
        xt-=5;
        break;
    case Qt::Key_L:
        xt+=5;
        break;
    case Qt::Key_K:
        yt-=5;
        break;
    case Qt::Key_I:
        yt+=5
                ;
        break;
    case Qt::Key_0:
        xt=0;yt=0;
        break;

    case Qt::Key_Escape:
        exit(0);
        break;
    }





    updateGL();
    //delete(m);
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
    glOrtho(-280.0, 280.0, -175.0, 175.0,-15000,15000.0);
    //    float ratio = 1.0f * width / height;
    //    glPerspective(1000, ratio, 0.2, 1200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}
void MyOpenGLWindow:: myRotate(GLfloat angle, GLfloat X, GLfloat Y, GLfloat Z, GLfloat co_X, GLfloat co_Y, GLfloat co_Z){
    glTranslatef(co_X,co_Y,co_Z);
    glRotatef(angle,X,Y,Z);
    glTranslatef(-co_X,-co_Y,-co_Z);
}


void MyOpenGLWindow::initializeGL(){

    //    const char* file_name[] = { "top1.ppm","linefollowerfloor.ppm","greenhousefloor.ppm","mazefloor.ppm","top2.ppm","floor.ppm",
    //                                "bottom.ppm"};
    //    tx.textureInitialisation(file_name, textureNum, 7);
//    cout<<"here"<<endl;
    //    const char* file_name[] = {"top1.ppm"};
    //    tx.textureInitialisation(file_name, textureNum, 1);
//    cout<<"here"<<endl;
    GLfloat material_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 100 };

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
    GLfloat light0_position[] = { 1000.0, 1000.0, 1000.0, 0.0 };
    GLfloat light1_position[] = { 10000.0, 10000.0, 10000.0, 0.0 };
    GLfloat light2_position[] = { -1000.0, 1000.0, 1000.0, 0.0 };
    GLfloat light3_position[] = { 1000.0, 1000.0, -1000.0, 0.0 };

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    //    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
    glLightfv(GL_LIGHT3, GL_POSITION, light3_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);



    glShadeModel(GL_SMOOTH);
    glClearColor(1,1,1,0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    //    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}
