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

	배열 list
	난수 씨앗
	RandomArray
	PrintArray
	putchar('\n');
	while (1) {
		"탐색할 값 ? "
		key에 일고
		if (key < 0)
			break;
		nNdx에 SequentialSearch를 호출하여 저장
		"탐색 색인 = %d\n"
		putchar('\n');
	}
	printf("탐색 종료\n");
}

int SequentialSearch(int a[], int n, int key)
{
	for (int i)
		if (찾으면)
			return i;
	return -1;
}

void PrintArray(int a[], int n)
{
	for (int i)	// 색인
		"%-2d "
	putchar('\n');
	for (int i)	// 값
		"%-2d "
	putchar('\n');
}

void RandomArray(int a[], int n)
{
	a[0]에 난수의 100 나머지
	for (int i) {
		do
			nValue에 난수의 100 나머지
		while (중복);
		a[i] = nValue;
	}
}