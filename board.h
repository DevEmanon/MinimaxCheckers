// board.h

#ifndef BOARD_H
#define BOARD_H

#include "utils.h"
#include <stdlib.h> 

typedef struct {
    char **board; 
    int size;      
} Board;

void initializeBoard(Board *board, int size);
void freeBoard(Board *board);
void displayBoard(const Board *board);
int getTypeOfPiecesInACase(Board *board, Position *position);

#endif // BOARD_H
