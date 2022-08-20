#include "parser.h"
#include "parsable_functions.h"


Addition_Node::Addition_Node(std::string left_substr, std::string right_substr) :
    left(parse(left_substr)), right(parse(right_substr)) {};

double Addition_Node::evaluate(double x) const
{
    return left->evaluate(x) + right->evaluate(x);
}


Subtraction_Node::Subtraction_Node(std::string left_substr, std::string right_substr) :
    left(parse(left_substr)), right(parse(right_substr)) {};

double Subtraction_Node::evaluate(double x) const
{
    return left->evaluate(x) - right->evaluate(x);
}


Multiplication_Node::Multiplication_Node(std::string left_substr, std::string right_substr) :
    left(parse(left_substr)), right(parse(right_substr)) {};

double Multiplication_Node::evaluate(double x) const
{
    return left->evaluate(x) * right->evaluate(x);
}


Division_Node::Division_Node(std::string left_substr, std::string right_substr) :
    left(parse(left_substr)), right(parse(right_substr)) {};

double Division_Node::evaluate(double x) const
{
    return left->evaluate(x) / right->evaluate(x);
}


Exponentiation_Node::Exponentiation_Node(std::string left_substr, std::string right_substr) :
    left(parse(left_substr)), right(parse(right_substr)) {};

double Exponentiation_Node::evaluate(double x) const
{
    return pow(left->evaluate(x), right->evaluate(x));
}


Function_Node::Function_Node(double(*func)(double), std::string input_str) :
    func(func), input(parse(input_str)) {};

double Function_Node::evaluate(double x) const
{
    return (*func)(input->evaluate(x));
}


X_Node::X_Node() {};

double X_Node::evaluate(double x) const
{
    return x;
}


Constant_Node::Constant_Node(double value) :
    value(value) {};

double Constant_Node::evaluate(double x) const
{
    return value;
}