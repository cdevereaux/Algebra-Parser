#pragma once
#include <map>
#include <string>

//For evaluating unary minuses
static double neg(double x) { return -x; }

const std::map<std::string, double(*)(double)> known_functions
{
    {"log", log}, {"exp", exp}, {"sqrt", sqrt},
    {"cos", cos}, {"sin", sin}, {"tan", tan},
    {"acos", acos}, {"asin", asin}, {"atan", atan},
    {"ceil", ceil}, {"floor", floor}, {"round", round},
    {"abs", fabs}, {"-", neg}
};