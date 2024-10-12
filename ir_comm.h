/**
 * @file ir_comm.h
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#ifndef IR_COMM_H
#define IR_COMM_H

#include "system.h"

void irCommInit(void);
void irCommReceiveMove(uint8_t* opponentCol, uint8_t* playerTurn);


#endif