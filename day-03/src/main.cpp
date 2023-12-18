#include <fstream>
#include <iostream>
#include <string>

#include "pseudoBitmap.h"
#include "tokenFactory.h"

int main()
{
    pseudoBitmap textArt{"./examples/riddle.txt"};
    // textArt.drawImage();
    std::unordered_map<std::string, int> imageSize = textArt.getSize();

    tokenFactory tokenizer(textArt, imageSize.at("width"), imageSize.at("heigth"));
    std::vector<token> collectionOfToken = tokenizer.tokenize();

    int sumOfPartNumbers = 0;
    for (auto & token : collectionOfToken)
    {
        std::cout << token.getValue() << std::endl;

        if (token.verify() == true)
        {
            sumOfPartNumbers += token.getValue();
        }
    }

    std::cout << "the sum of all available Parts is: " << sumOfPartNumbers << std::endl;

    return 0;
}

