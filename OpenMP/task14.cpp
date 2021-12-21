#include <iostream>
#include <stdio.h>
#include <omp.h>

int main() {

	int a = 210;
	int sum = 0;

#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < a; i++) {
		sum += i * 2 + 1;
	}

	printf("%d", sum);

	return 0;
}