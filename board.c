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
                    printf("\033[31mx \033[0m"); // Rouge
                    break;
                case 'o':
                    printf("\033[36mo \033[0m"); // Bleu ciel
                    break;
                case '.':
                    printf(". "); // Blanc
                    break;
            }
        }
        printf("\n");
    }
}
