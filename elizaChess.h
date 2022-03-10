#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "moveGenerators.h"
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

typedef struct boardState boardState;

struct boardState {
	short board[8][8];
	boardState **next;
	boardState *prev;
	short currentColor;
	int moveCount;
};

enum pieces {
	whitePawn = 10
};
enum playerColor {
	BLACK = -1,
	WHITE = 1
};


float evaluate(boardState *input);
boardState *moveGenerator(boardState *input);



int getColor(short board[8][8], int x, int y);
void copyBoardState(boardState *src, boardState *dst);
boardState *doMove(boardState *alt, int x_old, int y_old, int x_new, int y_new, int piece);
void printBoard(boardState *input);
