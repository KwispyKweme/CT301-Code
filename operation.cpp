#include "operation.h"
#include "exceptions.h"
#include <string>
#include <sstream>

Operation::Operation(const std::string &element)
{
    std::istringstream iss(element);
    std::string leftToken;
    std::string opToken;
    std::string rightToken;
    std::string extraToken;
    if (!(iss >> leftToken >> opToken >> rightToken))
    {
        throw InvalidElement("Expected 3 elements");
    }
    if (iss >> extraToken)
    {
        throw InvalidElement("Too many tokens!");
    }
    if ((opToken.size() != 1) || (opToken[0] != '+' && opToken[0] != '-' && opToken[0] != '/' && opToken[0] != '%' && opToken[0] != '*'))
    {
        throw InvalidOperator("Invalid operator");
    }
}

Operation::Operation(const Element &leftElem, char op, const Element &rightElem) : leftElem(leftElem), op(op), rightElem(rightElem)
{
}
Operation::Operation(const Operation &other)
{
}
std::ostream &operator<<(std::ostream &, const Operation &)
{
}
void Operation::Print(std::ostream &os) const
{
    os << "(" << leftElem << op << rightElem << ")";
}
