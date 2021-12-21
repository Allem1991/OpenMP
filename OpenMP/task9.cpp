#include <iostream>

int main() {

	int** d = new int* [6];

	for (int i = 0; i < 6; i++) {
		d[i] = new int[8];
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++)
		{
			d[i][j] = rand();
		}
	}

	int max = d[0][0];
	int min = d[0][0];

#pragma omp parallel num_threads(4)
#pragma omp for collapse(2)
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
#pragma omp critical
			if (d[i][j] > max) {
				max = d[i][j];
			}
			if (d[i][j] < min) {
				min = d[i][j];
			}
		}
	}

	printf("Max of array is - %d, min is - %d", max, min);
}
