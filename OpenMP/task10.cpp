#include <iostream>

int main() {

	int count = 0;
	int* a = new int[30];

	for (int i = 0; i < 30; i++) {
		a[i] = rand();
	}

#pragma omp parallel for num_threads(4)
	for (int i = 0; i < 30; i++) {
		if (a[i] % 9 == 0) {
#pragma omp atomic
			count++;
		}
	}

	printf("Number of multiples of 9 - %d", count);
}