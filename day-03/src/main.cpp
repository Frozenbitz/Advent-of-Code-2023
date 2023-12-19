#include <fstream>
#include <iostream>
#include <string>

#include "pseudoBitmap.h"
#include "tokenFactory.h"
#include "gearFactory.h"

int main()
{
    pseudoBitmap textArt{"./examples/riddle.txt"};
    // textArt.drawImage();
    std::unordered_map<std::string, int> imageSize = textArt.getSize();

    tokenFactory tokenizer(textArt, imageSize.at("width"), imageSize.at("heigth"));
    std::vector<token> collectionOfToken = tokenizer.tokenize();

    gearFactory lotsOfGears(collectionOfToken, textArt, imageSize.at("width"), imageSize.at("heigth"));
    std::vector<gear> collectionOfGears = lotsOfGears.tokenize();

    int sumOfPartNumbers = 0;
    for (auto & token : collectionOfToken)
    {
        if (token.verify() == true)
        {
            sumOfPartNumbers += token.getValue();
        }
    }

    int sumOfGearRatios = 0;
    for (auto && gears : collectionOfGears)
    {
        std::cout << gears.getRatio() << std::endl;
        sumOfGearRatios += gears.getRatio();
    }
    

    std::cout << "the sum of all available Parts is: " << sumOfPartNumbers << std::endl;
    std::cout << "the sum of all gear ratios is: " << sumOfGearRatios << std::endl;
    
    return 0;
}

