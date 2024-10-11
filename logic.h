#ifndef LOGIC_H
#define LOGIC_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef enum game_state {
    START = 0,
    SELECT,
    WAIT,
    DISPLAY, 
    CHECK,
    END
} game_state_t;

typedef enum who_win {
    NOT=0,
    you_win,
    they_win
} who_win_t;

chech_win(game_board);






#endif 