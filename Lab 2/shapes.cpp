#pragma once
#define SHAPES_R 4
#define SHAPES_P 5
#include "shapes.h"
#include <cmath>

/*Ractangle*/
Ractangle::Ractangle(Points* points) : Figure(points) {
	side = new double[SHAPES_R];
}

double Ractangle::getArea() {
	double p = getPerimeter() / 2;
	double s = 1;
	for (int i = 0; i < SHAPES_R; i++) {
		s *= p - side[i];
	}
	return sqrt(s);
}

double Ractangle::getPerimeter(){
	double sum = 0;
	for (int i = 0; i < SHAPES_R; i++) {
		sum += side[i];
	}
	return sum;
}

void Ractangle::onRotate(double angle) {
	
	for (int i = 0; i < SHAPES_R; i++) {
		getWeight();
		points->x[i] = weight[0] + (points->x[i] - weight[0]) * cos(angle) - (points->y[i] - weight[1]) * sin(angle);
		points->y[i] = weight[1] + (points->x[i] - weight[0]) * sin(angle) + (points->y[i] - weight[1]) * cos(angle);
	}

}

void Ractangle::onMove(double x, double y) {
	for (int i = 0; i < SHAPES_R; i++) {
		points->x[i] += x;
		points->y[i] += y;
	}
}

double* Ractangle::getWeight(){
	weight[0] = 0;
	weight[1] = 0;
	for (int i = 0; i < SHAPES_R; i++) {
		weight[0] += points->x[i];
		weight[1] += points->y[i];
	}
	weight[0] = weight[0] / SHAPES_R;
	weight[1] = weight[1] / SHAPES_R;

	return weight;
}

Ractangle::~Ractangle() {
	delete[] weight;
}

/*Pentagon*/
Pentagon::Pentagon(Points* points) : Figure(points) {
	side = new double[SHAPES_P];
}

double Pentagon::getArea() {
	double p = getPerimeter() / 2;
	double s = 1;
	for (int i = 0; i < SHAPES_P; i++) {
		s *= p - side[i];
	}
	return sqrt(s);
}

double Pentagon::getPerimeter()  {
	double sum = 0;
	for (int i = 0; i < SHAPES_P; i++) {
		sum += side[i];
	}
	return sum;
}

double* Pentagon::getWeight(){
	weight[0] = 0;
	weight[1] = 0;
	for (int i = 0; i < SHAPES_P; i++) {
		weight[0] += points->x[i];
		weight[1] += points->y[i];
	}
	weight[0] = weight[0] / SHAPES_P;
	weight[1] = weight[1] / SHAPES_P;

	return weight;
}

void Pentagon::onRotate(double angle) {

	for (int i = 0; i < SHAPES_P; i++) {
		points->x[i] = weight[0] + (points->x[i] - weight[0]) * cos(angle) - (points->y[i] - weight[1]) * sin(angle);
		points->y[i] += weight[1] + (points->x[i] - weight[0]) * sin(angle) + (points->y[i] - weight[1]) * cos(angle);
	}

}

void Pentagon::onMove(double x, double y) {
	for (int i = 0; i < SHAPES_P; i++) {
		points->x[i] += x;
		points->y[i] += y;
	}
}

Pentagon::~Pentagon() {
	delete[] weight;
}