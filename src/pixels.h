//
// Created by Pablo on 3/24/2022.
//

#ifndef PROJECT2_PIXELS_H
#define PROJECT2_PIXELS_H

struct Pixel{
    unsigned char blue;
    unsigned char green;
    unsigned char red;

    Pixel();
    Pixel(char b,char g, char r);
};

Pixel::Pixel() {

}

Pixel::Pixel(char b, char g, char r) {
    blue = b;
    green = g;
    red = r;
}

#endif //PROJECT2_PIXELS_H
