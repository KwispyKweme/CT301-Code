#ifndef element.h
#define element .h

#include <stdexcept>
#include <string>

class InvalidElement : std::invalid_argument
{
public:
    explicit InvalidElement(const std::string &message) : std::invalid_argument(message) {}
};

#endif