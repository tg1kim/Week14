#include <stdio.h>

#define ROWS 3
#define COLS 3

#pragma warning(disable: 4996 4326 6031)

void main()
{
	배열 A에 {
		{ 2,3,0 },
		{ 8,9,1 },
		{ 7,0,5 } }로 초기화
	배열 B에 {
		{ 1,0,0 },
		{ 1,0,0 },
		{ 1,0,0 } }로 초기화
	배열 C

	// 행렬을 출력한다.
	A 행렬 PrintMatrix
	putchar('\n');
	B 행렬 PrintMatrix
	putchar('\n');
	// 두개의 행렬을 더한다.
	행렬 A + 행렬 B --> 행렬 C
	// 행렬을 출력한다.
	C 행렬 PrintMatrix
}

void AddMatrix(int X[ROWS][COLS], int Y[ROWS][COLS], int Z[ROWS][COLS])
{
	for (int r)
		for (int c)
			Z <-- X + Y
}

void PrintMatrix(int X[ROWS][COLS])
{
	for (int r) {
		for (int c)
			"%d "
		putchar('\n');
	}
}