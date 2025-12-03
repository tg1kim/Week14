#include <stdio.h>
#include <ctype.h>

#pragma warning(disable: 4326)

int nWordCtr;
void CountWord(char chr);

void main()
{
	int chr;
	nWordCtr = 0;
	while ((chr = getchar()) != EOF)
		CountWord(chr);
	printf("Word ctr: %d\n", nWordCtr);
}