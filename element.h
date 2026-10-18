#include <string>

class Element
{
private:
    int int_value;
    double double_value;
    bool double_type;

public:
    Element(int newInt);
    Element(double newDouble);
    Element(const std::string &newVal);
    double Value() const;
    double DoubleValue() const;
    int intValue() const;
    bool isDouble() const;
    void Value(double newVal);
    void ChangeType();
    friend Element operator+(const Element &left, const Element &right);
    friend Element operator-(const Element &left, const Element &right);
    friend Element operator*(const Element &left, const Element &right);
    friend Element operator/(const Element &left, const Element &right);
    friend Element operator%(const Element &left, const Element &right);
    friend std::ostream &operator<<(std::ostream &os, const Element &e);
};