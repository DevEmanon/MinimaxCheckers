#include "board.h"
#include "utils.h"
#include <stdio.h>

int main() {
    Board board;
    char positionStr[] = "h7";
    printPosition(convertCharToPosition(positionStr));
    initializeBoard(&board, 10);
    displayBoard(&board);
    printf("\n");
    freeBoard(&board);
    return 0;
}