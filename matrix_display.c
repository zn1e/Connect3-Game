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


static uint8_t blinkState = 0;
static uint8_t blinkCounter = 0;

void displayInit(void)
{
    ledmat_init();
    pacer_init(PACER_RATE);
}

void displayBoardTurn(GameState_t* gameState, uint8_t blinkOn)
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

            if (cell == gameState->currentPlayer && blinkOn && blinkState) {
                continue;
            }

            if (cell != 0) {
                colPattern |= (1 << row);
            } else if (row == 0 && col == gameState->currentCol) {
                colPattern |= (1 << row);
            }
        }

        ledmat_display_column(colPattern, col);
        pacer_wait();
    }
}

void displayText(char* text)
{
    tinygl_init(PACER_RATE);
    tinygl_text_speed_set(10);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text(text);

    uint8_t counter = 0;
    int maxCount = 2 * PACER_RATE;

    while (counter < maxCount) {
        pacer_wait();
        tinygl_update();
        counter++;
    }

    clearDisplay();
}

void displayWinner(bool* winner)
{
    if (*winner) {
        displayText("YOU WIN!");
    } else {
        displayText("YOU LOSE!");
    }
}

void clearDisplay(void)
{
    for (uint8_t col = 0; col < COLS; col++) {
        ledmat_display_column(0, col);
    }
}
