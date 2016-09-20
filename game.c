#include"game.h"

void game_free(Game *game){
    if(game->board!=NULL)
        free(game->board);
    free(game);
}

int game_cell_is_alive(Game *game, size_t row, size_t col){
    return 0;
}

int game_cell_is_dead(Game *game, size_t row, size_t col){
    return 0;
}

Game *game_new(void){
    Game * g = malloc(sizeof(Game));
    return g;
}

int game_parse_board(Game *game, GameConfig *config){

    return 0;
}

void game_print_board(Game *game){

}

void game_cell_set_alive(Game *game, size_t row, size_t col){

}

void game_cell_set_dead(Game *game, size_t row, size_t col){

}

int game_tick(Game *game){
    return 0;
}