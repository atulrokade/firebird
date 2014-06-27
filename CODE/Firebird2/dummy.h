/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#ifndef DUMMY_H
#define DUMMY_H
void MyOpenGLWindow::keyboardKey(unsigned char key){
    //cout<<key;
    switch(key){
    case 'A':			// a = 97
        yRotated--;
        break;
    case 'D':
        yRotated++;
        break;

    case 'W':
        xRotated--;
        break;
    case 'S':
        xRotated++;
        break;

    case 'X':
        zRotated--;
        break;
    case 'Z':
        zRotated++;
        break;

    case 'R':
        xRotated=0;
        yRotated=0;
        zRotated=0;
        break;
    case 27:
        exit(0);
        break;
    }

}
void MyOpenGLWindow::specialKeyboard(int key) {
    /*
     *
     *
     * 	GLUT_KEY_F1
     GLUT_KEY_LEFT
     GLUT_KEY_UP
     GLUT_KEY_RIGHT
     GLUT_KEY_DOWN
     GLUT_KEY_PAGE_UP
     GLUT_KEY_PAGE_DOWN
     GLUT_KEY_HOME
     GLUT_KEY_END
     GLUT_KEY_INSERT
     */


    switch (key) {
    case GLUT_KEY_PAGE_UP:
        zoom=zoom+0.1;
        break;
    case GLUT_KEY_PAGE_DOWN:
        zoom=zoom-0.1;
        break;
    case GLUT_KEY_END:
        zoom=1;
        break;
    case GLUT_KEY_UP:
        //        speed-=20;
        break;
    case GLUT_KEY_DOWN:
        //        speed+=20;
        break;


    }
}

#endif // DUMMY_H
