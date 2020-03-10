#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include <set>
#include <fstream>
#include <List>
#include <Vector>

using namespace std;

vector<Line> lineList;
set<Point> interSet;

int main(int argc, char* argv[]) {
	ifstream input;
	ofstream output;
	int i; 
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0)
			input = ifstream(argv[i + 1]);
		else if (strcmp(argv[i], "-o") == 0)
			output = ofstream(argv[i + 1]);
	} 
	
	//input.open("input1.txt", ifstream::in);
	//output.open("output.txt", ifstream::out);
	
	int n;
	int x1, y1, x2, y2;
	char c;
	input >> n;
	for (i = 0; i < n; i++) {
		input >> c;
		if (c == 'L') {
			input >> x1 >> y1 >> x2 >> y2;
			Line l(x1, y1, x2, y2);
			
			for (auto iter = lineList.begin(); iter != lineList.end(); iter++) {
				Line lit = (Line)* iter;
				if (lit.isParallel(l)) {	// have intersected
					continue;
				}
				Point pInter = l.getIntersect(lit);
				interSet.insert(pInter);
			}
			lineList.push_back(l);
		}
		else if (c == 'C') {

		}
		else {
			cout << "ERROR INPUT!" << endl;
		}
	}
	output << interSet.size();
	//cout << interSet.size() << endl;
	return 0;
}