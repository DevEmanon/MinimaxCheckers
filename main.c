#include "board.h"
#include "utils.h"
#include "game_logic.h"
#include <stdio.h>

int main() {
    Board board;
    initializeBoard(&board, 10);
    displayBoard(&board);
    freeBoard(&board);
    return 0;
}