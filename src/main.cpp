#include <iostream>
#include <fstream>
#include <vector>
#include "picture.h"
#include "pixels.h"
#include "imageholder.h"

using namespace std;

image read(ifstream&);
image write(ofstream&, image i);

int main() {

    // Part 1

    ifstream inFile("input/pattern1.tga",ios_base::binary);
    image topLayer = read(inFile);
    inFile.close();

    inFile.open("input/layer1.tga",ios_base::binary);
    image bottomLayer = read(inFile);
    inFile.close();

    topLayer.multiply(bottomLayer);

    inFile.open("examples/EXAMPLE_part1.tga",ios_base::binary);
    image comparison = read(inFile);
    inFile.close();

    ofstream outFile("output/part1.tga",ios_base::binary);
    image part1 = write(outFile,topLayer);
    outFile.close();

    cout << "Part 1 " << part1.compare(comparison) << endl;

    // Part 2

    inFile.open("input/car.tga",ios_base::binary);
    topLayer = read(inFile);
    inFile.close();

    inFile.open("input/layer2.tga",ios_base::binary);
    bottomLayer = read(inFile);
    inFile.close();

    topLayer.subtract(bottomLayer);

    inFile.open("examples/EXAMPLE_part2.tga",ios_base::binary);
    comparison = read(inFile);
    inFile.close();

    outFile.open("output/part2.tga",ios_base::binary);
    image part2 = write(outFile,topLayer);
    outFile.close();

    cout << "Part 2 " << part2.compare(comparison) << endl;

    // Part 3

    inFile.open("input/pattern2.tga",ios_base::binary);
    topLayer = read(inFile);
    inFile.close();

    inFile.open("input/layer1.tga",ios_base::binary);
    bottomLayer = read(inFile);
    inFile.close();

    topLayer.multiply(bottomLayer);

    inFile.open("input/text.tga",ios_base::binary);
    image tempLayer1 = read(inFile);
    inFile.close();

    tempLayer1.screen(topLayer);

    inFile.open("examples/EXAMPLE_part3.tga",ios_base::binary);
    comparison = read(inFile);
    inFile.close();

    outFile.open("output/part3.tga",ios_base::binary);
    image part3 = write(outFile,tempLayer1);
    outFile.close();

    cout << "Part 3 " << part3.compare(comparison) << endl;

    // Part 4

    inFile.open("input/layer2.tga",ios_base::binary);
    topLayer = read(inFile);
    inFile.close();

    inFile.open("input/circles.tga",ios_base::binary);
    bottomLayer = read(inFile);
    inFile.close();

    inFile.open("input/pattern2.tga",ios_base::binary);
    image tempLayer2 = read(inFile);
    inFile.close();

    topLayer.multiply(bottomLayer);

    topLayer.subtract(tempLayer2);

    inFile.open("examples/EXAMPLE_part4.tga",ios_base::binary);
    comparison = read(inFile);
    inFile.close();

    outFile.open("output/part4.tga",ios_base::binary);
    image part4= write(outFile,topLayer);
    outFile.close();

    cout << "Part 4 " << part4.compare(comparison) << endl;

    // Part 5

    inFile.open("input/layer1.tga",ios_base::binary);
    topLayer = read(inFile);
    inFile.close();

    inFile.open("input/pattern1.tga",ios_base::binary);
    bottomLayer = read(inFile);
    inFile.close();

    topLayer.overlay(bottomLayer);

    inFile.open("examples/EXAMPLE_part5.tga",ios_base::binary);
    comparison = read(inFile);
    inFile.close();

    outFile.open("output/part5.tga",ios_base::binary);
    image part5= write(outFile,topLayer);
    outFile.close();

    cout << "Part 5 " << part5.compare(comparison) << endl;

    // Part 6

    inFile.open("input/car.tga",ios_base::binary);
    topLayer = read(inFile);
    inFile.close();

    topLayer.add(2,200);

    inFile.open("examples/EXAMPLE_part6.tga",ios_base::binary);
    comparison = read(inFile);
    inFile.close();

    outFile.open("output/part6.tga",ios_base::binary);
    image part6 = write(outFile,topLayer);
    outFile.close();

    cout << "Part 6 " << part6.compare(comparison) << endl;

    // Part 7

    inFile.open("input/car.tga",ios_base::binary);
    topLayer = read(inFile);
    inFile.close();

    topLayer.scale(0,1,4);

    inFile.open("examples/EXAMPLE_part7.tga",ios_base::binary);
    comparison = read(inFile);
    inFile.close();

    outFile.open("output/part7.tga",ios_base::binary);
    image part7 = write(outFile,topLayer);
    outFile.close();

    cout << "Part 7 " << part7.compare(comparison) << endl;

    // Part 8

    image splitRed;
    image splitBlue;
    image splitGreen;

    inFile.open("input/car.tga",ios_base::binary);
    topLayer = read(inFile);
    inFile.close();

    splitRed = topLayer.split(3);
    splitGreen = topLayer.split(2);
    splitBlue = topLayer.split(1);

    inFile.open("examples/EXAMPLE_part8_r.tga",ios_base::binary);
    image comparisonr = read(inFile);
    inFile.close();

    inFile.open("examples/EXAMPLE_part8_g.tga",ios_base::binary);
    image comparisong = read(inFile);
    inFile.close();

    inFile.open("examples/EXAMPLE_part8_b.tga",ios_base::binary);
    image comparisonb = read(inFile);
    inFile.close();

    outFile.open("output/part8_r.tga",ios_base::binary);
    image part8_r = write(outFile,splitRed);
    outFile.close();

    outFile.open("output/part8_g.tga",ios_base::binary);
    image part8_g = write(outFile,splitGreen);
    outFile.close();

    outFile.open("output/part8_b.tga",ios_base::binary);
    image part8_b = write(outFile,splitBlue);
    outFile.close();

    cout << "Part 8r " << part8_r.compare(comparisonr) << endl;
    cout << "Part 8g " << part8_g.compare(comparisong) << endl;
    cout << "Part 8b " << part8_b.compare(comparisonb) << endl;


    // Part 9

    inFile.open("input/layer_red.tga",ios_base::binary);
    image red = read(inFile);
    inFile.close();

    inFile.open("input/layer_green.tga",ios_base::binary);
    image green = read(inFile);
    inFile.close();

    inFile.open("input/layer_blue.tga",ios_base::binary);
    image blue = read(inFile);
    inFile.close();

    image combined = red.combine(red,green,blue);

    inFile.open("examples/EXAMPLE_part9.tga",ios_base::binary);
    comparison = read(inFile);
    inFile.close();

    outFile.open("output/part9.tga",ios_base::binary);
    image part9 = write(outFile,combined);
    outFile.close();

    cout << "Part 9 " << part9.compare(comparison) << endl;


    // Part 10

    inFile.open("input/text2.tga",ios_base::binary);
    topLayer = read(inFile);
    inFile.close();

    image rotated = topLayer.rotate();

    inFile.open("examples/EXAMPLE_part10.tga",ios_base::binary);
    comparison = read(inFile);
    inFile.close();

    outFile.open("output/part10.tga",ios_base::binary);
    image part10 = write(outFile,rotated);
    outFile.close();

    cout << "Part 10 " << part10.compare(comparison) << endl;

    return 0;
}

image read(ifstream& inFile){
    Header headerObject;
    vector<Pixel> listPixel;
    inFile.read(&headerObject.idLength,sizeof(headerObject.idLength));
    inFile.read(&headerObject.colorMapType,sizeof(headerObject.colorMapType));
    inFile.read(&headerObject.dataTypeCode,sizeof(headerObject.dataTypeCode));
    inFile.read((char *)(&headerObject.colorMapOrigin), sizeof(headerObject.colorMapOrigin));
    inFile.read((char *)(&headerObject.colorMapLength), sizeof(headerObject.colorMapLength));
    inFile.read(&headerObject.colorMapDepth,sizeof(headerObject.colorMapDepth));
    inFile.read((char *)(&headerObject.xOrigin), sizeof(headerObject.xOrigin));
    inFile.read((char *)(&headerObject.yOrigin), sizeof(headerObject.yOrigin));
    inFile.read((char *)(&headerObject.width), sizeof(headerObject.width));
    inFile.read((char *)(&headerObject.height), sizeof(headerObject.height));
    inFile.read(&headerObject.bitsPerPixel,sizeof(headerObject.bitsPerPixel));
    inFile.read(&headerObject.imageDescriptor,sizeof(headerObject.imageDescriptor));

    for (unsigned int i = 0; i < headerObject.height*headerObject.width; i++){

        char blue;
        inFile.read(&blue, sizeof(blue));
        char green;
        inFile.read(&green, sizeof(green));
        char red;
        inFile.read(&red, sizeof(red));

        Pixel newpixel(blue,green,red);
        listPixel.push_back(newpixel);
    }


    image newimage(headerObject,listPixel);

    return newimage;
}

image write(ofstream& outFile, image i){
    outFile.write(&i.hobj.idLength,sizeof(i.hobj.idLength));
    outFile.write(&i.hobj.colorMapType,sizeof(i.hobj.colorMapType));
    outFile.write(&i.hobj.dataTypeCode,sizeof(i.hobj.dataTypeCode));
    outFile.write((char *)(&i.hobj.colorMapOrigin), sizeof(i.hobj.colorMapOrigin));
    outFile.write((char *)(&i.hobj.colorMapLength), sizeof(i.hobj.colorMapLength));
    outFile.write(&i.hobj.colorMapDepth,sizeof(i.hobj.colorMapDepth));
    outFile.write((char *)(&i.hobj.xOrigin), sizeof(i.hobj.xOrigin));
    outFile.write((char *)(&i.hobj.yOrigin), sizeof(i.hobj.yOrigin));
    outFile.write((char *)(&i.hobj.width), sizeof(i.hobj.width));
    outFile.write((char *)(&i.hobj.height), sizeof(i.hobj.height));
    outFile.write(&i.hobj.bitsPerPixel,sizeof(i.hobj.bitsPerPixel));
    outFile.write(&i.hobj.imageDescriptor,sizeof(i.hobj.imageDescriptor));

    for (unsigned int k = 0; k < i.list.size(); k++){
        outFile.write((char *)&i.list[k].blue, sizeof(i.list[k].blue));
        outFile.write((char *)&i.list[k].green, sizeof(i.list[k].green));
        outFile.write((char *)&i.list[k].red, sizeof(i.list[k].red));
    }

    image newimage (i.hobj,i.list);

    return newimage;
}
