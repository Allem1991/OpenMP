#include <iostream>
#include <omp.h>
#include <chrono>
#include <ctime>   
using namespace std;

int main() {

	cout << "Height\n>";

	int rowCount;

	cin >> rowCount;

	cout << "Width\n>";

	int colCount;

	cin >> colCount;

	int** a = new int* [rowCount];

	for (int i = 0; i < rowCount; ++i)
		a[i] = new int[colCount];

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			cout << ">";
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	int length;

	cout << "Vector length\n>";

	cin >> length;

	int* vector = new int[length];
	int* summary = new int[length];

	for (int i = 0; i < length; i++) {
		cout << ">";
		cin >> vector[i];
		summary[i] = 0;
	}

	for (int i = 0; i < length; i++) {
		cout << vector[i] << " ";
	}

	cout << "\n";

	if (colCount != length) {
		return -1;
	}

	cout << "Non-parallel\n";

	auto start = std::chrono::system_clock::now();

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			summary[i] += a[i][j] * vector[j];
		}
	}

	auto end = std::chrono::system_clock::now();

	for (int i = 0; i < length; i++) {
		cout << summary[i] << " ";
	}

	cout << "\n";

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

#pragma warning(disable : 4996)
	std::cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";

	cout << "Parallel\n";

	int* summary1 = new int[length];

	for (int i = 0; i < length; i++) {
		summary1[i] = 0;
	}

	auto start1 = std::chrono::system_clock::now();

#pragma omp parallel for collapse(2)
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			summary1[i] += a[i][j] * vector[j];
		}
	}

	auto end1 = std::chrono::system_clock::now();
	for (int i = 0; i < length; i++) {
		cout << summary1[i] << " ";
	}
	cout << "\n";

	std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
	std::time_t end_time1 = std::chrono::system_clock::to_time_t(end1);

#pragma warning(disable : 4996)
	std::cout << "finished computation at " << std::ctime(&end_time1)
		<< "elapsed time: " << elapsed_seconds1.count() << "s\n";

}