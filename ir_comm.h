/**
 * @file ir_comm.h
 * @author Moises Allen Montalbo (mam417), ShunZhi Zhang (szh139)
 * @brief This header implements the IR communications between the two
 * microcontrollers. It includes initializing the IR comms, ordering the player,
 * and waiting for the move of current player taking turn.
 */

#ifndef IR_COMM_H
#define IR_COMM_H

#include "system.h"

/* Constant for first player number. */
#define FIRST_PLAYER 1

/* Constant for second player number. */
#define SECOND_PLAYER 2

/**
 * Initializes the IR communicat ion by setting up the IR UART interface.
 */
void irCommInit(void);

/**
 * Determine the player order for the game using IR communication.
 * @return the player's number
 */
uint8_t irPlayerOrder(void);

/**
 * Wait for the opponent's move via IR communication and update the board
 * accordingly.
 * @param opponentCol column of the opponent's move
 * @param playerNum number of current player
 * @param playerTurn flag describing the player turn
 */
void irWaitMove(uint8_t* opponentCol, uint8_t* playerNum, uint8_t* playerTurn);

#endif