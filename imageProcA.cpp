#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	void display(int image[8][16]);
	void inverse(int img[8][16]);

	int image[8][16] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

	printf("변환전 이미지\n");
	display(image);
	inverse(image);
	printf("\n\n변환후 이미지\n");
	display(image);
}

void display(int image[8][16])
{
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 16; c++)
			putchar(image[r][c] ? '-' : '*');
		putchar('\n');
	}
}

void inverse(int img[8][16])
{
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 16; c++)
			img[r][c] = 1 - img[r][c];
}
