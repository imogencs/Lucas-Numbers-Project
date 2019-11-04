//============================================================================
// Name        : hw2.cpp
// Author      : Imogen&Jyalu
// Version     :
// Copyright   : Your copyright notice
// Description : Lucas Number Calculator C++
//============================================================================

#include <iostream>
#include <time.h>
using namespace std;


void LucasPrint (int n, int val) {
	cout << "L(" << n << ") = " << val << endl;
}


void LucasNumbers(int targetN, int currentN, int nMinusOne, int nMinusTwo) {
	int thisNum = nMinusOne + nMinusTwo;
	LucasPrint(currentN, thisNum);
	if (targetN > currentN) {
		LucasNumbers(targetN, currentN+1, thisNum, nMinusOne);
	}
}


int main(int argc, char** argv) {
	int n = 0;
	if (argc > 1) {
		n = atoi(argv[1]);
	}

	if (n >= 0) {
		LucasPrint(0, 2);
	}
	if (n >= 1) {
		LucasPrint(1, 1);
	}
	if (n > 1) {
		LucasNumbers(n, 2, 1, 2);
	}
	return 0;
}
