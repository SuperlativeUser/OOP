#pragma once
#include "Points.h"
Points::Points(const int n) {
	x = new double[n];
	y = new double[n];
}

Points::~Points() {
	delete[] x;
	delete[] y;
}