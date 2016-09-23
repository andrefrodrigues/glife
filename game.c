#include"game.h"
#include<stdio.h>
#include<assert.h>

#define BUFFER_SIZE 100
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
    if(config==NULL||game==NULL)
        return 1;
    char buffer[BUFFER_SIZE];
    size_t rows,cols;
    fscanf(config->input_file,"Rows:%zu\n",&rows);
    fscanf(config->input_file,"Cols:%zu\n",&cols);
    game->rows = rows;
    game->cols=cols;
    game->board = malloc(rows*cols*sizeof(char));
    if(game->board==NULL)
        return 1;
       int i=0;
       char c;
       while((c=getc(config->input_file))!=EOF){
           if(c!='\n'){
            game->board[i]=c=='#'?1:0;
            i++;
           }
       } 
    return 0;
}

void game_print_board(Game *game){
    int i;
    if(game!=NULL){
        for(i=0;i<game->rows*game->cols;i++){
            if(i%game->cols==0)
                putchar('\n');
                if(game->board[i])
                    putchar('#');
                    else
                    putchar('.');
        }
        putchar('\n');
    }
}

void game_cell_set_alive(Game *game, size_t row, size_t col){

}

void game_cell_set_dead(Game *game, size_t row, size_t col){

}

int game_tick(Game *game){
    return 0;
}