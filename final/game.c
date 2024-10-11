#include "system.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "letters.h"
#include "display.h"
#include "logic.h"

int main (void)
{
    system_init ();
    navswitch_init();
    display_init();
    pacer_init(PACER_RATE); 
    ir_uart_init();
    
    game_state_t game_state = START;

    char their = 'T'; 
    char you = 'Y';
    char character = '1';

    while (1)
    {
        pacer_wait();
        navswitch_update(); 
        tinygl_update();
         switch (game_state) {
            case START:
                // tinygl_init (PACER_RATE);//pacer_rate pinlu
                // tinygl_font_set (&font5x7_1);
                // tinygl_text_speed_set (MESSAGE_RATE);//speed per 10 second
                
                // tinygl_text("Halloo");
                display_text("START");
                if (navswitch_push_event_p(NAVSWITCH_PUSH)) { 
                game_state=SELECT;
            }

                break;
            case SELECT:
                // you chooes 12345:
                if (navswitch_push_event_p (NAVSWITCH_NORTH))
                    character++;

                if (navswitch_push_event_p (NAVSWITCH_SOUTH))
                    character--;
                break;
            
            case WAIT:

                break;
            case DISPLAY:

                break;
            case END:

                break;

         }



    }
}
