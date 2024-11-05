/**
 * @file player.c
 * @author Moises Allen Montalbo (mam417)
 * @brief Module for player input handling and initialization of game.
 */

#include "player.h"
#include "navswitch.h"
#include "pacer.h"
#include "board.h"
#include "ir_uart.h"
#include "matrix_display.h"

/**
 * Initializes the player's input system by setting up the navigation switch.
 */
void playerInit(void)
{
    navswitch_init();
}

/**
 * Handles player input for moving and selecting a column to drop the token.
 * @param gameState struct containing game state and player's information
 */
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
            dropToken(gameState->currentCol, gameState->currentPlayer);
            gameState->playerTurn = 0;
            
            if (ir_uart_write_ready_p()) {
                ir_uart_putc('0' + (gameState->currentCol));
                
                while (!ir_uart_read_ready_p()) {
                    pacer_wait();
                }

                ir_uart_getc();
                pacer_wait();
                return;
            }
        }
    }
}
