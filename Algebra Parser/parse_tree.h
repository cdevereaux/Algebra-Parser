#pragma once
#include <memory>
#include <string>
#include <vector>

class Parse_Tree_Node
{
public:
    virtual double evaluate(double x) const { return 0; }
};

typedef std::shared_ptr<Parse_Tree_Node> Parse_Tree_Ptr;

enum class Binary_Operator
{
    Addition = '+', Subtraction = '-', Multiplication = '*', Division = '/', Exponentiation = '^'
};

class Binary_Operator_Node : public Parse_Tree_Node
{
private:
    const Binary_Operator op;
    Parse_Tree_Ptr left, right;
public:
    Binary_Operator_Node(Binary_Operator op, std::string left_substr, std::string right_substr);
    double evaluate(double x) const override;
};


class Function_Node : public Parse_Tree_Node
{
private:
    double(*func)(double);
    Parse_Tree_Ptr input;
public:
    Function_Node(double(*func)(double), std::string input_str);
    double evaluate(double x) const override;
};

class X_Node : public Parse_Tree_Node
{
public:
    X_Node();
    double evaluate(double x) const override;
};

class Constant_Node : public Parse_Tree_Node
{
private:
    double value;
public:
    Constant_Node(double value);
    double evaluate(double x) const override;
};