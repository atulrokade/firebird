/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "robot.h"

robot::robot()
{
    scale=1;
    mototDistance=20;
    irProximitySensorCount=8;irDistanceSensorCount=8;

}
robot::robot(float s){
    scale=s;
    mototDistance=20;
    irProximitySensorCount=8;irDistanceSensorCount=8;
}

void robot::drawRobot(float s,double leftSpeed_prm,double rightSpeed_prm){
    scale=s;
    glScalef(scale,scale,scale);

    {
        glScalef(1,1,1);
        glTranslatef(0,32,0);
        glPushMatrix();{
            /*//glTranslatef(-x,0,-z);
            //        glBegin(GL_LINES);{
            //            glColor3f(1,0,0);
            //            glVertex3f(robot_x,-100,robot_z);
            //            glVertex3f(robot_x,100,robot_z);
            //        }glEnd();
            //        glTranslated(robot_x,robot_y,robot_z);
            //        glRotated(robot_angle,0,1,0);
 */
            glPushMatrix();{
                /*//glRotatef(angle,0,1,0);

                //            myRotate(prev_angle,0,1,0,prev_co_X,0,prev_co_Z);

                //            glBegin(GL_LINES);{
                //                glColor3f(0,1,1);
                //                glVertex3f(0,-100,0);
                //                glVertex3f(0,100,0);
                //            }glEnd();
                //            myRotate(angle,0,1,0,co_X,0,co_Z);
                //            glBegin(GL_LINES);{
                //                glColor3f(1,1,1);
                //                glVertex3f(co_X,-100,0);
                //                glVertex3f(co_X,100,0);
                //            }glEnd();
 */

                drawChassis();
                drawMotors();
                drawLineSensors();
                drawIRProximitySensors();
                drawIRDistanceSensors();
                drawSonarSensors();
            }glPopMatrix();
            glColor4f(.9,.9,.9,.2);
        }glPopMatrix();
    }
}
void robot::drawChassis(){
    glPushMatrix();{

        // draw front support cylender
        {
            glEnable (GL_BLEND);
            glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(.9,.9,.9,.2);

            glPushMatrix();{
                glRotatef(-90,1,0,0);
                glTranslatef(0,120,-32);
                myDrawCylinder(5,5,11,10,360);

            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(90,37,0);
                myDrawRectangulatPrism(5,45,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(-95,37,0);
                myDrawRectangulatPrism(5,45,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(90,37,-90);
                myDrawRectangulatPrism(5,45,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(-95,37,-90);
                myDrawRectangulatPrism(5,45,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(30,37,-145);
                myDrawRectangulatPrism(5,45,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(-35,37,-145);
                myDrawRectangulatPrism(5,45,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(30,37,50);
                myDrawRectangulatPrism(5,45,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(-35,37,50);
                myDrawRectangulatPrism(5,45,5);
            }glPopMatrix();

            glPushMatrix();{
                glTranslatef(40,-20,-40);
                myDrawRectangulatPrism(5,62,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(-45,-20,-40);
                myDrawRectangulatPrism(5,62,5);
            }glPopMatrix();
            glPushMatrix();{
                glTranslatef(-2.5,-20,-130);
                myDrawRectangulatPrism(5,62,5);
            }glPopMatrix();

            glDisable(GL_BLEND);

        }

        //draw bottom disk
        glPushMatrix();{
            glEnable (GL_BLEND);
            glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(.9,.9,.9,.2);
            glRotatef(-90,1,0,0);
            glTranslatef(-66,25,-15);

            drawBottomDisk(5);
            glDisable(GL_BLEND);

        }glPopMatrix();

        //draw top disk
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPushMatrix();{
            glColor4f(.9,.9,.9,.2);
            glRotatef(-90,1,0,0);
            glTranslatef(0,50,37);

            myDrawDisk(110,110,5,20);
            //draw middle disk
            glColor4f(1,1,1,1);
            glTranslatef(0,0,20);
            myDrawDiskWithTexture(110,110,2,20);


            glColor4f(.9,.9,.9,.1);
            glTranslatef(0,0,20);
            myDrawDisk(110,110,5,20);
            //                    myDrawCylinder(100,100,5,20,360);
        }glPopMatrix();
        glDisable(GL_BLEND);


    }glPopMatrix();
}


void robot::drawIRProximitySensors(){
    //draw IR proximity sensors


    for(int i=0;i<8;i++){
        glPushMatrix();{
            glTranslatef(0,48,-50);
            glRotatef(i*45,0,1,0);
            glPushMatrix();{
                glTranslatef(105,0,0);
                glRotatef(90,0,1,0);
                drawIRProximitySensor();
            }glPopMatrix();
        }glPopMatrix();
    }


}

void robot::drawIRProximitySensor(){
    glPushMatrix();{
        glColor3f(0.3,0.3,0.3);
        glTranslatef(-5,0,2);
        myDrawRectangulatPrism(10,10,5);
        glTranslatef(2.5,0,2);
        myDrawRectangulatPrism(5,10,2);
    }glPopMatrix();

}
void robot::drawIRDistanceSensors(){
    //draw IR Distance sensors
    for(int i=0;i<8;i++){
        glPushMatrix();{
            glTranslatef(0,59,-50);
            glRotatef(i*45,0,1,0);
            glPushMatrix();{
                glTranslatef(105,0,0);
                glRotatef(90,0,1,0);
                drawIRDistanceSensor();
            }glPopMatrix();
        }glPopMatrix();
    }

}

void robot::drawIRDistanceSensor(){
    glPushMatrix();{
        glColor3f(0.3,0.3,0.3);
        glTranslatef(-20,0,2);
        myDrawRectangulatPrism(40,10,5);
        glTranslatef(5,0,5);
        myDrawRectangulatPrism(10,10,5);
        glTranslatef(20,0,0);
        myDrawRectangulatPrism(10,10,5);
    }glPopMatrix();

}
void robot::drawSonarSensors(){

    //draw sonar sensors
    for(int i=0;i<8;i++){
        glPushMatrix();{
            glTranslatef(0,69,-50);
            glRotatef(i*45,0,1,0);
            glPushMatrix();{
                glTranslatef(105,0,0);
                glRotatef(90,0,1,0);
                drawSonarSensor();
            }glPopMatrix();
        }glPopMatrix();
    }



}

void robot::drawSonarSensor(){
    glPushMatrix();{
        glColor3f(0.3,0.3,0.3);
        glTranslatef(-20,0,2);
        myDrawRectangulatPrism(40,10,2);
        glTranslatef(10,5,0);
        glColor3f(0.9,0.9,0.9);
        myDrawCylinder(5,5,5,10,360);
        glTranslatef(20,0,0);
        myDrawCylinder(5,5,5,10,360);
    }glPopMatrix();

}
void robot::drawLineSensors(){

    // draw line Sensor
    {
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(.9,.9,.9,.2);


        glPushMatrix();{
            //                    glRotatef(-90,1,0,0);
            glTranslatef(0,-20,-150);

            glPushMatrix();{
                glTranslatef(-(lineSensorCount+1)*lineSensorDistance/2,0,0);
                myDrawRectangulatPrism((lineSensorCount+1)*lineSensorDistance,5,20);
            }glPopMatrix();
            drawLineSensor();
        }glPopMatrix();
        glDisable(GL_BLEND);

    }
}

void robot::drawLineSensor(){

//    lineSensorCount=7;
//    lineSensorDistance=20;
    glColor4f(.5,.5,.5,.2);
    glPushMatrix();{
        for(int i=-lineSensorCount/2;i<=lineSensorCount/2;i++){
            glPushMatrix();{
                glTranslatef(i*lineSensorDistance,0,-10);
                glRotatef(90,1,0,0);
                myDrawDisk(8,0,15,10);
            }glPopMatrix();

        }
    }glPopMatrix();


}



void robot::drawBottomDisk(double height){

    glPushMatrix();{
        glBegin(GL_POLYGON);{

            glNormal3f(0, 0, 1); //center//1
            glVertex3f(0, 0, 0);
            glNormal3f(0, 0, 1); //center//2
            glVertex3f(45, 125, 0);
            glNormal3f(0, 0, 1); //center//3
            glVertex3f(85, 125, 0);
            glNormal3f(0, 0, 1); //center//4
            glVertex3f(130, 0, 0);

        }glEnd();
    }glPopMatrix();
    glPushMatrix();{
        glBegin(GL_POLYGON);{

            glNormal3f(0, 0, -1); //center//h1
            glVertex3f(0, 0, -height);
            glNormal3f(0, 0, -1); //center//h2
            glVertex3f(45, 125, -height);
            glNormal3f(0, 0, -1); //center//h3
            glVertex3f(85, 125, -height);
            glNormal3f(0, 0, -1);; //center//h4
            glVertex3f(130, 0, -height);

        }glEnd();
    }glPopMatrix();
    glPushMatrix();{
        glBegin(GL_POLYGON);{
            glNormal3f(0, -1,0); //center//1
            glVertex3f(0, 0, 0);
            glNormal3f(0, -1,0); //center//4
            glVertex3f(130, 0, 0);
            glNormal3f(0, -1,0); //center//h4
            glVertex3f(130, 0, -height);
            glNormal3f(0, -1,0); //center//h1
            glVertex3f(0, 0, -height);
        }glEnd();
    }glPopMatrix();

    glPushMatrix();{
        glBegin(GL_POLYGON);{

            glNormal3f(130, 0, 0); //center//4
            glVertex3f(130, 0, 0);
            glNormal3f(85, 125, 0); //center//3
            glVertex3f(85, 125, 0);
            glNormal3f(85, 125, -height); //center//h3
            glVertex3f(85, 125, -height);
            glNormal3f(130, 0, -height); //center//h4
            glVertex3f(130, 0, -height);

        }glEnd();
    }glPopMatrix();

    glPushMatrix();{
        glBegin(GL_POLYGON);{

            glNormal3f(0, 1,0); //center//3
            glVertex3f(85, 125, 0);
            glNormal3f(0, 1,0); //center//2
            glVertex3f(45, 125, 0);
            glNormal3f(0, 1,0); //center//h2
            glVertex3f(45, 125, -height);
            glNormal3f(0, 1,0); //center//h3
            glVertex3f(85, 125, -height);
        }glEnd();
    }glPopMatrix();

    glPushMatrix();{
        glBegin(GL_POLYGON);{

            glNormal3f(45, 125, 0); //center//2
            glVertex3f(45, 125, 0);
            glNormal3f(0, 0, 0); //center//1
            glVertex3f(0, 0, 0);
            glNormal3f(0, 0, -height); //center//h1
            glVertex3f(0, 0, -height);
            glNormal3f(45, 125, -height); //center//h2
            glVertex3f(45, 125, -height);
        }glEnd();
    }glPopMatrix();
}
void robot::drawMotors(){
    //draw right motor with wheel and clamp
    glPushMatrix();{
        glTranslatef(mototDistance,0,0);
        glPushMatrix();{
            glTranslatef(26,37,22);
            drawClamp();
        }glPopMatrix();

        glRotatef(-90,0,0,1);

        drawMotor(rightSpeed);
    }glPopMatrix();

    //reflect and draw left motor with wheel and clamp
    glPushMatrix();{
        glScalef(-1,1,1);
        glTranslatef(mototDistance,0,0);
        glPushMatrix();{
            glPushMatrix();{
                glTranslatef(26,37,22);
                drawClamp();
            }glPopMatrix();

            glRotatef(-90,0,0,1);

            drawMotor(leftSpeed);
        }glPopMatrix();

    }glPopMatrix();

}

void robot::drawMotor(int velocity){
    glPushMatrix();{
        glRotatef(-90,1.0,0.0,0.0);
        glPushMatrix();{
            glColor3f(0.6,0.6,0.6);

            myDrawCylinder(20,20,20,30,360);
            glTranslatef(0,0,20);
            glColor3f(.2,.2,.2);
            myDrawCylinder(22,22,20,30,360);
            glTranslatef(0,0,20);

            myDrawRing(5,5,10,10,10,30,360);
            //glTranslatef(0,0,10);
            glColor3f(1,1,1);
            glPushMatrix();{
                glRotatef(velocity,0,0,1);
                myDrawCylinder(5,5,40,30,270);//shaft
                glTranslatef(0,0,21);

                drawWheel();
            }glPopMatrix();
        }glPopMatrix();
    }glPopMatrix();
}

void robot::drawWheel(){

    glColor3f(1,1,0);
    myDrawCylinder(8,8,9,30,360);
    glTranslatef(0,0,9);
    myDrawCylinder(30,30,9,30,360);
    glColor3f(.2,.2,.2);
    myDrawRing(30,30,32,32,9,30,360);

    glPushMatrix();{
        glTranslatef(10,10,10);
        myDrawCylinder(5,5,0,30,360);
    }glPopMatrix();
    glPushMatrix();{
        glTranslatef(-10,10,10);
        myDrawCylinder(5,5,0,30,360);
    }glPopMatrix();
    glPushMatrix();{
        glTranslatef(10,-10,10);
        myDrawCylinder(5,5,0,30,360);
    }glPopMatrix();
    glPushMatrix();{
        glTranslatef(-10,-10,10);
        myDrawCylinder(5,5,0,30,360);
    }glPopMatrix();


    glPushMatrix();{
        glTranslatef(10,10,-1);
        myDrawCylinder(5,5,0,30,360);
    }glPopMatrix();
    glPushMatrix();{
        glTranslatef(-10,10,-1);
        myDrawCylinder(5,5,0,30,360);
    }glPopMatrix();
    glPushMatrix();{
        glTranslatef(10,-10,-1);
        myDrawCylinder(5,5,0,30,360);
    }glPopMatrix();
    glPushMatrix();{
        glTranslatef(-10,-10,-1);
        myDrawCylinder(5,5,0,30,360);
    }glPopMatrix();
}

void robot::drawClamp(){
    glColor3f(.9,.9,.9);
    glBegin(GL_QUADS);{
        glNormal3f(0,0,0);glVertex3f(0,0,0);
        glNormal3f(15,0,0);glVertex3f(15,0,0);
        glNormal3f(15,0,-44);glVertex3f(15,0,-44);
        glNormal3f(0,0,-44);glVertex3f(0,0,-44);

        glNormal3f(15,0,0);glVertex3f(15,0,0);
        glNormal3f(15,-59,0);glVertex3f(15,-59,0);
        glNormal3f(15,-59,-44);glVertex3f(15,-59,-44);
        glNormal3f(15,0,-44);glVertex3f(15,0,-44);
    }glEnd();

}
