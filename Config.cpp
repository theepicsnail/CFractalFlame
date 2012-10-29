#include "Config.h"
#include <vector>
#include <iostream>
using namespace std;
bool interpolateD(const Config& config, const char * path,
                  float p, double& out){
    float start, end;
    Setting& setting = config.lookup(path);
    if(setting.lookupValue("from",start)
      && setting.lookupValue("to",end))
    {
        out =start+(end-start)*p;
        return true;
    }
    return false;
}
bool interpolateI(const Config& config, const char* path,
                  float p, unsigned char& out){
    int start, end;
    Setting& setting = config.lookup(path);
    if(setting.lookupValue("from",start)
      && setting.lookupValue("to",end))
    {
        out = (unsigned char)(start+(end-start)*p);
        return true;
    }
    return false;
}

bool loadRenderConfig(Config& config, RendererConfig& rendConfig, double p){
    if(!config.lookupValue("iterations",rendConfig.iterations))
        return false;

    if(!config.lookupValue("points",rendConfig.points))
        return false;

    int width, height;
    if(config.lookupValue("width",width)
    && config.lookupValue("height",height)){
        rendConfig.image =new Image(width, height);
    }
    else
        return false;

    interpolateD(config,"variations.identity",p, rendConfig.weights.identity);
    interpolateD(config,"variations.spherical",p, rendConfig.weights.spherical);
    interpolateD(config,"variations.sinusoidal",p, rendConfig.weights.sinusoidal);
    interpolateD(config,"variations.swirl",p, rendConfig.weights.swirl);

    int functionCount = config.lookup("functions").getLength();
    if(functionCount == 0)
        return false;

    rendConfig.F = new vector<FlameParameters*>();

    int i;
    char path[50];
    for(i=0; i < functionCount ; i++){
        FlameParameters * fp = new FlameParameters();
        //Weight
        sprintf(path,"functions.[%i].weight",i);
        interpolateD(config,path,p,fp->p);

        //Color
        sprintf(path,"functions.[%i].color.red",i);
        interpolateI(config,path,p,fp->color.R);

        sprintf(path,"functions.[%i].color.green",i);
        interpolateI(config,path,p,fp->color.G);

        sprintf(path,"functions.[%i].color.blue",i);
        interpolateI(config,path,p,fp->color.B);
        
        //Coefs
        sprintf(path,"functions.[%i].coefs.a",i);
        interpolateD(config,path,p,fp->a);
        
        sprintf(path,"functions.[%i].coefs.b",i);
        interpolateD(config,path,p,fp->b);
        
        sprintf(path,"functions.[%i].coefs.c",i);
        interpolateD(config,path,p,fp->c);
        
        sprintf(path,"functions.[%i].coefs.d",i);
        interpolateD(config,path,p,fp->d);
        
        sprintf(path,"functions.[%i].coefs.e",i);
        interpolateD(config,path,p,fp->e);
        
        sprintf(path,"functions.[%i].coefs.f",i);
        interpolateD(config,path,p,fp->f);

        rendConfig.F->push_back(fp);
    }
    return true;
}
