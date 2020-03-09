#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H

#include "def.h"
#include "Radio.h"
#include <set>

using namespace std;

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
	int hash;

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

};



#endif // !_GRAPH_H
