/**
 * @file board.h
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#ifndef BOARD_H
#define BOARD_H

#include "system.h"

#define ROWS 7
#define COLS 5

void boardInit(void);

uint8_t isValidMove(uint8_t col);

int8_t dropToken(uint8_t col, uint8_t player);

uint8_t checkWin(uint8_t player);

uint8_t getCell(uint8_t row, uint8_t col);

#endif