#include <stdio.h>
#include <ctype.h>

#pragma warning(disable: 4326)

int nWordCtr;
static void CountWord(char chr);

void main()
{
	int chr;
	nWordCtr = 0;
	while ((chr = getchar()) != EOF)
		CountWord(chr);
	printf("Word ctr: %d\n", nWordCtr);
}

/****/
static void CountWord(char chr)			//				IN				OUT
{										// WS	Yes		inWord: false	nothing
	static int inWord = false;			//		No		nothing			inWord: true, ctr++
	if (inWord) {
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
static void CountWord(char chr)			//				IN				OUT
{										// WS	Yes		inWord: false	nothing
	static int inWord = false;			//		No		nothing			inWord: true, ctr++
	if (isspace(chr)) {
		if (inWord)
			inWord = false;
	}
	else if (!inWord) {
		inWord = true;
		nWordCtr++;
	}
}
/****/