#include "stdafx.h"
#include <cmath>
#include <iostream>
#include "point.cpp"

const float PI = 3.1415;

class Circle {

private:
	Point center;
	float r;

public:
	Circle() {

		center.set_x(0.0);
		center.set_y(0.0);
		r = 0.0;
	}

	float get_r() {
		return r;
	}
	void set_r(float var) {
		r = var;
	}

	float area() {

		return PI * r * r;
	}

	float distanceTo(Circle c2) {

		return center.distanceTo(c2.center) - r - c2.r;
	}

};
