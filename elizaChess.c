#include "elizaChess.h"

int counter = 0;

float evaluate(boardState *input) {
	int whiteValue = 0;
	int blackValue = 0;
	for(int x = 0; x <= 7; x++) {
		for(int y = 0; y <= 7; y++) {
			switch(input->board[x][y]){
				case 10:
					whiteValue += 1;
					break;
				case 13:
					whiteValue += 3;
					break;
				case 14:
					whiteValue += 3;
					break;
				case 15:
					whiteValue += 5;
					break;
				case 18:
					whiteValue += 9;
					break;
				case 19:
					whiteValue += 900;
					break;
				case 20:
					blackValue += 1;
					break;
				case 23:
					blackValue += 3;
					break;
				case 24:
					blackValue += 3;
					break;
				case 25:
					blackValue += 5;
					break;
				case 28:
					blackValue += 9;
					break;
				case 29:
					blackValue += 900;
					break;
			}
		}
	}
	return whiteValue - blackValue;
}

boardState *moveGenerator(boardState *input) {
	int moveCounter = 0;
	boardState *tmp = malloc(sizeof(boardState));
	tmp->next = malloc(sizeof(boardState)*100);
	for(int x = 0; x < 8; x++) {
		for(int y = 0; y < 8; y++) {
			switch(input->board[x][y]){
				case 10:
					if(input->currentColor == 1) {
						generatePawnMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 13:
					if(input->currentColor == 1) {
						generateBishophMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 14:
					if(input->currentColor == 1) {
						generateKnightMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 15:
					if(input->currentColor == 1) {
						generateRookMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 18:
					if(input->currentColor == 1) {
						generateQueenMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 19:
					if(input->currentColor == 1) {
						generateKingMove(input, tmp, x, y, &moveCounter);
					}
					break;


				case 20:
					if(input->currentColor == -1) {
						generatePawnMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 23:
					if(input->currentColor == -1) {
						generateBishophMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 24:
					if(input->currentColor == -1) {
						generateKnightMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 25:
					if(input->currentColor == -1) {
						generateRookMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 28:
					if(input->currentColor == -1) {
						generateQueenMove(input, tmp, x, y, &moveCounter);
					}
					break;
				case 29:
					if(input->currentColor == -1) {
						generateKingMove(input, tmp, x, y, &moveCounter);
					}
					break;
			}
		}
	}
	for(int i = 0; i < moveCounter; i++) {
		printBoard((tmp->next)[i]);
		printf("Evaluation: %f\n\n\n", evaluate((tmp->next)[i]));
	}
	tmp->moveCount = moveCounter;
	return tmp;
}



boardState *doMove(boardState *alt, int x_old, int y_old, int x_new, int y_new, int piece) {
	boardState *out = malloc(sizeof(boardState));
	copyBoardState(alt, out);
	out->board[x_old][y_old] = 0;
	out->board[x_new][y_new] = piece;
	out->prev = alt;
	if(alt->currentColor == -1) {
		out->currentColor = 1;
	}
	else if(alt->currentColor == 1) {
		out->currentColor = -1;
	}
}



int getColor(short board[8][8], int x, int y) {
	short field = board[x][y];
	if(field == 10 || field == 13 || field == 14 || field == 15 || field == 18 || field == 19) {
		return 1;
	}
	if(field == 0) {
		return 0;
	}
	if(field == 20 || field == 23 || field == 24 || field == 25 || field == 28 || field == 29) {
		return -1;
	}
}

void copyBoardState(boardState *src, boardState *dst) {
	for(int x = 0; x < 8; x++) {
		for(int y = 0; y < 8; y++) {
			dst->board[x][y] = src->board[x][y];
		}
	}
}

void printBoard(boardState *input) {
	for(int y = 7; y >= 0; y--) {
		for(int x = 0; x < 8; x++) {
			printf("%02d|", input->board[x][y]);
		}
		printf("\n");
	}
	printf("current Color is %d\n", input->currentColor);
}

void generate(boardState *root) {
	if(counter > -1) {
		root = moveGenerator(root);
		counter++;
		printf("\n\n%d\n", counter);
		for(int i = 0; i < root->moveCount; i++) {
			generate(root->next[i]);
		}
	}
}


int main() {
	/*
	 * Opening:
	 * 	  =========================	=========================
	 *	7 =25|24|23|28|29|23|24|25=	=sT|sS|sL|sD|sK|sL|sS|sT=
	 *	6 =20|20|20|20|20|20|20|20=	=sB|sB|sB|sB|sB|sB|sB|sB=
	 *	5 =00|00|00|00|00|00|00|00=	=  |  |  |  |  |  |  |  =
	 *	4 =00|00|00|00|00|00|00|00=	=  |  |  |  |  |  |  |	=
	 *	3 =00|00|00|00|00|00|00|00=	=  |  |  |  |  |  |  |	=
	 *	2 =00|00|00|00|00|00|00|00=	=  |  |  |  |  |  |  |	=
	 *	1 =10|10|10|10|10|10|10|10=	=wB|wB|wB|wB|wB|wB|wB|wB=
	 *	0 =15|14|13|18|19|13|14|15=	=wT|wS|wL|wD|wK|wL|wS|wT=
	 *	  =========================	=========================
	 *	   0  1  2  3  4  5  6  7
	 */
	boardState *opening = malloc(sizeof(boardState));
	for(int x = 0; x < 8; x++) {
		for(int y = 0; y < 8; y++) {
			opening->board[x][y] = 0;
		}
	}
	opening->board[0][0] = 15;
	opening->board[1][0] = 14;
	opening->board[2][0] = 13;
	opening->board[3][0] = 18;
	opening->board[4][0] = 19;
	opening->board[5][0] = 13;
	opening->board[6][0] = 14;
	opening->board[7][0] = 15;
	opening->board[0][1] = 10;
	opening->board[1][1] = 10;
	opening->board[2][1] = 10;
	opening->board[3][1] = 10;
	opening->board[4][1] = 10;
	opening->board[5][1] = 10;
	opening->board[6][1] = 10;
	opening->board[7][1] = 10;

	opening->board[0][7] = 25;
	opening->board[1][7] = 24;
	opening->board[2][7] = 23;
	opening->board[3][7] = 28;
	opening->board[4][7] = 29;
	opening->board[5][7] = 23;
	opening->board[6][7] = 24;
	opening->board[7][7] = 25;
	opening->board[0][6] = 20;
	opening->board[1][6] = 20;
	opening->board[2][6] = 20;
	opening->board[3][6] = 20;
	opening->board[4][6] = 20;
	opening->board[5][6] = 20;
	opening->board[6][6] = 20;
	opening->board[7][6] = 20;
	//opening->board[3][3] = 14;
	//opening->board[0][1] = 13;
	//opening->board[5][6] = 20;
	//opening->board[1][2] = 20;
	opening->currentColor = 1;
	printBoard(opening);
	generate(opening);
	return 0;
}
