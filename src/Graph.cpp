#include "Graph.h"
#include "Radio.h"

Point::Point(Radio xNew, Radio yNew) {
	x = xNew;
	y = yNew;
}

bool Point::equal(Point p) {
	return x.equal(p.getX()) && y.equal(p.getY());
}

Radio Point::getX() {
	return x;
}

Radio Point::getY() {
	return y;
}

Line::Line(int x1, int y1, int x2, int y2) {
	A = Radio(y2 - y1, 1);
	B = Radio(x1 - x2, 1);
	C = Radio(x2 * y1 - x1 * y2, 1);
	slope = Radio(y1 - y2, x1 - x2);
	hash = 31 * x1 + 15 * y1 + 7 * x2 + 3 * y2;
}

Radio Line::getslope() {
	return slope;
}

Radio Line::getA() {
	return A;
}

Radio Line::getB() {
	return B;
}

Radio Line::getC() {
	return C;
}

bool Line::isParallel(Line l) {
	return slope.equal(l.getslope());
}

bool Line::equal(Line l) {
	return A.equal(l.getA()) && B.equal(l.getB()) && C.equal(l.getC());
}

Point Line::getIntersect(Line l) {
	Radio a2 = l.getA();
	Radio b2 = l.getB();
	Radio c2 = l.getC();
	Radio x = B.mul(c2).sub(C.mul(b2))
		.div(A.mul(b2).sub(B.mul(a2)));
	Radio y = C.mul(a2).sub(A.mul(c2))
		.div(A.mul(b2).sub(B.mul(a2)));
	Point p(x, y);
	return p;
}

bool Line::containsPoint(Point p) {
	Radio zero(0, 1);
	Radio res = A.mul(p.getX()).add(B.mul(p.getY())).add(C);
	return res.equal(zero);
}



