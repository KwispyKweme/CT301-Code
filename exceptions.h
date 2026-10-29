#pragma once
#include <stdexcept>
#include <string>

class InvalidElement : public std::invalid_argument
{
public:
    InvalidElement(const std::string &message) : std::invalid_argument(message) {}
};
class InvalidOperator : public std::invalid_argument
{
public:
    InvalidOperator(const std::string &message) : std::invalid_argument(message) {}
};
