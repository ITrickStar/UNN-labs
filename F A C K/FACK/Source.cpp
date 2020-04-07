#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

const int n = 10;

struct s
{
	int a;
	int* b;
};

int* func(int* arr)
{
	struct s max;
	max.a = *arr;
	max.b = arr;

	for (int i = 1; i < n; i++) {
		if (arr[i] > max.a) {
			max.a = arr[i];
			max.b = (arr + i);
		}

	}

	return max.b;
}

void main()
{
	srand(time(NULL));

	int sum = 0;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand()%10;
		sum += arr[i];
	}

	sum /= n;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	*func(arr) = sum;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	delete[] (arr);
	system("pause");
}