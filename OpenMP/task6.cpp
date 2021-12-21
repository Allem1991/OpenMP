#include <iostream>
#include <omp.h>

int main() 
{
	int a[10] = { 1,5,3,4,1,3,221,31,4,-5 };
	int b[10] = { 40, 5, 2, -3, -2, 0, 229, 223, 45, 15 };


	float sum_a = 0;
	float sum_b = 0;
	
#pragma omp parallel for

	for (int i = 0; i < 10; i++) {
		sum_a += a[i];
		sum_b += b[i];
	}
	
	printf("(w/o reduction) Avg a[] is: %f, Avg b[] is %f\n", sum_a / 10, sum_b / 10);
	
	sum_a = 0;
	sum_b = 0;
	
#pragma omp parallel for reduction(+:sum_a)

	for (int i = 0; i < 10; i++) {
		sum_a += a[i];
	}
	
#pragma omp parallel for reduction(+:sum_b)

	for (int i = 0; i < 10; i++) {
		sum_b += b[i];
	}
	
	printf("(w/ reduction) Avg a[] is: %f, Avg b[] is %f\n", sum_a / 10, sum_b / 10);
}
