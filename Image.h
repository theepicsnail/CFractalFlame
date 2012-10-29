#ifndef Image_h
#define Image_h
#include <vector>
#include "Util.h"

class Image{
    std::vector<unsigned char> data;
    int width,height;
    bool toIdx(Point& pt, int& idx);
public:
    Image(int width, int height);
    Color getColor(Point& pt);
    void setColor(Point& pt, Color& c);
    void save(const char * filename);
};
#endif
