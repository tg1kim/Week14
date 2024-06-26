#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRIAL		10
#define RUNctr		16
#define DataRANGE	4000
#define DataNEXT	5000
#pragma warning (disable: 4326 4996)

void SetupLeafNode(int nTree[], int nData[]);
void FirstSelectionTree(int nTree[], int nData[]);
void RebuildSelectionTree(int nNdx, int nTree[], int nData[]);
void GetNextData(int nNdx, int nData[]);
void PrintSelectionTree(int nTree[], int nData[]);

void main()
{
	int nSelectionTree[RUNctr * 2], nRunData[RUNctr], nSortedData[TRIAL];
	srand((unsigned)time(NULL));
	SetupLeafNode(nSelectionTree, nRunData);
	FirstSelectionTree(nSelectionTree, nRunData);
	for (int i = 0; i < TRIAL; i++) {
		PrintSelectionTree(nSelectionTree, nRunData);
		int nNdx = nSelectionTree[1];
		printf("\n  Winner[%02d]: %d\n", nNdx, nSortedData[i] = nRunData[nNdx]);
		GetNextData(nNdx, nRunData);
		printf("New data[%02d]: %d\n\n", nNdx, nRunData[nNdx]);
		RebuildSelectionTree(nNdx, nSelectionTree, nRunData);
	}
	printf(" Sorted Data:");
	for (int i = 0; i < TRIAL; i++)
		printf(" %d", nSortedData[i]);
	putchar('\n');
}

void SetupLeafNode(int nTree[], int nData[])
{
	for (int i = 0; i < RUNctr; i++) {
		nTree[RUNctr + i] = i;
		nData[i] = rand() % DataRANGE + 1000;
	}
}

void FirstSelectionTree(int nTree[], int nData[])
{
	for (nNdx := RUNctr - 1 .. 1)
		int nNdxL = 왼쪽 자식 색인, nNdxR = 오른쪽 자식 색인;
		nTree[nNdx]에 작은 데이터의 색인을 저장;
}

void RebuildSelectionTree(int nNdx, int nTree[], int nData[])
{
	nNdx += RUNctr;			// Node index
	while (nNdx /= 2)
		int nNdxL = 왼쪽 자식 색인, nNdxR = 오른쪽 자식 색인;
		nTree[nNdx]에 작은 데이터의 색인을 저장;
}

void GetNextData(int nNdx, int nData[])
{
	nData[nNdx] += rand() % DataNEXT;
}

void FillSpace(int n)
{
	for (int i = 0; i < n; i++)
		putchar(0x20);
}

void PrintSelectionTree(int nTree[], int nData[])
{
	int nNdx = 1, nCtr = 1;
	for (int i = 1; i <= 4; i++, nCtr *= 2) {
		int nBgn = 3 * (RUNctr / nCtr) - 2;
		int nNxt = 6 * (RUNctr / nCtr) - 2;
		for (int j = 0, nTab = nBgn; j < nCtr; j++, nTab = nNxt) {
			FillSpace(nTab);
			printf("%02d", nTree[nNdx++]);
		}
		putchar('\n');
	}
	for (int i = 0; i < RUNctr; i++)
		printf("[%02d]  ", i);
	putchar('\n');
	for (int i = 0; i < RUNctr; i++)
		printf("%-6d", nData[i]);
	putchar('\n');
}
