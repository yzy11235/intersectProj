#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include "Radio.h"
#include <set>
#include <fstream>
#include <List>
#include <Vector>

using namespace std;

vector<Line> lineList;
list<pair<Point, set<Line>>> interList;

int main(int argc, char* argv[]) {
	ifstream input;
	ofstream output;
	int i; /*
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0)
			input = ifstream(argv[i + 1]);
		else if (strcmp(argv[i], "-o") == 0)
			output = ofstream(argv[i + 1]);
	}*/

	input.open("input.txt", ifstream::in);
	output.open("output.txt", ifstream::out);

	int n;
	int x1, y1, x2, y2;
	char c;
	input >> n;
	for (i = 0; i < n; i++) {
		input >> c;
		if (c == 'L') {
			input >> x1 >> y1 >> x2 >> y2;
			Line l(x1, y1, x2, y2);
			list<pair<Point, set<Line>>>::iterator it = interList.begin();
			set<Line> delLineSet;
			while (it != interList.end()) {
				Point p = (Point) it->first;
				if (l.containsPoint(p)) {
					delLineSet.insert(it->second.begin(), it->second.end());
					((set<Line>)it->second).insert(l);
			    }
				it++;
			}
			
			vector<Line>::iterator iter = lineList.begin();
			while (iter != lineList.end()) {
				Line lit = (Line)* iter;
				if (lit.isParallel(l)	// parallel
					|| delLineSet.find(lit) != delLineSet.end()) {	// have intersected
					continue;
				} 
				Point pInter = l.getIntersect(lit);
				set<Line> interLines;
				interLines.insert(l);
				interLines.insert(lit);
				interList.push_back(pair<Point, set<Line>>(pInter, interLines));
				iter++;
			}
			lineList.push_back(l);
		}
		else if (c == 'C') {

		}
		else {
			cout << "ERROR INPUT!" << endl;
		}

		output << interList.size();
		cout << interList.size() << endl;
		return 0;

	}
}