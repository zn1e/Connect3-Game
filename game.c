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


void gameInit(GameState_t* gameState)
{
    system_init();
    boardInit();
    displayInit();
    irCommInit();
    playerInit();

    if (ir_uart_read_ready_p()) {
        char received = ir_uart_getc();
        if (received == 'S') {
            gameState->currentPlayer = 2;
            gameState->playerTurn = 0;
        } else {
            gameState->currentPlayer = 1;
            gameState->playerTurn = 1;
            ir_uart_putc('S');
        }
    } else {
        gameState->currentPlayer = 1;
        gameState->playerTurn = 1;
        ir_uart_putc('S');
    }
    gameState->gameActive = true;
}

int main(void)
{
    GameState_t gameState = {0, 1, 1, false};
    gameInit(&gameState);
    
    while (gameState.gameActive) {
        
        if (gameState.playerTurn) {
            displayBoardTurn(&gameState, 1);
            handleInput(&gameState);

            if (checkWin(gameState.currentPlayer)) {
                gameState.gameActive = false;
                displayWinner(gameState.currentPlayer);
                break;
            }

        } else {
            displayBoardIdle();
            irCommReceiveMove(&(gameState.currentCol), &(gameState.playerTurn));

            if (checkWin(gameState.currentPlayer)) {
                gameState.gameActive = false;
                displayWinner(gameState.currentPlayer);
                break;
            }
        }
    }
    return 0;
}