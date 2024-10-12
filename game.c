/**
 * @file game.c
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#include "game.h"
#include "board.h"
#include "matrix_display.h"
#include "ir_comm.h"
#include "player.h"
#include "ir_uart.h"

static uint8_t currentCol = 0;
static uint8_t currentPlayer = 1;
static uint8_t playerTurn = 1;
static bool isPlayer1 = true;

void gameInit(void)
{
    boardInit();
    displayInit();
    irCommInit();
    playerInit();

    if (ir_uart_read_ready_p()) {
        isPlayer1 = false;
        currentPlayer = 2;
        playerTurn = 0;
    } else {
        isPlayer1= true;
        currentPlayer = 1;
        playerTurn = 1;

        ir_uart_putc('1');
    }
}

int main(void)
{
    while (1) {
        
        if (playerTurn) {
            displayBoard(currentCol, currentPlayer, 1);
            handleInput(&currentCol, &currentPlayer, &playerTurn);
        } else {
            displayBoard(currentCol, currentPlayer, 0);
            irCommReceiveMove(&currentCol, &playerTurn);
        }

        if (checkWin(currentPlayer)) {
            displayWinner(currentPlayer);
        }
    }
}