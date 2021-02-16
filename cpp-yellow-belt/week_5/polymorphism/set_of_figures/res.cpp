#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

class Figure {
public:
    virtual std::string Name() const = 0;    
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

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

std::shared_ptr<Figure> CreateFigure(std::istringstream& is); 

std::shared_ptr<Figure> CreateFigure(std::istringstream& is) {
    std::string figure_name;
    is >> figure_name;

    if (figure_name == "RECT") {
        double width = 0;
        double height = 0;

        is >> width >> height;

        return std::make_shared<Rect>(figure_name, width, height);
    } else if (figure_name == "TRIANGLE") {
        double a = 0;
        double b = 0;
        double c = 0;

        is >> a >> b >> c;

        return std::make_shared<Triangle>(figure_name, a, b, c);
    } else {
        double r = 0;

        is >> r;

        return std::make_shared<Circle>(figure_name, r);
    }
}
int main() {
    std::vector<std::shared_ptr<Figure>> figures;

    for (std::string line; getline(std::cin, line); ) {
        std::istringstream is(line);

        std::string command;
        is >> command;
        if (command == "ADD") {
            is >> std::ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                std::cout << std::fixed << std::setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << std::endl;
            }
        }
    }

    return 0;
}
