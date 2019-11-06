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

//void remove(int* arr, int *dest, int target, int size) {
//	int i = 0;
//	for (int j = 0; j < size; j++) {
//		if (j != target) {
//			dest[i] = arr[j];
//			i++;
//		}
//	}
//}


void sumCombos(int currentSum, int numsInCombo, int *combo, int *cindex, int startIndex) {
	for (int i = startIndex; i < SQUARE_SIZE; i++) {

		if (MAGIC_SQUARE[i] < (MAGIC_CONSTANT - currentSum)) {
			combo[numsInCombo - 1] = MAGIC_SQUARE[i];
			cindex[numsInCombo - 1] = i;
			if (i < SQUARE_SIZE - 1)
				sumCombos(currentSum+MAGIC_SQUARE[i], numsInCombo+1, combo, cindex,i+1);
		}
		else if (MAGIC_SQUARE[i] == (MAGIC_CONSTANT - currentSum)) {
			combo[numsInCombo - 1] = MAGIC_SQUARE[i];
			cindex[numsInCombo - 1] = i;
			currentSum += MAGIC_SQUARE[i];
			sizes[numsInCombo]++;

			if (numsInCombo == 3) {
				for (int j = 0; j < numsInCombo; j++) {
					cout << combo[j] << "(" << cindex[j] << ") ";
				}
			cout << "\t" << sizes[numsInCombo];
			cout << endl;
			}
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

	for (int i = 1; i < 7; i++) {
		cout << "Sums of 33 for " << i << " elements:\t" << sizes[i] << endl;
	}
	cout << "Sums of 33 for 8 elements:	0" << endl;

	return 1;
}

