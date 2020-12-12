#pragma once
class Points {
public:
	Points(int n);
	
	double* x;
	double* y;
	
	~Points();
};

class Figure {
public:
	Points* points;

	Figure(Points* tpoints) ;

	virtual double getArea();

	virtual double getPerimeter();

	virtual double* getWeight();

	virtual bool asSidesExist();

	virtual void onRotate(double angle);

	virtual void onMove(double x, double y);

	bool asSidesExist(int count);
	
	~Figure();
protected:
	
	double* side;
};

