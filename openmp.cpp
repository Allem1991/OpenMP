#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAGIC 35

int main() {

	/*printf("1 task\n");

#pragma omp parallel num_threads(8)
	printf("Hello World from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());

	printf("\n");
	printf("2 task\n");

	omp_set_dynamic(0);
	omp_set_num_threads(8);

#pragma omp parallel if(omp_get_max_threads() > 1)
	{
		printf("Hello World from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
	}

	omp_set_num_threads(1);

#pragma omp parallel if(omp_get_max_threads() > 1)
	{
		printf("Hello World from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
	}
	

	printf("\n");
	printf("3 task\n");

	int a = 0, b = 0;

	printf("#before a:%d b:%d\n", a, b);

#pragma omp parallel num_threads(2) private(a) firstprivate(b)
	{
		a = 0;
		a += omp_get_thread_num();
		b += omp_get_thread_num();
		printf("#during%d a:%d b:%d\n", omp_get_thread_num(), a, b);
	}
	printf("#after a:%d b:%d\n\n\n", a, b);

#pragma omp parallel num_threads(4) shared(a) private(b)
	{
		b = 0;
#pragma omp atomic
		a -= omp_get_thread_num();
		b -= omp_get_thread_num();
		printf("#during%d a:%d b:%d\n", omp_get_thread_num(), a, b);
	}
	printf("#after a:%d b:%d\n\n\n", a, b);
	

	printf("\n");
	printf("4 task\n");

	int a[10] = { 5, 2, 3, 4, 1, 6, 5, 4, 3, 2 };
	int b[10] = { 5, 2, 3, 4, 12, 1, 5, 4, 2, 3 };

	int min = 10;
	int max = 0;

#pragma omp parallel sections num_threads(2)
	{
#pragma omp section
		{
			for (int i = 0; i < 10; i++) {
				if (min > a[i]) { min = a[i]; }
			}
		}

#pragma omp section
		{
			for (int i = 0; i < 10; i++) {
				if (max < b[i]) { max = b[i]; }
			}
		}
	}

	printf("max is %d, min is %d\n", max, min);*/

	printf("\n");
	printf("5 task\n");

	int d[6][8];
	srand(time(NULL));

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			d[i][j] = rand() % MAGIC;
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");

#pragma omp parallel sections
	{
#pragma omp section
		{
			int elements = 0;
			int sum = 0;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					sum += d[i][j];
					elements++;
				}
			}
			printf("mid is %.2f from %d thread\n", sum * 1.0 / elements, omp_get_thread_num());
		}

#pragma omp section
		{
			int min = MAGIC + 1;
			int max = -1;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					if (min > d[i][j]) {
						min = d[i][j];
					}
					if (max < d[i][j]) {
						max = d[i][j];
					}
				}
			}
			printf("max is %d and min is %d from %d thread\n", max, min, omp_get_thread_num());
		}

#pragma omp section
		{
			int sum = 0;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					if (d[i][j] % 3 == 0) {
						sum ++;
					}
				}
			}
			printf("sum of deviders is %d from %d thread\n", sum, omp_get_thread_num());
		}
	}
}

