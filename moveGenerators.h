#pragma once
#include "elizaChess.h"

typedef struct boardState boardState;

void generatePawnMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter);
void generateBishophMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter);
void generateKnightMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter);
void generateRookMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter);
void generateQueenMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter);
void generateKingMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter);
