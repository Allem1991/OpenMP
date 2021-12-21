#include <iostream>
#include <omp.h>

int main() {
	
	int a[12];
	int b[12];
	int c[12];
	
#pragma omp parallel num_threads(3)
	{
		int n = omp_get_thread_num();
		int all = omp_get_num_threads();
		printf("Number of threads: %d, Thread: %d\n", all, n);
		
#pragma omp for schedule(static,4)

		for (int i = 0; i < 12; i++) {
			a[i] = rand();
			srand(a[i] + omp_get_thread_num());
			b[i] = rand();
			srand(a[i] + b[i]);
		}
		
#pragma omp single
		{
			printf("Array a: ");
			for (int i = 0; i < 12; i++)
			{
				printf("%d, ", a[i]);
			}
			printf("\nArray b: ");
			for (int i = 0; i < 12; i++)
			{
				printf("%d, ", b[i]);
			}
			printf("\n");
		}

	}
	
#pragma omp parallel num_threads(4)
	{
		int n = omp_get_thread_num();
		int all = omp_get_num_threads();
		printf("Number of threads: %d, Thread: %d\n", all, n);
		
#pragma omp for schedule(dynamic,3)

		for (int i = 0; i < 12; i++) {
			c[i] = a[i] + b[i];
		}
		
#pragma omp single 

		{
			printf("Array c: ");
			for (int i = 0; i < 12; i++) {
				printf("%d, ", c[i]);
			}
		}
	}
}