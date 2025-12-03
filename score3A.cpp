#include <stdio.h>

#define STUDENTS 5

#pragma warning(disable: 4996 4326 6031)

void main()
{

	int scores[STUDENTS];
	int sum = 0;
	for (int i = 0; i < STUDENTS; i++) {
		printf("학생들의 성적을 입력하시오: ");	
		scanf("%d", &scores[i]);
	}
	for (int i = 0; i < STUDENTS; i++)
		sum += scores[i];
	float average = sum / float(STUDENTS);
	printf("성적 평균 = %.1f\n", average);
}