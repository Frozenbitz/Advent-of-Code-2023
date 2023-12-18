#include <fstream>
#include <iostream>
#include <string>

#include "pseudoBitmap.h"

int main()
{
    pseudoBitmap textArt{"./examples/example.txt"};
    textArt.drawImage();
    
    return 0;
}
