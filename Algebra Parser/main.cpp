#include <iostream>
#include <string>
#include "parser.h"
#include "Tree Printer/tree_printer.h"

int main()
{
    Tree_Printer printer;

    std::cout << "f(x) = ";
    std::string input;
    while (std::getline(std::cin, input))
    {
        auto formula = parse(input);

        
        std::cout << formula->evaluate(5) << std::endl;
        std::cout << "f(x) = ";
        printer.print(formula);
    }
}