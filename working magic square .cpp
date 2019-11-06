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

int MAX_TARGET_SUM = 33;
int **sizes = new int*[MAX_TARGET_SUM+1];

void sumCombos(int currentSum, int numsInCombo, int *combo, int startIndex, int targetSum) {
	for (int i = startIndex; i < SQUARE_SIZE; i++) {
		if (MAGIC_SQUARE[i] < (targetSum - currentSum)) {
			combo[numsInCombo - 1] = MAGIC_SQUARE[i];
			sumCombos(currentSum+MAGIC_SQUARE[i], numsInCombo+1, combo, i+1, targetSum);
		}
		else if (MAGIC_SQUARE[i] == (targetSum - currentSum)) {
			combo[numsInCombo - 1] = MAGIC_SQUARE[i];
			sizes[targetSum][numsInCombo]++;
		}
	}
}

void combosForEachSum() {
	int *combo = new int[SQUARE_SIZE];
	for (int i = 0; i <= MAX_TARGET_SUM; i++) {
		sumCombos(0, 1, combo, 0, i);
	}
}

int main () {
	for (int i = 0; i <= MAX_TARGET_SUM; i++) {
		sizes[i] = new int[SQUARE_SIZE];
		for (int j = 0; j < SQUARE_SIZE; j++) {
			sizes[i][j] = 0;
		}
	}


	int *combo = new int[SQUARE_SIZE];
	combosForEachSum();

	for (int targetSum = 0; targetSum <= MAX_TARGET_SUM; targetSum++) {
		for (int i = 1; i < SQUARE_SIZE; i++) {
			cout << "Sums of " << targetSum << " for " << i << " elements:\t";
			cout << sizes[targetSum][i] << endl;
		}
	}
	return 1;
}
