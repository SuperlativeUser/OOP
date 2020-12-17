#pragma once
#include "shapeFactory.h"
#include "pentagon.h"
#include "Ractangle.h"
#include <iostream>

Figure* ShapeFactory::createFigure(int count, Points* points) {
	if (count > _MINIMUM_FIGURE_SIDE) {
		points = new Points(count);

		std::cout << "Enter points by clockwise" << std::endl;
		for (int i = 0; i < count; i++) {
			std::cout << "Enter ";

			std::cout << "x" << i + 1 << " y" << i + 1 << std::endl;

			std::cin >> points->x[i] >> points->y[i];
		}

		switch (count) {
		case 4:
			return new Ractangle(points);
		case 5:
			return new Pentagon(points);
		}
	}
	else {
		return NULL;
	}
	
}