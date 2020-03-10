#pragma once

#include "stdafx.h"
#include <set>
#include <iostream>

using namespace std;

class Radio
{
public:
	Radio();
	Radio(int numNew, int denNew);
	// radio = num / den;

	int getNum();
	int getDen();
	Radio add(Radio r);
	Radio sub(Radio r);
	Radio mul(Radio r);
	Radio div(Radio r);
	bool equal(Radio r);

private:
	int num;
	int den;

	int gcd();
	void contract();
};


class Point
{
public:
	Point(Radio xNew, Radio yNew);
	bool equal(Point p);
	Radio getX();
	Radio getY();

private:
	Radio x;
	Radio y;
};


class Line
{
public:
	Line(int x1, int y1, int x2, int y2);
	Radio getA();
	Radio getB();
	Radio getC();
	Radio getslope();
	bool isParallel(Line l);
	bool containsPoint(Point p);
	Point getIntersect(Line l);	
	bool equal(Line l);
	bool operator<(const Line& l) const {
		return hash < l.hash;
	}

private:
	// line: Ax + By + C = 0;
	Radio A;
	Radio B;
	Radio C;
	Radio slope;
	int hash;

};
