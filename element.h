#pragma once
#include <string>

class Element
{
private:
    int int_value;
    double double_value;
    bool double_type;

public:
    Element();
    Element(int newInt);
    Element(double newDouble);
    Element(const std::string &newVal);
    virtual double Value() const;
    virtual double DoubleValue() const;
    virtual int intValue() const;
    virtual bool isDouble() const;
    virtual void Value(double newVal);
    virtual void ChangeType();
    friend Element operator+(const Element &left, const Element &right);
    friend Element operator-(const Element &left, const Element &right);
    friend Element operator*(const Element &left, const Element &right);
    friend Element operator/(const Element &left, const Element &right);
    friend Element operator%(const Element &left, const Element &right);
    friend std::ostream &operator<<(std::ostream &os, const Element &e);
};