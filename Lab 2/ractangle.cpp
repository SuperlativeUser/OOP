#pragma once
#include "ractangle.h"
#include <cmath>

/*Ractangle*/
Ractangle::Ractangle(const int count) : Figure(count) {}

double Ractangle::getArea() {
 	double p = getPerimeter() / 2;
	double s = 1;
	for (int i = 0; i < _R; i++) {
		s *= p - side[i];
	}
	return sqrt(s);
}

double Ractangle::getPerimeter(){
	double sum = 0;
	for (int i = 0; i < _R; i++) {
		sum += side[i];
	}
	return sum;
}

void Ractangle::onRotate(const double angle) {
	
	for (int i = 0; i < _R; i++) {
		getWeight();
		points->x[i] = weight[0] + (points->x[i] - weight[0]) * cos(angle) - (points->y[i] - weight[1]) * sin(angle);
		points->y[i] = weight[1] + (points->x[i] - weight[0]) * sin(angle) + (points->y[i] - weight[1]) * cos(angle);
	}

}

void Ractangle::onMove(double x, double y) {
	for (int i = 0; i < _R; i++) {
		points->x[i] += x;
		points->y[i] += y;
	}
}

void Ractangle::getWeight(){
	weight[0] = 0;
	weight[1] = 0;
	for (int i = 0; i < _R; i++) {
		weight[0] += points->x[i];
		weight[1] += points->y[i];
	}
	weight[0] = weight[0] / _R;
	weight[1] = weight[1] / _R;
}

Ractangle::~Ractangle() {}
