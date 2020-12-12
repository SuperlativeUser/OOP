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
	double* weight = new double[2];
};

class Pentagon: public Figure{
public:
	Pentagon(Points* points);

	double getArea() override;

	double getPerimeter() override;

	double* getWeight() override;

	void onRotate(double angle) override;

	void onMove(double x, double y) override;

	~Pentagon();
private:
	double* weight = new double[2];
};