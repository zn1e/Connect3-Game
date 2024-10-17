/**
 * @file game.c
 * @author Moises Allen Montalbo (mam417) ShunZhi Zhang (szh139)
 * @brief
 */

#include "game.h"
#include "board.h"
#include "pacer.h"
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