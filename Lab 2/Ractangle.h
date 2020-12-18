#pragma once
#include "figure.h"

class Ractangle: public Figure {
public:
	

	Ractangle(const int count);

	double getArea() override;

	double getPerimeter() override;

	void onRotate(const double angle) override;
	
	void onMove(const double x, const double y) override;

	void getWeight() override;

	~Ractangle();
private:
	static const int _R = 4;
	
};