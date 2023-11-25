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


Position *convertCharToPosition(char *position);
char *convertPositionToChar(Position* position);
Position* createNewPosition(int newLine, int newColumn);
void printPosition(Position *position);
void convertToLower(char *str, int length);

#endif // UTILS_HS