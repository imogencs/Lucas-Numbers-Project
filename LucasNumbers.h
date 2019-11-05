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
clock_t LucasNumbers(int n);
clock_t nextLucasNumber(int targetN, int currentN, long long nMinusOne, long long nMinusTwo,
		clock_t currentTime, clock_t thisTime, float prevTime);
void LucasPrint (int n, long long val, clock_t time, float pTime);

#endif /* LUCASNUMBERS_H_ */
