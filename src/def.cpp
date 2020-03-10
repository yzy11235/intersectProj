#include "def.h"

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int absInt(int a) {
	return (a < 0) ? -a : a;
}

bool isRadioPos(int a, int b) {
	return (a > 0 && b > 0) || (a < 0 && b < 0);
}