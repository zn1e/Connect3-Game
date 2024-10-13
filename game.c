/**
 * @file game.c
 * @author Moises Allen Montalbo (mam417) ShunZhi Zhang (szh139)
 * @brief
 */

#include "game.h"
#include "board.h"
#include "matrix_display.h"
#include "ir_comm.h"
#include "player.h"
#include "ir_uart.h"

static uint8_t currentCol = 0;
static uint8_t currentPlayer = 0;
static uint8_t playerTurn = 0;
static bool isPlayer1 = true;

void gameInit(void)
{
    system_init();
    boardInit();
    displayInit();
    irCommInit();
    playerInit();

    if (ir_uart_read_ready_p()) {
        char received = ir_uart_getc();
        if (received == 'S') {
            isPlayer1 = false;
            currentPlayer = 2;
            playerTurn = 0;
        } else {
            isPlayer1 = true;
            currentPlayer = 1;
            playerTurn = 1;
            ir_uart_putc('S');
        }
    } else {
        isPlayer1 = true;
        currentPlayer = 1;
        playerTurn = 1;
        ir_uart_putc('S');
    }
}

int main(void)
{
    gameInit();
    while (1) {
        
        if (playerTurn) {
            displayBoardTurn(currentCol, currentPlayer, 1);
            handleInput(&currentCol, &currentPlayer, &playerTurn);

            if (checkWin(currentPlayer)) {
                displayWinner(currentPlayer);
                break;
            }  

        } else {
            displayBoardIdle();
            irCommReceiveMove(&currentCol, &playerTurn);
            
            if (checkWin(currentPlayer)) {
                displayWinner(currentPlayer);
                break;
            }
        }

    }
    return 0;
}