#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <math.h>
using namespace std;

int main() {

	int a, b;
	cout << "Left interval: >";
	cin >> a;
	cout << "Right interval: >";
	cin >> b;

#pragma omp parallel for
	for (int i = a; i <= b; i++) {
		bool multiple = false;

		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				multiple = true;
				break;
			}
		}

		if (!multiple) {
			printf("%d\n", i);
		}

	}

}