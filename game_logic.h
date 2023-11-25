// game_logic.h

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "board.h"
#include "utils.h"

int checkDiagonal(Position *positionFrom, Position *positionTo);
int isValidMove(Board *board, Position *positionFrom, Position *positionTo, int isAI);
int isValidMovePawn(Board *board, Position *positionFrom, Position *positionTo, int isAI);
int isValidMoveQueen(Board *board, Position *positionFrom, Position *positionTo, int isAI);
int checkCapture(Board *board, char turn, int isAI);
int checkCapturePawn(Board *board, Position *caseToCheck, int isAI);
int checkCaptureQueen(Board *board, Position *caseToCheck, int isAI);
int isGameOver(Board *board, int isAI);
void makeMove(Board *board, Position *positionFrom, Position *positionTo, int isAI);

#endif // GAME_LOGIC_H
