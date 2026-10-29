#pragma once
#include <string>
#include "element.h"
#include <iostream>

class Operation : public Element
{
private:
    Element leftElem;
    char op;
    Element rightElem;

public:
    Operation(const std::string &element);
    Operation(const Element &leftElem, char op, const Element &rightElem);
    Operation(const Operation &other);
    Operation &operator=(Operation other);
    virtual ~Operation();
    friend std::ostream &operator<<(std::ostream &, const Operation &);
    void Print(std::ostream &os) const override;
};