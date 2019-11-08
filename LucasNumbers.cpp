//============================================================================
// Name        : LucasNumbers.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     : 11/8/19
// Copyright   : ©2019 IMOLU
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

	long long* answers = new long long[n];
	float* times = new float[n];
	for (int i = 0; i <= n; i++) {
		times[i] = -1000;
	}

	clock_t time = clock();
	LucasNumbers(n, answers, times, t0);
	cout << "TOTAL: " << (((float)clock()) - ((float)time))/CLOCKS_PER_SEC << endl;

	return 0;
}

/**
 * Finds each Lucas Number from 0 to n recursively and prints out the value of the Lucas
 * Number, the time it took to calculate it, and the ratio Time(L(n+1))/Time(L(n)).
 * @param n The given n specified by the argument in the command line
 * @param answers An array that stores all the Lucas Numbers from 0 to n
 * @param times An array that stores the times it took to calculate Lucas Numbers 0 to n
 * @param startTime The starting time
 * @return The nth Lucas Number
 */
long long LucasNumbers(int n, long long* answers, float* times, clock_t startTime) {
	long long answer = 0;
	startTime = clock();
	if (n == 0) {
		answer = 2;
	}
	else if (n == 1) {
		answer = 1;
	}
	else {
		answer = (LucasNumbers(n - 2, answers, times, startTime)) +
				(LucasNumbers(n - 1, answers, times, startTime));
	}
	answers[n] = answer;
	if (times[n] == -1000) {
		LucasPrint(n, answers, times, startTime);
	}
	return answer;
}

/**
 * Prints out the Lucas Number corresponding to the given n.
 * @param n The given n specified by the argument in the command line
 * @param val The nth Lucas Number
 * @param totalTime The time it took to calculate the nth Lucas Number
 * @param prevTime The time  it took to calculate the (n-1)th Lucas Number
 */
void LucasPrint(int n, long long* answers, float* times, clock_t startTime) {
	times[n] = (((float)clock()) - ((float)startTime)) / CLOCKS_PER_SEC;
	cout << "L(" << n << ") = " << answers[n];
	cout << "\t\tTime: " << times[n] << "\tsecs";
	cout << "\t\tRatio: " << ((float) times[n]) /((float) times[n - 1]) << endl;

}
