#include <board.h>

void initializeBoard(Board *board, int size)
{
    int i;
    board->size = size;
    board->board = malloc(size * sizeof(char*));
    if (board->board == NULL)
    {
        printf("Error: malloc failed\n");
        exit(1);
    }

    for (i = 0; i < size; ++i)
    {
        board->board[i] = malloc(size * sizeof(char));
        if (board->board[i] == NULL)
        {
            printf("Error: malloc failed\n");
            exit(1);
        }
    }

    // ' ' = vide, 'N' = pion noir, 'B' = pion blanc, 'D' = dame blanche, = dame noire 
}