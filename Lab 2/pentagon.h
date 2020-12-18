#pragma once
#include "figure.h"
class Pentagon : public Figure {
public:
	

	Pentagon(const int count);

	double getArea() override;

	double getPerimeter() override;

	void getWeight() override;

	void onRotate(const double angle) override;

	void onMove(const double x, const double y) override;

	~Pentagon();
private:
	static const int _P = 5;
	
};