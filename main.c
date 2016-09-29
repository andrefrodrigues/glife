#include"config.h"
#include"game.h"
int main(int argc,char *argv[]){
    GameConfig* gc = game_config_new_from_cli(argc,argv);
    if(gc!=NULL){

    Game* g = game_new();
    if( !game_parse_board(g,gc)){
        int current;
        if(!gc->silent){
            printf("Generation 0:\n");
            game_print_board(g);
        }

        for(current=1; current < gc->generations && !game_tick(g); current++){
            if(gc->debug){
                printf("Generation %d:\n",current);
                game_print_board(g);
            }
        }
        if(!gc->silent){
            printf("Generation %d:\n",current);
            game_print_board(g);
        }
    }
    }
    return 0;
}