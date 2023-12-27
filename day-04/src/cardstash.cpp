#include "cardstash.h"

#include <sstream>
#include <iostream>
#include <regex>
#include <numeric>

cardstash::cardstash(std::string const & card)
{

    // split the card strings into all 3 parts: cardstash, winning, hands
    std::string ccard = card;
    std::vector<std::string> token = split(ccard, ':');
    std::string tmp = token.at(1);
    token.pop_back();
    std::vector<std::string> tmpToken = split(tmp, '|');
    token.insert(token.end(), tmpToken.begin(), tmpToken.end());

    CardID = extractID(token.at(0));
    winningNumbers = extractHands(token.at(1));
    scratchHands = extractHands(token.at(2));

    // compare the winning numbers with the scratch hand and calc. the points
    calculatePoints();
    
    if (CardID == -1)
        throw std::invalid_argument("card id not correct");

    if (points == -1)
        throw std::invalid_argument("points cannot be negative");

}


int cardstash::getPoints() const
{
    return points;
}


int cardstash::getID() const
{
    return CardID;
}


int cardstash::extractID(std::string const & card)
{
    std::string pattern = R"(\s*Card\s*(\d+))";
    std::regex token_pattern(pattern, std::regex::ECMAScript);
    std::smatch tmatch;

    if (not std::regex_search(card, tmatch, token_pattern))
        return -1;
        
    return stoi(tmatch[1]);
}


std::vector<int> cardstash::extractHands(std::string const & hands)
{
    std::string pattern = R"(\s*(\d+)\s*)";
    std::regex token_pattern(pattern, std::regex_constants::ECMAScript);
    auto words_begin = std::sregex_iterator(hands.begin(), hands.end(), token_pattern);
    auto words_end = std::sregex_iterator(); //The default-constructed std::regex_iterator is the end-of-sequence iterator.

    std::vector<int> results {};

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) { // invrement calls r_search
        std::smatch match = *i;
        results.push_back(stoi(match.str()));
        // std::cout << stoi(match.str()) << std::endl;
    }

    return results;
}


// See: https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
std::vector<std::string> cardstash::split(const std::string& s,
                                              char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void cardstash::calculatePoints()
{
    const std::vector<int> tmp = scratchHands;
    points = 0;

    for (auto && n : winningNumbers)
    {
        if (std::find(tmp.begin(), tmp.end(), n) != std::end(tmp))
        {
            points++;
        }
    }
}

// int cardstash::power(int base, int exponent) const {
//     std::vector<int> v(exponent, base);
//     return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
// }