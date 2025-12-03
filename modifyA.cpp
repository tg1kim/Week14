#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

#define SIZE 7

void main()
{
	int list[SIZE] = { 1, 2, 3, 4, 5, 6, 7 } ;
	void ModifyArray(int a[], int n);
	void PrintArray(int a[], int n);
	PrintArray(list, SIZE);
	ModifyArray(list, SIZE);	// 배열은 원본이 전달된다.
	PrintArray(list, SIZE);
}

// a[]를 변경하면 원본이 변경된다. 
void ModifyArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		++a[i];
}

// 배열 원소들을 화면에 출력한다. 
void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%3d ", a[i]);
	putchar('\n');
}