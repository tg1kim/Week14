#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
 
#pragma warning(disable: 4996 4326 6031)

void main()
{
	void PrintArray(int a[], int n);
	void RandomArray(int a[], int n);
	int SequentialSearch(int a[], int n, int key);

	int list[SIZE];
	srand((unsigned)time(NULL));
	RandomArray(list, SIZE);
	PrintArray(list, SIZE);
	putchar('\n');
	while (1) {
		printf("Å½»öÇÒ °ª ? ");
		int key;
		scanf("%d", &key);
		if (key < 0)
			break;
		int nNdx = SequentialSearch(list, SIZE, key);
		printf("Å½»ö »öÀÎ = %d\n", nNdx);
		putchar('\n');
	}
	printf("Å½»ö Á¾·á\n");
}

int SequentialSearch(int a[], int n, int key)
{
	for (int i = 0; i < n; i++)
		if (a[i] == key)
			return i;
	return -1;
}

void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%-2d ", i);
	putchar('\n');
	for (int i = 0; i < n; i++)
		printf("%-2d ", a[i]);
	putchar('\n');
}

void RandomArray(int a[], int n)
{
	a[0] = rand() % 100;
	for (int i = 1, nValue; i < n; i++) {
		do
			nValue = rand() % 100;
		while (SequentialSearch(a, i, nValue) >= 0);
		a[i] = nValue;
	}
}