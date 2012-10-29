#ifndef Renderer_h
#define Renderer_h
#include "Util.h"
#include "Image.h"
#include <vector>
struct FlameParameters {
    double a,b,c,d,e,f;
    double X(Point& p){
        return a*p.x+b*p.y+c;
    }
    double Y(Point& p){
        return d*p.x+e*p.y+f;
    }

    double p;
    Color color;
};
struct VariationWeights {
    double identity
        ,  spherical
        ,  sinusoidal
        ,  swirl
        ;
};

struct RendererConfig {
    VariationWeights weights;
    std::vector<FlameParameters*> * F;
    Image* image;
    int iterations;//iterations per point
    int points; // number of points
};

class Renderer {
    RendererConfig* config;
    FlameParameters* chooseFlameParameters();
    public:
        Renderer(RendererConfig&);
        void render();
        Image* getImage();
        void renderPoint();
        
};

#endif
