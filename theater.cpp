#include <stdio.h>

#define SIZE 10

#pragma warning(disable: 4996 4326 6031)

void main()
{
	배열 seats에 0으로 초기화
	while (1) {		
		"예약(y/n) ? "
		cYesNo에 읽고
		if ('y'가 아니다)
			break;
		GetSeat를 호출하여 nSeat에 저장
		nSeat좌석에 예약
		"%d번 좌석에 예약되었습니다.\n"
		PrintReservation
	}
}

void PrintReservation(int a[], int n)
{
	printf("-------------------------------\n");
	printf("  1  2  3  4  5  6  7  8  9  10\n");
	printf("-------------------------------\n");
	for (int i)
		"%3d"
	printf("\n\n");
}

int GetSeat(int a[], int n)
{
	PrintReservation
	while (1) {
		while (1) {
			"좌석 ? "
			nSeat에 읽고
			if (올바른 좌석)
				break;
			printf("1부터 %d사이의 숫자를 입력하세요\n\n", n);
		}
		if ()			// 예약되지 있지 않았으면
			break;
		printf("이미 예약된 자리입니다.\n\n");
	}
	return nSeat;
}