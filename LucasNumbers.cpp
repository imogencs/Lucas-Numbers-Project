//============================================================================
// Name        : LucasNumbers.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     :
// Copyright   : Your copyright notice
// Description : Lucas Number Calculator C++
//============================================================================

#include <iostream>
#include <time.h>
#include "LucasNumbers.h"
using namespace std;


int main(int argc, char** argv) {
	clock_t t0 = clock();
	int n = 0;
	if (argc > 1) {
		n = atoi(argv[1]);
	}

	// part 2 - Lucas nums up to n
	clock_t totalTime = LucasNumbers(n);
	t0 = clock() - t0;
//	cout << "It took " << ((float)totalTime)/CLOCKS_PER_SEC << " seconds to compute the first ";
//			cout << n << " Lucas Numbers. " << endl;

	return 0;
}


clock_t LucasNumbers(int n){
	clock_t startTime = clock();
	clock_t thisTime = startTime;
	float prevTime = ((float) startTime)/CLOCKS_PER_SEC;

	if (n >= 0) {
		thisTime = clock() - startTime;
		LucasPrint(0, 2, thisTime, prevTime);
		prevTime = ((float) thisTime)/CLOCKS_PER_SEC;
	}
	if (n >= 1) {
		thisTime = clock() - startTime;
		LucasPrint(1, 1, thisTime, prevTime);
	}
	if (n > 1) {
		thisTime = nextLucasNumber(n, 2, 1, 2, startTime, thisTime, prevTime);
	}
	return thisTime;
}


clock_t nextLucasNumber(int targetN, int currentN, long long nMinusOne, long long nMinusTwo,
		clock_t startTime, clock_t thisTime, float prevTime) {

	long long thisNum = nMinusOne + nMinusTwo;
	prevTime = ((float) thisTime)/CLOCKS_PER_SEC;
	thisTime = clock() - startTime;
	LucasPrint(currentN, thisNum, thisTime, prevTime);

	if (targetN > currentN) {
		thisTime = nextLucasNumber(targetN, currentN+1, thisNum, nMinusOne,
				startTime, thisTime, prevTime);
	}
	return thisTime;
}


void LucasPrint (int n, long long val, clock_t time, float prevTime) {
	float tTime = ((float) time) / CLOCKS_PER_SEC;

	cout << "L(" << n << ") = " << val << "\t\t in " << tTime;
	cout << "\tseconds.";

	if (n >= 1) {
		cout << "\tprevious time: " << prevTime;
		cout << "\t\tRatio: " << (tTime / prevTime) << endl;
	}
	else {
		cout << endl;
	}

}
