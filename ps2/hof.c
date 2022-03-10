#include <stdio.h>

#include "hof.h"

int load(struct player list[])
{
    FILE* f=fopen("score","r");
    int size=0;
    if(f==NULL)
    {
        return -1;
    }
    for(size_t i = 0; i < 10; i++)
    {
        fread(&list[i], sizeof list[0], 1, f);
    }
    fclose(f);
    for(int i=0;i<10;i++)
    {
        if(list[i].name!=NULL)
        {
            if(size<0)
            {
                size=0;
            }
            size++;
        }
        //printf("%s\n",list[i].name);
        //printf("%s\t%d\n",list[i].name,list[i].score);
    }
    printf("%s\n",list[0].name);
    return size;
}

bool save(const struct player list[], const int size)
{
    return true;
}

bool add_player(struct player list[], int* size, const struct player player)
{
    return true;
}