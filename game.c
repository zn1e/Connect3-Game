/**
 * @file game.c
 * @author Moises Allen Montalbo (mam417)
 * @brief This is the main module of the game that includes game initialization, checking and updating
 * the winner, and taking turns between the player.
 */

#include "game.h"
#include "board.h"
#include "pacer.h"
#include "matrix_display.h"
#include "ir_comm.h"
#include "player.h"
#include "ir_uart.h"

/**
 * Function for initializing the game.
 * @param gameState struct containing information about the player and state of game
 */
void gameInit(GameState_t* gameState)
{
    system_init();
    boardInit();
    irCommInit();
    playerInit();
    displayInit();
    
    gameState->currentPlayer = irPlayerOrder();

    if (gameState->currentPlayer == FIRST_PLAYER) {
        gameState->playerTurn = 1;
    } else {
        gameState->playerTurn = 0;
    }

    gameState->gameActive = true;
}

/**
 * Function for checking and updating the winner of the game.
 * @param gameState struct containing information about the player and state of game
 * @param winner pointer to player number
 */
void checkUpdateWinner(GameState_t* gameState, uint8_t* winner)
{
    if (checkWin(1)) {
        gameState->gameActive = false;
        *winner = 1;
    } else if (checkWin(2)) {
        gameState->gameActive = false;
        *winner = 2;
    }
}

/**
 * Main function of the game. This initializes the gameState struct and calls the loop
 * for taking turns of the players. After each round, the game state is check if there is
 * a winner, if so, it ends the game and display the winning player.
 */
int main(void)
{
    GameState_t gameState = {0, 0, 0, false};
    gameInit(&gameState);
    uint8_t winner = 0;

    while (gameState.gameActive && winner == 0) {
        clearDisplay();

        if (gameState.playerTurn) {
            displayBoardTurn(&gameState, 1);
            handleInput(&gameState);
        } else {
            irWaitMove(&(gameState.currentCol), &(gameState.currentPlayer), &(gameState.playerTurn));
        }
        
        checkUpdateWinner(&gameState, &winner);   
    }

    displayWinner(winner);
}
