#include "Image.h"
#define LODEPNG_COMPILE_ENCODER
#include "lodepng.h"
#include <iostream>
bool Image::toIdx(Point& pt, int& idx){
    int x = (int)((pt.x+1)*width/2);
    int y = (int)((pt.y+1)*height/2);
    if(x < 0 || x >= width || y < 0 || y >= height)
        return false;
    idx = (y*width+x)*4;
    return true;
}

Color Image::getColor(Point& pt){
    int idx = data.size();

    Color c;
    if(toIdx(pt,idx)){
        c.R=data.at(idx);
        c.G=data[idx+1];
        c.B=data[idx+2];
    }
    return c;
}
void Image::setColor(Point& pt, Color& c){
    int idx;
    if(toIdx(pt,idx)){
        data[idx]=c.R;
        data[idx+1]=c.G;
        data[idx+2]=c.B;
        data[idx+3]=255;
    }
}
Image::Image(int width, int height)
    :width(width),
     height(height)
{
    data.assign(width*height*4, 255);
}

void Image::save(const char* filename){
    std::cout << lodepng::encode(filename,data,width,height) << std::endl;
}
