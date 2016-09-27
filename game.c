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
    assert(row*game->cols+col < game->rows*game->cols);
    return  game->board[row*game->cols+col];
}

int game_cell_is_dead(Game *game, size_t row, size_t col){
    assert(row*game->cols+col < game->rows*game->cols);
    return !game->board[row*game->cols+col];
}

Game *game_new(void){
    Game * g = malloc(sizeof(Game));
    return g;
}

int game_parse_board(Game *game, GameConfig *config){
    if(config==NULL||game==NULL)
        return 1;
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
            if(i%game->cols==0&&i!=0)
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


/*
Regras: 
qualquer celula viva com < 2 vivos morre
qualquer celula viva com 2 ou 3 vivos vive
qualquer celula viva com > 3 vivos morre
qualquer celula com 3 vivos vive
*/ 

int get_cell_alive_neighbours(Game *game,int row, int col){
    int count=0,x,y,currentRow,currentCol;

    for(y=row-1;y<=row+1;y++){
        currentRow=y;
        if(y<0)
          currentRow=game->rows-1;
        else if(currentRow > game->rows-1)
             currentRow=0;
        for(x=col-1;x<=col+1;x++){
            currentCol=x;
            if(x<0)
                currentCol= game->cols-1;
            else if(currentCol > game->cols-1)
                currentCol=0;
            if(game_cell_is_alive(game,currentRow,currentCol)){
                if(currentCol!=col || currentRow!=row){
                    count++;
                }
            }
        }
    }
    return count;
}

int game_tick(Game *game){
    if(!game)
        return 1;
    if(!game->board)
        return 1;
    int x,y,i;
    size_t board_size =game->rows*game->cols;
    char neighbours[board_size];
    for(y=0;y<game->rows;y++){
        for(x=0;x<game->cols;x++){
            neighbours[y*game->cols+x] = get_cell_alive_neighbours(game,y,x);
         
        }
    }

    for(i=0;i<board_size;i++){
        if(i%game->cols==0&&i!=0)
            printf("\n");
        printf("%d",neighbours[i]);
        if(neighbours[i]<2 || neighbours[i]>3)
            game->board[i]=0;
        else
            game->board[i]=1;
    }
    printf("\n");
    return 0;
}