#pragma once
class Points {
public:
	Points(int n);
	
	double* x = 0;
	double* y = 0;
	
	~Points();
};

class Figure {
public:
	Points* points;

	Figure(Points* tpoints) ;

	virtual double getArea();

	virtual double getPerimeter();

	virtual double* getWeight();

	virtual void onRotate(double angle);

	virtual void onMove(double x, double y);

	bool asSidesExist(int count);
	
	~Figure();
protected:
	
	double* side;
};

