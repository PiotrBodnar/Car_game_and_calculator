#include "Calculator.hpp"
#include <cmath>

Calculator::Calculator() {}

Calculator::~Calculator() {}

void Calculator::add(double x, double y) {
    result = x + y;
}

void Calculator::subtract(double x, double y) {
    result = x - y;
}

void Calculator::multiply(double x, double y) { 
    result = x * y;
}

Calculator::Status Calculator::divide(double x, double y) {
    if (y == 0.0) {
        return Calculator::Status::DivisionByZero;
    }
    result = x / y;
    return Calculator::Status::Success;
}

double Calculator::get_result() {
    return result;
}

Calculator::Status Calculator::square_function_roots (
    double a, double b, double c,
    double& x1, double& x2
) {
    int delta = 0;
    if (a != 0)
    {
        delta = pow(-b, 2) - 4 * a * c;

        if (delta > 0)
        {
            x1 = (-b - sqrt(delta)) / 2 * a;
            x2 = (-b + sqrt(delta)) / 2 * a;
            return Calculator::Status::TwoRoots;
        }
        else if(delta==0)
        {
            x1 = -b / 2 * a;
            x2 = x1;
            return Calculator::Status::OneRoot;
        }
        else
        {
            return Calculator::Status::NoRoots;
        }
    }
    else if (b != 0)
    {
        return Calculator::Status::LinearFunction;
    }
    else
    {
        return Calculator::Status::ConstansFunction;
    }

  return Calculator::Status::Success;
}
