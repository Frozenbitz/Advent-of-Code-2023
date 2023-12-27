#ifndef CARDSTASH_H
#define CARDSTASH_H

#include <string>
#include <vector>

class cardstash
{
private:
    std::vector<int> winningNumbers {};
    std::vector<int> scratchHands {};
    int CardID = -1;
    int points = -1;
public:
    cardstash(std::string const & card);
    ~cardstash() = default;

    int getPoints() const;
    int getID() const;
    int extractID(std::string const & card);
    std::vector<int> extractHands(std::string const & hands);
    std::vector<std::string> split(const std::string& s, char delimiter);
    void calculatePoints();
    int power(int base, int exponent) const;

};



#endif // CARDSTASH_H