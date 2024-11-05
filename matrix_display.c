/**
 * @file display.c
 * @author Moises Allen Montalbo (mam417)
 * @brief Module for implementing the display on LED matrix for each microcontrollers.
 * This includes function for initialization, displaying the state of the board on 
 * player's turn, displaying text and winner, and clearing the display.
 */

#include "matrix_display.h"
#include "ledmat.h"
#include "board.h"
#include "pacer.h"
#include "tinygl.h"

/* State for blinking effect (on or off). */
static uint8_t blinkState = 0;

/* Counter to manage blinking rate. */
static uint8_t blinkCounter = 0;

/**
 * Initializes the LED matrix display and pacer.
 */
void displayInit(void)
{
    ledmat_init();
    pacer_init(PACER_RATE);
}

/**
 * Displays the current state of the game board on the LED matrix.
 * @param gameState struct containing the game state and player's information
 * @param blinkOn flag for blinking the player's tokens
 */
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
            } 

            if (col == gameState->currentCol && blinkOn && gameState->playerTurn) {
                colPattern |= (1<< 0);
            }
        }

        ledmat_display_column(colPattern, col);
        pacer_wait();
    }
}

/**
 * Display scrolling text on the LED matrix.
 * @param text string of characters to be displayed
 */
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

/**
 * Displays the winner of the game.
 * @param winner player number of the winner
 */
void displayWinner(uint8_t winner)
{
    if (winner == 1) {
        displayText("P1 WINS!");
    } else {
        displayText("P2 WINS!");
    }
}

/**
 * Clears the display of LED matrix.
 */
void clearDisplay(void)
{
    for (uint8_t col = 0; col < COLS; col++) {
        ledmat_display_column(0, col);
    }
}
