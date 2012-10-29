#ifndef Util_h
#define Util_h
#include <cstdlib>
class Color{
public:
    unsigned char R,G,B;
    void blend(const Color& c){
        this->R = (this->R+c.R)>>1;
        this->G = (this->G+c.G)>>1;
        this->B = (this->B+c.B)>>1;
    }
    Color():R(0),G(0),B(0){}
};
struct Point{
    double x,y;
    Point(double X, double Y){
      x=X;
      y=Y;
    }
    Point(){
      x=y=0;
    }
    void scale(double factor){
        this->x*=factor;
        this->y*=factor;
    }
    void set(double x, double y){
        this->x = x;
        this->y = y;
    }
    void translate(double dx, double dy){
        this->x+=dx;
        this->y+=dy;
    }
    void translate(Point& p){
        this->x+=p.x;
        this->y+=p.y;
    }
};
double frand(double min, double max);
void seed(long l);

#endif
