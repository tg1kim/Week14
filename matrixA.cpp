#include <stdio.h>

#define ROWS 3
#define COLS 3

#pragma warning(disable: 4996 4326 6031)

void main()
{
	void PrintMatrix(int X[ROWS][COLS]);
	void AddMatrix(int X[ROWS][COLS], int Y[ROWS][COLS], int Z[ROWS][COLS]);

	int A[ROWS][COLS] = {
		{ 2,3,0 },
		{ 8,9,1 },
		{ 7,0,5 } };
	int B[ROWS][COLS] = {
		{ 1,0,0 },
		{ 1,0,0 },
		{ 1,0,0 } };
	int C[ROWS][COLS];

	// 행렬을 출력한다.
	PrintMatrix(A);
	putchar('\n');
	PrintMatrix(B);
	putchar('\n');
	// 두개의 행렬을 더한다.
	AddMatrix(A, B, C);
	// 행렬을 출력한다.
	PrintMatrix(C);
}

void AddMatrix(int X[ROWS][COLS], int Y[ROWS][COLS], int Z[ROWS][COLS])
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			Z[r][c] = X[r][c] + Y[r][c];
}

void PrintMatrix(int X[ROWS][COLS])
{
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++)
			printf("%d ", X[r][c]);
		putchar('\n');
	}
}