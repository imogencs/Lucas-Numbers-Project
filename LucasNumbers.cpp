//============================================================================
// Name        : LucasNumbers.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     : 11/5/19
// Copyright   : Your copyright notice
// Description : Lucas Number Calculator C++
//============================================================================

#include <iostream>
#include <time.h>
#include "LucasNumbers.h"
using namespace std;


int main(int argc, char** argv) {
//	float t0 = ((float) clock())/CLOCKS_PER_SEC;
	clock_t t0 = clock();

	int n = 0;
	if (argc > 1) {
		n = atoi(argv[1]);
	}

	long long* answers = new long long[n];
	float* times = new float[n];
	for (int i = 0; i <= n; i++) {
		times[i] = -1000;
	}

	clock_t time = clock();
	slowLucasNumbers(n, answers, times, t0);
	//	for (int i = 0; i <= n; i++) {
	//		cout << "L(" << i << ") = " << answers[i];
	//		cout << "\t\tTime: " << times[i] << "\tseconds";
	//		if (i > 0) {
	//			cout << "\t\tRatio: " << times[i]/times[i-1] << endl;
	//		}
	//		else {
	//			cout << endl;
	//		}
	//	}
	cout << "TOTAL: " << (((float)clock()) - ((float)time))/CLOCKS_PER_SEC << endl;
//	cout << "TOTAL: " << (((float) clock()) - ((float) time)) / CLOCKS_PER_SEC << endl;


	//	LucasNumbers(n);

	//
	//	// part 2 - Lucas nums up to n
	//	clock_t totalTime = LucasNumbers(n);
	//	t0 = clock() - t0;
	//	//	cout << "It took " << ((float)totalTime)/CLOCKS_PER_SEC << " seconds to compute the first ";
	//	//			cout << n << " Lucas Numbers. " << endl;

	return 0;
}

long long slowLucasNumbers(int n, long long* answers, float* times, clock_t startTime) {
	long long answer = 0;
//	startTime = clock();
	if (n == 0) {
		answer = 2;
	}
	else if (n == 1) {
		answer = 1;
	}
	else {
		answer = (slowLucasNumbers(n - 2, answers, times, startTime)) +
				(slowLucasNumbers(n - 1, answers, times, startTime));
	}
	answers[n] = answer;
	if (times[n] == -1000) {
		times[n] = (((float)clock()) - ((float)startTime)) / CLOCKS_PER_SEC;
		cout << "L(" << n << ") = " << answers[n];
		cout << "\t\tTime: " << times[n] << "\tsecs";
		if (n > 0) {
			cout << "\t\tRatio: " << ((float) times[n]) /((float) times[n - 1]) << endl;
		}
		else {
			cout << endl;
		}

	}
	return answer;
}

clock_t LucasNumbers(int n){
	clock_t startTime = clock();
	clock_t totalTime = startTime;
	float prevTime = ((float) startTime)/CLOCKS_PER_SEC;

	if (n >= 0) {
		//		thisTime = clock() - startTime;
		totalTime = clock() - startTime;
		LucasPrint(0, 2, totalTime, 0);
		prevTime = ((float) totalTime)/CLOCKS_PER_SEC;
	}
	if (n >= 1) {
		totalTime = clock() - startTime;
		LucasPrint(1, 1, totalTime, prevTime);
		prevTime = ((float) totalTime)/CLOCKS_PER_SEC;
	}
	if (n > 1) {
		totalTime = nextLucasNumber(n, 2, 1, 2, startTime, prevTime);
	}
	return totalTime;
}


clock_t nextLucasNumber(int targetN, int currentN, long long nMinusOne, long long nMinusTwo,
		clock_t startTime, float prevTime) {

	long long thisNum = nMinusOne + nMinusTwo;
	//	prevTime = ((float) totalTime)/CLOCKS_PER_SEC;
	//	thisTime = clock() - startTime;
	//	totalTime = clock();
	clock_t totalTime = clock() - startTime;

	LucasPrint(currentN, thisNum, totalTime, prevTime);
	prevTime = ((float) totalTime)/CLOCKS_PER_SEC;

	if (targetN > currentN) {
		totalTime = nextLucasNumber(targetN, currentN+1, thisNum, nMinusOne,
				startTime, prevTime);
	}
	return totalTime;
}


void LucasPrint (int n, long long val, clock_t totalTime, float prevTime) {
	float tTime = ((float) totalTime) / CLOCKS_PER_SEC;

	cout << "L(" << n << ") = " << val;
	cout << "\t\tTime: " << tTime << "\tseconds";

	if (n >= 1) {
		//		cout << "\tPrevious time: " << prevTime;
		cout << "\t\tRatio: " << (tTime / prevTime) << endl;
	}
	else {
		cout << endl;
	}

}
