//============================================================================
// Name        : SuribachsMagicSquare.h
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     : 11/8/19
// Copyright   : ©2019 IMOLU
// Description : Suribachs Magic Square in C++
//============================================================================

#ifndef SURIBACHSMAGICSQUARE_H_
#define SURIBACHSMAGICSQUARE_H_


int SQUARE_SIZE = 16;
int MAGIC_CONSTANT = 33;
int MAGIC_SQUARE[16] = {
		1, 14, 14, 4,
		11, 7, 6, 9,
		8, 10, 10, 5,
		13, 2, 3, 15
};

void sumCombos(int currentSum, int numsInCombo, int *combo, int startIndex, int targetSum);
void combosForEachSum();


#endif /* SURIBACHSMAGICSQUARE_H_ */
