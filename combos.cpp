#include <iostream>
using namespace std;

int *sizes = new int[16];

void remove(int* arr, int *dest, int target, int size) {
	int i = 0;
	for (int j = 0; j < size; j++) {
		if (j != target) {
			dest[i] = arr[j];
			i++;
		}
	}
}
		

void sumCombos(int currentSum, int *arr, int arrSize, int n) {
	for (int i = 0; i < arrSize; i++) { 
		if (arr[i] < 33 - currentSum) {
			int *dest = new int[16];
			remove(arr, dest, i, arrSize);
			sumCombos(currentSum+arr[i], dest, arrSize-1, n+1);
		}
		else if (arr[i] == 33 - currentSum) {
			sizes[n]++;
		}
	}
}

int main () {
	for (int i = 0; i < 16; i++) {
		sizes[i] = 0;
	}

	int arr[16] = {1, 14, 14, 4, 
			11, 7, 6, 9, 
			8, 10, 10, 5, 
			13, 2, 3, 15};
	sumCombos(0, arr, 16, 1);

	for (int i = 1; i < 16; i++) {
		cout << "Sums of 33 for " << i << "elements:\t" << sizes[i] << endl;
	}
	
	return 1;
}


