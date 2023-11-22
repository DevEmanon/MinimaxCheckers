#include "board.h"
#include "evaluation.h"
#include "game_logic.h"
#include "minimax.h"
#include "player.h"
#include <stdio.h>

int main() {
    Board board;
    initializeBoard(&board, 10);
    displayBoard(&board);
    printf("\n");
    freeBoard(&board);
    return 0;
}