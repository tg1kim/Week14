#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable: 4326 4996)

typedef struct tree {
	char sName[9];			// �̸�
	int  nNo;
	char sPosition[3];		// ������
	char sBirthday[11];		// ������� 2002.06.04
	int  nHeight;			// Ű
	int  nWeight;			// ������
	char sClub[30];
	struct tree *lChild;
	struct tree *rChild;
}	Data, *DataPtr, Tree, *TreePtr, Node, *NodePtr;

void main()
{
	void MakeSearchTree(TreePtr& pTree1, TreePtr& pTree2);
	TreePtr SearchTree(TreePtr pTree, char *sName);
	TreePtr pTree1 = NULL, pTree2 = NULL;
	MakeSearchTree(pTree1, pTree2);
	TreePtr pTree = pTree1;
	while (1) {
		void SwapTree(TreePtr pTree);
		bool EqualTree(TreePtr pTree1, TreePtr pTree2);
		void Inorder(TreePtr pTree);
		char sCmnd[20];
		printf("[sqnx*e] ? ");
		gets_s(sCmnd);							// ����� �Է��Ѵ�.
		TreePtr pNode;
		switch (*sCmnd | 0x20) {
		case 'e':								// �ƹ��� ����� ������
			return;
		case 's':								// Ʈ���� ���ʰ� ������ �ڽ��� �ٲ۴�
			SwapTree(pTree);
			printf("Swap: Tree%d\n", (pTree == pTree1) ? 1 : 2);
			break;
		 case 'q':								// �� Ʈ���� ������ ���Ѵ�.
			printf("%s\n", EqualTree(pTree1, pTree2) ? "good" : "bad");
			break;
		 case 'n':								// inorder traverse�ϸ鼭 ���� �̸��� ����Ѵ�.
			Inorder(pTree);
			putchar('\n');
			break;
		 case 'x':								// Ž�� ����� pTree1�� pTree2�� �ٲ۴�.
			if (pTree == pTree1) {
				pTree = pTree2;
				printf("pTree2 ���\n");
			}
			else {
				pTree = pTree1;
				printf("pTree1 ���\n");
			}
			break;
		 default:								// �˻��� ������ �̸����� ����
			pNode = SearchTree(pTree, sCmnd);	// �˻��� �Ѵ�.
			if (pNode) {
				printf("    �̸�: %s\n", pNode->sName);
				printf("      No: %d\n", pNode->nNo);
				printf("  ������: %s\n", pNode->sPosition);
				printf("�������: %s\n", pNode->sBirthday);
				printf("      Ű: %d\n", pNode->nHeight);
				printf("  ������: %d\n", pNode->nWeight);
				printf("    �Ҽ�: %s\n", pNode->sClub);
			}
			else
				printf("  No name......\n");
		}
		putchar('\n');
	}
}

void MakeSearchTree(TreePtr& pTree1, TreePtr& pTree2)
{
#include "nationalTeam.h"

	TreePtr InsertNode1(TreePtr pTree, DataPtr pNode);
	void InsertNode2(TreePtr& pTree, DataPtr pNode);
	for (int i = 0; i < sizeof(nationalTeam) / sizeof(nationalTeam[0]); i++) {
		pTree1 = InsertNode1(pTree1, nationalTeam + i);
		InsertNode2(pTree2, nationalTeam + i);
	}
}

TreePtr InsertNode1(TreePtr pTree, DataPtr pNode)
{
	// Ʈ���� �ϳ��� ��带 �����Ѵ�.
	// �̹� �����ϸ� �ƹ��� ���� ���� �ʴ´�.
	int nCond;
	if (pTree == NULL) {
		pTree = (TreePtr)malloc(sizeof(Node));
		if (pTree) {
			*pTree = *pNode;		//memcpy(pTree, pNode, sizeof(Data));
			pTree->lChild = pTree->rChild = NULL;
		}
	}
	else if ((nCond = strcmp(pNode->sName, pTree->sName)) < 0)
		pTree->lChild = InsertNode1(pTree->lChild, pNode);
	else if (nCond > 0)
		pTree->rChild = InsertNode1(pTree->rChild, pNode);
	return pTree;
}

void InsertNode2(TreePtr& pTree, DataPtr pNode)
{
	// Ʈ���� �ϳ��� ��带 �����Ѵ�.
	// �̹� �����ϸ� �ƹ��� ���� ���� �ʴ´�.
	int nCond;
	if (pTree == NULL) {
		pTree = (TreePtr)malloc(sizeof(Node));
		if (pTree) {
			*pTree = *pNode;		//memcpy(pTree, pNode, sizeof(Data));
			pTree->lChild = pTree->rChild = NULL;
		}
	}
	else if ((nCond = strcmp(pNode->sName, pTree->sName)) < 0)
		InsertNode2(pTree->lChild, pNode);
	else if (nCond > 0)
		InsertNode2(pTree->rChild, pNode);
}

TreePtr SearchTree(TreePtr pTree, char *sName)
{
	// Ž��Ʈ������ sName�� ���� ������ ã�� �� ��带 return�Ѵ�.
	// �� ������ ������ NULL�� return�Ѵ�.
	if (pTree) {
		int nCond;
		if ((nCond = strcmp(sName, pTree->sName)) < 0)
			pTree = SearchTree(pTree->lChild, sName);
		else if (nCond > 0)
			pTree = SearchTree(pTree->rChild, sName);
	}
	return pTree;
} 

void Inorder(TreePtr pTree)
{
	// �̸��� ����Ѵ�
	if (pTree) {
		Inorder(pTree->lChild);
		printf("%s ", pTree->sName);
		Inorder(pTree->rChild);
	}
}

void SwapTree(TreePtr pTree)
{
	// ����Ʈ���� ��� ����� �����ʰ� ���� �ڽ��� ���� �ٲ۴�.
	// �� �ſ� ��ģ ����� ����Ʈ���� ��ȯ�Ѵ�.
	// Ž��Ʈ���� ����ϹǷ� �������� �۰Եǰ� ������ ũ�� �ȴ�.
	if (pTree) {
		SwapTree(pTree->lChild);
		SwapTree(pTree->rChild);
		TreePtr pTemp = pTree->lChild;
		pTree->lChild = pTree->rChild;
		pTree->rChild = pTemp;
	}
}

bool EqualTree(TreePtr pTree1, TreePtr pTree2)
{
	// �� Ʈ���� ������ ���Ͽ� true/false�� return�Ѵ�.
	// �� ���� sName, nNo �� �ʵ常 ���Ͽ� �Ǵ��Ѵ�.
	if (pTree1 == NULL && pTree2 == NULL)
		return true;
	if (pTree1 && pTree2)
		return strcmp(pTree1->sName, pTree2->sName) == 0 && pTree1->nNo == pTree2->nNo &&
			   EqualTree(pTree1->lChild, pTree2->lChild) && EqualTree(pTree1->rChild, pTree2->rChild);
	return false;
}
