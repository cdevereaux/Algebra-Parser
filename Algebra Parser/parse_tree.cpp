#include "parser.h"
#include "parsable_functions.h"


Binary_Operator_Node::Binary_Operator_Node(Binary_Operator op, std::string left_substr, std::string right_substr) 
    try : op(op), left(parse(left_substr)), right(parse(right_substr)) {}
catch (Unknown_Function_Exception &e) {
    throw e;
}
catch (...) {
    throw Missing_Operand_Exception(op, &left_substr, &right_substr);
};

double Binary_Operator_Node::evaluate(double x) const
{
    switch (op)
    {
    case Binary_Operator::Addition:
        return left->evaluate(x) + right->evaluate(x);
    case Binary_Operator::Subtraction:
        return left->evaluate(x) - right->evaluate(x);
    case Binary_Operator::Multiplication:
        return left->evaluate(x) * right->evaluate(x);
    case Binary_Operator::Division:
        return left->evaluate(x) / right->evaluate(x);
    case Binary_Operator::Exponentiation:
        return pow(left->evaluate(x), right->evaluate(x));
    default:
        //Should never run, all enum values are accounted for above
        throw std::exception();
    }
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