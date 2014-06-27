/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "image.h"

image::image()
{
    texInt= new GLuint[100];
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(100, texInt);
}
image::image(string str){

    unsigned img_width, img_height;
    GLubyte *myImg;

    unsigned error = lodepng_decode32_file(&myImg, &img_width, &img_height, str.c_str());
    if(error) {
        std::cout << "11 decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }

    name=str;
    textureNumber=1;
    width=(int)img_width;
    height=(int)img_height;

}
int image::createImageTexture(){

    unsigned img_width, img_height;
    GLubyte *myImg;




//    cout<<name<<endl;
    unsigned error = lodepng_decode32_file(&myImg, &img_width, &img_height, name.c_str());
    if(error) {
        std::cout << "22 decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, texInt[0]);
    {
//        cout<<"here"<<endl;

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_width, img_height,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, myImg);
    }


    textureNumber=(int)texInt[0];
    width=(int)img_width;
    height=(int)img_height;

    imgdata = new float*[(int)height];
    for(int i = 0; i < height; i++)
        imgdata[i] = new float[(int)width];

//    Y' =  0.2126 R' + 0.7152 G' + 0.0722 B'.
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            imgdata[i][j]
                    =0.2126*(int(myImg[(i*width*4)+(4*j)])/255.0)
                    +0.7152*(int(myImg[(i*width*4)+(4*j)+1])/255.0)
                    +0.0722*(int(myImg[(i*width*4)+(4*j)+2])/255.0);
        }
    }

    delete myImg;


    return (textureNumber);
}
int image::createImageTexture1(){

    unsigned img_width, img_height;
    GLubyte *myImg;




//    cout<<name<<endl;
    unsigned error = lodepng_decode32_file(&myImg, &img_width, &img_height, name.c_str());
    if(error) {
        std::cout << "22 decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, texInt[1]);
    {
//        cout<<"here"<<endl;

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_width, img_height,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, myImg);
    }
    delete myImg;

    textureNumber=(int)texInt[1];
    width=(int)img_width;
    height=(int)img_height;

    return (textureNumber);
}
