#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

#pragma warning(disable: 4996 4326 6031)

void main()
{
	void RandomArray(int a[], int n);
	void PrintArray(int a[], int n);
	int FindMinimum(int a[], int n);

	int prices[SIZE];
	srand((unsigned)time(NULL));
	RandomArray(prices, SIZE);
	PrintArray(prices, SIZE);
	int minimum = FindMinimum(prices, SIZE);
	putchar('\n');
	printf("최소값은 %d입니다.\n", minimum);
}

void RandomArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100 + 1;
}

void PrintArray(int a[], int n)
{
	printf("---------------------------------------\n");
	printf("1   2   3   4   5   6   7   8   9   10\n");
	printf("---------------------------------------\n");
	for (int i = 0; i < n; i++)
		printf("%-4d", a[i]);
	putchar('\n');
}

int FindMinimum(int a[], int n)
{
	int minimum = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] < minimum)
			minimum = a[i];
	return minimum;
}