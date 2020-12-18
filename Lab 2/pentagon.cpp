#pragma once
#include "pentagon.h"
#include <cmath>

Pentagon::Pentagon(int count) : Figure(count) {}

double Pentagon::getArea() {
	double p = getPerimeter() / 2;
	double s = 1;
	for (int i = 0; i < _P; i++) {
		s *= p - side[i];
	}
	return sqrt(s);
}

double Pentagon::getPerimeter() {
	double sum = 0;
	for (int i = 0; i < _P; i++) {
		sum += side[i];
	}
	return sum;
}

void Pentagon::getWeight() {
	weight[0] = 0;
	weight[1] = 0;
	for (int i = 0; i < _P; i++) {
		weight[0] += points->x[i];
		weight[1] += points->y[i];
	}
	weight[0] = weight[0] / _P;
	weight[1] = weight[1] / _P;
}

void Pentagon::onRotate(double angle) {

	for (int i = 0; i < _P; i++) {
		points->x[i] = weight[0] + (points->x[i] - weight[0]) * cos(angle) - (points->y[i] - weight[1]) * sin(angle);
		points->y[i] += weight[1] + (points->x[i] - weight[0]) * sin(angle) + (points->y[i] - weight[1]) * cos(angle);
	}

}

void Pentagon::onMove(double x, double y) {
	for (int i = 0; i < _P; i++) {
		points->x[i] += x;
		points->y[i] += y;
	}
}

Pentagon::~Pentagon() {}