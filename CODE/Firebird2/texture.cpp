/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "texture.h"

texture::texture()
{
}

GLubyte* texture::read_PPM(const char *filename, int *width, int *height){
    FILE* fp;
    int i, w, h, d;
    unsigned char* image;
    char head[70]; /* max line <= 70 in PPM (per spec). */

    fp = fopen(filename, "rb");
    if (!fp) {
        perror(filename);
        return NULL;
    }

    /* grab first two chars of the file and make sure that it has the
     correct magic cookie for a raw PPM file. */
    fgets(head, 70, fp);
    if (strncmp(head, "P6", 2)) {
        fprintf(stderr, "%s: Not a raw PPM file\n", filename);
        return NULL;
    }

    /* grab the three elements in the header (width, height, maxval). */
    i = 0;
    while (i < 3) {
        fgets(head, 70, fp);
        if (head[0] == '#') /* skip comments. */
            continue;
        if (i == 0)
            i += sscanf(head, "%d %d %d", &w, &h, &d);
        else if (i == 1)
            i += sscanf(head, "%d %d", &h, &d);
        else if (i == 2) i += sscanf(head, "%d", &d);
    }

    /* grab all the image data in one fell swoop. */
    image = (unsigned char*) malloc(sizeof(unsigned char) * w * h * 3);
    fread(image, sizeof(unsigned char), w * h * 3, fp);
    fclose(fp);

    *width = w;
    *height = h;
    return image;
}
/*
GLubyte* texture::read_bmp(const char *filename, int *width, int *height){
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int w = *(int*)&info[18];
    int h = *(int*)&info[22];

    int size = 3 * w * h;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);

//    for(i = 0; i < size; i += 3)
//    {
//            unsigned char tmp = data[i];
//            data[i] = data[i+2];
//            data[i+2] = tmp;
//    }

    for(i=0;i<size/2;i++){
        unsigned char tmp = data[i];
        data[i] = data[size-i-1];
        data[size-i-1] = tmp;
    }

    *width = w;
    *height = h;
    return data;
}
*/
void texture::textureInitialisation(const char **fn, const int size){
    unsigned img_width, img_height;
    GLubyte *myImg;

    GLuint * texInt= new GLuint[2];
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(size, texInt);

    for (int i = 0; i < size; i++) {
//        myImg = read_PPM(fn[i], &img_width, &img_height);
        //        myImg = read_bmp(fn[i], &img_width, &img_height);
        unsigned error = lodepng_decode32_file(&myImg, &img_width, &img_height, fn[i]);
        if(error) {
            std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
        }
        cout<<"here"<<endl;

        glBindTexture(GL_TEXTURE_2D, texInt[0]);
        {
            cout<<"here"<<endl;

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                            GL_NEAREST);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_width, img_height,
                         0, GL_RGBA, GL_UNSIGNED_BYTE, myImg);
        }
    }
//    fstream ff;
//    ff.open("test.txt", ios::out);
//    for (int i=0;i<img_height*img_width*4;i++){
////        for (int j=0;j<img_width*4;j++){
//            ff<<(int)myImg[i]<<" ,";
////        }
//    }
//    cout<<texInt[0]<<endl;
    delete myImg;

}
void texture::enableTexture(GLuint texInt){
    glEnable( GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, texInt);

}
void texture::disableTexture() {
    glDisable( GL_TEXTURE_2D);
}

