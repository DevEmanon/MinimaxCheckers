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

void initializeObligatoryMoves(ObligatoryMoves *moves)
{
    moves->sequences = malloc(MAX_MOVES * sizeof(Position*));
    moves->sequenceLengths = malloc(MAX_MOVES * sizeof(int));
    moves->numberOfSequences = 0;
}


void addObligatorySequence(ObligatoryMoves *moves, Position *sequence, int sequenceLength)
{
    int i;
    if (moves->numberOfSequences < MAX_MOVES)
    {
        Position *newSequence = malloc(sequenceLength * sizeof(Position));
        for (i = 0; i < sequenceLength; ++i)
        {
            newSequence[i] = sequence[i];
        }
        moves->sequences[moves->numberOfSequences] = newSequence;
        moves->sequenceLengths[moves->numberOfSequences] = sequenceLength;
        moves->numberOfSequences++;
    }
}

void cleanObligatoryMoves(ObligatoryMoves *moves)
{
    int i;
    for (i = 0; i < moves->numberOfSequences; ++i)
    {
        free(moves->sequences[i]);
    }
    free(moves->sequences);
    free(moves->sequenceLengths);
    moves->sequences = NULL;
    moves->sequenceLengths = NULL;
    moves->numberOfSequences = 0;
}

void initializePossibleMoves(PossibleMoves *moves)
{
    moves->numberOfPairs = 0;
}

void addPossibleMove(PossibleMoves *moves, Position from, Position to)
{
    if (moves->numberOfPairs < MAX_MOVES)
    {
        moves->pairs[moves->numberOfPairs][0] = from;
        moves->pairs[moves->numberOfPairs][1] = to;
        moves->numberOfPairs++;
    }
}

