/**
 * @file ir_comm.c
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#include "ir_comm.h"
#include "ir_uart.h"
#include "board.h"

void irCommInit(void)
{
    ir_uart_init();
}

void irCommReceiveMove(uint8_t* opponentCol, uint8_t* playerTurn)
{
    if (ir_uart_read_ready_p()) {
        *opponentCol = ir_uart_getc();
        if (isValidMove(*opponentCol)) {
            dropToken(*opponentCol, 2);
            *playerTurn = 1;
        }
    }
}

