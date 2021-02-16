#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <iomanip>

#include "i_figure.h"
#include "rect.h"
#include "triangle.h"
#include "circle.h"
#include "create_figure.h"

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
