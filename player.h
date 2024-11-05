/**
 * @file player.h
 * @author Moises Allen Montalbo (mam417)
 * @brief Header file for player input handling and initialization of game.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "system.h"
#include "game.h"

/**
 * Initializes the player's input system by setting up the navigation switch.
 */
void playerInit(void);

/**
 * Handles player input for moving and selecting a column to drop the token.
 * @param gameState struct containing game state and player's information
 */
void handleInput(GameState_t* gameState);

#endif
