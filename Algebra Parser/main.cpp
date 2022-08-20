#include <iostream>
#include <string>
#include "parser.h"
#include "Tree Printer/tree_printer.h"

int main()
{
    std::cout << "f(x) = ";
    std::string input;
    while (std::getline(std::cin, input))
    {
        try {
            auto formula = parse(input);
            std::cout << formula->evaluate(5);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << std::endl << "f(x) = ";
    }
}