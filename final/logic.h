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







#endif 