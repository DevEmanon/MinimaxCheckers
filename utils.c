#include "utils.h"

Position* convertCharToPosition(char *position)
{
    convertToLower(position, 2);
    Position *pos = (Position*) malloc(sizeof(Position));
    *pos = (Position) { .line = atoi(&position[1]) - 1, .column = (int)position[0] - 97};
    return pos;
    
}

// char* convertPositionToChar(Position *position)
// {
// }

void printPosition(Position *position)
{
    printf("Line: %d, Column: %d\n", position->line, position->column);
}

void convertToLower(char *str, int length)
{
    int i;
    for(i = 0; i < length; ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + ('a' - 'A');
        }
    }
}