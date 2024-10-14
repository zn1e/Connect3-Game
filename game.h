/**
 * @file game.h
 * @author Moises Allen Montalbo (mam417) ShunZhi Zhang (szh139)
 * @brief
 */


#ifndef GAME_H
#define GAME_H

#include "system.h"

typedef struct {
    uint8_t currentCol;
    uint8_t currentPlayer;
    uint8_t playerTurn;
    bool gameActive;
    bool winner;
} GameState_t;

void gameInit(GameState_t* gameState);

int main(void);


#endif