/**
 * @file board.c
 * @author Moises Allen Montalbo (mam417), ShunZhi Zhang (szh139)
 * @brief This module is responsible for the state of the board. It contains
 * function for initializing the board, checking if a move is valid, drops 
 * token in the board, checking if there's a winner, and getting a cell to 
 * be used for matrix display.
 */

#include "board.h"

/**
 * 2D array representing the game board. 
 */
static uint8_t board[ROWS][COLS];

/**
 * Initializes the game board by setting all cells to 0.
 */
void boardInit(void)
{
    for (uint8_t i = 0; i < ROWS; i++) {
        for (uint8_t j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

/**
 * Checks if a move in the specified column is valid. 
 * @param col uin8_t value of the column
 */
uint8_t isValidMove(uint8_t col)
{
    return board[0][col] == 0;
}

/**
 * Drops a token for the specified player into the given column.
 * @param col uint8_t value of the column
 * @param player uint8_t number of player
 * @return row where token is dropped, or -1 if column is full
 */
int8_t dropToken(uint8_t col, uint8_t player)
{
    for (int8_t i = ROWS - 1; i > 0; i--) {
        if (board[i][col] == 0) {
            board[i][col] = player;
            return i;
        }
    }
    return -1;
}

/**
 * Checks if the specified player has won the game.
 * @param player number of the player
 * @return 1 if the player wins, 0 otherwise
 */
uint8_t checkWin(uint8_t player)
{
    // Check horizontally (3 consecutive tokens in same row)
    for (uint8_t i = 0; i < ROWS; i++) {
        for (uint8_t j = 0; j < COLS - 2; j++) {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player) {
                return 1;
            }
        }
    }
    
    // Check vertically (3 consecutive tokens in the same column)
    for (uint8_t i = 0; i < ROWS - 2; i++) {
        for (uint8_t j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player) {
                return 1;
            }
        }
    }
    
    // Check diagonally (top-left to bottom-right)
    for (uint8_t i = 1; i < ROWS - 2; i++) {
        for (uint8_t j = 0; j < COLS - 2; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player) {
                return 1;
            }
        }
    }

    // Check diagonally (bottom-left to top-right)
    for (uint8_t i = 2; i < ROWS; i++) {
        for (uint8_t j = 0; j < COLS - 2; j++){
            if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player) {
                return 1;
            }
        }
    }

    return 0;
}

/**
 * Returns the value of the cell at the specified row and column.
 * @param row value of the row
 * @param col value of the column
 * @return player number, 0 otherwise
 */
uint8_t getCell(uint8_t row, uint8_t col)
{
    return board[row][col];
}