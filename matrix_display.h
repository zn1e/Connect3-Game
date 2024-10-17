/**
 * @file display.h
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#ifndef MATRIX_DISPLAY_H
#define MATRIX_DISPLAY_H

#include "system.h"
#include "game.h"

#define PACER_RATE 500
#define BLINK_RATE 2

void displayInit(void);

void displayBoardTurn(GameState_t* gameState, uint8_t blinkOn);

void displayText(char* text);

void displayWinner(uint8_t winner);

void clearDisplay(void);

#endif