#pragma once
#include "i_figure.h"

class Rect : public Figure {
public:
    Rect(
        const std::string& name,
        const double width,
        const double height
    );

    std::string Name() const override;
    double Perimeter() const override;
    double Area() const override;
private:
    const std::string name_;
    const double width_;
    const double height_;
};
