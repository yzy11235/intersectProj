
#include "Radio.h"

Radio::Radio() {}

Radio::Radio(int numNew, int denNew){
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
	return num == r.getNum() && den == r.getDen();
}

int Radio::gcd() {
	// x >= y >= z
	int x = max(num, den);
	int y = min(num, den);
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



