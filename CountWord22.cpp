#include <ctype.h>

extern int nWordCtr;

/****/
void CountWord(char chr)				//				IN				OUT
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
void CountWord(char chr)				//				IN				OUT
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