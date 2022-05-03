#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "world.h"

struct container* create_world()
{
    struct container* container_room=calloc(1,sizeof(struct container));
    struct container* container_item=calloc(1,sizeof(struct container));
    /*create_container(container_room,ROOM,create_room("HALL", "ENTRENCE ROOM"));
    create_container(container_room,ROOM,create_room("KITCHEN", "COOKING ROOM"));
    create_container(container_room,ROOM,create_room("BATH ROOM", "BATHROOM ROOM"));
    create_container(container_room,ROOM,create_room("LIVING ROOM", "LIVING ROOM"));
    set_exits_from_room(container_room->room, container_room->next->room, NULL, NULL,container_room->next->next->next->room);
    set_exits_from_room(container_room->next->next->room, NULL, container_room->next->next->next->room, container_room->next->room,NULL);*/
    
    create_container(container_room,ROOM,create_room("ROOM 1", "room"));
    create_container(container_room,ROOM,create_room("ROOM 2", "room"));
    create_container(container_room,ROOM,create_room("ROOM 3", "room"));
    create_container(container_room,ROOM,create_room("ROOM 4", "room"));
    create_container(container_room,ROOM,create_room("ROOM 5", "room"));
    create_container(container_room,ROOM,create_room("ROOM 6", "room"));
    create_container(container_room,ROOM,create_room("ROOM 7", "room"));
    create_container(container_room,ROOM,create_room("ROOM 8", "room"));
    create_container(container_room,ROOM,create_room("ROOM 9", "room"));
    create_container(container_room,ROOM,create_room("ROOM 10", "room"));
    create_container(container_room,ROOM,create_room("ROOM 11", "room"));
    create_container(container_room,ROOM,create_room("ROOM 12", "room"));
    create_container(container_room,ROOM,create_room("ROOM 13", "room"));
    create_container(container_room,ROOM,create_room("ROOM 14", "room"));
    create_container(container_room,ROOM,create_room("ROOM 15", "room"));
    create_container(container_item,ITEM,create_item("ITEM 1", "item",NONE));
    create_container(container_item,ITEM,create_item("ITEM 2", "item",MOVABLE));
    create_container(container_item,ITEM,create_item("ITEM 3", "item",USABLE));
    create_container(container_item,ITEM,create_item("ITEM 4", "item",EXAMINABLE));
    create_container(container_item,ITEM,create_item("ITEM 5", "item",OPENABLE));
    //1
    add_item_to_room(container_room->room,container_item->item);
    add_item_to_room(container_room->room,container_item->next->item);
    add_item_to_room(container_room->room,container_item->next->next->item);
    add_item_to_room(container_room->room,container_item->next->next->next->item);
    add_item_to_room(container_room->room,container_item->next->next->next->next->item);
    //2
    add_item_to_room(container_room->next->room,container_item->item);
    add_item_to_room(container_room->next->room,container_item->next->item);
    add_item_to_room(container_room->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->room,container_item->next->next->next->next->item);
    //3
    add_item_to_room(container_room->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->room,container_item->next->next->next->next->item);
    //4
    add_item_to_room(container_room->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->room,container_item->next->next->next->next->item);
    //5
    add_item_to_room(container_room->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->room,container_item->next->next->next->next->item);
    //6
    add_item_to_room(container_room->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //7
    add_item_to_room(container_room->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //8
    add_item_to_room(container_room->next->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //9
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //10
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //11
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //12
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //13
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //14
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    //14
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->item);
    add_item_to_room(container_room->next->next->next->next->next->next->next->next->next->next->next->next->next->next->room,container_item->next->next->next->next->item);
    return container_room;
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
    return create_container(world,ROOM,room);
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
