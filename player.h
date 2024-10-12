/**
 * @file player.h
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "system.h"

void playerInit(void);

void handleInput(uint8_t* currentCol, uint8_t* currentPlayer, uint8_t* playerTurn);

void playerSwitch(uint8_t* currentPlayer);


#endif