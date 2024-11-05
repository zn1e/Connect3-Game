/**
 * @file game.h
 * @author Moises Allen Montalbo (mam417)
 * @brief This is the header of main module of the game that includes game initialization, checking and updating
 * the winner, and taking turns between the player.
 */


#ifndef GAME_H
#define GAME_H

#include "system.h"

/* Struct containing the information of game state and player. */
typedef struct {
    uint8_t currentCol;
    uint8_t currentPlayer;
    uint8_t playerTurn;
    bool gameActive;
} GameState_t;

/**
 * Function for initializing the game.
 * @param gameState struct containing information about the player and state of game
 */
void gameInit(GameState_t* gameState);

/**
 * Function for checking and updating the winner of the game.
 * @param gameState struct containing information about the player and state of game
 * @param winner pointer to player number
 */
void checkUpdateWinner(GameState_t* gameState, uint8_t* winner);

/**
 * Main function of the game. This initializes the gameState struct and calls the loop
 * for taking turns of the players. After each round, the game state is check if there is
 * a winner, if so, it ends the game and display the winning player.
 */
int main(void);


#endif
