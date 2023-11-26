// utils.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVES 1000

typedef struct {
    int line;
    int column;
} Position;

typedef struct {
    Position **sequences; 
    int *sequenceLengths; 
    int numberOfSequences; 
} ObligatoryMoves;

typedef struct {
    Position pairs[MAX_MOVES][2]; 
    int numberOfPairs; 
} PossibleMoves;

Position *convertCharToPosition(char *position);
char *convertPositionToChar(Position* position);
Position* createNewPosition(int newLine, int newColumn);
void printPosition(Position *position);
void convertToLower(char *str, int length);
void initializeObligatoryMoves(ObligatoryMoves *moves);
void addObligatorySequence(ObligatoryMoves *moves, Position *sequence, int sequenceLength);
void cleanObligatoryMoves(ObligatoryMoves *moves);
void initializePossibleMoves(PossibleMoves *moves);
void addPossibleMove(PossibleMoves *moves, Position from, Position to);

#endif // UTILS_HS
