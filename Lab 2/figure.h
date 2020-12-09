#pragma once
class Points {
public:
	Points(int n) {
		x = new double[n];
		y = new double[n];
	};
	double* x;
	double* y;
	~Points() {
		delete[] x;
		delete[] y;
	}
};

class Figure {
public:
	Figure(Points* tpoints): side(0) {
		points = tpoints;
	}
	virtual double getArea() { return -1; }

	virtual double getPerimeter(){ return -1; }

	virtual double* getWeight() { return 0; }

	virtual bool asSidesExist() { return false; }
	
	virtual ~Figure() {
		delete points;
		delete[] side;
	};

protected:
	Points* points;
	double* side;
};

