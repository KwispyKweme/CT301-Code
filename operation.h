#include <string>
#include "element.h"

class Operation : public Element
{
public:
    Operation(const std::string &element);
    Operation(const Element &leftElem, char op, const Element &rightElem);
    Operation(const Operation &other);
    Operation &operator=(Operation other);
    virtual ~Operation();
};