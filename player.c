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

void handleInput(uint8_t* currentCol, uint8_t* currentPlayer, uint8_t* playerTurn)
{
    navswitch_update();

    if (navswitch_push_event_p(NAVSWITCH_WEST) && *currentCol > 0) {
        (*currentCol)--;
    }
    if (navswitch_push_event_p(NAVSWITCH_EAST) && *current_col < COLS - 1) {
        (*currentCol)++;
    }
    if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        if (validMove(*currentCol)) {
            int8_t row = dropToken(*currentCol, *currentPlayer);
            if (row != -1 && checkWin(*currentPlayer)) {
                // flash winner
            }
        }

        if (ir_uart_write_ready_p()) {
            ir_uart_putc(*currentCol);
        }
        playerSwitch(currentPlayer);
        *playerTurn = 0;
    }
}

void playerSwitch(uint8_t* currentPlayer)
{
    *currentPlayer = (*currentPlayer == 1) ? 2 : 1;
}