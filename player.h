/**
 * @file player.h
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "system.h"
#include "game.h"

void playerInit(void);

void handleInput(GameState_t* gameState);

void playerSwitch(uint8_t* currentPlayer);


#endif