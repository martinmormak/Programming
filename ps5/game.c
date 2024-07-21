#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "game.h"
#include "world.h"

void play_game(struct game* game)
{
    struct container* container=calloc(1,sizeof(struct container));
    game->state=RESTART;
    char bfr[INPUT_BUFFER_SIZE+1];
    while(game->state==PLAYING)
    {
        scanf("%s",bfr);
    }
    free(container);
}

struct game* create_game()
{
    srand((unsigned int)time(0)!=REG_NOMATCH);
    struct game* game=calloc(1,sizeof(struct game));
    game->state=PLAYING;
    game->parser=create_parser();
    game->world=create_world();
    game->current_room=game->world->room;
    int a=rand()%10+1;
    game->backpack=create_backpack(a);
    return game;
}

struct game* destroy_game(struct game* game)
{
    if(game!=NULL)
    {
        if(game->world!=NULL)
        {
            destroy_world(game->world);
        }
        if(game->parser!=NULL)
        {
            destroy_parser(game->parser);
        }
        if(game->current_room!=NULL)
        {
            destroy_room(game->current_room);
        }
        if(game->backpack!=NULL)
        {
            destroy_backpack(game->backpack);
        }
        free(game);
    }
    return NULL;
}

void execute_command(struct game* game, struct command* command)
{
    if(game==NULL||command==NULL)
    {
        return;
    }if(game==NULL||command==NULL)
    {
        return;
    }
    if(regexec(&command->preg,"KONIEC",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"QUIT",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"EXIT",0,NULL,0)!=REG_NOMATCH)
    {
        game->state=GAMEOVER;
    }
    else if(regexec(&command->preg,"SEVER",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"S",0,NULL,0)!=REG_NOMATCH)
    {
        if(game->current_room->north!=NULL)
        {
            game->current_room=game->current_room->north;
        }
        else
        {
            printf("Na severe nie je žiadna miestnosť.\n");
        }
    }
    else if(regexec(&command->preg,"JUH",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"J",0,NULL,0)!=REG_NOMATCH)
    {
        if(game->current_room->south!=NULL)
        {
            game->current_room=game->current_room->south;
        }
        else
        {
            printf("Na juhu nie je žiadna miestnosť.\n");
        }
    }
    else if(regexec(&command->preg,"VYCHOD",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"V",0,NULL,0)!=REG_NOMATCH)
    {
        if(game->current_room->east!=NULL)
        {
            game->current_room=game->current_room->east;
        }
        else
        {
            printf("Na východe nie je žiadna miestnosť.\n");
        }
    }
    else if(regexec(&command->preg,"ZAPAD",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"Z",0,NULL,0)!=REG_NOMATCH)
    {
        if(game->current_room->west!=NULL)
        {
            game->current_room=game->current_room->west;
        }
        else
        {
            printf("Na zapade nie je žiadna miestnosť.\n");
        }
    }
    else if(regexec(&command->preg,"ROZHLIADNI SA",0,NULL,0)!=REG_NOMATCH)
    {
        show_room(game->current_room);
    }
    else if(regexec(&command->preg,"PRIKAZY",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"HELP",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"POMOC",0,NULL,0)!=REG_NOMATCH)
    {
        struct container* ptr1=game->parser->commands;
        while(ptr1!=NULL)
        {
            printf("%s\t%s\n",ptr1->command->name,ptr1->command->description);
            ptr1=ptr1->next;
        }
        free(ptr1);
    }
    else if(regexec(&command->preg,"VERZIA",0,NULL,0)!=REG_NOMATCH)
    {
        printf("Verzia hry: 0.0.1\n Autor:\nmeno: Martin Mormák\ne-mail: martin.mormak@student.tuke.sk\n");
    }
    else if(regexec(&command->preg,"RESTART",0,NULL,0)!=REG_NOMATCH)
    {
        game->state=RESTART;
    }
    else if(regexec(&command->preg,"O HRE",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"ABOUT",0,NULL,0)!=REG_NOMATCH)
    {
        printf("Kde bolo tam bolo, študenti TUKE dostali na predmete PVJC problemset 5 kde bolo potrebné vytvoriť advanturu.\n");
    }
    else if(regexec(&command->preg,"VEZMI",0,NULL,0)!=REG_NOMATCH)
    {
    }
    else if(regexec(&command->preg,"POLOZ",0,NULL,0)!=REG_NOMATCH)
    {
    }
    else if(regexec(&command->preg,"INVENTAR",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"I",0,NULL,0)!=REG_NOMATCH)
    {
    }
    else if(regexec(&command->preg,"POUZI",0,NULL,0)!=REG_NOMATCH)
    {
    }
    else if(regexec(&command->preg,"PRESKUMAJ",0,NULL,0)!=REG_NOMATCH)
    {
    }
    else if(regexec(&command->preg,"NAHRAJ",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"LOAD",0,NULL,0)!=REG_NOMATCH)
    {
    }
    else if(regexec(&command->preg,"ULOZ",0,NULL,0)!=REG_NOMATCH||regexec(&command->preg,"SAVE",0,NULL,0)!=REG_NOMATCH)
    {
    }
    else
    {
        printf("Nenašiel som zadaný príkaz\n");
    }
}
