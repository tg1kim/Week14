#include <stdio.h>

#define SIZE 10

#pragma warning(disable: 4996 4326 6031)

void main()
{
    배열 list에 { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 }를 초기화
    PrintArray
    for (int i)
        nNdx에 FindLeastIndex를 호출하여 저장
	Swap을 호출하여 [i]와 [nNdx]를 바꾼다
    PrintArray
}

int FindLeastIndex(int a[], int nFrom, int nTo)
{
    minNdx
    for (int i)
        if (a[minNdx] ~ a[i])
            minNdx = i;
    return minNdx;
}

void Swap(int a[], int x, int y)
{
    a[x]와 a[y]를 바꾼다
}

void PrintArray(int a[], int n)
{
    for (int i)
        "%d "
    putchar('\n');
}