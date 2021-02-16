#include "rect.h"

Rect::Rect(
    const std::string& name,
    const double width,
    const double height
):
    name_(name),
    width_(width),
    height_(height) {}


std::string Rect::Name() const {
    return name_;
}

double Rect::Perimeter() const {
    return (width_ + height_) * 2;
}

double Rect::Area() const {
    return width_ * height_;
}
