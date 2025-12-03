#include <stdio.h>

#define SIZE 10

#pragma warning(disable: 4996 4326 6031)

void main()
{
	void PrintReservation(int a[], int n);
	int GetSeat(int a[], int n);

	int seats[SIZE] = { 0 };
	while (1) {		
		printf("예약(y/n) ? ");
		char cYesNo;
		scanf(" %c", &cYesNo);
		if (cYesNo != 'y')
			break;
		int nSeat = GetSeat(seats, SIZE);
		seats[nSeat - 1] = 1;
		printf("%d번 좌석에 예약되었습니다.\n", nSeat);
		PrintReservation(seats, SIZE);
	}
}

void PrintReservation(int a[], int n)
{
	printf("-------------------------------\n");
	printf("  1  2  3  4  5  6  7  8  9  10\n");
	printf("-------------------------------\n");
	for (int i = 0; i < SIZE; i++)
		printf("%3d", a[i]);
	printf("\n\n");
}

int GetSeat(int a[], int n)
{
	PrintReservation(a, n);
	int nSeat;
	while (1) {
		while (1) {
			printf("좌석 ? ");
			scanf("%d", &nSeat);
			if (nSeat >= 1 && nSeat <= n)
				break;
			printf("1부터 %d사이의 숫자를 입력하세요\n\n", n);
		}
		if (a[nSeat - 1] == 0)			// 예약되지 않았으면
			break;
		printf("이미 예약된 자리입니다.\n\n");
	}
	return nSeat;
}