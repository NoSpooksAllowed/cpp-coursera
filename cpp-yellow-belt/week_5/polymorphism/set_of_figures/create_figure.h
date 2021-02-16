#pragma once
#include <sstream>
#include <memory>
#include <string>

#include "i_figure.h"
#include "circle.h"
#include "rect.h"
#include "triangle.h"

std::shared_ptr<Figure> CreateFigure(std::istringstream& is); 
