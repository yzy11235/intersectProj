#include "def.h"
#include "Graph.h"


Radio::Radio() {}

Radio::Radio(int numNew, int denNew) {
	num = numNew;
	den = denNew;
	contract();
}

Radio Radio::add(Radio r) {
	int denNew = getDen() * r.getDen();
	int numNew = getNum() * r.getDen()
		+ r.getNum() * getDen();
	return Radio(numNew, denNew);
}

Radio Radio::sub(Radio r) {
	int denNew = getDen() * r.getDen();
	int numNew = getNum() * r.getDen()
		- r.getNum() * getDen();
	return Radio(numNew, denNew);
}

Radio Radio::mul(Radio r) {
	return Radio(getNum() * r.getNum(), getDen() * r.getDen());
}

Radio Radio::div(Radio r) {
	return Radio(getNum() * r.getDen(), getDen() * r.getNum());
}

int Radio::getNum() {
	return num;
}

int Radio::getDen() {
	return den;
}

bool Radio::equal(Radio r) {
	return absInt(num) == absInt(r.getNum())
		&& absInt(den) == absInt(r.getDen())
		&& isRadioPos(num, den) == isRadioPos(r.getNum(), r.getDen());
}

int Radio::gcd() {
	// x >= y >= z

	int x = max(absInt(num), absInt(den));
	int y = min(absInt(num), absInt(den));
	int z = y;
	while (x % y != 0) {
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}

void Radio::contract() {
	int z = gcd();
	num = num / z;
	den = den / z;
}




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



