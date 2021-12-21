#include <stdio.h>
#include <omp.h>

int main() {

	int a[30] = { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 };
	int sum = 0;

#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < 30; i++) {
		if (a[i] == 0) {
			continue;
		}

		int b = 1;

#pragma omp parallel for
		for (int j = 0; j < i; j++) {
			b *= 2;
		}

		sum += b;
	}

	printf("%d", sum);
}