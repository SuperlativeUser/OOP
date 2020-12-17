#pragma once
#include "figure.h"

class Ractangle: public Figure {
public:
	Ractangle(Points* points);

	double getArea() override;

	double getPerimeter() override;

	void onRotate(double angle) override;
	
	void onMove(double x, double y) override;

	double* getWeight() override;

	~Ractangle();
private:
	static const int _R = 4;
	double* weight = new double[2];
};