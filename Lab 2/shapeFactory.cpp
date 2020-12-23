#pragma once
#include "shapeFactory.h"
#include "pentagon.h"
#include "ractangle.h"
#include <iostream>

Figure* ShapeFactory::createFigure(const int count) {
	if (count > _MINIMUM_FIGURE_SIDE) {
		Figure* figure = nullptr;
		switch (count) {
		case 4:
			figure = new Ractangle(count);
			break;
		case 5:
			figure = new Pentagon(count);
			break;
		}
		if (!figure->Figure::asSidesExist(count)) {
			delete figure;
			return nullptr;
		}
		else {
			return figure;
		}
	}
	return nullptr;
}