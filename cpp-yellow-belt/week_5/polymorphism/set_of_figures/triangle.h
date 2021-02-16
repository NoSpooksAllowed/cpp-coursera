#pragma once
#include "i_figure.h"

class Triangle : public Figure {
public:
    Triangle(
        const std::string& name,
        const double a,
        const double b,
        const double c
    );

    std::string Name() const override;
    double Perimeter() const override;
    double Area() const override;
private:
    const std::string name_;
    const double a_;
    const double b_;
    const double c_;
};
