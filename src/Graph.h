#pragma once

#include "stdafx.h"
#include <set>
#include <iostream>
#include <cmath>

#define EQS (1e-6)
#define EQFLOAT(a,b) (fabs((a) - (b)) < EQS)

using namespace std;


class Point
{
public:
	int hash;

	Point(float xNew, float yNew);
	bool equal(Point p);
	float getX();
	float getY();
	bool operator<(const Point& p) const {
		return hash < p.hash;
	}

private:
	float x;
	float y;
};


class Line
{
public:
	int hash;

	Line(int x1, int y1, int x2, int y2);
	float getA();
	float getB();
	float getC();
	float getslope();
	bool isParallel(Line l);
	bool containsPoint(Point p);
	Point getIntersect(Line l);	
	bool equal(Line l);
	bool operator<(const Line& l) const {
		return hash < l.hash;
	}

private:
	// line: Ax + By + C = 0;
	float A;
    float B;
	float C;
	float slope;

};
