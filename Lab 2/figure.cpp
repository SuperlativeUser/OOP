#pragma once
#include "figure.h"
#include <cmath>
#include <iostream>
Figure::Figure(const int count) : side(0) {
	points = getPoints(count);
}

bool Figure::asSidesExist(const int count){
	side = new double[count];
	double sum = 0, max = -1;

	for (int i = 1; i < count; i++) {
		double tempx = points->x[i] - points->x[i - 1];
		double tempy = points->y[i] - points->y[i - 1];
		side[i - 1] = sqrt(tempx * tempx + tempy * tempy);
		if (max < side[i - 1]) {
			max = side[i - 1];
		}
		sum += side[i - 1];
	}
	double tempx = points->x[0] - points->x[count - 1];
	double tempy = points->y[0] - points->y[count - 1];
	side[count - 1] = sqrt(tempx * tempx + tempy * tempy);
	sum += side[count - 1];
	if (max < side[count - 1]) {
		max = side[count - 1];
	}
	if (sum - max <= max) {
		return false;
	}
	return true;
}

double Figure::getArea() { return -1; }

double Figure::getPerimeter() { return -1; }

void Figure::getWeight() {}

void Figure::onRotate(const double angle) {}

void Figure::onMove(const double x, const double y) {}

Points* Figure::getPoints(const int count) {
	Points* points = new Points(count);
	std::cout << "Enter points by clockwise" << std::endl;
	for (int i = 0; i < count; i++) {
		std::cout << "Enter ";

		std::cout << "x" << i + 1 << " y" << i + 1 << std::endl;

		std::cin >> points->x[i] >> points->y[i];
	}
	return points;
}

Figure::~Figure() {
	delete points;
	delete[] side;
	delete[] weight;
}

Points::Points(const int n) {
	x = new double[n];
	y = new double[n];
}

Points::~Points() {
	delete[] x;
	delete[] y;
}