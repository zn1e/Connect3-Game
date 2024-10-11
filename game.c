#include "system.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
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
    who_win_t who_win= NOT;
    char they = 'T'; 
    char you = 'Y';
    char character = '1';
    char game_board[5][7]={{'','','','','','',''},
    {'','','','','','',''},
    {'','','','','','',''},
    {'','','','','','',''},
    {'','','','','','',''}}

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
                display_text_loop("START");
                if (navswitch_push_event_p(NAVSWITCH_PUSH)) { 
                    game_state=SELECT;
            }

                break;
            case SELECT:
                // you chooes 12345:
                //blue isnot light which mean I not get
                if (navswitch_push_event_p (NAVSWITCH_NORTH)){
                    character++;
                    dispaly(character);
                }
                    

                if (navswitch_push_event_p (NAVSWITCH_SOUTH)){
                     character--;
                    dispaly(character);

                }
                   
                if (navswitch_push_event_p (NAVSWITCH_PUSH)){
                    game_state=WAIT;
                }
                    
                
                break;
            
            case WAIT:
                if (they==ir_uart_write_ready_p()){
                    //blue is light which mean I get
                    

                }

                break;
            case DISPLAY:
                //show 2D array
                display_2D(game_board)
                if (navswitch_push_event_p (NAVSWITCH_PUSH)){
                    game_state=CHECK;
                }
                
                break;

            case CHECK:
                //check win?
                who_win=chech_win(game_board);//can get you_win1 or ther_win2 or not win0
                switch(who_win){
                    case NOT:
                        game_state=SELECT;
                        break;
                    case you_win:
                        game_state=END;
                        break;
                    case they_win:
                        game_state=END;
                        break;
                }
                break:

            case END:
                if(who_win==you_win){
                    display('win')
                } else {
                    display('lose')
                }
                if(navswitch_push_event_p (NAVSWITCH_PUSH)){
                    game_state=START;
                }
                break;

         }



    }
}
