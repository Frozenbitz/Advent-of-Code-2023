#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

class card
{
private:
    std::vector<int> winningNumbers {};
    std::vector<int> scratchHands {};
    int CardID = -1;
    int points = -1;
public:
    card(std::string const & card);
    ~card() = default;

    int getPoints() const;
    int extractID(std::string const & card);
    std::vector<int> extractHands(std::string const & hands);
    std::vector<std::string> split(const std::string& s, char delimiter);
    void calculatePoints();
    int power(int base, int exponent) const;
};



#endif // CARD_H