//这题很吃力，唉，递归不会啊
#include <stdio.h>

int conflict(int chessboard[][8], int row, int column);
void place_queen(int chessboard[][8], int row);

int queen(void) {
	int chessboard[8][8] = { 0 };//creating chessboard to place pieces
	int i, j;
	place_queen(chessboard, 0);
	
}

int conflict(int chessboard[][8], int row, int column) {
	int i, j;
	for (i = 0; i < 8; i++) {
		if (chessboard[i][column] == 1 && (i != row)) {
			return 1;//you(have) conflict
		}
	}
	for (j = 0; j < 8; j++) {
		if (chessboard[row][j] == 1 && (j != column)) {
			return 1;
		}
	}
	for (i = 1, j = 1; row - i >= 0 && column - j >= 0; i++, j++) {
		if (chessboard[row - i][column - j] == 1) {
			return 1;
		}
	}
	for (i = 1, j = 1; row + i <= 8 && column + j <= 8; i++, j++) {
		if (chessboard[row + i][column + j] == 1) {
			return 1;
		}
	}
	for (i = 1, j = 1; row - i <= 8 && column + j <= 8; i++, j++) {
		if (chessboard[row - i][column + j] == 1) {
			return 1;
		}
	}
	for (i = 1, j = 1; row + i <= 8 && column - j <= 8; i++, j++) {
		if (chessboard[row + i][column - j] == 1) {
			return 1;
		}
	}
	return 0;//no conflict

}

void place_queen(int chessboard[][8], int row) {

	int i, j;
	for (j = 0; j < 8 && row < 8; j++) {
		chessboard[row][j] = 1;
		if (!conflict(chessboard, row, j)) {
			if (row < 7)
				place_queen(chessboard, row + 1);
			else if (row == 7) {
				for (i = 0; i < 8; i++) {
					for (j = 0; j < 8; j++) {
						printf("%d ", chessboard[i][j]);
					}
					putchar('\n');
				}
			}
		}
		chessboard[row][j] = 0;
	}
}
