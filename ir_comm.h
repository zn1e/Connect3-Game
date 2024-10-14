/**
 * @file ir_comm.h
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#ifndef IR_COMM_H
#define IR_COMM_H

#include "system.h"

#define FIRST_PLAYER 1
#define SECOND_PLAYER 2

void irCommInit(void);

uint8_t irPlayerOrder(void);

void irWaitMove(uint8_t* opponentCol, uint8_t* playerNum, uint8_t* playerTurn);

#endif