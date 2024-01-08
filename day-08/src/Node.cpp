#include "Node.h"

Node::Node(std::string const& name, std::string const& left, std::string const& right) :
    name{name}, left{left}, right{right} {}


std::string Node::traverseLeft() const {
    return left;
}


std::string Node::traverseRight() const {
    return right;
}

std::string Node::getName() const {
    return name;
}