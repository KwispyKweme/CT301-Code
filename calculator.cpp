#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include "element.h"
int Do_Math(std::string left, char op, std::string right)
{
    if (op == '%')
    {
        int left_el = stoi(left);
        int right_el = stoi(right);
        int result = left_el % right_el;
        std::cout << result << std::endl;
        return 0;
    }
    else
    {
        double left_el = stod(left);
        double right_el = stod(right);
        double result;
        switch (op)
        {
        case '+':
            result = left_el + right_el;
            std::cout << result << std::endl;
            return 0;
        case '*':
            result = left_el * right_el;
            std::cout << result << std::endl;
            return 0;
        case '/':
            result = left_el / right_el;
            std::cout << result << std::endl;
            return 0;
        case '-':
            result = left_el - right_el;
            std::cout << result << std::endl;
            return 0;
        default:
            return 1;
        }
    }
}

int FileMode(std::string File_Path)
{
    std::ifstream file(File_Path);
    if (!file.is_open())
    {
        std::cerr << "File could not be opened" << std::endl;
        return 2;
    }
    std::string line;
    int line_num = 0;
    while (std::getline(file, line))
    {
        ++line_num;
        if (line.find_first_not_of(" \t\n\r\v\f") == std::string::npos) // Changed this to check for whitespace line
        {
            continue;
        }
        std::istringstream ss(line);
        std::string left;
        std::string op;
        std::string right;
        if (!(ss >> left >> op >> right))
        {
            std::cerr << "Invalid equation on line " << line_num << std::endl;
            return 2 + line_num;
        }
        for (size_t i = 0; i < left.length(); ++i) // int was changed to size_t becasue of error received by auto grader script
        {
            if (!std::isdigit(left[i]) && left[i] != '.')
            {
                std::cerr << "Left element contains a non-digit element on line " << line_num << std::endl;
                return 2 + line_num;
            }
        }
        for (size_t i = 0; i < right.length(); ++i) // int was changed to size_t becasue of error received by auto grader script
        {
            if (!std::isdigit(right[i]) && right[i] != '.')
            {
                std::cerr << "Right element contains a non-digit element on line " << line_num << std::endl;
                return 2 + line_num;
            }
        }
        if ((op == "/" || op == "%") && stod(right) == 0)
        {
            std::cerr << "Division or Modulo by zero is not allowed on line " << line_num << std::endl;
            return 2 + line_num;
        }
        if ((op == "%") && ((left.find('.') != std::string::npos || right.find('.') != std::string::npos)))
        {
            std::cerr << "Modulo is not allowed between floating point values on line " << line_num << std::endl;
            return 2 + line_num;
        }
        if (op != "+" && op != "-" && op != "/" && op != "%" && op != "*")
        {
            std::cerr << "Invalid Mathematical Operator on line " << line_num << std::endl;
            return 2 + line_num;
        }
        Do_Math(left, op[0], right);
    }
    file.close();
    return 0;
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "Usage: Enter either a filename to parse or an equation to be parsed in the format of \"Left_Element Operator Right_Element\"" << std::endl;
        return 1;
    }
    else if (argc == 2)
    {
        FileMode(argv[1]);
    }
    else if (argc == 4) // Note, change this into a function when you get time
    {
        std::string left = argv[1];
        std::string op = argv[2];
        std::string right = argv[3];
        for (size_t i = 0; i < left.length(); ++i) // int was changed to size_t becasue of error received by auto grader script
        {
            if (!std::isdigit(left[i]) && left[i] != '.')
            {
                std::cerr << "Left element contains a non-digit element" << std::endl;
                return 3;
            }
        }
        for (size_t i = 0; i < right.length(); ++i) // int was changed to size_t becasue of error received by auto grader script
        {
            if (!std::isdigit(right[i]) && right[i] != '.')
            {
                std::cerr << "Right element contains a non-digit element" << std::endl;
                return 3;
            }
        }
        if ((op == "/" || op == "%") && stod(right) == 0)
        {
            std::cerr << "Division or Modulo by zero is not allowed" << std::endl;
            return 5;
        }
        if (op != "+" && op != "-" && op != "/" && op != "%" && op != "*")
        {
            std::cerr << "Invalid Mathematical Operator" << std::endl;
            return 4;
        }
        if ((op == "%") && ((left.find('.') != std::string::npos || right.find('.') != std::string::npos)))
        {
            std::cerr << "Modulo is not allowed between floating point values" << std::endl;
            return 5;
        }
        Do_Math(left, op[0], right);
    }
    else
    {
        std::cerr << "Invalid number of arguments" << std::endl;
        return 2;
    }
}