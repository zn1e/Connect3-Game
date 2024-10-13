/**
 * @file display.c
 * @author Moises Allen Montalbo (mam417)
 * @brief
 */

#include "matrix_display.h"
#include "ledmat.h"
#include "board.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define BLINK_RATE 2

static uint8_t blinkState = 0;
static uint8_t blinkCounter = 0;

void displayInit(void)
{
    ledmat_init();
    pacer_init(PACER_RATE);
}

void displayBoard(uint8_t currentCol, uint8_t currentPlayer, uint8_t blinkOn)
{
    
    blinkCounter++;
    if (blinkCounter >= (PACER_RATE / (2 * BLINK_RATE))) {
        blinkState = !blinkState;
        blinkCounter = 0;
    }

    for (uint8_t col = 0; col < COLS; col++) {
        uint8_t colPattern = 0;

        for (uint8_t row = 0; row < ROWS; row++) {
            uint8_t cell = getCell(row, col);

            if (cell == currentPlayer && blinkOn && blinkState) {
                continue;
            }

            if (cell != 0 || (row == 0 && col == currentCol)) {
                colPattern |= (1 << row);
            }
        }

        ledmat_display_column(colPattern, col);

        pacer_wait();
    }
}

void displayWinner(uint8_t player)
{
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(10);

    if (player == 1) {
        tinygl_text("YOU WIN!");
    } else {
        tinygl_text("YOU LOSE!");
    }
}

