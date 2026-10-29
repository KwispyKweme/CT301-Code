#pragma once
#include <string>
#include "element.h"

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
};