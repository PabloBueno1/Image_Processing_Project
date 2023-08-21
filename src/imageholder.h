//
// Created by Pablo on 3/24/2022.
//

#ifndef PROJECT2_IMAGEHOLDER_H
#define PROJECT2_IMAGEHOLDER_H
#include <vector>
#include "pixels.h"
#include "picture.h"

using namespace std;

struct image{
    Header hobj;
    vector<Pixel> list;

    image();
    image(Header h,vector<Pixel>& l);

    bool compare(image& p);
    void multiply(image& p);
    void screen(image& p);
    void subtract(image& p);
    void add(int rgb,int amount);
    void scale(int blueScale,int greenScale,int redScale);
    void overlay(image& p);
    image split(int count);
    image combine(image red, image green, image blue);
    image rotate();
};

image::image() {

}

image::image(Header h, vector<Pixel>& l) {
    hobj = h;

    for (int i = 0; i < l.size(); i++) {
        Pixel temppix;
        temppix.blue = l[i].blue;
        temppix.green = l[i].green;
        temppix.red = l[i].red;

        list.push_back(temppix);
    }
}


bool image::compare(image& p) {
    if(hobj.idLength != p.hobj.idLength ||
hobj.colorMapType != p.hobj.colorMapType ||
    hobj.dataTypeCode != p.hobj.dataTypeCode ||
    hobj.colorMapOrigin != p.hobj.colorMapOrigin ||
    hobj.colorMapLength != p.hobj.colorMapLength ||
    hobj.colorMapDepth != p.hobj.colorMapDepth ||
    hobj.xOrigin != p.hobj.xOrigin ||
    hobj.yOrigin != p.hobj.yOrigin ||
    hobj.width != p.hobj.width ||
    hobj.height != p.hobj.height ||
    hobj.bitsPerPixel != p.hobj.bitsPerPixel ||
    hobj.imageDescriptor != p.hobj.imageDescriptor){
        return false;
    }
    for(unsigned int i = 0; i < p.list.size();i++){

        if(this->list[i].blue != p.list[i].blue ||
        this->list[i].green != p.list[i].green ||
        this->list[i].red != p.list[i].red){
            return false;
        }
    }
    return true;

}

void image::multiply(image &p) {
    for(unsigned int i = 0; i < this->list.size();i++){

        float blue1 = (float)this->list[i].blue;
        float blue2 = (float)p.list[i].blue;
        float green1 = (float)this->list[i].green;
        float green2 = (float)p.list[i].green;
        float red1 = (float)this->list[i].red;
        float red2 = (float)p.list[i].red;

        float blueFinal = (float)blue1*blue2/255+0.5f;
        float greenFinal = (float)green1*green2/255+0.5f;
        float redFinal = (float)red1*red2/255+0.5f;

        this->list[i].blue = blueFinal;
        this->list[i].green = greenFinal;
        this->list[i].red = redFinal;

    }
}

void image::subtract(image &p) {
    for(unsigned int i = 0; i < this->list.size();i++){

        int blue1 = this->list[i].blue;
        int blue2 = p.list[i].blue;
        int green1 = this->list[i].green;
        int green2 = p.list[i].green;
        int red1 = this->list[i].red;
        int red2 = p.list[i].red;

        if (blue1-blue2 < 0){
            this->list[i].blue = 0;
        }
        else {
            this->list[i].blue = blue1 - blue2;
        }

        if (green1-green2 < 0){
            this->list[i].green = 0;
        }
        else {
            this->list[i].green = green1 - green2;
        }

        if (red1-red2 < 0){
            this->list[i].red = 0;
        }
        else {
            this->list[i].red = red1 - red2;
        }

    }
}

void image::add(int rgb,int amount) {
    for(unsigned int i = 0; i < this->list.size();i++){

        int blue1 = this->list[i].blue;
        int green1 = this->list[i].green;
        int red1 = this->list[i].red;

        if (rgb == 1){
            if (blue1 + amount > 255){
                this->list[i].blue = 255;
            }
            else {
                this->list[i].blue = blue1 + amount;
            }
        }
        if (rgb == 2){
            if (green1 + amount > 255){
                this->list[i].green = 255;
            }
            else {
                this->list[i].green = green1 + amount;
            }
        }
        if (rgb == 3){
            if (red1 + amount > 255){
                this->list[i].red = 255;
            }
            else {
                this->list[i].red = red1 + amount;
            }
        }
    }
}

void image::scale(int blueScale, int greenScale, int redScale) {

    for(unsigned int i = 0; i < this->list.size();i++){

        int blue1 = this->list[i].blue;
        int green1 = this->list[i].green;
        int red1 = this->list[i].red;

        if (blue1*blueScale > 255){
            this->list[i].blue = 255;
        }
        else {
            this->list[i].blue = blue1*blueScale;
        }
        if (green1*greenScale > 255){
            this->list[i].green = 255;
        }
        else {
            this->list[i].green = green1 * greenScale;
        }
        if (red1*redScale > 255){
            this->list[i].red = 255;
        }
        else {
            this->list[i].red = red1 * redScale;
        }

    }

}

image image::split(int count) {

    image splitImage(this->hobj,this->list);

    for(unsigned int i = 0; i < this->list.size();i++) {

        if(count == 1){
            splitImage.list[i].blue = this->list[i].blue;
            splitImage.list[i].green = this->list[i].blue;
            splitImage.list[i].red = this->list[i].blue;
        }
        if(count == 2){
            splitImage.list[i].blue = this->list[i].green;
            splitImage.list[i].green = this->list[i].green;
            splitImage.list[i].red = this->list[i].green;
        }
        if(count == 3){
            splitImage.list[i].blue = this->list[i].red;
            splitImage.list[i].green = this->list[i].red;
            splitImage.list[i].red = this->list[i].red;
        }
    }
    return splitImage;
}

image image::combine(image red1, image green1, image blue1) {
    image combined(this->hobj,this->list);

    for(unsigned int i = 0; i < this->list.size();i++) {

        combined.list[i].red = red1.list[i].red;
        combined.list[i].green = green1.list[i].green;
        combined.list[i].blue = blue1.list[i].blue;

    }
    return combined;

}

image image::rotate() {
    image rotated(this->hobj,this->list);
    int firstIndex = 0;

    for (int i = this->list.size()-1; i >= 0; --i) {


        rotated.list[firstIndex].blue = this->list[i].blue;
        rotated.list[firstIndex].green = this->list[i].green;
        rotated.list[firstIndex].red = this->list[i].red;

        firstIndex++;
    }

    return rotated;
}

void image::screen(image &p) {
    for(unsigned int i = 0; i < this->list.size();i++){

        float blue1 = (float)this->list[i].blue;
        float blue2 = (float)p.list[i].blue;
        float green1 = (float)this->list[i].green;
        float green2 = (float)p.list[i].green;
        float red1 = (float)this->list[i].red;
        float red2 = (float)p.list[i].red;

        float blueFinal = (float)255-((255-blue1)*(255-blue2))/255+0.5f;
        float greenFinal = (float)255-((255-green1)*(255-green2))/255+0.5f;
        float redFinal = (float)255-((255-red1)*(255-red2))/255+0.5f;

        this->list[i].blue = blueFinal;
        this->list[i].green = greenFinal;
        this->list[i].red = redFinal;

    }
}

void image::overlay(image &p) {
    for(unsigned int i = 0; i < this->list.size();i++) {

        float blue1 = (float)this->list[i].blue;
        float blue2 = (float)p.list[i].blue;
        float green1 = (float)this->list[i].green;
        float green2 = (float)p.list[i].green;
        float red1 = (float)this->list[i].red;
        float red2 = (float)p.list[i].red;

        if (blue2 < 128){
            float blueFinal = (float)2*blue1*blue2/255+0.5f;
            this->list[i].blue = blueFinal;
        }
        else {
            float blueFinal = (float)255-(2*(255-blue1)*(255-blue2))/255+0.5f;
            this->list[i].blue = blueFinal;
        }

        if (green2 < 128){
            float greenFinal = (float)2*green1*green2/255+0.5f;
            this->list[i].green = greenFinal;
        }
        else {
            float greenFinal = (float)255-(2*(255-green1)*(255-green2))/255+0.5f;
            this->list[i].green = greenFinal;
        }

        if (red2 < 128){
            float redFinal = (float)2*red1*red2/255+0.5f;
            this->list[i].red = redFinal;
        }
        else {
            float redFinal = (float)255-(2*(255-red1)*(255-red2))/255+0.5f;
            this->list[i].red = redFinal;
        }
    }

}

#endif //PROJECT2_IMAGEHOLDER_H
