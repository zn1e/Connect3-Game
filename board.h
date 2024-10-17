/**
 * @file board.h
 * @author Moises Allen Montalbo (mam417), ShunZhi Zhang (szh139)
 * @brief This module is responsible for the state of the board. It contains
 * function for initializing the board, checking if a move is valid, drops 
 * token in the board, checking if there's a winner, and getting a cell to 
 * be used for matrix display.
 */

#ifndef BOARD_H
#define BOARD_H

#include "system.h"

/* Constant for the number of rows. */
#define ROWS 7

/* Constant for the number of columns. */
#define COLS 5

/**
 * Initializes the game board by setting all cells to 0.
 */
void boardInit(void);

/**
 * Checks if a move in the specified column is valid. 
 * @param col uin8_t value of the column
 */
uint8_t isValidMove(uint8_t col);

/**
 * Drops a token for the specified player into the given column.
 * @param col uint8_t value of the column
 * @param player uint8_t number of player
 * @return row where token is dropped, or -1 if column is full
 */
int8_t dropToken(uint8_t col, uint8_t player);

/**
 * Checks if the specified player has won the game.
 * @param player number of the player
 * @return 1 if the player wins, 0 otherwise
 */
uint8_t checkWin(uint8_t player);

/**
 * Returns the value of the cell at the specified row and column.
 * @param row value of the row
 * @param col value of the column
 * @return player number, 0 otherwise
 */
uint8_t getCell(uint8_t row, uint8_t col);

#endif