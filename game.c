/**
 * @file game.c
 * @author Moises Allen Montalbo (mam417) ShunZhi Zhang (szh139)
 * @brief
 */

#include "game.h"
#include "board.h"
#include "matrix_display.h"
#include "ir_comm.h"
#include "player.h"
#include "ir_uart.h"

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

void checkUpdateWinner(GameState_t* gameState)
{
    if (checkWin(gameState->currentPlayer)) {
        gameState->gameActive = false;
        gameState->winner = true;
    }
}

int main(void)
{
    GameState_t gameState = {0, 0, 0, false, false};
    gameInit(&gameState);

    while (gameState.gameActive) {
        clearDisplay();
        
        if (gameState.playerTurn) {
            displayBoardTurn(&gameState, 1);
            handleInput(&gameState);
            checkUpdateWinner(&gameState);
        } else {
            irWaitMove(&(gameState.currentCol), &(gameState.currentPlayer), &(gameState.playerTurn));
            displayBoardTurn(&gameState, 1);
            checkUpdateWinner(&gameState);
        }
    }

    displayWinner(&(gameState.winner));
}