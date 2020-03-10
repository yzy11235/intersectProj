#include "def.h"
#include "Graph.h"



Point::Point(float xNew, float yNew) {
	x = xNew;
	y = yNew;
	hash = (int)x << 3 + (int)y << 2;
}

bool Point::equal(Point p) {
	return EQFLOAT(x, p.getX()) && EQFLOAT(y, p.getY());
}

float Point::getX() {
	return x;
}

float Point::getY() {
	return y;
}



Line::Line(int x1, int y1, int x2, int y2) {
	A = (float) y2 - y1;
	B = (float) x1 - x2;
	C = (float) x2 * y1 - x1 * y2;
	slope = (float) (y1 - y2)/(x1 - x2);
	hash = 31 * x1 + 15 * y1 + 7 * x2 + 3 * y2;
}

float Line::getslope() {
	return slope;
}

float Line::getA() {
	return A;
}

float Line::getB() {
	return B;
}

float Line::getC() {
	return C;
}

bool Line::isParallel(Line l) {
	return slope == l.getslope();
}

bool Line::equal(Line l) {
	return EQFLOAT(A, l.getA()) && EQFLOAT(B, getB()) && EQFLOAT(C, getC());
}

Point Line::getIntersect(Line l) {
	float a2 = l.getA();
	float b2 = l.getB();
	float c2 = l.getC();
	float x = (B * c2 - C * b2) / (A * b2 - B * a2);
	float y = (C * a2 - A * c2) / (A * b2 - B * a2);
	Point p(x, y);
	return p;
}

bool Line::containsPoint(Point p) {
	float res = A * p.getX() + B * p.getY() + C;
	return res == 0;
}



