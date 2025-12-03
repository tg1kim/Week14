// Á¤¿­

#include <stdio.h>

#define SIZE 10

#pragma warning(disable: 4996 4326 6031)

void main()
{
    void PrintArray(int a[], int n);
    int FindLeastIndex(int a[], int nFrom, int nTo);
    void Swap(int a[], int x, int y);

    int list[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };
    PrintArray(list, SIZE);
    for (int i = 0; i < SIZE - 1; i++)
        Swap(list, i, FindLeastIndex(list, i, SIZE - 1));
    PrintArray(list, SIZE);
}

int FindLeastIndex(int a[], int nFrom, int nTo)
{
    int minNdx = nFrom;
    for (int i = nFrom + 1; i <= nTo; i++)
        if (a[minNdx] > a[i])
            minNdx = i;
    return minNdx;
}

void Swap(int a[], int x, int y)
{
    int tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}