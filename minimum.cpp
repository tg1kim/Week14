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

	배열 prices 정의
	난수 씨앗 설정
	RandomArray
	PrintArray
	minimum에 FindMinimum을 호출하여 저장
	putchar('\n');
	"최소값은 %d입니다.\n"
}

void RandomArray(int a[], int n)
{
	for (int i)
		a[i]에 1~100 난수 저장
}

void PrintArray(int a[], int n)
{
	printf("---------------------------------------\n");
	printf("1   2   3   4   5   6   7   8   9   10\n");
	printf("---------------------------------------\n");
	for (int i)
		"%-4d"
	putchar('\n');
}

int FindMinimum(int a[], int n)
{
	int minimum = a[0];
	for (int i)
		if (minimum ~ a[i])
			minimum = a[i];
	return minimum;
}