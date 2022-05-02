#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "room.h"

struct room* create_room(char *name, char *description)
{
    if(name==NULL||description==NULL)
    {
        return NULL;
    }
    char* inpu=(char*)calloc(1,strlen(name)+1);
    memcpy(inpu,name,strlen(name));
    for(int i=0;i<strlen(name);i++)
    {
        inpu[i]=(char)toupper(name[i]);
    }
    //printf("%s\n",inpu);
    int a=0;
    while(inpu[a]==' ')
    {
        a++;
    }
    char bfr='a';
    char* buf=(char*)calloc(1,strlen(inpu)+1);
    for(a=a;a<strlen(inpu);a++)
    {
        if(bfr==' '&&inpu[a]==' ')
        {}
        else
        {
            buf[strlen(buf)]=inpu[a];
            buf[strlen(buf)]='\0';
        }
        bfr=inpu[a];
    }
    a=(int)strlen(buf)-1;
    while(buf[a]==' ')
    {
        a--;
    }
    buf[a+1]='\0';
    struct room* room=calloc(1,sizeof(struct room));
    room->name=buf;
    room->description=description;
    free(inpu);
    free(buf);
    return room;
}

struct room* destroy_room(struct room* room)
{
    if(room!=NULL)
    {
        if(room->name!=NULL)
        {
            //free(room->name);
            room->name=NULL;
        }
        if(room->description!=NULL)
        {
            //free(room->description);
            room->description=NULL;
        }
        if(room->north!=NULL)
        {
            room->north->south=NULL;
        }
        if(room->south!=NULL)
        {
            room->south->north=NULL;
        }
        if(room->east!=NULL)
        {
            room->east->west=NULL;
        }
        if(room->west!=NULL)
        {
            room->west->east=NULL;
        }
        destroy_containers(room->items);
        free(room);
    }
    return NULL;
}

void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west)
{
    if(room!=NULL)
    {
        room->north=north;
        if(north!=NULL)
        {
            north->south=room;
        }
        room->south=south;
        if(south!=NULL)
        {
            south->north=room;
        }
        room->east=east;
        if(east!=NULL)
        {
            east->west=room;
        }
        room->west=west;
        if(west!=NULL)
        {
            west->east=room;
        }
    }
}

void show_room(const struct room* room)
{
    printf("Nazhadzas sa v %s\n",room->description);
    if(room->north!=NULL||room->south!=NULL||room->east!=NULL||room->west!=NULL)
    {
        printf("Mozne vychody z miesnosti:");
        if(room->north!=NULL)
        {
            printf("\tsever\n");
        }
        if(room->south!=NULL)
        {
            printf("\tjuh\n");
        }
        if(room->east!=NULL)
        {
            printf("\tvýchod\n");
        }
        if(room->west!=NULL)
        {
            printf("\tzápad\n");
        }
    }
    struct container* ptr=room->items;
    if(ptr!=NULL)
    {
        printf("Vidíš:\n");
    }
    while(ptr!=NULL)
    {
        printf("\t%s\n",ptr->item->name);
        ptr=ptr->next;
    }
    free(ptr);
}

void delete_item_from_room(struct room* room, struct item* item)
{
    if(room==NULL)
    {
        return;
    }
    remove_container(room->items,item);
}

void add_item_to_room(struct room* room, struct item* item)
{
    if(room==NULL)
    {
        return;
    }
    create_container(room->items,ITEM,item);
}

struct item* get_item_from_room(const struct room* room, const char* name)
{
    if(room!=NULL)
    {
        return NULL;
    }
    char* inpu=(char*)calloc(1,strlen(name)+1);
    memcpy(inpu,name,strlen(name));
    for(int i=0;i<strlen(name);i++)
    {
        inpu[i]=(char)toupper(name[i]);
        inpu[i]='\0';
    }
    //printf("%s\n",inpu);
    int a=0;
    while(inpu[a]==' ')
    {
        a++;
    }
    char bfr='a';
    char* nam=(char*)calloc(1,strlen(inpu)+1);
    for(a=a;a<strlen(inpu);a++)
    {
        if(bfr==' '&&inpu[a]==' ')
        {}
        else
        {
            nam[strlen(nam)]=inpu[a];
            nam[strlen(nam)]='\0';
        }
        bfr=inpu[a];
    }
    a=(int)strlen(nam)-1;
    while(nam[a]==' ')
    {
        a--;
    }
    nam[a+1]='\0';struct container* ptr=room->items;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->item->name,nam))
        {
            free(nam);
            free(inpu);
            return ptr->item;
        }
        ptr=ptr->next;
    }
    free(ptr);
    free(inpu);
    free(nam);
    return NULL;
}
