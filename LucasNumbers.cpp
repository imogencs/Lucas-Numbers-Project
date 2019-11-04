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


void LucasPrint (int n, long long val, clock_t time, float pTime) {
	float tTime = ((float) time) / CLOCKS_PER_SEC;

	cout << "L(" << n << ") = " << val << "\t\t in " << tTime;
	cout << "\tseconds.";
	cout << "\tprevious time: " << pTime;
	cout << "\t\tRatio: " << (tTime / pTime) << endl;
}


clock_t nextLucasNumber(int targetN, int currentN, long long nMinusOne, long long nMinusTwo,
		clock_t currentTime, clock_t totalTime) {

	long long thisNum = nMinusOne + nMinusTwo;
	clock_t previousTime = totalTime;

	currentTime = clock() - currentTime;
	totalTime += currentTime;
	LucasPrint(currentN, thisNum, totalTime, ((float) previousTime) / CLOCKS_PER_SEC);
	if (targetN > currentN) {
		totalTime = nextLucasNumber(targetN, currentN+1, thisNum, nMinusOne,
				currentTime, totalTime);
	}
	return totalTime;
}

clock_t LucasNumbers(int n){
	clock_t t = clock();
	clock_t totalTime = t;
	if (n >= 0) {
		totalTime = clock() - t;
		LucasPrint(0, 2, totalTime, t);
	}
	if (n >= 1) {
		totalTime = clock() - t;
		LucasPrint(1, 1, totalTime, t);
	}
	if (n > 1) {
		totalTime = clock() - t;
		totalTime = nextLucasNumber(n, 2, 1, 2, t, totalTime);
	}
	return totalTime;
}


int main(int argc, char** argv) {
	clock_t t0 = clock();
	int n = 0;
	if (argc > 1) {
		n = atoi(argv[1]);
	}

	// part 2 - Lucas nums up to n
	clock_t totalTime = LucasNumbers(n);
	t0 = clock() - t0;
	cout << "It took " << ((float)totalTime)/CLOCKS_PER_SEC << " seconds to compute the first ";
			cout << n << " Lucas Numbers. " << endl;
//
//
//	// part 3 - up to n=30
//	for (int i = 0; i < 30; i++) {
//		clock_t ti = clock();
//		LucasNumbers(i);
//		ti = clock() - ti;
//		cout << "It took " << ((float)ti)/CLOCKS_PER_SEC << " seconds to compute the first " << n << " Lucas Numbers. " << endl;
//
//	}

	return 0;
}
