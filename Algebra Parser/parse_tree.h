#pragma once
#include <memory>
#include <string>

class Parse_Tree_Node
{
public:
    virtual double evaluate(double x) { return 0; }
};

typedef std::shared_ptr<Parse_Tree_Node> Parse_Tree_Ptr;

class Addition_Node : public Parse_Tree_Node
{
private:
    Parse_Tree_Ptr left, right;
public:
    Addition_Node(std::string left_substr, std::string right_substr);
    double evaluate(double x) override;
};

class Subtraction_Node : public Parse_Tree_Node
{
private:
    Parse_Tree_Ptr left, right;
public:
    Subtraction_Node(std::string left_substr, std::string right_substr);
    double evaluate(double x) override;
};

class Multiplication_Node : public Parse_Tree_Node
{
private:
    Parse_Tree_Ptr left, right;
public:
    Multiplication_Node(std::string left_substr, std::string right_substr);
    double evaluate(double x) override;
};

class Division_Node : public Parse_Tree_Node
{
private:
    Parse_Tree_Ptr left, right;
public:
    Division_Node(std::string left_substr, std::string right_substr);
    double evaluate(double x) override;
};

class Exponentiation_Node : public Parse_Tree_Node
{
private:
    Parse_Tree_Ptr left, right;
public:
    Exponentiation_Node(std::string left_substr, std::string right_substr);
    double evaluate(double x) override;
};

class Function_Node : public Parse_Tree_Node
{
private:
    double(*func)(double);
    Parse_Tree_Ptr input;
public:
    Function_Node(double(*func)(double), std::string input_str);
    double evaluate(double x) override;
};

class X_Node : public Parse_Tree_Node
{
public:
    X_Node();
    double evaluate(double x) override;
};

class Constant_Node : public Parse_Tree_Node
{
private:
    double value;
public:
    Constant_Node(double value);
    double evaluate(double x) override;
};