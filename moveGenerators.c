#include "moveGenerators.h"

void generatePawnMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter) {
	if(getColor(input->board, x, y) == WHITE) {
		if(getColor(input->board, x, y+1) == 0 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x, y+1, 10);
			(*moveCounter)++;
		}
		if(y == 1) {
            if(getColor(input->board, x, y+1) == 0 && y+2 < 8) {
    			if(getColor(input->board, x, y+2) == 0) {
    				tmp->next[*moveCounter] = doMove(input, x, y, x, y+2, 10);
    				(*moveCounter)++;
    			}
            }
		}
		if(getColor(input->board, x-1, y+1) == -1 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y+1, 10);
			(*moveCounter)++;
		}
		if(getColor(input->board, x+1, y+1) == -1 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y+1, 10);
			(*moveCounter)++;
		}

	}
	if(getColor(input->board, x, y) == BLACK) {
		if(getColor(input->board, x, y-1) == 0 && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x, y-1, 20);
			(*moveCounter)++;
		}
		if(y == 6) {
            if(getColor(input->board, x, y-1) == 0 && y-1 >= 0) {
    			if(getColor(input->board, x, y-2) == 0) {
    				tmp->next[*moveCounter] = doMove(input, x, y, x, y-2, 20);
    				(*moveCounter)++;
    			}
            }
		}
		if(getColor(input->board, x-1, y-1) == 1 && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y-1, 20);
			(*moveCounter)++;
		}
		if(getColor(input->board, x+1, y-1) == 1 && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y-1, 20);
			(*moveCounter)++;
		}
	}
}
void generateBishophMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter) {
	if(getColor(input->board, x, y) == WHITE) {
		for(int i = 0; i < 8; i++) {
			if(x-i < 0 || y-i < 0) {
				break;
			}
            if(getColor(input->board, x-i, y-i) == WHITE) {
                break;
            }
			if(getColor(input->board, x-i, y-i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y-i, 13);
				(*moveCounter)++;
			}
			if(getColor(input->board, x-i , y-i) == BLACK) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y-i, 13);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x-i < 0 || y+i > 7) {
				break;
			}
            if(getColor(input->board, x-i, y+i) == WHITE) {
                break;
            }
			if(getColor(input->board, x-i, y+i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y+i, 13);
				(*moveCounter)++;
			}
			if(getColor(input->board, x-i, y+i) == BLACK) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y+i, 13);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x+i > 7 || y+i > 7) {
				break;
			}
            if(getColor(input->board, x+i, y+i) == WHITE) {
                break;
            }
			if(getColor(input->board, x+i, y+i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y+i, 13);
				(*moveCounter)++;
			}
			if(getColor(input->board, x+i, y+i) == BLACK) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y+i, 13);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x+i > 7 || y-i < 0) {
				break;
			}
            if(getColor(input->board, x+i, y-i) == WHITE) {
                break;
            }
			if(getColor(input->board, x+i, y-i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y-i, 13);
				(*moveCounter)++;
			}
			if(getColor(input->board, x+i, y-i) == BLACK) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y-i, 13);
				(*moveCounter)++;
				break;
			}
		}
	}
	if(getColor(input->board, x, y) == BLACK) {
		for(int i = 0; i < 8; i++) {
			if(x-i < 0 || y-i < 0) {
				break;
			}
            if(getColor(input->board, x-i, y-i) == BLACK) {
                break;
            }
			if(getColor(input->board, x-i, y-i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y-i, 23);
				(*moveCounter)++;
			}
			if(getColor(input->board, x-i , y-i) == WHITE) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y-i, 23);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x-i < 0 || y+i > 7) {
				break;
			}
            if(getColor(input->board, x-i, y+i) == BLACK) {
                break;
            }
			if(getColor(input->board, x-i, y+i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y+i, 23);
				(*moveCounter)++;
			}
			if(getColor(input->board, x-i, y+i) == WHITE) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y+i, 23);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x+i > 7 || y+i > 7) {
				break;
			}
            if(getColor(input->board, x+i, y+i) == BLACK) {
                break;
            }
			if(getColor(input->board, x+i, y+i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y+i, 23);
				(*moveCounter)++;
			}
			if(getColor(input->board, x+i, y+i) == WHITE) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y+i, 23);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x+i > 7 || y-i < 0) {
				break;
			}
            if(getColor(input->board, x+i, y-i) == BLACK) {
                break;
            }
			if(getColor(input->board, x+i, y-i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y-i, 23);
				(*moveCounter)++;
			}
			if(getColor(input->board, x+i, y-i) == WHITE) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y-i, 23);
				(*moveCounter)++;
				break;
			}
		}
	}
}
void generateKnightMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter) {
	if(getColor(input->board, x, y) == WHITE) {
		if((getColor(input->board, x-1, y-2) == 0 || getColor(input->board, x-1, y-2) == BLACK) && x-1 > -1 && y-2 > -1) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y-2, 14);
			(*moveCounter)++;
		}
		if((getColor(input->board, x-1, y+2) == 0 || getColor(input->board, x-1, y+2) == BLACK) && x-1 > -1 && y+2 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y+2, 14);
			(*moveCounter)++;
		}
		if((getColor(input->board, x+1, y+2) == 0 || getColor(input->board, x+1, y+2) == BLACK) && x+1 < 8 && y+2 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y+2, 14);
			(*moveCounter)++;
		}
		if((getColor(input->board, x+1, y-2) == 0 || getColor(input->board, x+1, y-2) == BLACK) && x+1 < 8 && y-2 > -1) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y-2, 14);
			(*moveCounter)++;
		}

		if((getColor(input->board, x-2, y-1) == 0 || getColor(input->board, x-2, y-1) == BLACK) && x-2 > -1 && y-1 > -1) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-2, y-1, 14);
			(*moveCounter)++;
		}
		if((getColor(input->board, x-2, y+1) == 0 || getColor(input->board, x-2, y+1) == BLACK) && x-2 > -1 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-2, y+1, 14);
			(*moveCounter)++;
		}
		if((getColor(input->board, x+2, y-1) == 0 || getColor(input->board, x+2, y-1) == BLACK) && x+2 < 8 && y-1 > -1) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+2, y-1, 14);
			(*moveCounter)++;
		}
		if((getColor(input->board, x+2, y+1) == 0 || getColor(input->board, x+2, y+1) == BLACK) && x+2 < 8 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+2, y+1, 14);
			(*moveCounter)++;
		}
	}

	if(getColor(input->board, x, y) == BLACK) {
		if((getColor(input->board, x-1, y-2) == 0 || getColor(input->board, x-1, y-2) == WHITE) && x-1 > -1 && y-2 > -1) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y-2, 24);
			(*moveCounter)++;
		}
		if((getColor(input->board, x-1, y+2) == 0 || getColor(input->board, x-1, y+2) == WHITE) && x-1 > -1 && y+2 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y+2, 24);
			(*moveCounter)++;
		}
		if((getColor(input->board, x+1, y+2) == 0 || getColor(input->board, x+1, y+2) == WHITE) && x+1 < 8 && y+2 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y+2, 24);
			(*moveCounter)++;
		}
		if((getColor(input->board, x+1, y-2) == 0 || getColor(input->board, x+1, y-2) == WHITE) && x+1 < 8 && y-2 > -1) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y-2, 24);
			(*moveCounter)++;
		}

		if((getColor(input->board, x-2, y-1) == 0 || getColor(input->board, x-2, y-1) == WHITE) && x-2 > -1 && y-1 > -1) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-2, y-1, 24);
			(*moveCounter)++;
		}
		if((getColor(input->board, x-2, y+1) == 0 || getColor(input->board, x-2, y+1) == WHITE) && x-2 > -1 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-2, y+1, 24);
			(*moveCounter)++;
		}
		if((getColor(input->board, x+2, y-1) == 0 || getColor(input->board, x+2, y-1) == WHITE) && x+2 < 8 && y-1 > -1) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+2, y-1, 24);
			(*moveCounter)++;
		}
		if((getColor(input->board, x+2, y+1) == 0 || getColor(input->board, x+2, y+1) == WHITE) && x+2 < 8 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+2, y+1, 24);
			(*moveCounter)++;
		}
	}
}

void generateRookMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter) {
    if(getColor(input->board, x, y) == WHITE) {
        for(int i = 0; i < 8; i++) {
            if(x+i > 7) {
                break;
            }
            if(getColor(input->board, x+i, y) == WHITE) {
                break;
            }
            if(getColor(input->board, x+i, y) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x+i, y, 15);
                (*moveCounter)++;
            }
            if(getColor(input->board, x+i, y) == BLACK) {
                tmp->next[*moveCounter] = doMove(input, x, y, x+i, y, 15);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(x-i < 0) {
                break;
            }
            if(getColor(input->board, x-i, y) == WHITE) {
                break;
            }
            if(getColor(input->board, x-i, y) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x-i, y, 15);
                (*moveCounter)++;
            }
            if(getColor(input->board, x-i, y) == BLACK) {
                tmp->next[*moveCounter] = doMove(input, x, y, x-i, y, 15);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(y+i > 7) {
                break;
            }
            if(getColor(input->board, x, y+i) == WHITE) {
                break;
            }
            if(getColor(input->board, x, y+i) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y+i, 15);
                (*moveCounter)++;
            }
            if(getColor(input->board, x, y+i) == BLACK) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y+i, 15);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(y-i < 0) {
                break;
            }
            if(getColor(input->board, x, y-i) == WHITE) {
                break;
            }
            if(getColor(input->board, x, y-i) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y-i, 15);
                (*moveCounter)++;
            }
            if(getColor(input->board, x, y-i) == BLACK) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y-i, 15);
                (*moveCounter)++;
                break;
            }
        }
    }

    if(getColor(input->board, x, y) == BLACK) {
        for(int i = 0; i < 8; i++) {
            if(x+i > 7) {
                break;
            }
            if(getColor(input->board, x+i, y) == BLACK) {
                break;
            }
            if(getColor(input->board, x+i, y) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x+i, y, 25);
                (*moveCounter)++;
            }
            if(getColor(input->board, x+i, y) == WHITE) {
                tmp->next[*moveCounter] = doMove(input, x, y, x+i, y, 25);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(x-i < 0) {
                break;
            }
            if(getColor(input->board, x-i, y) == BLACK) {
                break;
            }
            if(getColor(input->board, x-i, y) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x-i, y, 25);
                (*moveCounter)++;
            }
            if(getColor(input->board, x-i, y) == WHITE) {
                tmp->next[*moveCounter] = doMove(input, x, y, x-i, y, 25);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(y+i > 7) {
                break;
            }
            if(getColor(input->board, x, y+i) == BLACK) {
                break;
            }
            if(getColor(input->board, x, y+i) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y+i, 25);
                (*moveCounter)++;
            }
            if(getColor(input->board, x, y+i) == WHITE) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y+i, 25);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(y-i < 0) {
                break;
            }
            if(getColor(input->board, x, y-i) == BLACK) {
                break;
            }
            if(getColor(input->board, x, y-i) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y-i, 25);
                (*moveCounter)++;
            }
            if(getColor(input->board, x, y-i) == WHITE) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y-i, 25);
                (*moveCounter)++;
                break;
            }
        }
    }
}

void generateQueenMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter) {
    if(getColor(input->board, x, y) == WHITE) {
        for(int i = 0; i < 8; i++) {
            if(x+i > 7) {
                break;
            }
            if(getColor(input->board, x+i, y) == WHITE) {
                break;
            }
            if(getColor(input->board, x+i, y) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x+i, y, 18);
                (*moveCounter)++;
            }
            if(getColor(input->board, x+i, y) == BLACK) {
                tmp->next[*moveCounter] = doMove(input, x, y, x+i, y, 18);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(x-i < 0) {
                break;
            }
            if(getColor(input->board, x-i, y) == WHITE) {
                break;
            }
            if(getColor(input->board, x-i, y) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x-i, y, 18);
                (*moveCounter)++;
            }
            if(getColor(input->board, x-i, y) == BLACK) {
                tmp->next[*moveCounter] = doMove(input, x, y, x-i, y, 18);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(y+i > 7) {
                break;
            }
            if(getColor(input->board, x, y+i) == WHITE) {
                break;
            }
            if(getColor(input->board, x, y+i) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y+i, 18);
                (*moveCounter)++;
            }
            if(getColor(input->board, x, y+i) == BLACK) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y+i, 18);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(y-i < 0) {
                break;
            }
            if(getColor(input->board, x, y-i) == WHITE) {
                break;
            }
            if(getColor(input->board, x, y-i) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y-i, 18);
                (*moveCounter)++;
            }
            if(getColor(input->board, x, y-i) == BLACK) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y-i, 18);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
			if(x-i < 0 || y-i < 0) {
				break;
			}
            if(getColor(input->board, x-i, y-i) == WHITE) {
                break;
            }
			if(getColor(input->board, x-i, y-i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y-i, 18);
				(*moveCounter)++;
			}
			if(getColor(input->board, x-i , y-i) == BLACK) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y-i, 18);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x-i < 0 || y+i > 7) {
				break;
			}
            if(getColor(input->board, x-i, y+i) == WHITE) {
                break;
            }
			if(getColor(input->board, x-i, y+i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y+i, 18);
				(*moveCounter)++;
			}
			if(getColor(input->board, x-i, y+i) == BLACK) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y+i, 18);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x+i > 7 || y+i > 7) {
				break;
			}
            if(getColor(input->board, x+i, y+i) == WHITE) {
                break;
            }
			if(getColor(input->board, x+i, y+i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y+i, 18);
				(*moveCounter)++;
			}
			if(getColor(input->board, x+i, y+i) == BLACK) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y+i, 18);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x+i > 7 || y-i < 0) {
				break;
			}
            if(getColor(input->board, x+i, y-i) == WHITE) {
                break;
            }
			if(getColor(input->board, x+i, y-i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y-i, 18);
				(*moveCounter)++;
			}
			if(getColor(input->board, x+i, y-i) == BLACK) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y-i, 18);
				(*moveCounter)++;
				break;
			}
		}
    }

    if(getColor(input->board, x, y) == BLACK) {
        for(int i = 0; i < 8; i++) {
            if(x+i > 7) {
                break;
            }
            if(getColor(input->board, x+i, y) == BLACK) {
                break;
            }
            if(getColor(input->board, x+i, y) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x+i, y, 28);
                (*moveCounter)++;
            }
            if(getColor(input->board, x+i, y) == WHITE) {
                tmp->next[*moveCounter] = doMove(input, x, y, x+i, y, 28);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(x-i < 0) {
                break;
            }
            if(getColor(input->board, x-i, y) == BLACK) {
                break;
            }
            if(getColor(input->board, x-i, y) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x-i, y, 28);
                (*moveCounter)++;
            }
            if(getColor(input->board, x-i, y) == WHITE) {
                tmp->next[*moveCounter] = doMove(input, x, y, x-i, y, 28);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(y+i > 7) {
                break;
            }
            if(getColor(input->board, x, y+i) == BLACK) {
                break;
            }
            if(getColor(input->board, x, y+i) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y+i, 28);
                (*moveCounter)++;
            }
            if(getColor(input->board, x, y+i) == WHITE) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y+i, 28);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
            if(y-i < 0) {
                break;
            }
            if(getColor(input->board, x, y-i) == BLACK) {
                break;
            }
            if(getColor(input->board, x, y-i) == 0) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y-i, 28);
                (*moveCounter)++;
            }
            if(getColor(input->board, x, y-i) == WHITE) {
                tmp->next[*moveCounter] = doMove(input, x, y, x, y-i, 28);
                (*moveCounter)++;
                break;
            }
        }
        for(int i = 0; i < 8; i++) {
			if(x-i < 0 || y-i < 0) {
				break;
			}
            if(getColor(input->board, x-i, y-i) == BLACK) {
                break;
            }
			if(getColor(input->board, x-i, y-i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y-i, 28);
				(*moveCounter)++;
			}
			if(getColor(input->board, x-i , y-i) == WHITE) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y-i, 28);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x-i < 0 || y+i > 7) {
				break;
			}
            if(getColor(input->board, x-i, y+i) == BLACK) {
                break;
            }
			if(getColor(input->board, x-i, y+i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y+i, 28);
				(*moveCounter)++;
			}
			if(getColor(input->board, x-i, y+i) == WHITE) {
				tmp->next[*moveCounter] = doMove(input, x, y, x-i, y+i, 28);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x+i > 7 || y+i > 7) {
				break;
			}
            if(getColor(input->board, x+i, y+i) == BLACK) {
                break;
            }
			if(getColor(input->board, x+i, y+i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y+i, 28);
				(*moveCounter)++;
			}
			if(getColor(input->board, x+i, y+i) == WHITE) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y+i, 28);
				(*moveCounter)++;
				break;
			}
		}
		for(int i = 0; i < 8; i++) {
			if(x+i > 7 || y-i < 0) {
				break;
			}
            if(getColor(input->board, x+i, y-i) == BLACK) {
                break;
            }
			if(getColor(input->board, x+i, y-i) == 0) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y-i, 28);
				(*moveCounter)++;
			}
			if(getColor(input->board, x+i, y-i) == WHITE) {
				tmp->next[*moveCounter] = doMove(input, x, y, x+i, y-i, 28);
				(*moveCounter)++;
				break;
			}
		}
    }
}

void generateKingMove(boardState *input, boardState *tmp, int x, int y, int *moveCounter) {
    if(getColor(input->board, x, y) == WHITE) {
        if((getColor(input->board, x-1, y-1) == 0 || getColor(input->board, x-1, y-1) == BLACK) && x-1 >= 0 && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y-1, 19);
			(*moveCounter)++;
		}
        if((getColor(input->board, x-1, y) == 0 || getColor(input->board, x-1, y) == BLACK) && x-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y, 19);
			(*moveCounter)++;
		}
        if((getColor(input->board, x-1, y+1) == 0 || getColor(input->board, x-1, y+1) == BLACK) && x-1 >= 0 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y+1, 19);
			(*moveCounter)++;
		}
        if((getColor(input->board, x, y+1) == 0 || getColor(input->board, x, y+1) == BLACK) && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x, y+1, 19);
			(*moveCounter)++;
		}
        if((getColor(input->board, x+1, y+1) == 0 || getColor(input->board, x+1, y+1) == BLACK) && x+1 < 8 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y+1, 19);
			(*moveCounter)++;
		}
        if((getColor(input->board, x+1, y) == 0 || getColor(input->board, x+1, y) == BLACK) && x+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y, 19);
			(*moveCounter)++;
		}
        if((getColor(input->board, x+1, y-1) == 0 || getColor(input->board, x+1, y-1) == BLACK) && x+1 < 8 && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y-1, 19);
			(*moveCounter)++;
		}
        if((getColor(input->board, x, y-1) == 0 || getColor(input->board, x, y-1) == BLACK) && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x, y-1, 19);
			(*moveCounter)++;
		}
    }
    if(getColor(input->board, x, y) == BLACK) {
        if((getColor(input->board, x-1, y-1) == 0 || getColor(input->board, x-1, y-1) == WHITE) && x-1 >= 0 && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y-1, 29);
			(*moveCounter)++;
		}
        if((getColor(input->board, x-1, y) == 0 || getColor(input->board, x-1, y) == WHITE) && x-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y, 29);
			(*moveCounter)++;
		}
        if((getColor(input->board, x-1, y+1) == 0 || getColor(input->board, x-1, y+1) == WHITE) && x-1 >= 0 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x-1, y+1, 29);
			(*moveCounter)++;
		}
        if((getColor(input->board, x, y+1) == 0 || getColor(input->board, x, y+1) == WHITE) && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x, y+1, 29);
			(*moveCounter)++;
		}
        if((getColor(input->board, x+1, y+1) == 0 || getColor(input->board, x+1, y+1) == WHITE) && x+1 < 8 && y+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y+1, 29);
			(*moveCounter)++;
		}
        if((getColor(input->board, x+1, y) == 0 || getColor(input->board, x+1, y) == WHITE) && x+1 < 8) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y, 29);
			(*moveCounter)++;
		}
        if((getColor(input->board, x+1, y-1) == 0 || getColor(input->board, x+1, y-1) == WHITE) && x+1 < 8 && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x+1, y-1, 29);
			(*moveCounter)++;
		}
        if((getColor(input->board, x, y-1) == 0 || getColor(input->board, x, y-1) == WHITE) && y-1 >= 0) {
			tmp->next[*moveCounter] = doMove(input, x, y, x, y-1, 29);
			(*moveCounter)++;
		}
    }
}
