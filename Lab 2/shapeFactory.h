#pragma once
#include "figure.h"
class ShapeFactory {
public:
	static Figure* createFigure(const int value);
private:
	static const int _MINIMUM_FIGURE_SIDE = 3;
};