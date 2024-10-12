/**
 * @file board.c
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#include "board.h"

static uint8_t board[ROWS][COLS];

void boardInit(void)
{
    for (uint8_t i = 0; i < ROWS; i++) {
        for (uint8_t j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

uint8_t isValidMove(uint8_t col)
{
    return board[0][col] == 0;
}

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

uint8_t checkWin(uint8_t player)
{
    for (uint8_t i = 0; i < ROWS; i++) {
        for (uint8_t j = 0; j < COLS - 2; j++) {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player) {
                return 1;
            }
        }
    }
    
    for (uint8_t i = 0; i < ROWS - 2; i++) {
        for (uint8_t j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player) {
                return 1;
            }
        }
    }
    
    for (uint8_t i = 1; i < ROWS - 2; i++) {
        for (uint8_t j = 0; j < COLS - 2; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player) {
                return 1;
            }
        }
    }

    for (uint8_t i = 2; i < ROWS; i++) {
        for (uint8_t j = 0; j < COLS - 2; j++){
            if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player) {
                return 1;
            }
        }
    }

    return 0;
}

uint8_t getCell(uint8_t row, uint8_t col)
{
    return board[row][col];
}