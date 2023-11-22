// utils.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int line;
    int column;
} Position;

Position *convertCharToPosition(char *position);
// char *convertPositionToChar(Position *position);
void printPosition(Position *position);
void convertToLower(char *str, int length);

#endif // UTILS_H