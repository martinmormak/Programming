#include <stdio.h>
#include <stdlib.h>

#include "hof.h"

int cmp(const void *p1,const void *p2)
{
    struct player* player1=(struct player*)p1;
    struct player* player2=(struct player*)p2;

    if(player1->score<=player2->score)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int load(struct player list[])
{
    FILE* f=fopen("score","r");
    int size=-1;
    int idx=0;
    //struct player p;
    if(f==NULL)
    {
        return -1;
    }
    while(fscanf(f, "%20s %d", list[idx].name,&list[idx].score) != EOF)
    {
        //printf("%s\n%d\n",list[idx].name,list[idx].score);
        idx++;
    }  
    fclose(f);
    for(int i=0;i<idx;i++)
    {
        if(list[i].name!=NULL)
        {
            if(size<0)
            {
                size=0;
            }
            size++;
        }
    }
    // for(int i=0;i<idx;i++)
    // {
    //     for(int x=0;x<idx-1;x++)
    //     {
    //         if(list[x].score<=list[x+1].score)
    //         {
    //             p.name=list[x].name;
    //             list[x].name=list[x+1].name;
    //             list[x+1].name=p.name;
    //             p.score=list[x].score;
    //             list[x].score=list[x+1].score;
    //             list[x+1].score=p.score;
    //         }
    //     }
    // }
    qsort(list,size,sizeof list[0],cmp);
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