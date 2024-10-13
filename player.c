/**
 * @file player.c
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#include "player.h"
#include "navswitch.h"
#include "board.h"
#include "ir_uart.h"

void playerInit(void)
{
    navswitch_init();
    ir_uart_init();
}

void handleInput(GameState_t* gameState)
{
    navswitch_update();

    if (navswitch_push_event_p(NAVSWITCH_WEST) && gameState->currentCol > 0) {
        gameState->currentCol--;
    }
    if (navswitch_push_event_p(NAVSWITCH_EAST) && gameState->currentCol < COLS - 1) {
        gameState->currentCol++;
    }
    if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        if (isValidMove(gameState->currentCol)) {
            if (ir_uart_write_ready_p()) {
                ir_uart_putc('0' + gameState->currentCol);
            }

            dropToken(gameState->currentCol, gameState->currentPlayer);
            playerSwitch(&gameState->currentPlayer);
            gameState->playerTurn = 0;
        }

    }
}

void playerSwitch(uint8_t* currentPlayer)
{
    *currentPlayer = (*currentPlayer == 1) ? 2 : 1;
}