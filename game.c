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
    return  game->board[row*game->cols+col];
}

int game_cell_is_dead(Game *game, size_t row, size_t col){
    return !game->board[row*game->cols+col];
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
    game->board[row*game->cols+col] = 1;
}

void game_cell_set_dead(Game *game, size_t row, size_t col){
    game->board[row*game->cols+col] = 0;
}

//TODO
/*
Regras: 
qualquer celula viva com < 2 vivos morre
qualquer celula viva com 2 ou 3 vivos vive
qualquer celula viva com > 3 vivos morre
qualquer celula com 3 vivos vive
*/

//returns the number of neighbours for the rules
int get_cell_alive_neighbours(game,size_t row, size_t cols){
    
    return 0;
}

int game_tick(Game *game){
    int x,y;
    for(y=0;y<game->rows;y++){
        for(x=0;x<game->cols;x++){
            if(game_cell_is_alive(game,y,x)){
                
            }
            else{

            }
        }
    }

    return 0;
}