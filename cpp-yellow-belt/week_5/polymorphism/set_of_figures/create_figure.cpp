#include "create_figure.h"

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
