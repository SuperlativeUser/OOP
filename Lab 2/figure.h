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

	bool asSidesExist(int count) {
		side = new double[count];
		double sum = 0, max = -1;

		for (int i = 1; i < count; i++) {
			double tempx = points->x[i] - points->x[i - 1];
			double tempy = points->y[i] - points->y[i - 1];
			side[i - 1] = sqrt(tempx * tempx + tempy * tempy);
			if (max < side[i - 1]) {
				max = side[i - 1];
			}
			sum += side[i - 1];
		}
		double tempx = points->x[0] - points->x[count - 1];
		double tempy = points->y[0] - points->y[count - 1];
		side[count - 1] = sqrt(tempx * tempx + tempy * tempy);
		sum += side[count - 1];
		if (max < side[count - 1]) {
			max = side[count - 1];
		}
		if (sum - max <= max) {
			return false;
		}
		return true;
	}
protected:
	Points* points;
	double* side;
};

