#include "cubeConundrum.h"
#include "game.h"
#include <sstream>
#include <regex>


cubeConundrum::cubeConundrum(std::string const& singleLineOfText)
    : cumulativeGameData{
          {"Game", -1}, {"red", -1}, {"green", -1}, {"blue", -1}, // token should map to the colors used!
      }
{
    std::vector<token> gamesToken = tokenizeColorRangeFromString (singleLineOfText);
    tokenMax(gamesToken);
}

std::vector<token> cubeConundrum::tokenizeColorRangeFromString ( const std::string & lineOfText)
{
    std::vector<std::string> tokenizedString = split(lineOfText, {':'});
    game newGame {tokenizedString[0]};
    if (setCumulativeGameData(newGame.gameKey, newGame.gameID) == false) 
        throw std::invalid_argument("could not insert to cumulativeGameData");

    std::vector<std::string> games = split(tokenizedString.at(1), {';'});
    std::vector<std::string> outputVector;
    for (auto const & cubeToken : games)
    {
        std::vector tmp = split(cubeToken, ',');
        outputVector.insert(outputVector.end(), tmp.begin(), tmp.end());
    }

    std::vector<token> gamesToken;
    for (auto const & singleToken : outputVector)
    {
        gamesToken.push_back(singleToken);
    }

    return gamesToken;
}

// See: https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
std::vector<std::string> cubeConundrum::split(const std::string& s, char delimiter)
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


void cubeConundrum::tokenMax(const std::vector<token> & tokenVector)
{
    // process all token and find the max value for each map value
    for (const auto & i: tokenVector )
    {
        if (cumulativeGameData[i.color] < i.CubeVal)
        {
            cumulativeGameData[i.color] = i.CubeVal; 
        }
    }
}

int cubeConundrum::getCumulativeGameData(std::string const & key) const
{
    auto iter = cumulativeGameData.find(key);
    if (iter != cumulativeGameData.end())
    {
        return iter->second;
    }

    return -1;
}

bool cubeConundrum::setCumulativeGameData(std::string const & key, int value)
{
    auto iter = cumulativeGameData.find(key);
    if (iter != cumulativeGameData.end())
    {
        iter->second = value;
        return true;
    }

    return false;
}

bool cubeConundrum::evaluateGame(int red, int green, int blue) const
{
    if((cumulativeGameData.at("red") <= red) &&
    (cumulativeGameData.at("blue") <= blue) &&
    (cumulativeGameData.at("green") <= green))
    {
        return true;
    }

    return false;
}