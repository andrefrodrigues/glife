#include"config.h"
#include"game.h"
int main(int argc,char *argv[]){
    GameConfig* gc = game_config_new_from_cli(argc,argv);
    if(gc!=NULL){

    Game* g = game_new();
    if( !game_parse_board(g,gc)){
        size_t current;
        if(!gc->silent){
            printf("Generation 0:\n");
            game_print_board(g);
        }

        for(current=1; current <= gc->generations && !game_tick(g); current++){
            if(gc->debug){
                printf("Generation %d:\n",current);
                game_print_board(g);
            }
        }
        if(!gc->silent && !gc->debug){
            printf("Generation %d:\n",current);
            game_print_board(g);
        }
    }
    game_config_free(gc);
    game_free(g);
    }
    return 0;
}