#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    FILE* f=fopen(HOF_FILE,"r");
    int size=-1;
    int idx=0;
    if(f==NULL)
    {
        return -1;
    }
    while(fscanf(f, "%s %d", list[idx].name,&list[idx].score) != EOF)
    {
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
    qsort(list,(size_t)size,sizeof list[0],cmp);
    return size;
}

bool save(const struct player list[], const int size)
{
    FILE* f=fopen("score","w");
    struct player p[size];
    if(f==NULL)
    {
        return false;
    }
    for(int i=0;i<size;i++)
    {
        p[i]=list[i];
    }
    qsort(p,(size_t)size,sizeof list[0],cmp);
    for(int i=0;i<size;i++)
    {
        if(i==size-1)
        {
            fprintf(f, "%s %d", p[i].name,p[i].score);
        }
        else
        {
            fprintf(f, "%s %d\n", p[i].name,p[i].score);
        }
    }
    return true;
}

bool add_player(struct player list[], int* size, const struct player player)
{
    bool re=false;
    int s=*size;
    struct player p[s+1];
    for(int i=0;i<s;i++)
    {
        p[i]=list[i];
    }
    p[s]=player;
    for(int i=0;i<s;i++)
    {
        if(list[i].score<=p[s].score)
        {
            re=true;
        }
    }
    qsort(p,(size_t)s+1,sizeof list[0],cmp);
    if(s<10)
    {
        s++;
    }
    printf("%d\n",s);
    for(int i=0;i<s;i++)
    {
        list[i]=p[i];
    }
    *size=s;
    printf("%d\n",re);
    return re;
}