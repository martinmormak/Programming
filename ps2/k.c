#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "k.h"

void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}

bool is_game_won(const struct game game)
{
    for(int y=0;y<SIZE;y++)
    {
        for(int x=0;x<SIZE;x++)
        {
            if(game.board[y][x]=='K')
            {
                return true;
            }
        }
    }
    return false;
}

bool is_move_possible(const struct game game)
{
    for(int y=0;y<SIZE;y++)
    {
        for(int x=0;x<SIZE;x++)
        {
            if(x<SIZE-1)
            {
                if(game.board[y][x]==game.board[y][x+1])
                {
                    return true;
                }
            }
            if(y<SIZE-1)
            {
                if(game.board[y][x]==game.board[y+1][x])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool update(struct game *game, int dy, int dx)
{
    if(dy!=0&&dx!=0)
    {
        return false;
    }
    if(dy==0&&dx==0)
    {
        return false;
    }
    struct game g;
    for(int y=0;y<SIZE;y++)
    {
        for(int x=0;x<SIZE;x++)
        {
            g.board[y][x]=game->board[y][x];
        }
    }
    switch(dy)
    {
        case -1:
        {
            for(int a=0;a<SIZE;a++)
            {
                for(int y=SIZE-1;y>0;y--)
                {
                    for(int x=0;x<SIZE;x++)
                    {
                        if(game->board[y-1][x]<'A'||game->board[y-1][x]>'K')
                        {
                            game->board[y-1][x]=game->board[y][x];
                            game->board[y][x]=' ';
                        }
                    }
                }
            }
            for(int y=0;y<SIZE-1;y++)
            {
                for(int x=0;x<SIZE;x++)
                {
                    if(game->board[y][x]==game->board[y+1][x]&&game->board[y][x]!=' ')
                    {
                        game->board[y][x]++;
                        game->board[y+1][x]=' ';
                        game->score=game->score+(int)pow(2,game->board[y][x]-'A'+1);
                    }
                }
            }
            for(int a=0;a<SIZE;a++)
            {
                for(int y=SIZE-1;y>0;y--)
                {
                    for(int x=0;x<SIZE;x++)
                    {
                        if(game->board[y-1][x]<'A'||game->board[y-1][x]>'K')
                        {
                            game->board[y-1][x]=game->board[y][x];
                            game->board[y][x]=' ';
                        }
                    }
                }
            }
            break;
        }
        case 1:
        {
            for(int a=0;a<SIZE;a++)
            {
                for(int y=0;y<SIZE-1;y++)
                {
                    for(int x=0;x<SIZE;x++)
                    {
                        if(game->board[y+1][x]<'A'||game->board[y+1][x]>'K')
                        {
                            game->board[y+1][x]=game->board[y][x];
                            game->board[y][x]=' ';
                        }
                    }
                }
            }
            for(int y=SIZE-1;y>0;y--)
            {
                for(int x=0;x<SIZE;x++)
                {
                    if(game->board[y][x]==game->board[y-1][x]&&game->board[y][x]!=' ')
                    {
                        game->board[y][x]++;
                        game->board[y-1][x]=' ';
                        game->score=game->score+(int)pow(2,game->board[y][x]-'A'+1);
                    }
                }
            }
            for(int a=0;a<SIZE;a++)
            {
                for(int y=0;y<SIZE-1;y++)
                {
                    for(int x=0;x<SIZE;x++)
                    {
                        if(game->board[y+1][x]<'A'||game->board[y+1][x]>'K')
                        {
                            game->board[y+1][x]=game->board[y][x];
                            game->board[y][x]=' ';
                        }
                    }
                }
            }
            break;
        }
    }
    switch(dx)
    {
        case -1:
        {
            for(int a=0;a<SIZE;a++)
            {
                for(int y=0;y<SIZE;y++)
                {
                    for(int x=SIZE-1;x>0;x--)
                    {
                        if(game->board[y][x-1]<'A'||game->board[y][x-1]>'K')
                        {
                            game->board[y][x-1]=game->board[y][x];
                            game->board[y][x]=' ';
                        }
                    }
                }
            }
            for(int y=0;y<SIZE;y++)
            {
                for(int x=0;x<SIZE-1;x++)
                {
                    if(game->board[y][x]==game->board[y][x+1])
                    {
                        game->board[y][x]++;
                        game->board[y][x+1]=' ';
                        game->score=game->score+(int)pow(2,game->board[y][x]-'A'+1);
                    }
                }
            }
            for(int a=0;a<SIZE;a++)
            {
                for(int y=0;y<SIZE;y++)
                {
                    for(int x=SIZE-1;x>0;x--)
                    {
                        if(game->board[y][x-1]<'A'||game->board[y][x-1]>'K')
                        {
                            game->board[y][x-1]=game->board[y][x];
                            game->board[y][x]=' ';
                        }
                    }
                }
            }
            break;
        }
        case 1:
        {
            for(int a=0;a<SIZE;a++)
            {
                for(int y=0;y<SIZE;y++)
                {
                    for(int x=0;x<SIZE-1;x++)
                    {
                        if(game->board[y][x+1]<'A'||game->board[y][x+1]>'K')
                        {
                            game->board[y][x+1]=game->board[y][x];
                            game->board[y][x]=' ';
                        }
                    }
                }
            }
            for(int y=0;y<SIZE;y++)
            {
                for(int x=SIZE-1;x>0;x--)
                {
                    if(game->board[y][x]==game->board[y][x-1])
                    {
                        game->board[y][x]++;
                        game->board[y][x-1]=' ';
                        game->score=game->score+(int)pow(2,game->board[y][x]-'A'+1);
                    }
                }
            }
            for(int a=0;a<SIZE;a++)
            {
                for(int y=0;y<SIZE;y++)
                {
                    for(int x=0;x<SIZE-1;x++)
                    {
                        if(game->board[y][x+1]<'A'||game->board[y][x+1]>'K')
                        {
                            game->board[y][x+1]=game->board[y][x];
                            game->board[y][x]=' ';
                        }
                    }
                }
            }
            break;
        }
    }
    for(int y=0;y<SIZE;y++)
    {
        for(int x=0;x<SIZE;x++)
        {
            if(g.board[y][x]!=game->board[y][x])
            {
                return true;
            }
        }
    }
    return false;
}
