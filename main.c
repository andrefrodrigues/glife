#include"config.h"
#include"game.h"
int main(int argc,char *argv[]){
    GameConfig* gc = game_config_new_from_cli(argc,argv);
    if(gc!=NULL){
    printf("%zu\n",game_config_get_generations(gc));
    printf("debug mode is: %d\n",gc->debug);
    printf("silent mode is: %d\n",gc->silent);
    Game* g = game_new();
    game_parse_board(g,gc);
    printf("Rows: %zu\n",g->rows);
    printf("Cols: %zu\n",g->cols);
    }
    return 0;
}