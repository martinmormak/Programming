#include <stdio.h>
#include <stdbool.h>

#include "hof.h"
#include "k.h"
#include "ui.h"

int main()
{
    //game is won
    // struct game game = {
    //     .board = {
    //         {'A', ' ', ' ', ' '},
    //         {' ', ' ', ' ', ' '},
    //         {' ', ' ', ' ', 'A'},
    //         {'B', ' ', ' ', ' '}
    //     },
    //     .score = 0
    // };
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
    // bool result = update(&game, 1, 0);
    // printf("%s\n", result ? "true" : "false");

    //write on the screen
    // render(game);

    //load from document
    struct player list[10];
    load(list);
    return 0;
}
