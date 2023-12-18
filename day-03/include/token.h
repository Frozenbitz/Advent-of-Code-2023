#ifndef TOKEN_H
#define TOKEN_H


#include <string>
#include <unordered_map>
#include <vector>

class token
{
private:
    std::string value;
    int parsedValue = -1;
    std::unordered_map<std::string, int> location {{"line", -1}, {"offset", -1}};
    std::string neighbours {};
public:
    token(/* args */) = delete;
    token(std::string const & tokenValue, int line, int offset, std::string newNeighbours);
    ~token() = default;

    bool verify() const;
    int getValue() const;
};



#endif // TOKEN_H