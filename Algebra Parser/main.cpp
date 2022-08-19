#include <iostream>
#include <string>
#include "parser.h"

int main()
{
    std::cout << "f(x) = ";
    std::string input;
    while (std::getline(std::cin, input))
    {
        auto formula = parse(input);

         //formula->draw();
        std::cout << formula->evaluate(5) << std::endl;
        std::cout << "f(x) = ";
    }
}