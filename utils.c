#include "utils.h"

Position* convertCharToPosition(char *position)
{
    convertToLower(position, 2);
    
    Position *pos = createNewPosition(atoi(&position[1]) - 1, (int)position[0] - 97);
    return pos;
    
}

char* convertPositionToChar(Position* position) {
    char* positionStr = (char*) malloc(3 * sizeof(char));
    
    positionStr[0] = (char)(position->column + 'a');
    positionStr[1] = (char)(position->line + '1');
    positionStr[2] = '\0';

    return positionStr;
}


Position* createNewPosition(int newLine, int newColumn)
{
    Position *pos = (Position*) malloc(sizeof(Position));
    *pos = (Position) { .line = newLine, .column = newColumn};
    return pos;
}

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
