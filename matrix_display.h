/**
 * @file display.h
 * @author Moises Allen Montalbo (mam417), ShunZhi Zhang (szh139)
 * @brief Header file for implementing the display on LED matrix for each microcontrollers.
 * This includes function for initialization, displaying the state of the board on 
 * player's turn, displaying text and winner, and clearing the display.
 */

#ifndef MATRIX_DISPLAY_H
#define MATRIX_DISPLAY_H

#include "system.h"
#include "game.h"

/* Constant for pacer rate. */
#define PACER_RATE 500

/* Constant for blink rate. */
#define BLINK_RATE 2

/**
 * Initializes the LED matrix display and pacer.
 */
void displayInit(void);

/**
 * Displays the current state of the game board on the LED matrix.
 * @param gameState struct containing the game state and player's information
 * @param blinkOn flag for blinking the player's tokens
 */
void displayBoardTurn(GameState_t* gameState, uint8_t blinkOn);

/**
 * Display scrolling text on the LED matrix.
 * @param text string of characters to be displayed
 */
void displayText(char* text);

/**
 * Displays the winner of the game.
 * @param winner player number of the winner
 */
void displayWinner(uint8_t winner);

/**
 * Clears the display of LED matrix.
 */
void clearDisplay(void);

#endif