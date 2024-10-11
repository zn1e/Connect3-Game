#include "logic.h"
#include <stdio.h>
#include <stdint.h>
#define ROW 5
#define COL 4
#define  4
void chech_win(game_board){
    for(size_t row=0; row<ROW;row++){ //check column
        for(size_t col;col<= 2;col++){
            if (game_board[row][col] != ' ' &&
                game_board[row][col] == game_board[row][col+1] &&
                game_board[row][col+1] == game_board[row][col+2] &&
                game_board[row][col+2] == game_board[row][col+3]) {
                    if(game_board[row][col]=='Y'){
                        return you_win;
                    } else {
                        return they_win;
                    }
            } 
                
        }
        
    }
    for (size_t col = 0; col < COL; col++) { //check row
        for (size_t row = 0; row <=2; row++) {
            if (game_board[row][col] != ' ' &&
                game_board[row][col] == game_board[row+1][col] &&
                game_board[row+1][col] == game_board[row+2][col] &&
                game_board[row+2][col] == game_board[row+3][col]) {
                if(game_board[row][col]=='Y'){
                        return you_win;
                    } else {
                        return they_win;
                    }
            }
        }
    }
    for (size_t row = 0; row <= ROWS - WIN_CONDITION; row++) { //left-top to right-botton
        for (size_t col = 0; col <= COLS - WIN_CONDITION; col++) {
            if (game_board[row][col] != ' ' &&
                game_board[row][col] == game_board[row+1][col+1] &&
                game_board[row+1][col+1] == game_board[row+2][col+2] &&
                game_board[row+2][col+2] == game_board[row+3][col+3]) {
                if(game_board[row][col]=='Y'){
                        return you_win;
                    } else {
                        return they_win;
                    }
            }
        }
    }


    for (size_t row = 0; row <= ROWS - WIN_CONDITION; row++) {  //right-top to left-botton
        for (size_t col = WIN_CONDITION - 1; col < COLS; col++) {
            if (game_board[row][col] != ' ' &&
                game_board[row][col] == game_board[row+1][col-1] &&
                game_board[row+1][col-1] == game_board[row+2][col-2] &&
                game_board[row+2][col-2] == game_board[row+3][col-3]) {
                if(game_board[row][col]=='Y'){
                        return you_win;
                    } else {
                        return they_win;
                    }
            }
        }
    }


    return NOT;//not winer
}