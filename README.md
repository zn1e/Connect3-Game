# Connect3 Game
# Author: Moises Allen Montalbo (mam417), ShunZhi Zhang (szh139)

## Overview
**Connect3** is a two-player game where players take turns dropping tokens into a grid using a navigation switch. The goal is to connect three tokens horizontally, vertically, or diagonally to win. The game is played using two UCFK4, with IR communication to handle player moves and an LED matrix to display the game board. 
>*Note: Only **6** rows are used in the game. The first row is for selecting the column for the token to be dropped.*


## How to Play

### Setup
1. **Power on both microcontrollers**: Plug the microcontrollers on USB port.
2. **Booting the setup**: Locate the directory of the file. Open the terminal from the directory and run `sudo make program` for both microcontrollers. Make sure all the utils used are within the higher hierarchy of the file.
3. **Player Order**: The game automatically determines which player goes first using IR communication. The LED matrix displays `WAITING` whenever the other player is taking a turn.

### Controls
- **Left (NAVSWITCH_WEST)**: Move the selected column left.
- **Right (NAVSWITCH_EAST)**: Move the selected column right.
- **Down (NAVSWITCH_SOUTH)**: Drop the token into the selected column.

### Objective
Connect three tokens in a row either:
- **Horizontally**
- **Vertically**
- **Diagonally**

### Game Flow
1. **Player 1's Turn**: 
   - Use the navigation switch to select a column.
   - Press the navigation switch down to drop a token.
   - The move is sent to Player 2 via IR communication.
   
2. **Player 2's Turn**:
   - After receiving Player 1's move, Player 2 selects a column and drops their token.
   
3. Continue alternating turns until a player wins by connecting three tokens, or the grid is full.

### Winning the Game
- A player wins by connecting three tokens in a row (horizontally, vertically, or diagonally).
- The LED matrix will display a message:
  - Player 1 wins: `P1 WINS!`
  - Player 2 wins: `P2 WINS!`

### Resetting the Game
Press the `S2` switch on both microcontrollers to reset the game.
