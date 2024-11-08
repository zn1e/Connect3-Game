/**
 * @file ir_comm.c
 * @author Moises Allen Montalbo (mam417)
 * @brief This module implements the IR communications between the two
 * microcontrollers. It includes initializing the IR comms, ordering the player,
 * and waiting for the move of current player taking turn.
 */

#include "ir_comm.h"
#include "ir_uart.h"
#include "board.h"
#include "matrix_display.h"
#include "player.h"
#include "pacer.h"
#include "tinygl.h"
#include "../../fonts/font5x7_1.h"

/**
 * Initializes the IR communicat ion by setting up the IR UART interface.
 */
void irCommInit(void)
{
    ir_uart_init();
}

/**
 * Determine the player order for the game using IR communication.
 * @return the player's number
 */
uint8_t irPlayerOrder(void)
{
    uint8_t playerNum = 0;

    if (!ir_uart_read_ready_p()) {
        ir_uart_putc('1');  

        int timeout = 3000;
        while (!ir_uart_read_ready_p() && timeout > 0) {
            pacer_wait();
            timeout--;
        }

        if (ir_uart_read_ready_p()) {
            char received = ir_uart_getc();
                
            if (received == '2') {
                playerNum = FIRST_PLAYER;
            }
        } else {
            playerNum = FIRST_PLAYER;
        }
    } else {
        while (!ir_uart_read_ready_p()) {
            pacer_wait();
        }
        char received = ir_uart_getc();

        if (received == '1') {
            ir_uart_putc('2');
            playerNum = SECOND_PLAYER;
        }
    }

    // Short delay before proceeding to ensure proper synchronization
    for (int i = 0; i < 1500; i++) {
        pacer_wait();
    }

    return playerNum;  
}

/**
 * Wait for the opponent's move via IR communication and update the board
 * accordingly.
 * @param opponentCol column of the opponent's move
 * @param playerNum number of current player
 * @param playerTurn flag describing the player turn
 */
void irWaitMove(uint8_t* opponentCol, uint8_t* playerNum, uint8_t* playerTurn)
{
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(10);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text("WAITING");

    while (1) {
        pacer_wait();
        tinygl_update();

        if (ir_uart_read_ready_p()) {
            char received = ir_uart_getc();
            if (received >= '0' && received < ('0' + COLS)) {
                *opponentCol = received - '0';

                if (isValidMove(*opponentCol)) {
                    uint8_t opponentPlayer = (*playerNum == FIRST_PLAYER) ? SECOND_PLAYER : FIRST_PLAYER;
                    dropToken(*opponentCol, opponentPlayer);
                    ir_uart_putc('A');
                    *playerTurn = 1;
                    break;  
                } 
            }
        }
    }
    clearDisplay();
}

