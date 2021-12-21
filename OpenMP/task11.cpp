#include <iostream>

int main() {

	const int N = 100000;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		arr[i] = rand();
	}

	int max = NULL;

#pragma omp parallel num_threads(4)
#pragma omp for
	for (int i = 0; i < N; i++) {
#pragma omp critical
		if ((arr[i] > max && arr[i] % 7 == 0) || (arr[i] % 7 == 0 && max == NULL)) {
			max = arr[i];
		}

	}

	printf("Max of array is - %d", max);
}