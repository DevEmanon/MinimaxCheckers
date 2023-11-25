#include "game_logic.h"

int checkDiagonal(Position *positionFrom, Position *positionTo)
{
    int lineDiff = abs(positionFrom->line - positionTo->line);
    int columnDiff = abs(positionFrom->column - positionTo->column);

    return lineDiff == columnDiff;
}

int isValidMove(Board *board, Position *positionFrom, Position *positionTo, int isAI)
{
    if (positionFrom->line == positionTo->line && positionFrom->column == positionTo->column)
    {
        if (!isAI)
            printf("Un coup ne peut être sur place.\n");
        return 0;
    }

    int typeOfPieces = getTypeOfPiecesInACase(board, positionFrom);
    if (typeOfPieces == 1)
    {
        return isValidMovePawn(board, positionFrom, positionTo, isAI);
    }
    else if (typeOfPieces == 2)
    {
        return isValidMoveQueen(board, positionFrom, positionTo, isAI);
    }
    else
    {
        if (!isAI)
            printf("La case de départ est vide.");
        return 0;
    }
}

int isValidMovePawn(Board *board, Position *positionFrom, Position *positionTo, int isAI)
{
    if (checkDiagonal(positionFrom, positionTo) == 0)
    {
        if (!isAI)
            printf("Votre coup n'est pas en diagonale.");
        return 0;
    }

    int lineDiff = abs(positionFrom->line - positionTo->line);
    int columnDiff = abs(positionFrom->column - positionTo->column);

    if (!(lineDiff == 1 && columnDiff == 1))
    {
        if (!isAI)
            printf("Un pion ne se déplace pas à plus d'une case.");
        return 0;
    }

    if (getTypeOfPiecesInACase(board, positionTo) == 0)
    {
        return 1;
    }
    else
    {
        if (!isAI)
            printf("La case désirée n'est pas vide.");
        return 0;
    }
}

int isValidMoveQueen(Board *board, Position *positionFrom, Position *positionTo, int isAI)
{
    if (checkDiagonal(positionFrom, positionTo) == 0)
    {
        if (!isAI)
            printf("Votre coup n'est pas en diagonale.");
        return 0;
    }
}

int checkCapture(Board *board, char turn, int isAI)
{
    int line, column, typeOfPieces, returnResult = 0;
    Position *newCase = createNewPosition(0, 0);
    char turnUpper;
    if (turn == 'x')
        turnUpper = 'X';
    else
        turnUpper = 'O';
    for (line = 0; line < board->size; ++line)
    {
        for (column = 0; column < board->size; ++column)
        {
            if (board->board[line][column] == turn || board->board[line][column] == turnUpper)
            {
                newCase->line = line;
                newCase->column = column;
                typeOfPieces = (board, newCase);
                if (typeOfPieces == 1)
                {
                    if (checkCapturePawn(board, newCase, isAI))
                    {
                        if (!isAI)
                            printf("Une ou plusieurs prises obligatoires ont été trouvés à la case : %s", convertPositionToChar(newCase));
                        returnResult = 1;
                    }
                }
                else if (typeOfPieces == 2)
                {
                    if (checkCaptureQueen(board, newCase, isAI))
                    {
                        if (!isAI)
                            printf("Une ou plusieurs prises obligatoires ont été trouvés à la case : %s", convertPositionToChar(newCase));
                        returnResult = 1;
                    }
                }
            }
            
        }
    }
    free(newCase);
    return returnResult;
}

int checkCapturePawn(Board *board, Position *caseToCheck, int isAI)
{
    
}

int checkCaptureQueen(Board *board, Position *caseToCheck, int isAI)
{
  
}

int isGameOver(Board *board, int isAI)
{
  
}

void makeMove(Board *board, Position *positionFrom, Position *positionTo, int isAI)
{
  
}


