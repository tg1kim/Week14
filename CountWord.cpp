#include <stdio.h>
#include <ctype.h>

#pragma warning(disable: 4326)

void CountWord(char chr, int inWord, int nWordCtr);

void main()
{
	int chr;
	int nWordCtr = 0, inWord = false;
	while ((chr = getchar()) != EOF)
		CountWord(chr, inWord, nWordCtr);			// call by value: fail
	printf("Word ctr: %d\n", nWordCtr);
}

/****/
// 이 함수는 매개변수 chr, inWord, nWordCtr이 지역 변수이므로 메인의 변수들과 다르다(값만 복사되어 같음)
// 그래서 이 함수에서 inWord, nWordCtr를 수정해도 함수가 끝나면 사멸되어 연속성이 없다
void CountWord(char chr, int inWord, int nWordCtr)	//				IN				OUT
{													// WS	Yes		inWord: false	nothing
	if (inWord) {									//		No		nothing			inWord: true, ctr++
		if (isspace(chr))
			inWord = false;
	}
	else if (!isspace(chr)) {
		inWord = true;
		nWordCtr++;
	}
}
/****/

/****
void CountWord(char chr, int inWord, int nWordCtr)	//				IN				OUT
{													// WS	Yes		inWord: false	nothing
	if (isspace(chr)) {								//		No		nothing			inWord: true, ctr++
		if (inWord)
			inWord = false;
	}
	else if (!inWord) {
		inWord = true;
		nWordCtr++;
	}
}
/****/