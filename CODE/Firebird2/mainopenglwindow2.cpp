/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "mainopenglwindow2.h"

mainOpenglWindow2::mainOpenglWindow2(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::ClickFocus);
    xRotated=80;yRotated=0;zRotated=0;zoom=0.5;
    xTrans=150;yTrans=60;zTrans=0;

    xRotated=15;yRotated=30;zRotated=0;zoom=1;
    xTrans=-10;yTrans=-40;zTrans=0;
    irProximitySensors=new point[8];
    irDistanceSensors=new point[8];
    sonarSensors=new point[8];

    robotPrm.velocityLeft=0;
    robotPrm.velocityRight=0;

    robotCurrent.x=20;
    robotCurrent.y=10;
    robotCurrent.z=-20;



    floorImg=new image();


    envObjectType tempFloor={"Floor",220,220,0,0,0,0};
    envObjectList.push_back(tempFloor);

    robotObjectType tempChassis={"Chassis",0,0};
    robotObjectList.push_back(tempChassis);

    envFlag=false;
    robotFlag=false;

    bzero((char*)&server,sizeof(server));
    portNumber=5005;
    //    cm=new communicate();

    readCommandTimer=new QTimer();
//    readCommandTimer->start(1);
    connect(readCommandTimer,SIGNAL(timeout()),SLOT(receive()));
    //    connect(readCommandTimer,SIGNAL(timeout()),SLOT(start()));
    //    cout<<"mSignal----->"<<mSignal<<endl;
    mRead();
    //    cout<<"mSignal----->"<<mSignal<<endl;
    prvmSignal=mSignal;
    sRead();

    lineSensorStatus=true;
    irProximitySensorsStatus=true;
    irDistanceSensorStatus=true;
    sonarSensorSatus=true;

}
void mainOpenglWindow2::reset(){
    readCommandTimer->stop();
    motionCommand="stop";
    robotCurrent=robotInit;
    updateGL();
}

void mainOpenglWindow2::start(){

    robotInit=robotCurrent;
    //    cm->startTimer();
        cout<<"start..........."<<endl;
        readCommandTimer->start(1);
        mRead();
        //    cout<<"mSignal----->"<<mSignal<<endl;
        prvmSignal=mSignal;
        sRead();

//    if(motionCommand=="forward"){
//        robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*1;
//        robotPrm.velocityRight=fabs(robotPrm.velocityRight)*1;
//        move();
//    }
//    else if(motionCommand=="backward"){
//        robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*-1;
//        robotPrm.velocityRight=fabs(robotPrm.velocityRight)*-1;
//        move();
//    }
//    else if(motionCommand=="left"){
//        robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*-1;
//        robotPrm.velocityRight=fabs(robotPrm.velocityRight)*1;
//        move();
//    }
//    else if(motionCommand=="right"){
//        robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*1;
//        robotPrm.velocityRight=fabs(robotPrm.velocityRight)*-1;
//        move();
//    }
//    else if(motionCommand=="stop"){
//    }

    //    cout<<"vel======> "<<robotPrm.velocityLeft<<"  "<<robotPrm.velocityRight<<endl;

}
void mainOpenglWindow2::send(string str){

}
void mainOpenglWindow2::receive(){
    readCommandTimer->stop();

    mRead();
    if(prvmSignal!=mSignal){
        semRead();
        while(semaphore){semRead();}
        semaphore=1;semWrite();
        readCommand();
        semaphore=0;semWrite();

        //        cout<<"input-->"<<inputString<<endl;
//        cout<<command<<"----"<<arguments[0]<<" "<<arguments[1]<<endl;
        if(command=="forward" || command=="backward" ||command=="left"||command=="right"||command=="stop")
        {
            motionCommand=command;
        }
        else if(command=="glss"){
            if(lineSensorStatus){results="on";}else{results="off";}
        }
        else if(command=="girpss"){
            if(irProximitySensorsStatus){results="on";}else{results="off";}
        }
        else if(command=="girdss"){
            if(irDistanceSensorStatus){results="on";}else{results="off";}
        }
        else if(command=="gsss"){
            if(sonarSensorSatus){results="on";}else{results="off";}
        }
        else if(command=="slss"){
            if(arguments[0]=="on"){lineSensorStatus=true;}else{lineSensorStatus=false;}
        }
        else if(command=="sirpss"){
            if(arguments[0]=="on"){irProximitySensorsStatus=true;}else{irProximitySensorsStatus=false;}
        }
        else if(command=="sirdss"){
            if(arguments[0]=="on"){irDistanceSensorStatus=true;}else{irDistanceSensorStatus=false;}
        }
        else if(command=="ssss"){
            if(arguments[0]=="on"){sonarSensorSatus=true;}else{sonarSensorSatus=false;}
        }
        else if(command=="sv"){
            robotPrm.velocityLeft=atof(arguments[0].c_str());
            robotPrm.velocityRight=atof(arguments[1].c_str());

//            cout<<"string velocity------"<<arguments[0].c_str()<<" "<<arguments[1].c_str()<<endl;
//            cout<<"velocity------"<<robotPrm.velocityLeft<<" "<<robotPrm.velocityRight<<endl;
        }
        else if(command=="gls"){
            stringstream ss;
            for(int i=0;i<robotPrm.lineSensorCount+2;i++){
            ss <<lineSensors[i].value<<" ";
            }
            results=ss.str();
        }
        else if(command=="girps"){
            stringstream ss;
            for(int i=0;i<robotPrm.irProximitySensorCount;i++){
            ss <<irProximitySensors[i].value<<" ";
            }
            results=ss.str();
        }
        else if(command=="girds"){
            stringstream ss;
            for(int i=0;i<robotPrm.irDistanceSensorCount;i++){
            ss <<irDistanceSensors[i].value<<" ";
            }
            results=ss.str();
        }
        else if(command=="gss"){
            stringstream ss;
            for(int i=0;i<robotPrm.sonarSensorCount;i++){
            ss <<sonarSensors[i].value<<" ";
            }
            results=ss.str();
        }
        /*
          do ur stuff
          */
//        results="Hello";

        cout<<inputString<<"----->"<<results<<endl;
        semRead();
        while(semaphore){semRead();}
        semaphore=1;semWrite();
        writeResult();
        semaphore=0;semWrite();


        sSignal=!sSignal;
        sWrite();

        prvmSignal=mSignal;

    }
    {
        if((robotCurrent.z < -floorImg->height-200 )
                ||(robotCurrent.z > 200)
                ||(robotCurrent.x < -200 )
                ||(robotCurrent.x > floorImg->width+200)){
            motionCommand="stop";
        }
        if(motionCommand=="forward"){
            robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*1;
            robotPrm.velocityRight=fabs(robotPrm.velocityRight)*1;
            move();
        }
        else if(motionCommand=="backward"){
            robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*-1;
            robotPrm.velocityRight=fabs(robotPrm.velocityRight)*-1;
            move();
        }
        else if(motionCommand=="left"){
            robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*-1;
            robotPrm.velocityRight=fabs(robotPrm.velocityRight)*1;
            move();
        }
        else if(motionCommand=="right"){
            robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*1;
            robotPrm.velocityRight=fabs(robotPrm.velocityRight)*-1;
            move();
        }
        else if(motionCommand=="stop"){
        }
    }
    readCommandTimer->start(1);

}




void mainOpenglWindow2::getEnvName(string strPrm){
    cout<<"MyOpenGLWindow2 "<<strPrm<<endl;
    envFlag=true;

    fstream file;
    file.open(strPrm.c_str());
    string str;
    envObjectType temp;
    envObjectList.clear();
    while(file>>str){
        temp.name=str;
        if(str[0]=='/'){
            floorImg->name=str;
            floorTextureNumber=floorImg->createImageTexture();
//            cout<<floorTextureNumber<<endl;
            //            fstream f;
            //            f.open("testy.txt",ios::out);
            //            for(int i = 0; i < floorImg->height; i++){
            //                for(int j = 0; j < floorImg->width; j++){
            //                    f<<floorImg->imgdata[i][j]<<" ";
            //                }
            //                f<<endl<<endl;
            //            }
            //            f.close();
        }
        file>>temp.sizeX>>temp.sizeY>>temp.sizeZ>>temp.locationX>>temp.locationY>>temp.locationZ;
        envObjectList.push_back(temp);

    }
    file.close();
    zoom=320.00/floorImg->width;
    envObjectType left={"Boundary_l",200,floorImg->height+400,400,-200,-200,0};
    envObjectType right={"Boundary_r",200,floorImg->height+400,400,floorImg->width,-200,0};
    envObjectType top={"Boundary_t",floorImg->width,200,400,0,floorImg->height,0};
    envObjectType bottom={"Boundary_b",floorImg->width,200,400,0,-200,0};
    envObjectList.push_back(left);
    envObjectList.push_back(right);
    envObjectList.push_back(top);
    envObjectList.push_back(bottom);

    updateGL();
}
void mainOpenglWindow2::drawEnv(){
    glTranslatef(-envObjectList[0].sizeX/2,0,envObjectList[0].sizeY/2);
    for(int i=0;i<envObjectList.size();i++){
        if(envObjectList[i].name[0]=='/'){
            glColor4f(1, 1, 1,1);

            tx.enableTexture(floorTextureNumber);
            glPushMatrix();{
                glBegin(GL_POLYGON);
                glTexCoord2f(0,1);glNormal3f(0,1,0);glVertex3f(0,0,0);
                glTexCoord2f(1,1);glNormal3f(0,1,0);glVertex3f(envObjectList[i].sizeX,0,0);
                glTexCoord2f(1,0);glNormal3f(0,1,0);glVertex3f(envObjectList[i].sizeX,0,-envObjectList[i].sizeY);
                glTexCoord2f(0,0);glNormal3f(0,1,0);glVertex3f(0,0,-envObjectList[i].sizeY);
                glEnd();
            }glPopMatrix();
            tx.disableTexture();
        }
        else if(envObjectList[i].name[0]=='C') {
            glColor3f(0.9f, 0.9f, 0.9f);
            glPushMatrix();{
                glTranslatef(envObjectList[i].locationX,envObjectList[i].locationZ,-envObjectList[i].locationY);
                myDrawRectangulatPrism(envObjectList[i].sizeX,envObjectList[i].sizeZ,envObjectList[i].sizeY);
            }glPopMatrix();
        }
    }
}

void mainOpenglWindow2::getRobotName(string strPrm){
    cout<<"MyOpenGLWindow2 "<<strPrm<<endl;

    robotFlag=true;
    image *img1;
    img1=new image();

    img1->name="top.png";
    robotTextureNumber=img1->createImageTexture1();

    fstream file;
    file.open(strPrm.c_str(),ios::in);
    string str;
    robotObjectType temp;
    robotObjectList.clear();
    while(file>>str){
        temp.name=str;
        file>>temp.distance>>temp.count;
        if(temp.name=="Line_Sensors"){
            robotPrm.lineSensorDistance=temp.distance;
            robotPrm.lineSensorCount=temp.count;
        }
        else if(temp.name=="IR_Proximity_Sensors"){
            robotPrm.irProximitySensorCount =temp.count;
        }
        else if(temp.name=="IR_Distance_Sensors"){
            robotPrm.irDistanceSensorCount =temp.count;
        }
        else if(temp.name=="Sonar_Sensors"){
            robotPrm.sonarSensorCount =temp.count;
        }
        robotObjectList.push_back(temp);

    }
    robotPrm.scale=0.3;
    lineSensors=new point[robotPrm.lineSensorCount+2];
    calcSensorsLocation();
    file.close();
    updateGL();
}
void mainOpenglWindow2::drawRobot(){
    glPushMatrix();{

        glTranslatef(robotCurrent.x,robotCurrent.y,robotCurrent.z);
        glRotatef(robotCurrent.angle,0,1,0);
        glScalef( robotPrm.scale, robotPrm.scale, robotPrm.scale);
        glPushMatrix();{
            for(int i=0;i<robotObjectList.size();i++){
                if(robotObjectList[i].name=="Chassis"){
                    tx.enableTexture(robotTextureNumber);
                    rb.drawChassis();
                    tx.disableTexture();
                }
                else if(robotObjectList[i].name=="Motors"){
                    rb.mototDistance=robotObjectList[i].distance;
                    rb.drawMotors();
                }
                else if(robotObjectList[i].name=="Line_Sensors"){
                    rb.lineSensorDistance=robotObjectList[i].distance;
                    rb.lineSensorCount=robotObjectList[i].count;
                    rb.drawLineSensors();
                }
                else if(robotObjectList[i].name=="IR_Proximity_Sensors"){
                    rb.drawIRProximitySensors();
                }
                else if(robotObjectList[i].name=="IR_Distance_Sensors"){
                    rb.drawIRDistanceSensors();
                }
                else if(robotObjectList[i].name=="Sonar_Sensors"){
                    rb.drawSonarSensors();
                }

            }
        }glPopMatrix();
    }glPopMatrix();

}
void mainOpenglWindow2::getPortNumber(int portnum){
    portNumber=portnum;
//    cout<<portNumber<<endl;

}
void mainOpenglWindow2::updateRobotLocation(robotLocation r){
    robotInit=r;
//    cout<<robotInit.x<<" "<<robotInit.y<<" "<<robotInit.z<<" "<<robotInit.angle<<endl;
    robotCurrent=r;
    robotPrev=robotCurrent;

    updateGL();
}

void mainOpenglWindow2::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Escape:
        exit(0);
        break;
    case Qt::Key_PageUp:
        zoom+=0.1;
        cout<<"zoom="<<zoom<<endl;
        break;
    case Qt::Key_PageDown:
        zoom-=0.1;
        cout<<"zoom="<<zoom<<endl;
        break;
    case Qt::Key_End:
        zoom=1;
        break;
    case Qt::Key_Right:
        xTrans+=5;
        break;
    case Qt::Key_Left:
        xTrans-=5;
        break;
    case Qt::Key_Up:
        yTrans+=5;
        break;
    case Qt::Key_Down:
        yTrans-=5;
        break;
    case Qt::Key_A:			// a = 97
        yRotated-=5;
        break;
    case Qt::Key_D:
        yRotated+=5;
        break;

    case Qt::Key_W:
        xRotated-=5;
        break;
    case Qt::Key_S:
        xRotated+=5;
        break;

    case Qt::Key_X:
        zRotated-=5;
        break;
    case Qt::Key_Z:
        zRotated+=5;
        break;

    case Qt::Key_R:
        xRotated=15;yRotated=30;zRotated=0;zoom=1;
        xTrans=-40;yTrans=-40;zTrans=0;
        break;
    }
    updateGL();
}
void mainOpenglWindow2::initializeGL(){
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
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

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
void mainOpenglWindow2::resizeGL(int width, int height){

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
    glOrtho(-205.0, 205.0, -140.0, 140.0,-5000,2000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}
void mainOpenglWindow2::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(xTrans,yTrans,zTrans);
    glScalef(zoom,zoom,zoom);
    glRotatef(xRotated,1.0,0.0,0.0); // rotation about X axis
    glRotatef(yRotated,0.0,1.0,0.0);// rotation about Y axis
    glRotatef(zRotated,0.0,0.0,1.0);  // rotation about Z axis

//    cout<<xRotated<<" "<<yRotated<<" "<<zRotated<<"-----";
//    cout<<xTrans<<" "<<yTrans<<" "<<zTrans<<endl;


    if(envFlag)
        drawEnv();
    if(robotFlag){
        calcSensorsLocation();
        drawRobot();
//        cout<<robotCurrent.angle<<endl;


        //        cout<<axis.x<<"   "<<axis.z<<endl;

//        glColor3f(1,0,0);
//        glBegin(GL_LINES);{
//            glVertex3f(axis.x,100,axis.z);
//            glVertex3f(axis.x,-100,axis.z);
//        }glEnd();
        glColor3f(1,1,1);

        {
            glColor3f(1,0,0);
            calcLineSensorsValues();
            calcIRDistanceSensorsValues();
            //            for(int i=0;i<robotPrm.lineSensorCount;i++){
            //                cout<<lineSensors[i].value<<" ";
            //            }
//            cout<<endl;
            //            cout<<"line sensors-------------------------------------"<<endl;
//                        for(int i=0;i<robotPrm.lineSensorCount+2;i++){
//                            glBegin(GL_LINES);{
//                                //            cout<<lineSensors[i].x<<"##########"<<lineSensors[i].z<<endl;
//                                glVertex3f(lineSensors[i].x,-100,lineSensors[i].z);
//                                glVertex3f(lineSensors[i].x,100,lineSensors[i].z);

//                            }glEnd();
//                        }

            //            cout<<"ir proximity-------------------------------------"<<endl;
//            for(int i=0;i<8;i++){
//                glBegin(GL_LINES);{
//                    //            cout<<lineSensors[i].x<<"##########"<<lineSensors[i].z<<endl;
//                    glVertex3f(irProximitySensors[i].x,-100,irProximitySensors[i].z);
//                    glVertex3f(irProximitySensors[i].x,100,irProximitySensors[i].z);

//                }glEnd();
//            }
            glColor3f(1,1,1);
        }


    }

    //            glBegin(GL_POLYGON);
    //            glVertex3f(0,0,0);
    //            glVertex3f(100,0,0);
    //            glVertex3f(100,100,0);
    //            glVertex3f(0,100,0);

    //    glEnd();
}
void mainOpenglWindow2::mRead(){
    int tt;
    fin.open("shared_files/microcontrollerSignal.txt");
    fin>>mSignal;
    fin.close();
}
void mainOpenglWindow2::mWrite(){
    fout.open("shared_files/microcontrollerSignal.txt");
    fout<<mSignal;
    fout.close();
}
void mainOpenglWindow2::sRead(){
    fin.open("shared_files/simulatorSignal.txt");
    fin>>sSignal;
    fin.close();
}
void mainOpenglWindow2::sWrite(){
    fout.open("shared_files/simulatorSignal.txt");
    fout<<sSignal;
    fout.close();
}
void mainOpenglWindow2::semRead(){
    fin.open("shared_files/semaphore.txt");
    fin>>semaphore;
    fin.close();
}
void mainOpenglWindow2::semWrite(){
    fout.open("shared_files/semaphore.txt");
    fout<<semaphore;
    fout.close();
}
void mainOpenglWindow2::readCommand(){
    fin.open("shared_files/share.txt");
    getline(fin,inputString);
    fin.close();

    istringstream iss(inputString);

    arguments.clear();
    bool sflag=true;
    do
    {
        string tempSub;
        iss >> tempSub;
        if(sflag){
            command=tempSub;
            sflag=false;
        }
        else
            arguments.push_back(tempSub);
    }while(iss);
}
void mainOpenglWindow2::writeCommand(){
    fout.open("shared_files/share.txt");
    fout<<command<<endl;
    fout.close();
}
void mainOpenglWindow2::writeResult(){
    fout.open("shared_files/share.txt");
    fout<<results<<endl;
    fout.close();
}

void mainOpenglWindow2::calcSensorsLocation(){
    //    cout<<"robotCurrent---->"<<robotCurrent.x<<" "<<robotCurrent.z<<endl;

    // line sensors without side sensors-----------------------------------------------------------------
/*    {
        double ldis=robotPrm.lineSensorDistance*robotPrm.scale;
        double d;
        d=ldis*(robotPrm.lineSensorCount/2);
        for(int i=0;i<robotPrm.lineSensorCount;i++){
            lineSensors[i].x=robotCurrent.x
                    -(160*robotPrm.scale)*sin(robotCurrent.angle*0.01745329251)
                    -d*cos(robotCurrent.angle*0.01745329251);
            lineSensors[i].z=robotCurrent.z
                    -(160*robotPrm.scale)*cos(robotCurrent.angle*0.01745329251)
                    +d*sin(robotCurrent.angle*0.01745329251);

            d-=ldis;

        }
    }
*/
    // line sensors with side sensors-----------------------------------------------------------------
    {
        double ldis=robotPrm.lineSensorDistance*robotPrm.scale;
        double d;
        d=ldis*(robotPrm.lineSensorCount/2);

        lineSensors[0].x=robotCurrent.x
                -(2)*d*cos(robotCurrent.angle*0.01745329251);
        lineSensors[0].z=robotCurrent.z
                +(2)*d*sin(robotCurrent.angle*0.01745329251);

        lineSensors[1].x=robotCurrent.x
                -(-1)*(2)*d*cos(robotCurrent.angle*0.01745329251);
        lineSensors[1].z=robotCurrent.z
                +(-1)*(2)*d*sin(robotCurrent.angle*0.01745329251);

        for(int i=2;i<robotPrm.lineSensorCount+2;i++){
            lineSensors[i].x=robotCurrent.x
                    -(160*robotPrm.scale)*sin(robotCurrent.angle*0.01745329251)
                    -d*cos(robotCurrent.angle*0.01745329251);
            lineSensors[i].z=robotCurrent.z
                    -(160*robotPrm.scale)*cos(robotCurrent.angle*0.01745329251)
                    +d*sin(robotCurrent.angle*0.01745329251);

            d-=ldis;

        }
    }

    // IRproximity sensors-----------------------------------------------------------------
    {
        int alpha=180;
        for(int i=0;i<robotPrm.irProximitySensorCount;i++){
            irProximitySensors[i].x=robotCurrent.x
                    -(50*robotPrm.scale)*sin(robotCurrent.angle*0.01745329251)
                    +(105*robotPrm.scale)*cos((robotCurrent.angle+alpha)*0.01745329251);

            irProximitySensors[i].z=robotCurrent.z
                    -(50*robotPrm.scale)*cos(robotCurrent.angle*0.01745329251)
                    -(105*robotPrm.scale)*sin((robotCurrent.angle+alpha)*0.01745329251);

            irProximitySensors[i].y=robotCurrent.y+58*robotPrm.scale;
            alpha-=45;

        }
    }

    // IRdistance sensors-----------------------------------------------------------------
    {
        int alpha=180;
        for(int i=0;i<robotPrm.irDistanceSensorCount;i++){
            irDistanceSensors[i].x=robotCurrent.x
                    -(50*robotPrm.scale)*sin(robotCurrent.angle*0.01745329251)
                    +(105*robotPrm.scale)*cos((robotCurrent.angle+alpha)*0.01745329251);

            irDistanceSensors[i].z=robotCurrent.z
                    -(50*robotPrm.scale)*cos(robotCurrent.angle*0.01745329251)
                    -(105*robotPrm.scale)*sin((robotCurrent.angle+alpha)*0.01745329251);

            irDistanceSensors[i].y=robotCurrent.y+69*robotPrm.scale;

            alpha-=45;

        }
    }

    // sonar sensors-----------------------------------------------------------------
    {
        int alpha=180;
        for(int i=0;i<robotPrm.sonarSensorCount;i++){
            sonarSensors[i].x=robotCurrent.x
                    -(50*robotPrm.scale)*sin(robotCurrent.angle*0.01745329251)
                    +(105*robotPrm.scale)*cos((robotCurrent.angle+alpha)*0.01745329251);

            sonarSensors[i].z=robotCurrent.z
                    -(50*robotPrm.scale)*cos(robotCurrent.angle*0.01745329251)
                    -(105*robotPrm.scale)*sin((robotCurrent.angle+alpha)*0.01745329251);

            sonarSensors[i].y=robotCurrent.y+79*robotPrm.scale;

            alpha-=45;

        }
    }
}
void mainOpenglWindow2::calcLineSensorsValues(){
    //    cout<<floorImg->width<<"  X  "<<floorImg->height<<endl;
    for(int i=0;i<robotPrm.lineSensorCount+2;i++){
        int x=lineSensors[i].x;
        int y=floorImg->height+lineSensors[i].z;
        //        cout<<x<<" "<<y<<" ---->";
        if(( x>0 &&  x<floorImg->width)
                &&(y>0 && y<floorImg->height)){

            if(floorImg->imgdata[y][x]>=0.6){
                lineSensors[i].value=1;
            }
            else{
                lineSensors[i].value=0;
            }

            //            lineSensors[i].value=floorImg->imgdata[y][x];
            //            cout<<"in ";
        }
        else{
            lineSensors[i].value=0;
        }
        //        cout<<lineSensors[i].value<<endl;

    }

}

void mainOpenglWindow2::calcIRDistanceSensorsValues(){

    int alpha=180;

    int value=0;
    if(sonarSensorSatus){
        value=1000;
    }
    else if(irDistanceSensorStatus){
        value=1000;
    }
    else if(irProximitySensorsStatus){
        value=10;
    }

    point pr;
    for(int i=0;i<robotPrm.irDistanceSensorCount;i++){

        int rr=-10;
        bool flag=true;
        while(flag && rr<value){

            rr+=10;
            pr.x=robotCurrent.x
                    -(50*robotPrm.scale)*sin(robotCurrent.angle*0.01745329251)
                    +(rr+(105*robotPrm.scale))*cos((robotCurrent.angle+alpha)*0.01745329251);

            pr.z=robotCurrent.z
                    -(50*robotPrm.scale)*cos(robotCurrent.angle*0.01745329251)
                    -(rr+(105*robotPrm.scale))*sin((robotCurrent.angle+alpha)*0.01745329251);

            pr.y=irDistanceSensors[i].y;

            //            struct envObjectType {
            //                string name;
            //                int sizeX,sizeY,sizeZ;
            //                int locationX,locationY,locationZ;
            //            };

            for(int j=0;j<envObjectList.size();j++){
                //                for(vector<envObjectType>::iterator it = envObjectList.begin() ; it != envObjectList.end(); ++it){
                point start,end;
                start.x=envObjectList[j].locationX;
                start.y=envObjectList[j].locationZ;
                start.z=-envObjectList[j].locationY;

                end.x=start.x+envObjectList[j].sizeX;
                end.y=start.y+envObjectList[j].sizeZ;
                end.z=start.z-envObjectList[j].sizeY;

                if((pr.x>start.x && pr.x<end.x)
                        &&(pr.y>start.y && pr.y<end.y)
                        &&(pr.z<start.z && pr.z>end.z)){
                    flag=false;
                    break;
                }

            }

        }
        sonarSensors[i].value=rr;
        if(rr>1000){
            irDistanceSensors[i].value=1000;
        }
        else{
            irDistanceSensors[i].value=rr;
        }

        if(rr>=10){
            irProximitySensors[i].value=1;
        }
        else{
            irProximitySensors[i].value=0;
        }


//        glBegin(GL_LINES);{
//            glVertex3f(irDistanceSensors[i].x,irDistanceSensors[i].y,irDistanceSensors[i].z);
//            glVertex3f(pr.x,pr.y,pr.z);
//        }glEnd();

        alpha-=45;

    }

}


void mainOpenglWindow2::setVelocityLeft(double v){
    robotPrm.velocityLeft=v*1;

}
void mainOpenglWindow2::setVelocityRight(double v){
    robotPrm.velocityRight=v*1;

}
void mainOpenglWindow2::setVelocity(double v){
    robotPrm.velocityLeft=v*1;
    robotPrm.velocityRight=v*1;

}

void mainOpenglWindow2::forward(){
    //    robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*1;
    //    robotPrm.velocityRight=fabs(robotPrm.velocityRight)*1;
    cout<<"forward"<<endl;
    motionCommand="forward";
}

void mainOpenglWindow2::backward(){
    //    robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*-1;
    //    robotPrm.velocityRight=fabs(robotPrm.velocityRight)*-1;
    cout<<"backward"<<endl;
    motionCommand="backward";
}

void mainOpenglWindow2::left(){
    //    robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*1;
    //    robotPrm.velocityRight=fabs(robotPrm.velocityRight)*-1;
    cout<<"left"<<endl;
    motionCommand="left";

}

void mainOpenglWindow2::right(){
    //    robotPrm.velocityLeft=fabs(robotPrm.velocityLeft)*-1;
    //    robotPrm.velocityRight=fabs(robotPrm.velocityRight)*1;
    cout<<"right"<<endl;
    motionCommand="right";

}
void mainOpenglWindow2::stop(){
//    cout<<"stop"<<endl;
    readCommandTimer->stop();
    motionCommand="stop";
//    stringstream ss;
//    for(int i=0;i<robotPrm.lineSensorCount;i++){
//    ss <<lineSensors[i].value<<" ";
//    }
//    cout<<ss.str()<<endl;

}

void mainOpenglWindow2::move(){
    //    cout<<motionCommand<<" "<<robotPrm.velocityLeft<<" "<<robotPrm.velocityRight<<endl;

    robotPrev=robotCurrent;

    double time=0.01;
    double distanceLeft=robotPrm.velocityLeft*time;
    double distanceRight=robotPrm.velocityRight*time;

    double theta=0,r=0;

    //    cout<<robotCurrent.x<<" "<<robotCurrent.z<<"  <"<<robotCurrent.angle<<" sin"<<sin(robotCurrent.angle*0.01745329251)<<" cos"<<cos(robotCurrent.angle*0.01745329251)<<endl;
    if(robotPrm.velocityLeft==robotPrm.velocityRight){
        robotCurrent.x=robotCurrent.x-distanceLeft*0.8*sin(robotCurrent.angle*0.01745329251);
        robotCurrent.z=robotCurrent.z-distanceLeft*0.8*cos(robotCurrent.angle*0.01745329251);


        //        if(robotPrm.velocityLeft>0 && robotPrm.velocityRight>0){
        //            robotCurrent.x=robotCurrent.x-distanceLeft*sin(robotCurrent.angle*0.01745329251);
        //            robotCurrent.z=robotCurrent.z-distanceLeft*cos(robotCurrent.angle*0.01745329251);
        //        }
        //        else{
        //            robotCurrent.x=robotCurrent.x+sin(robotCurrent.angle*0.01745329251);
        //            robotCurrent.z=robotCurrent.z+cos(robotCurrent.angle*0.01745329251);
        //        }
        updateGL();
    }
    else if(robotPrm.velocityLeft!=robotPrm.velocityRight){

        r=((200*distanceLeft)/(distanceRight-distanceLeft));


        if(distanceLeft<distanceRight){
            r=fabs(r)*-1;
        }
        else{
            r=fabs(r)*1;
        }
        if(distanceRight!=0){
            //            cout<<"R  ";
            theta=(distanceRight/r+200);//*0.01745329251;
        }
        else if(distanceLeft!=0){
            //            cout<<"L  ";
            theta=(distanceLeft/(r));
        }
        else{
            theta=0;
        }

        //        cout<<distanceLeft<<" "<<distanceRight<<" "<<r;
        //        r-=100;
        if(distanceLeft<distanceRight){
            r+=100;
        }
        else{
            r-=100;
        }
        r*=robotPrm.scale;


        if(motionCommand=="left"
                ||(motionCommand=="forward" && distanceLeft>distanceRight)
                ||(motionCommand=="backward" && distanceLeft<distanceRight)){
            theta=fabs(theta)*1;
        }
        else{
            theta=fabs(theta)*-1;
        }

        if(motionCommand=="forward"){
            r=-r;
            theta=-theta;
        }


        //        cout<<theta<<endl;
        theta/=400;
        //        cout<<"  <"<<theta<<endl;


        axis.x=robotCurrent.x-r*cos(robotCurrent.angle*0.01745329251);
        axis.z=robotCurrent.z+r*sin(robotCurrent.angle*0.01745329251);


        robotCurrent.x=axis.x
                +r*cos((theta+robotCurrent.angle)*0.01745329251);

        robotCurrent.z=axis.z
                -r*sin((theta+robotCurrent.angle)*0.01745329251);

        robotCurrent.angle=(robotCurrent.angle+theta);

        updateGL();
    }
}
void mainOpenglWindow2::stops(){

}
