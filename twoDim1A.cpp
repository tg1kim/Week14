#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5

#pragma warning(disable: 4996 4326 6031)

void main()
{
	int s[ROWS][COLS];					// 2차원 배열 선언
	srand((unsigned)time(NULL));		// 난수 생성기 초기화
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			s[i][j] = rand() % 100;		// i행, j열에 난수를 저장한다.
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			printf("%2d ", s[i][j]);
		putchar('\n');
	}
}