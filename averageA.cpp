#include <stdio.h>

#define STUDENTS 5

#pragma warning(disable: 4996 4326 6031)

void main()
{
	int scores[STUDENTS] = { 1, 2, 3, 4, 5 };
	float getAverage(int scores[], int size);		// ①
	float avg = getAverage(scores, STUDENTS);
	printf("평균은 %.1f입니다.\n", avg);
}

// 배열에 들어 있는 값들의 평균을 계산하는 함수
float getAverage(int scores[], int size)			// ②
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += scores[i];
	return sum / (float)size;
}
