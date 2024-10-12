/**
 * @file display.h
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#ifndef MATRIX_DISPLAY_H
#define MATRIX_DISPLAY_H

#include "system.h"

void displayInit(void);
void displayBoard(uint8_t currentCol, uint8_t currentPlayer, uint8_t blinkOn);
void displayWinner(uint8_t player);


#endif