/*
LodePNG Examples

Copyright (c) 2005-2012 Lode Vandevenne

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.
*/
#define LODEPNG_COMPILE_ENCODER

#include "lodepng.h"
#include <iostream>
#include "libconfig.h++"

using namespace libconfig;

//Example 1
//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
{
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

//saves image to filename given as argument. Warning, this overwrites the file without warning!
int main(int argc, char *argv[])
{
    Config cfg;
    Setting &root = cfg.getRoot();
    root.add("foo", Setting::TypeGroup);
    Setting &grp = root["foo"];
    grp.add("i",Setting::TypeInt)=40;
    cfg.writeFile("foo2.cfg");



  //NOTE: this sample will overwrite the file or test.png without warning!
  const char* filename = argc > 1 ? argv[1] : "test.png";

  //generate some image
  unsigned width = 512, height = 512;
  std::vector<unsigned char> image;
  image.resize(width * height * 4);
  for(unsigned y = 0; y < height; y++)
  for(unsigned x = 0; x < width; x++)
  {
    image[4 * width * y + 4 * x + 0] = ~(x & y);
    image[4 * width * y + 4 * x + 1] = x ^ y;
    image[4 * width * y + 4 * x + 2] = x | y;
    image[4 * width * y + 4 * x + 3] = 255;
  }

  encodeOneStep(filename, image, width, height);

#ifdef DEBUG
  std::cout<<"Debug1."<<std::endl;
#endif

#ifdef RELEASE
  std::cout<<"Release1."<<std::endl;
#endif

}
