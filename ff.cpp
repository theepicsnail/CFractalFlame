#include<png.h>
#include<stdio.h>
#include<stdlib.h>
#include"image.h"
#include<vector>
#include<math.h>
#include<time.h>

using namespace std;
struct point {
    double x,y;
};

struct function {
    double p,a,b,c,d,e,f;
    pixel_t color;
};

struct variation {
    double w;
    void (*func)(point* src, point* dest);
};

double frand(double min, double max){
    return (rand()/(double)RAND_MAX)*(max-min)+min;
}

void genFunc(function& func, double p, uint8_t r, uint8_t g, uint8_t b ){//{{{
    func.p = p;
    func.color.red = r;
    func.color.green = g;
    func.color.blue = b;

    int min = -1;
    int max = 1;

    func.a = frand(min,max);
    func.b = frand(min,max);
    func.c = frand(min,max);
    func.d = frand(min,max);
    func.e = frand(min,max);
    func.f = frand(min,max);
}//}}}

//{{{ Variations
void identity(point *src, point *dst){
    dst->x = src->x;
    dst->y = src->y;
}
void spherical(point *src, point *dst){
    double mag = src->x * src->x 
               + src->y * src->y;
    mag *= 3;
    dst->x=src->x/mag;
    dst->y=src->y/mag;
}
void sinusoidal(point *src, point *dst){
    dst->x = sin(src->x);
    dst->y = sin(src->y);
}
void swirl(point *src, point *dst){
    double r = src->x*src->y;
    r *=r;
    dst->x = src->x*sin(r)-src->y*cos(r);
    dst->y = src->x*cos(r)+src->y*sin(r);
}

//}}}

vector<variation> getVariations(){//{{{
    vector<variation> variations(2);
    variations[0].w = .5;
    variations[0].func = swirl;
    
    variations[1].w = .5;
    variations[1].func = identity;
//    variations[2].w = .1;
//    variations[2].func = spherical;
    return variations;
}//}}}

vector<function> getFunctions(){//{{{
    vector<function> table (3);
    genFunc(table[0], .4, 255,0,0);
    genFunc(table[1], .4, 255,255,0);
    table[2].p=.5;
    table[2].a=.8;
    table[2].b=.6;
    table[2].c=0;
    table[2].d=.6;
    table[2].e=.8;
    table[2].f=0;
    table[2].color.red=255;
//    genFunc(table[3], .4, 255,255,255);
    return table;
}//}}}

int selectFunction(vector<function> table){//{{{
    /*
        Select a function from the table. 
        Returning the index of the selected function

        This behaves a little weird if the probabilities
        don't add to 1.
    */
    double r = frand(0,1);
    vector<function>::iterator it;
    int i = 0;
    for(it=table.begin(); it < table.end(); it++)
    {
        if(it->p >= r)
            return i;
        r-=it->p;
        i++;
    }
    return 0;
}//}}}

void F(const function* func, point* pt, vector<variation> vars){//{{{
    //apply the function/variation set to pt. 
    //pt will contain the location after operations have been applied.
    double x = 0;
    double y = 0;
    point tmp;
    point fpt;
    fpt.x = func->a*pt->x+func->b*pt->y+func->c;
    fpt.y = func->d*pt->x+func->e*pt->y+func->f;
 
    vector<variation>::iterator it;
    for(it = vars.begin(); it < vars.end(); it++){
        (it->func)(&fpt, &tmp);
        x += tmp.x*it->w;
        y += tmp.y*it->w;
    }
    pt->x = x;
    pt->y = y;
}//}}}

void blend(pixel_t* src, pixel_t* dst){//{{{
    //Blend src and dst pixels and store the result into dst.
    dst->red = (dst->red+src->red)>>1;
    dst->green = (dst->green+src->green)>>1;
    dst->blue = (dst->blue+src->blue)>>1;
}//}}}

static int pix (int value, int max)//{{{
{
    if (value < 0)
        return 0;
    return (int) (256.0 *((double) (value)/(double) max));
}//}}}

void getPixel(double x, double y, pixel_t* pix, bitmap_t* image){//{{{
    int ix = (int)(image->width*(x+1)/2);
    int iy = (int)(image->height*(y+1)/2);
    if(ix < 0 || iy < 0 || ix >= image->width || iy >= image->height){
        pix->red = 0;
        pix->green = 0;
        pix->blue = 0;
    }else{
        pixel_t* p = pixel_at(image, ix, iy);
        pix->red = p->red;
        pix->green = p->green;
        pix->blue = p->blue;
    }
}//}}}

void setPixel(bitmap_t* image, point* pt, pixel_t* pix){
    int ix = (int)(image->width*(pt->x+1)/2);
    int iy = (int)(image->height*(pt->y+1)/2);
    if(ix < 0 || iy < 0 || ix >= image->width || iy >= image->height)
        return;
    pixel_t* tmp = pixel_at(image, ix, iy);
    tmp -> red = pix -> red;
    tmp -> green = pix -> green;
    tmp -> blue = pix -> blue;
}


int main (int argc, char* argv[])
{
    srand(time(0));
    vector<function> funcs = getFunctions();
    vector<variation> vars = getVariations();
    point pt;
    
    std::vector<unsigned char> image;
    image.resize(width * height * 4);


    bitmap_t image;
    pixel_t pixel, tmpPixel;
    image.width = 500;
    image.height = 500;
    image.pixels =(pixel_t*) calloc (sizeof (pixel_t), image.width * image.height);


    int totalPoints = 100000;
    int count, iters, max_iters=10;

    int progress = totalPoints/100;
    for (count = 0; count < totalPoints; count ++){
        if(count%progress ==0)
            printf("%i%%\n",count*100/totalPoints);


        double x = frand(-1,1);
        double y = frand(-1,1);
        pt.x = x;
        pt.y = y;
        getPixel(x, y, &pixel, &image);

        for(iters = 0 ; iters < max_iters; iters++){
            int j = selectFunction(funcs);
            F(&funcs[j], &pt, vars);
            blend(&funcs[j].color, &pixel);
        }
        getPixel(pt.x, pt.y, &tmpPixel, &image);
        blend(&tmpPixel,&pixel);
        setPixel(&image, &pt, &pixel);
    }
/*    for (y = 0; y < image.height; y++) {
        for (x = 0; x < image.width; x++) {
            pixel_t * pixel = pixel_at (& image, x, y);
            pixel->red = pix (x, image.width);
            pixel->green = pix (y, image.height);
        }
    }*/

    /* Write the image to a file 'image.png'. */

    save_png_to_file (& image, "image.png");

    return 0;
}

