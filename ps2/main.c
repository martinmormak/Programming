#include <stdio.h>
#include <stdbool.h>

#include "hof.h"
#include "k.h"
#include "ui.h"

int main()
{
    //game is won
    struct game game = {
        .board = {
            {'A', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', 'A'},
            {'B', ' ', ' ', ' '}
        },
        .score = 0
    };
    is_game_won(game);
    // printf("is won: %d\n", is_game_won(game));

    //another move is possible
    // struct game game = {
    //     .board = {
    //         {'A', 'B', 'C', 'D'},
    //         {'E', 'F', 'G', 'H'},
    //         {'I', 'J', 'K', 'A'},
    //         {'B', 'C', 'D', 'E'}
    //     },
    //     .score = 0
    // };
    is_move_possible(game);
    // printf("is move possible: %d\n", is_move_possible(game));

    //move
    // struct game game = {
    //     .board = {
    //         {'A', 'C', 'C', 'C'},
    //         {'B', 'D', 'D', 'D'},
    //         {'J', 'E', 'E', 'E'},
    //         {'J', 'F', 'F', 'F'}
    //     },
    //     .score = 0
    // };
    bool result = update(&game, 1, 0);
    // printf("%s\n", result ? "true" : "false");

    //write on the screen
    render(game);

    //load from document
    struct player list[10];
    /*int size=load(list);
    printf("size:%d\n",size);
    printf("\nload\n");*/
    struct player hof [2] = {
    {.score=  800, .name="Manager"},
    {.score=  341, .name="Manager"}};
    result = save(hof, 2);
    int size=load(list);
    printf("Ahoj %d\n",size);
    for(int i=0;i<size;i++)
    {
        printf("%s\t%d\n",list[i].name,list[i].score);
    }
    struct player player = {
        .name = "Manager",
        .score = 250
    };
    if(size<0)
    {
        size=0;
    }
    result = add_player(list, &size, player);
    printf("\nadd_player: %s\n", result ? "true" : "false");
    for(int i=0;i<size;i++)
    {
        printf("%s\t%d\n",list[i].name,list[i].score);
    }
    //result = save(list, size);
    printf("%s\n", result ? "true" : "false");
    
    //add letter
    add_random_tile(&game);
    
    //write on the screen
    render(game);
    return 0;
}
