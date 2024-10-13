/**
 * @file display.h
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#ifndef MATRIX_DISPLAY_H
#define MATRIX_DISPLAY_H

#include "system.h"
#include "game.h"

void displayInit(void);
void displayBoardTurn(GameState_t* gameState, uint8_t blinkOn);
void displayBoardIdle(void);
void displayWinner(uint8_t player);


#endif