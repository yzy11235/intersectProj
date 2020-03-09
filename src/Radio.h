#pragma once
#ifndef _RADIO_H
#define _RADIO_H

#include "def.h"


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
	bool isLess(Radio r);

private:
	int num;
	int den;

	int gcd();
	void contract();
};




#endif // !_RADIO_H

