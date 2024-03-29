#include <algorithm>
#include <iostream>
#include <vector>
#include "parse_tree.h"
#include "parser.h"
#include "parsable_functions.h"


static void validate_parentheses(const std::string& str)
{
    auto paren_count = 0;
    for (auto it = str.cbegin(); it != str.cend(); it++)
    {
        if (*it == '(') paren_count++;
        else if (*it == ')') paren_count--;
        if (paren_count < 0) throw Mismatched_Parentheses_Exception();
    }
    if (paren_count != 0) throw Mismatched_Parentheses_Exception();
}


//finds rightmost instance of any of the given operands,
//ignores unary plusses & minuses
//returns str.size() on failure
static size_t find_binary_operand(const std::string &str, std::vector<char> ops)
{
    auto paren_count = 0;
    for (auto it = str.crbegin(); it != str.crend(); it++)
    {
        if ( *it == '(') paren_count--;
        else if ( *it == ')') paren_count++;
        else if ((paren_count == 0))
        {
            //check for unary operands
            if ( *it == '-' || *it == '+')
            {
                //if there is an open parenthesis or operand to the left
                //of a valid minus sign, then it must be a unary minus
                char c;
                if ( (it+1) == str.crend() || (c = *(it+1), c == '(') ||
                    c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
                {
                    continue;
                }
            }
            for (auto c : ops)
            {
                if ( *it == c)
                {
                    return it.base() - str.begin() - 1;
                }
            }
        }
    }
    return str.size();
}


static Parse_Tree_Ptr parse_req(std::string str)
{
    if (str.empty())
    {
        throw std::exception();
    }

    if ((str.front() == '(') && (str.back() == ')'))
    {
        auto paren_count = 1;
        for (auto i = 1u; i < str.size(); i++)
        {
            auto c = str.at(i);
            if (c == '(') paren_count++;
            else if (c == ')') {
                paren_count--;
                if (paren_count == 0) {
                    if (i == (str.size() - 1)) return parse_req(str.substr(1, str.size() - 2));
                    else break;
                }
            }
        }   
    }

    if (str == "x")
    {
        return std::make_shared<X_Node>();
    }

    //Search for addition and subtraction
    auto ind = find_binary_operand(str, std::vector<char>{'+', '-'});
    if (ind != str.size())
    {
        auto left_substr = str.substr(0, ind);
        auto right_substr = str.substr(ind + 1);
       if (str.at(ind) == '+') return std::make_shared<Binary_Operator_Node>(Binary_Operator::Addition, left_substr, right_substr);
       else return std::make_shared<Binary_Operator_Node>(Binary_Operator::Subtraction, left_substr, right_substr);
    }

    //Search for multiplication and division
    ind = find_binary_operand(str, std::vector<char>{'*', '/'});
    if (ind != str.size())
    {
        auto left_substr = str.substr(0, ind);
        auto right_substr = str.substr(ind + 1);
        if (str.at(ind) == '*') return std::make_shared<Binary_Operator_Node>(Binary_Operator::Multiplication, left_substr, right_substr);
        else return std::make_shared<Binary_Operator_Node>(Binary_Operator::Division, left_substr, right_substr);
    }

    //Search for exponentiation
    ind = find_binary_operand(str, std::vector<char>{'^'});
    if (ind != str.size())
    {
        auto left_substr = str.substr(0, ind);
        auto right_substr = str.substr(ind + 1);
        return std::make_shared<Binary_Operator_Node>(Binary_Operator::Exponentiation, left_substr, right_substr);
    }

    //check if only a constant remains
    try
    {
        //stod throws exception on failure
        return std::make_shared<Constant_Node>(std::stod(str));
    }
    //else try to find function that prefixes str
    catch (...)
    {
        for (auto p : known_functions) {
            if (p.first.size() < str.size())
            {
                if (str.substr(0, p.first.size()) == p.first)
                {
                    return std::make_shared<Function_Node>(p.second, str.substr(p.first.size()));
                }
            }
        }
        throw Unknown_Function_Exception(str);
    }
}


Parse_Tree_Ptr parse(std::string str)
{
    //remove any whitespace characters
    auto remove_end = std::remove_if(str.begin(), str.end(), isspace);
    str.erase(remove_end);

    //make all characters lower-case
    std::transform(str.cbegin(), str.cend(), str.begin(),
        [](char c) { return std::tolower(c); });

    //check to make sure all parentheses match
    validate_parentheses(str);

    return parse_req(str);
}