#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#pragma warning (disable: 4326 4996 6031)
#define	MaxCtr	127

typedef struct node {		// 트리의 노드
	int	nData;
	struct node *lChild;
	struct node *rChild;
}	Node, *NodePtr, *TreePtr;

typedef struct node1 {		// 연결리스트의 노드
	NodePtr	pData;
	struct node1* link;
}	Node1, *Node1Ptr, *QueuePtr;

int  SetOPtions(int arData[]);
void MakeAVLTree(TreePtr &pTree, int arData[], int nCtr);
int  AVLInsert(TreePtr &pTree, int nData);
void BalanceFactor(TreePtr &pTree, int bRttn);
void LeftRotate(TreePtr &pTree);
void RghtRotate(TreePtr &pTree);
int  TreeHeight(TreePtr pTree);
void FreeTree(TreePtr pTree);
void PrintTree(TreePtr pTree);
void PrintData(int nCtr, char *strData = NULL);
int  AddQ(QueuePtr& pQueue, NodePtr pData);
int  DeleteQ(QueuePtr& pQueue, NodePtr& pData);

char sRttnMsg[10];

void main()
{
	srand((unsigned)time(NULL));
	while (1) {
		int nCtr, arData[MaxCtr];
		if ((nCtr = SetOPtions(arData)) == 0)
			break;
		TreePtr pTree = NULL;
		MakeAVLTree(pTree, arData, nCtr);
		FreeTree(pTree);
		putchar('\n');
	}
	printf("Bye, ...\n\n");
}

int SetOPtions(int arData[])
{
	int nCtr;
	printf("노드 개수 ? ");
	scanf("%d", &nCtr);
	if (nCtr <= 0 || nCtr > MaxCtr)
		return 0;
	char sChoice[10];
	gets_s(sChoice);
	printf("Asc, Des, Rnd ? ");
	gets_s(sChoice);
	switch (sChoice[0] | 0x20) {
	case 'a':
		for (int i = 0; i < nCtr; i++)
			arData[i] = i + 1;
		break;
	case 'd':
		for (int i = 0; i < nCtr; i++)
			arData[i] = nCtr - i;
		break;
	case 'r':
		for (int nNdx = 0, k; nNdx < nCtr; nNdx++) {
			do {
				arData[nNdx] = rand() % 99 + 1;
				for (k = 0; k < nNdx; k++)
					if (arData[k] == arData[nNdx])
						break;
			} while (k != nNdx);
		}
	}
	return nCtr;
}

void MakeAVLTree(TreePtr &pTree, int arData[], int nCtr)
{
	
	for (int i = 0; i < nCtr; i++) {
		printf("Data: %d\n", arData[i]);
		sRttnMsg[0] = NULL;
		AVLInsert(pTree, arData[i]);
		if (sRttnMsg[0])
			printf(sRttnMsg);
		PrintTree(pTree);
		putchar('\n');
	}
}

int AVLInsert(TreePtr &pTree, int nData)
{
	int nRttn = 0;			// XY: LL=0, LR=1, RL=2, RR=3
	if (pTree == NULL) {
		pTree = new Node;
		if (pTree) {
			pTree->nData = nData;
			pTree->lChild = pTree->rChild = NULL;
		}
	}
	else if (nData < pTree->nData)
		AVLInsert(pTree->lChild, nData);
	else if (nData > pTree->nData)
		AVLInsert(pTree->rChild, nData);
	// Balance Factor
	return nRttn;
}

void BalanceFactor(TreePtr &pTree, int nRttn)
{
	int nBalance = 양쪽 자식트리의 높이 차;
	if (nBalance < -1 || nBalance > 1) {
		static const char *sRttn[] = { "LL", "LR", "RL", "RR" };
		sprintf(sRttnMsg, "[%02d] %s\n", pTree->nData, sRttn[nRttn]);
		switch (nRttn) {					// XY, L: 0, R: 1, X: Up, Y: Down
		case 1:								// LR Roation
			LeftRotate(왼쪽 자식);
		case 0:								// LL Rotation
			RghtRotate(현재 root);
			break;
		case 2:								// RL Rotation
			RghtRotate(오른쪽 자식);
		case 3:								// RR Rotation
			LeftRotate(현재 root);
		}
	}
}

void LeftRotate(TreePtr &pTree)
{
	새로운 root pRoot는 오른쪽 자식이 된다
	pTree의 오른쪽 자식은 pRoot의 왼쪽 자식이 된다
	pRoot의 왼쪽 자식은 기존의 root pTree가 된다
	pTree는 새로운 root인 pRoot가 된다.
}

void RghtRotate(TreePtr &pTree)
{
	새로운 root pRoot는 왼쪽 자식이 된다
	pTree의 왼쪽 자식은 pRoot의 오른쪽 자식이 된다.
	pRoot의 오른쪽 자식은 기존의 root pTree가 된다
	pTree는 새로운 root인 pRoot가 된다.
}

int TreeHeight(TreePtr pTree)
{
	int nHeight = 0;
	if (pTree) {
		int nlHeight = TreeHeight(pTree->lChild);
		int nrHeight = TreeHeight(pTree->rChild);
		nHeight = __max(nlHeight, nrHeight) + 1;
	}
	return nHeight;
}

int AddQ(QueuePtr& pQueue, NodePtr pData)
{
	Node1Ptr pNew = new Node1;
	if (pNew) {
		pNew->pData = pData;
		if (pQueue) {
			pNew->link = pQueue->link;
			pQueue->link = pNew;
		}
		else
			pNew->link = pNew;
		pQueue = pNew;
	}
	return (int)pNew;
}

int DeleteQ(QueuePtr& pQueue, NodePtr& pData)
{
	if (pQueue == NULL)
		return false;
	Node1Ptr pDel = pQueue->link;
	pData = pDel->pData;
	if (pQueue == pDel)
		pQueue = NULL;
	else
		pQueue->link = pDel->link;
	delete pDel;
	return true;
}

void PrintData(int nCtr, char *strData)
{
	for (int i = 0; i < nCtr; i++)
		putchar(0x20);
	strData && printf(strData);
}

void PrintTree(TreePtr pTree)
{
	QueuePtr pQueue = NULL;
	char strData[5] = {0};
	int nHeight = TreeHeight(pTree);
	int nLeafNodeCtr = (int)pow(2, nHeight - 1);
	int nTtlWidth = (nLeafNodeCtr - 1) * 3 + 2;
	AddQ(pQueue, pTree);
	NodePtr pData, pData1, pData2;
	for (int nLevel = 1, nNodeCtr = 1; nLevel <= nHeight; nLevel++, nNodeCtr *= 2) {
		int nCtr, nOutCtr = 0;
		int nDbl = nNodeCtr * 2;
		int nBlnkCtr = nTtlWidth - nNodeCtr * 2;
		for (int i = 0; i < nNodeCtr; i++) {
			DeleteQ(pQueue, pData);
			strData[0] = strData[1] = 0x20;
			if (pData)
				sprintf(strData, "%02d", pData->nData);
			if (nLevel != nHeight) {
				pData1 = pData2 = NULL;
				if (pData) {
					pData1 = pData->lChild;
					pData2 = pData->rChild;
				}
				AddQ(pQueue, pData1);
				AddQ(pQueue, pData2);
			}
			nCtr = (nBlnkCtr * (2 * i + 1) + nNodeCtr) / nDbl - nOutCtr;
			PrintData(nCtr, strData);
			nOutCtr += nCtr;
			nCtr = (nBlnkCtr * 2 * (i + 1) + nNodeCtr) / nDbl - nOutCtr;
			PrintData(nCtr);
			nOutCtr += nCtr;
		}
		putchar('\n');
	}
}

void FreeTree(TreePtr pTree)
{
	if (pTree) {
		FreeTree(pTree->lChild);
		FreeTree(pTree->rChild);
		delete pTree;
	}
}