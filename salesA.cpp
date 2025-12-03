#include <stdio.h>

#define  YEARS 	3
#define  PRODUCTS 	5

#pragma warning(disable: 4996 4326 6031)

void main()
{
	int sales[YEARS][PRODUCTS] = {
		{ 1,  2,  3,  4,  5},
		{11, 12, 13, 14, 15},
		{21, 22, 23, 24, 25} };
	int Sum(int scores[YEARS][PRODUCTS]);
	int totalSale = Sum(sales);
	printf("총매출은 %d입니다.\n", totalSale);
}

int Sum(int scores[YEARS][PRODUCTS])
{
	int total = 0;
	for(int y = 0; y < YEARS; y++)
		for(int p = 0; p < PRODUCTS; p++)
			total += scores[y][p];
	return total;
}
