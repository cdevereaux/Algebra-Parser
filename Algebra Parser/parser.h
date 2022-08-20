#pragma once
#include <exception>
#include "parse_tree.h"


Parse_Tree_Ptr parse(std::string str);

class Missing_Operand_Exception : public std::exception
{
	std::string _what;
public:
	const char op;
	const bool left_missing, right_missing;
	
	Missing_Operand_Exception(Binary_Operator op, std::string *left, std::string *right)
		: op(static_cast<char>(op)), left_missing(left->empty()), right_missing(right->empty())
	{
		_what = "Error: expected two operands for ";
		_what += this->op;
		if (left_missing && right_missing) _what += "\nMissing both operands.";
		else if (left_missing) _what += "\nMissing left operand.";
		else if (right_missing) _what += "\nMissing right operand.";
	}
	const char* what() const throw ()
	{
		return _what.c_str();
	}
};


class Mismatched_Parentheses_Exception : public std::exception
{
public:
	const char* what() const throw () 
	{
		return "Error: Mismatched Parentheses";
	}
};

class Unknown_Function_Exception : public std::exception
{
	std::string _what;
public:

	Unknown_Function_Exception(std::string name)
	{
		_what = "Error: Unknown Function: " + name;
	}

	const char* what() const throw () 
	{
		return _what.c_str();
	}
};