#pragma once
#include "figure.h"
class ShapeFactory {
public:
	static Figure* createFigure(int value, Points* point);
private:
	static const int _MINIMUM_FIGURE_SIDE = 3;
};