/**
 * @file player.c
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#include "player.h"
#include "navswitch.h"
#include "pacer.h"
#include "board.h"
#include "ir_uart.h"
#include "matrix_display.h"

void playerInit(void)
{
    navswitch_init();
}

void handleInput(GameState_t* gameState)
{
    if (gameState->playerTurn == 0) {
        return;
    }

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
                ir_uart_putc('0' + (gameState->currentCol));
                
                while (!ir_uart_read_ready_p()) {
                    pacer_wait();
                }
                ir_uart_getc();

                dropToken(gameState->currentCol, gameState->currentPlayer);
                gameState->playerTurn = 0;
                pacer_wait();
                return;
            }
        }
    }
}
