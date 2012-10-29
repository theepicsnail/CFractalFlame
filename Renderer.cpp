#include "Renderer.h"
#include <cmath>
#include <iostream>
//{{{ Variations
void identity(const Point& src, Point& dst){
    dst.x=src.x;
    dst.y=src.y;
}
void spherical(const Point& src, Point& dst){
    double mag = src.x * src.x + src.y * src.y + 1;
    dst.x = src.x/mag;
    dst.y = src.y/mag;
}
void sinusoidal(const Point& src, Point& dst){
    dst.x = sin(src.x);
    dst.y = sin(src.y);
}
void swirl(const Point& src, Point& dst){
    double r = src.x * src.x + src.y * src.y;
    dst.x = src.x*sin(r)-src.y*cos(r);
    dst.y = src.x*cos(r)+src.y*sin(r);
}
//}}}


FlameParameters* Renderer::chooseFlameParameters(){//{{{
    double r = frand(0,1);
    unsigned int i;
    for(i = 0 ;i < config->F->size() ; i++)
      if(r<=config->F->at(i)->p)
        return config->F->at(i);
      else
        r -= config->F->at(i)->p;
    return config->F->at(0);
}//}}}

void Renderer::renderPoint(){//{{{
    Point P(frand(-1,1), frand(-1,1));
    Color c = config->image->getColor(P);
    int i;
    FlameParameters* fp;

    Point src, dst, sum;
    for(i = 0; i < config->iterations; i++){

        //iteration setup
        fp = chooseFlameParameters();
        src.set(fp->X(P), fp->Y(P));
        sum.scale(0);

        //Process variations
        identity(src,dst);
        dst.scale(config->weights.identity);
        sum.translate(dst);

        swirl(src,dst);
        dst.scale(config->weights.swirl);
        sum.translate(dst);

        spherical(src,dst);
        dst.scale(config->weights.spherical);
        sum.translate(dst);

        sinusoidal(src,dst);
        dst.scale(config->weights.sinusoidal);
        sum.translate(dst);
        //end variations

        //Update image
        P.set(sum.x,sum.y);
        c.blend(fp->color);
        c.blend(config->image->getColor(P));
        config->image->setColor(P,c);
    }
}//}}}

void Renderer::render(){//{{{
    int i;
    for(i =0; i < config->points; i++){
        renderPoint();
    }
}//}}}

Renderer::Renderer(RendererConfig& cfg){
    config = &cfg;
}

Image* Renderer::getImage(){
  return config->image;
}
