#include "circle.h"

Circle::Circle(
    const std::string& name, 
    const double r
):
    name_(name),
    r_(r) {}

std::string Circle::Name() const {
    return name_;
}

double Circle::Perimeter() const {
    return 2.0 * 3.14 * r_;
}

double Circle::Area() const {
    return 3.14 * (r_ * r_);
}
