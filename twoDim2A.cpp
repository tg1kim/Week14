#include <stdio.h>

#define ROWS 3
#define COLS 5

#pragma warning(disable: 4996 4326 6031)

void main()
{
	int a[ROWS][COLS] = {
		{ 87, 98, 80, 76, 3 },
		{ 99, 89, 90, 90, 0 },
		{ 65, 68, 50, 49, 0 }
	};
	float weight[COLS] = { 0.3F, 0.4F, 0.2F, 0.1F };
	for (int i = 0; i < ROWS; i++) {
		float finalScores = 0;
		for (int j = 0; j < COLS; j++)
			finalScores += a[i][j] * weight[j]; 
		finalScores -= a[i][4];
		printf("학생 #%d의 최종 성적 = %.2f\n", i + 1, finalScores);
	}
}