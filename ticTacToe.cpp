#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

// TicTacToe
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
	while (1) 
		PlayOneGame
		if NoMoreGame
			break
	"Bye, ...\n"
}

void PlayOneGame
{
	배열 board
	Init Board
	Print Board
	Player = 'X'
	do
		Play One Round By Player
		Player: 'X' <--> 'O'
	while NOT IsGameOver --> Winner
	Report Winner
}

void PlayOneRound
{
	row, col <-- GetRowColumn By board Player
	board(row,col) <-- Player
	Print Board
}

void GetRowColumn
{
	while (1)
		"[%c] 행열 ? ", Player
		"%d %d" --> row, col
		Error <-- IsWrongRowCol By row, col, board
		if No Error
			return
		"%s 오류\n\n" <-- "좌표", "선택"
}

void PrintBoard
{
	for (int row = 0)
		"+---+---+---+\n"
		for (int col = 0)
			"| %c " <-- board(row,col)
		"|\n"
	"+---+---+---+\n\n"
}

void ReportWinner
{
	if Winner == ' '
		"Draw"
	else
		"%c win" <-- Winner
	"\n\n"
}

int NoMoreGame
{
	"More(y/n) ? "
	" %c" --> cYesNo
	return (cYesNo | 0x20) != 'y';			// [Yes] [Other No]
//	return cYesNo != 'y' || cYesNo != 'Y';	// [Yes] [Other No]
//	return (cYesNo | 0x20) == 'n';			// [Yes Other] [No]
//	return cYesNo == 'n' || cYesNo == 'N';	// [Yes Other] [No]
}

void InitBoard
{
	board(row,col) <-- ' '
}

int IsWrongRowCol
{
	if row:0~2				// 좌표 오류
	   col:0~2
		return 좌표 오류
	if board(row,col) != ' '				// 선택 오류
		return 선택 오류
	return 오류 없음								// 오류 없음
}

int IsGameOver
{
	for (int r = 0)								// 행 3 줄
		if b[r][0] == b[r][1] == b[r][2]
			if Winner <-- b[r][1] != ' '
				return true;
	for (int c = 0)								// 열 3 줄
		if b[0][c] == b[1][c] == b[2][c]
			if Winner <-- b[1][c] != ' ')
				return true;
	if b[0][0] == b[1][1]  == b[2][2] ||			// 대각선
	   b[0][2] == b[1][1]  == b[2][0]
		if Winner <-- b[1][1] != ' ')
			return true;
	for (int r = 0)
		for (int c = 0)
			if b[r][c] == ' '								// 빈 칸
				return false;
	Winner <-- ' ';
	return true;
}
