#pragma once
#include "figure.h"
#include <cmath>


class Ractangle: public Figure {
public:
	Ractangle(Points* points): Figure(points) {}

	double getArea() override {
		double p= getPerimeter() / 2;
		double s = 1;
		for (int i = 0; i < 4; i++) {
			s *= p - side[i];
		}
		return sqrt(s);
	}

	double getPerimeter() override {
		double sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += side[i];
		}
		return sum;
	}

	double* getWeight() override {
		weight[0] = 0;
		weight[1] = 0;
		for (int i = 0; i < 4; i++) {
			weight[0] += points->x[i];
			weight[1] += points->y[i];
		}
		weight[0] = weight[0] / 4;
		weight[1] = weight[1] / 4;
		
		return weight;
	}

	
	~Ractangle() {
		delete[] weight;
	}
private:
	double* weight = new double[2];
};

class Pentagon: public Figure{
public:
	Pentagon(Points* points) : Figure(points) {
		side = new double[5];
	}

	double getArea() override {
		double p = getPerimeter() / 2;
		double s = 1;
		for (int i = 0; i < 5; i++) {
			s *= p - side[i];
		}
		return sqrt(s);
	}

	double getPerimeter() override {
		double sum = 0;
		for (int i = 0; i < 5; i++) {
			sum += side[i];
		}
		return sum;
	}

	double* getWeight() override {
		weight[0] = 0;
		weight[1] = 0;
		for (int i = 0; i < 4; i++) {
			weight[0] += points->x[i];
			weight[1] += points->y[i];
		}
		weight[0] = weight[0] / 4;
		weight[1] = weight[1] / 4;

		return weight;
	}

	bool asSidesExist() override {
		double sum = 0, max = -1;

		for (int i = 1; i < 5; i++) {
			double tempx = points->x[i] - points->x[i - 1];
			double tempy = points->y[i] - points->y[i - 1];
			side[i] = sqrt(tempx * tempx + tempy * tempy);
			if (max < side[i]) {
				max = side[i];
			}
			sum += side[i];
		}
		double tempx = points->x[0] - points->x[4];
		double tempy = points->y[0] - points->y[4];
		side[4] = sqrt(tempx * tempx + tempy * tempy);
		sum += side[4];
		if (max < side[4]) {
			max = side[4];
		}

		if (sum - max <= max) {
			return false;
		}
		return true;
	}
	~Pentagon() {
		delete[] weight;
	}
private:
	double* weight = new double[2];
};