#define _POSIX_C_SOURCE 2
#include"config.h"
#include<unistd.h>
#define ARGUMENTS "dsn:"
#define DEFAULT_ITERATIONS 20

void game_config_free(GameConfig *config){
    fclose(config->input_file);
    free(config);
}

size_t game_config_get_generations(GameConfig *config){
    return config->generations;
}

GameConfig *game_config_new_from_cli(int argc, char *argv[]){
    int c;
    GameConfig* gc = malloc(sizeof(GameConfig));
    if(gc==NULL)
        return gc;
        gc->generations = DEFAULT_ITERATIONS;
    while ((c =getopt(argc,argv,ARGUMENTS))!=-1){
        switch(c){
            case 'd':
                gc->debug=1;
            break;
            case 's':
                gc->silent=1;
            break;
            case'n':
                if(optarg!=NULL)
                    gc->generations = atoi(optarg);
            break;
        }
    }
    if(gc->debug&&gc->silent){
        printf("Cannot use both -n and -s\n");
        exit(-1);
    }
    int last = optind;
    if(last<argc){
        FILE* f = fopen(argv[last],"r");
        if(f==NULL){
            printf("Error opening file %s\n", argv[last]);
            exit(-1);
        }
        gc->input_file = f;
    }
    else{
        printf("No file input\n");
        exit(-1);
    }
    return gc;
}