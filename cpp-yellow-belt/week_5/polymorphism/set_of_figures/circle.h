#pragma once
#include "i_figure.h"

class Circle : public Figure {
public:
    Circle(const std::string& name, const double r);
    
    std::string Name() const override;
    double Perimeter() const override;
    double Area() const override;
private:
    const std::string name_;
    const double r_;
};
