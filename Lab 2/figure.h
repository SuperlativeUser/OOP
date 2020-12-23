#pragma once
#include "points.h"

class Figure {
public:
	Points* points;
	double* weight = new double[2];
	Figure(const int count);

	virtual double getArea();

	virtual double getPerimeter();

	virtual void getWeight();

	virtual void onRotate(const double angle);

	virtual void onMove(const double x, double y);

	bool asSidesExist(const int count);
	
	~Figure();
protected:
	double* side;

private:
	Points* getPoints(const int count);
};

