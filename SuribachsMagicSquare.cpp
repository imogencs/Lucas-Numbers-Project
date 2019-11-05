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

void remove(int* arr, int *dest, int target, int size) {
	int i = 0;
	for (int j = 0; j < size; j++) {
		if (j > target) {
			dest[i] = arr[j];
			i++;
		}
	}
}


void sumCombos(int currentSum, int *arr, int arrSize, int numsInCombo, int *combo) {
	for (int i = 0; i < arrSize; i++) {
		int *dest = new int[arrSize-1];
		remove(arr, dest, i, arrSize);

		if (arr[i] < (33 - currentSum)) {
			combo[numsInCombo - 1] = arr[i];
			sumCombos(currentSum+arr[i], dest, arrSize-1, numsInCombo+1, combo);
		}
		else if (arr[i] == (33 - currentSum)) {
			combo[numsInCombo - 1] = arr[i];
			currentSum += arr[i];
			sizes[numsInCombo]++;

			if (numsInCombo == 4) {
				for (int j = 0; j < numsInCombo; j++) {
								cout << combo[j] << " ";
							}
							cout << "\tcurrent: " << currentSum;
				cout << "\t " << sizes[numsInCombo] << endl;
			}
		}
	}
}

int main () {
	for (int i = 0; i < 16; i++) {
		sizes[i] = 0;
	}

	int *combo = new int[16];
	sumCombos(0, MAGIC_SQUARE, 16, 1, combo);

	for (int i = 1; i < 16; i++) {
		cout << "Sums of 33 for " << i << " elements:\t" << sizes[i] << endl;
	}

	return 1;
}

