//============================================================================
// Name        : LucasNumbers.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     :
// Copyright   : Your copyright notice
// Description : Lucas Number Calculator C++
//============================================================================

#include <time.h>

#ifndef LUCASNUMBERS_H_
#define LUCASNUMBERS_H_

int main(int argc, char** argv);
long long slowLucasNumbers(int n, long long* answers, float* times, clock_t startTime);
clock_t LucasNumbers(int n);
clock_t nextLucasNumber(int targetN, int currentN, long long nMinusOne, long long nMinusTwo,
		clock_t startTime, float prevTime);
void LucasPrint (int n, long long val, clock_t time, float pTime);

#endif /* LUCASNUMBERS_H_ */
