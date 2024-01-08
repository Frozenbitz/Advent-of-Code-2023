#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    Node(std::string const& name, std::string const& left, std::string const& right); // constructor
    ~Node() = default; // destructor

    std::string traverseLeft() const;
    std::string traverseRight() const;
    std::string getName() const;

private:
    // Add your member variables here
    std::string name;
    std::string left;
    std::string right;
};

#endif // NODE_H