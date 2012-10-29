#define LODEPNG_COMPILE_ENCODER
/*#include "Image.h"
 *
    Image img(500,500);
    Color c;
    Point pt;
    for(double x = -1; x < 1; x += 10/250.0)
    for(double y = -1; y < 1; y += 10/250.0){
        pt.set(x,y);
        c.R = (int)(255*(x+1)/2);
        img.setColor(pt,c);
    }
    img.save("img.png");


 *
 */
#include <iostream>
#include <stdio.h>
#include "Config.h"
#include "Renderer.h"
using namespace std;

int main(int argc, char *args[])
{

    if(argc != 4){
        cout << "Usage: "<<args[0]<<" [config file] [t-value] [image file (png)]" << endl;
        cout << "Generate a fractal based on the config file" << endl;
        cout << "t-value is used to determine which frame to render." << endl;
        return 1;
    }
    
    float p = atof(args[2]);

    libconfig::Config config;
    config.readFile(args[1]);
    
    RendererConfig rConfig;
    loadRenderConfig(config,rConfig,p);
    
    Renderer rend(rConfig);
    rend.render();

    rend.getImage()->save(args[3]);
    return 0;
/*
    libconfig::Config config;
    config.readFile("tmp.cfg");

    int i=0;
    RendererConfig rConfig;
    char img[20];
    
    for(; i < 10 ; i++){
        loadRenderConfig(config,rConfig,i*.1f);

        Renderer rend(rConfig);
        rend.render();
        sprintf(img,"img%i.png",i);
        printf("%s\n",img);
        rend.getImage()->save(img);
    }
*/
}
