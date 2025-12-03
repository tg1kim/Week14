#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

#pragma warning(disable: 4996 4326 6031)

void main()
{
	int freq[SIZE] = { 0 };				// 주사위의 면의 빈도를 0으로 한다.
	for (int i = 0; i < 10000; i++)		// 주사위를 10000번 던진다.
		freq[rand() % 6]++;				// 해당면의 빈도를 하나 증가한다.
	printf("====================\n");
	printf(" 면     빈도\n");
	printf("====================\n");

	for (int i = 0; i < SIZE; i++)
		printf("%3d     %3d\n", i, freq[i]);
}
