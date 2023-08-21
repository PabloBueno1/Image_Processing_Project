//
// Created by Pablo on 3/24/2022.
//

#ifndef PROJECT2_PICTURE_H
#define PROJECT2_PICTURE_H

struct Header{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;

    Header();
    Header(char leng, char mapty, char typecode, short maporigin, short mapLength, char mapdepth, short x, short y, short w, short h, char bitsper, char descriptor);
};

Header::Header() {

}

Header::Header(char leng, char mapty, char typecode, short maporigin, short mapLength, char mapdepth, short x, short y,
               short w, short h, char bitsper, char descriptor) {

}

#endif //PROJECT2_PICTURE_H
