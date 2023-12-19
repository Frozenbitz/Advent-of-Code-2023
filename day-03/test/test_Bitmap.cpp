#include <cassert>
#include <iostream>

#include "pseudoBitmap.h"
#include "tokenFactory.h"

int main()
{

    pseudoBitmap textArt{"./testdata/test01.txt"};
    
    // textArt.drawImage();
    std::unordered_map<std::string, int> imageSize = textArt.getSize();

    tokenFactory tokenizer(textArt, imageSize.at("width"), imageSize.at("heigth"));
    std::vector<token> collectionOfToken = tokenizer.tokenize();

    int sumOfPartNumbers = 0;
    for (auto & token : collectionOfToken)
    {
        std::cout << token.getValue();

        if (token.verify() == true)
        {
            std::cout << "*";
        }

        std::cout << std::endl << "\r";
    }

    return 0;
}