#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

#define SIZE 16

void main()
{
	int key;
	int grade[SIZE] = { 2,6,11,13,18,20,22,27,29,30,34,38,41,42,45,47 };
	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &key);
	int binarySearch(int list[], int n, int key);
	printf("탐색 결과 = %d\n", binarySearch(grade, SIZE, key));
}

int binarySearch(int list[], int n, int key)
{
	int left = 0, rght = n -1;
	while (left <= rght) {					// 탐색 구간이 존재하면
   		int middle = (left + rght) / 2; 	// 중간 원소 결정
   		if (key == list[middle])			// 탐색 완료
			return middle;
		else if (key > list[middle])		// key는 중간 원소보다 오른쪽에
			left = middle + 1;				// 새로운 값으로 low 설정
		else 								// key는 중간 원소보다 왼쪽에
			rght = middle - 1;				// 새로운 값으로 high 설정
	}   
	return -1;
}

