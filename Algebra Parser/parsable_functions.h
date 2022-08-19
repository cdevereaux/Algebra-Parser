#pragma once
#include <map>
#include <string>

//For evaluating unary minuses
static double neg(double x) { return -x; }
//For evaluating unary plusses
static double id(double x) { return x; }

const std::map<std::string, double(*)(double)> known_functions
{
    {"-", neg}, {"+", id},
    {"log", log}, {"exp", exp}, {"sqrt", sqrt},
    {"cos", cos}, {"sin", sin}, {"tan", tan},
    {"acos", acos}, {"asin", asin}, {"atan", atan},
    {"ceil", ceil}, {"floor", floor}, {"round", round},
    {"abs", fabs}
};