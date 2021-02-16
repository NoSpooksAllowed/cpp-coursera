#include "triangle.h"
#include <cmath>

Triangle::Triangle(
    const std::string& name,
    const double a,
    const double b,
    const double c
): 
    name_(name), 
    a_(a), 
    b_(b), 
    c_(c) {}


std::string Triangle::Name() const {
    return name_;
}

double Triangle::Perimeter() const {
    return a_ + b_ + c_;
}

double Triangle::Area() const {
    const double p = Perimeter() / 2;
    return std::sqrt(p * (p - a_) * (p - b_) * (p - c_));
}
