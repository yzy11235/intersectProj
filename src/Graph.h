#pragma once

#include "stdafx.h"
#include <set>
#include <iostream>
#include <cmath>

#define EQS (1e-8)
#define EQFLOAT(a,b) (fabs((a) - (b)) < EQS)

using namespace std;


class Point
{
public:
	float x;
	float y;

	Point(float xNew, float yNew);
	bool equal(Point p);
	float getX();
	float getY();
	bool operator<(const Point& p) const {
		if (!EQFLOAT(x, p.x))
			return x < p.x;
		else
			return y < p.y;
	}
	bool operator==(const Point& p) const {
		return EQFLOAT(x, p.x) && EQFLOAT(y, p.y);
	}

private:

};


class Line
{
public:

	Line(int x1, int y1, int x2, int y2);
	float getA();
	float getB();
	float getC();
	float getslope();
	bool isParallel(Line l);
	bool containsPoint(Point p);
	Point getIntersect(Line l);	
	bool equal(Line l);

private:
	// line: Ax + By + C = 0;
	float A;
    float B;
	float C;
	float slope;

};
