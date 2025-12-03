#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

// ∆Ω≈√≈‰
void PlayOneGame();
void PlayOneRound(char board[][3], char cPlayer);

// GameIO
void GetRowColumn(int& row, int& col, const char b[][3], char cPlyr);
void PrintBoard(const char board[][3]);
void ReportWinner(char cWinner);
int  NoMoreGame();

// GameCheck
void InitBoard(char board[][3]);
int  IsWrongRowCol(int row, int col, const char board[][3]);
int  IsGameOver(const char b[][3], char& cWinner);

void main()
{
	while (1) {
		PlayOneGame();
		if (NoMoreGame())
			break;
		putchar('\n');
	}
}

void PlayOneGame()
{
	char board[3][3];
	InitBoard(board);
	PrintBoard(board);
	char cPlayer = 'X', cWinner;
	do {
		PlayOneRound(board, cPlayer);
		cPlayer = 'X' + 'O' - cPlayer;
	} while (!IsGameOver(board, cWinner));
	ReportWinner(cWinner);
}

void PlayOneRound(char board[][3], char cPlayer)
{
	int row, col;
	GetRowColumn(row, col, board, cPlayer);
	board[row][col] = cPlayer;
	PrintBoard(board);
}

void GetRowColumn(int& row, int& col, const char b[][3], char cPlyr)
{
	while (1) {
		printf("[%c]  ? ? ", cPlyr);
		scanf("%d %d", &row, &col);
		int nError = IsWrongRowCol(row, col, b);
		if (nError == 0)
			return;
		printf("%s     \n\n", nError == 1 ? "  ?" : "    ");
	}
}

void PrintBoard(const char board[][3])
{
	for (int row = 0; row < 3; row++) {
		printf("+---+---+---+\n");
		for (int col = 0; col < 3; col++)
			printf("| %c ", board[row][col]);
		printf("|\n");
	}
	printf("+---+---+---+\n\n");
}

void ReportWinner(char cWinner)
{
	if (cWinner == ' ')
		printf("Draw");
	else
		printf("%c win", cWinner);
	printf("\n\n");
}

int NoMoreGame()
{
	printf("More(y/n) ? ");
	char cYesNo;
	scanf(" %c", &cYesNo);
	return (cYesNo | 0x20) != 'y';			// [Yes] [Other No]
	//	return cYesNo != 'y' || cYesNo != 'Y';	// [Yes] [Other No]
	//	return (cYesNo | 0x20) == 'n';			// [Yes Other] [No]
	//	return cYesNo == 'n' || cYesNo == 'N';	// [Yes Other] [No]
}

void InitBoard(char board[][3])
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';
}

int IsWrongRowCol(int row, int col, const char board[][3])
{
	if (row < 0 || row > 2 ||				//   ?     
		col < 0 || col > 2)
		return 1;
	if (board[row][col] != ' ')				//          
		return 2;
	return 0;								//          
}

int IsGameOver(const char b[][3], char& cWinner)
{
	for (int r = 0; r < 3; r++)								//    3   
		if (b[r][0] == b[r][1] && b[r][1] == b[r][2])
			if ((cWinner = b[r][1]) != ' ')
				return true;
	for (int c = 0; c < 3; c++)								//    3   
		if (b[0][c] == b[1][c] && b[1][c] == b[2][c])
			if ((cWinner = b[1][c]) != ' ')
				return true;
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2] ||			//   O  
		b[0][2] == b[1][1] && b[1][1] == b[2][0])
		if ((cWinner = b[1][1]) != ' ')
			return true;
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			if (b[r][c] == ' ')								//    ?
				return false;
	cWinner = ' ';
	return true;
}
