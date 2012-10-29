#ifndef Config_h
#define Config_h
#include <libconfig.h++>
#include "Renderer.h"
using namespace libconfig;

bool loadRenderConfig(Config& config, RendererConfig&, double p);
#endif
