#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "world.h"

struct container* create_world()
{
    struct container* container=calloc(1,sizeof(struct container));
    create_container(container,ROOM,create_room("HALL", "ENTRENCE ROOM"));
    create_container(container,ROOM,create_room("KITCHEN", "COOKING ROOM"));
    create_container(container,ROOM,create_room("BATH ROOM", "BATHROOM ROOM"));
    create_container(container,ROOM,create_room("LIVING ROOM", "LIVING ROOM"));
    set_exits_from_room(container->room, container->next->room, NULL, NULL,container->next->next->next->room);
    set_exits_from_room(container->next->next->room, NULL, container->next->next->next->room, container->next->room,NULL);
    return container;
}

struct container* add_room_to_world(struct container* world, struct room* room)
{
    struct container* container=world;
    while (container!=NULL)
    {
        /*if(strcmp(container->room->name,room->name))
        {
            if(container!=NULL)
            {
                free(container);
            }
            return NULL;
        }*/
        container=container->next;
    }
    create_container(world,ROOM,room);
    return container;
}

struct container* destroy_world(struct container* world)
{
    if(world!=NULL)
    {
        if(world!=NULL)
        {
            destroy_containers(world);
        }
    }
    return NULL;
}

struct room* get_room(struct container* world, char* name)
{
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
    struct container* container=world;
    while(container!=NULL)
    {
        /*if(strcmp(container->room->name,buf))
        {
            return container->room;
        }*/
        container=container->next;
    }
    free(inpu);
    free(buf);
    return NULL;
}
