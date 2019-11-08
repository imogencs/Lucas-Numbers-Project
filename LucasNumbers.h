//============================================================================
// Name        : LucasNumbers.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     : 11/8/19
// Copyright   : ©2019 IMOLU
// Description : Lucas Number Calculator C++
//============================================================================

#include <time.h>

#ifndef LUCASNUMBERS_H_
#define LUCASNUMBERS_H_

int main(int argc, char** argv);
long long LucasNumbers(int n, long long* answers, float* times, clock_t startTime);
void LucasPrint(int n, long long* answers, float* times, clock_t startTime);

#endif /* LUCASNUMBERS_H_ */
