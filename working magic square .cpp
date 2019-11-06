//============================================================================
// Name        : SuribachsMagicSquare.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     :
// Copyright   : Your copyright notice
// Description : Suribachs Magic Square in C++
//============================================================================

#include <iostream>
#include "SuribachsMagicSquare.h"
using namespace std;

int *sizes = new int[16];

void sumCombos(int currentSum, int numsInCombo, int *combo, int *cindex, int startIndex) {
	for (int i = startIndex; i < SQUARE_SIZE; i++) {
		if (MAGIC_SQUARE[i] < (MAGIC_CONSTANT - currentSum)) {
			combo[numsInCombo - 1] = MAGIC_SQUARE[i];
			sumCombos(currentSum+MAGIC_SQUARE[i], numsInCombo+1, combo, cindex,i+1);
		}
		else if (MAGIC_SQUARE[i] == (MAGIC_CONSTANT - currentSum)) {
			combo[numsInCombo - 1] = MAGIC_SQUARE[i];
			sizes[numsInCombo]++;
		}
	}
}

int main () {
	for (int i = 0; i < 16; i++) {
		sizes[i] = 0;
	}

	int *combo = new int[16];
	int *cindex = new int[16];
	sumCombos(0, 1, combo, cindex, 0);

	for (int i = 1; i < SQUARE_SIZE; i++) {
		cout << "Sums of " << MAGIC_CONSTANT << " for " << i << " elements:\t" << sizes[i] << endl;
	}

	return 1;
}
