#include <fstream>
#include <iostream>
#include <string>

#include "pseudoBitmap.h"

int main()
{
    pseudoBitmap textArt{"./examples/example.txt"};
    textArt.drawImage();

    std::cout << textArt.getImageEssentials("width") << " x " << textArt.getImageEssentials("heigth") << std::endl;

    return 0;
}

