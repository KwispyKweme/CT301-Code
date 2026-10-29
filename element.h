#pragma once
#include <string>

class Element
{
private:
    int int_value;
    double double_value;
    bool double_type;

public:
    Element() = default;
    Element(int newInt);
    Element(double newDouble);
    Element(const std::string &newVal);
    virtual double Value() const;
    virtual double DoubleValue() const;
    virtual int intValue() const;
    virtual bool isDouble() const;
    void Value(double newVal);
    void ChangeType();
    virtual Element *Clone() const;
    virtual ~Element() = default;
    virtual void Print(std::ostream &os) const;
    friend Element operator+(const Element &left, const Element &right);
    friend Element operator-(const Element &left, const Element &right);
    friend Element operator*(const Element &left, const Element &right);
    friend Element operator/(const Element &left, const Element &right);
    friend Element operator%(const Element &left, const Element &right);
    friend std::ostream &operator<<(std::ostream &os, const Element &e);
};