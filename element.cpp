#include "element.h"
#include <string>
#include <stdexcept>
int int_value;
double double_value;
bool double_type;
Element::Element(int newInt)
{
    int_value = newInt;
    double_type = false;
}
Element::Element(double newDouble)
{
    double_value = newDouble;
    double_type = true;
}
Element::Element(const std::string &newVal)
{
    if (newVal.find('.') != std::string::npos)
    {
        double_value = std::stod(newVal);
        double_type = true;
    }
    else
    {
        int_value = std::stoi(newVal);
        double_type = false;
    }
}
double Element::Value() const
{
    if (double_type)
    {
        return double_value;
    }
    return int_value;
}
double Element::DoubleValue() const
{
    return double_value;
}
int Element::intValue() const
{
    return int_value;
}
bool Element::isDouble() const
{
    return double_type;
}
// All Operator functions are practically the same, save for modulo and division
Element operator+(const Element &left, const Element &right)
{
    if (left.isDouble() || right.isDouble())
    {
        return Element(left.double_value + right.double_value);
    }
    return Element(left.intValue() + right.intValue());
}
Element operator-(const Element &left, const Element &right)
{
    if (left.isDouble() || right.isDouble())
    {
        return Element(left.double_value - right.double_value);
    }
    return Element(left.intValue() - right.intValue());
}
Element operator*(const Element &left, const Element &right)
{
    if (left.isDouble() || right.isDouble())
    {
        return Element(left.double_value * right.double_value);
    }
    return Element(left.intValue() * right.intValue());
}
Element operator/(const Element &left, const Element &right)
{
    if (right.Value() == 0)
    {
        throw std::domain_error("Division by zero is not allowed");
    }
    if (left.isDouble() || right.isDouble())
    {
        return Element(left.double_value / right.double_value);
    }
    return Element(left.intValue() / right.intValue());
}
Element operator%(const Element &left, const Element &right)
{
    if (left.isDouble() || right.isDouble() || right.int_value == 0)
    {
        throw std::domain_error("Modulo with floating point values or Zero is not allowed");
    }
    return Element(left.intValue() % right.intValue());
}
std::ostream &operator<<(std::ostream &os, const Element &e)
{
    if (e.double_type)
    {
        os << e.double_type;
    }
    else
    {
        os << e.int_value;
    }
    return os;
}
