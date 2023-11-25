#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void initializeBoard(Board *board, int size)
{
    int i, j;

    board->size = size;
    board->board = (char **)malloc(size * sizeof(char *));

    for (i = 0; i < size; ++i)
    {
        board->board[i] = (char *)malloc(size * sizeof(char));
    }

    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            if (i < size / 2 - 1 && (i + j) % 2 == 1)
            {
                board->board[i][j] = 'x';
            } 
            else if (i > size / 2 && (i + j) % 2 == 1)
            {
                board->board[i][j] = 'o';
            } 
            else
            {
                board->board[i][j] = '.';
            }
        }
    }
}

void freeBoard(Board *board)
{
    int i;
    for (i = 0; i < board->size; ++i)
    {
        free(board->board[i]);
    }
    free(board->board);
}

void displayBoard(const Board *board)
{
    int i, j;
    printf("  ");
    for (i = 0; i < board->size; ++i)
    {
        printf(" %c", 'a' + i);
    }
    printf("\n");
    for (i = 0; i < board->size; ++i)
    {
        printf("%-2d ", i + 1); 
        for (j = 0; j < board->size; ++j)
        {
            switch (board->board[i][j])
            {
                case 'x':
                    printf("\033[31mx \033[0m"); // Red
                    break;
                case 'o':
                    printf("\033[36mo \033[0m"); // Blue sky
                    break;
                case 'X':
                    printf("\033[31mX \033[0m"); // Red
                    break;
                case 'O':
                    printf("\033[36mO \033[0m"); // Blue sky
                    break;
                case '.':
                    printf(". "); // White
                    break;
            }
        }
        printf("\n");
    }
}

int getTypeOfPiecesInACase(Board *board, Position *position)
{
    if (board->board[position->line][position->column] == 'x' || board->board[position->line][position->column] == 'o')
    {
        return 1;
    }
    else if (board->board[position->line][position->column] == 'X' || board->board[position->line][position->column] == 'O')
    {
        return 2;
    }
    else{
        return 0;
    }

}
