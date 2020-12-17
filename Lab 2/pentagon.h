#pragma once
#include "figure.h"
class Pentagon : public Figure {
public:
	Pentagon(Points* points);

	double getArea() override;

	double getPerimeter() override;

	double* getWeight() override;

	void onRotate(double angle) override;

	void onMove(double x, double y) override;

	~Pentagon();
private:
	static const int _P = 5;
	double* weight = new double[2];
};