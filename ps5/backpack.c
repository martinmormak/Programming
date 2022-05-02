#include <stdlib.h>
#include <string.h>

#include "backpack.h"

struct backpack* create_backpack(const int capacity)
{
    struct backpack* backpack=calloc(1,sizeof(struct backpack));
    backpack->capacity=capacity;
    backpack->items=NULL;
    backpack->size=0;
    return backpack;
}

struct backpack* destroy_backpack(struct backpack* backpack)
{
    if(backpack!=NULL)
    {
        if(backpack->items!=NULL)
        {
            destroy_containers(backpack->items);
        }
        free(backpack);
    }
    return NULL;
}

bool add_item_to_backpack(struct backpack* backpack, struct item* item)
{
    create_container(backpack->items,ITEM,item);
    return false;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item)
{
    remove_container(backpack->items,item);
}

struct item* get_item_from_backpack(const struct backpack* backpack, char* name)
{
    struct container* container=backpack->items;
    while(container!=NULL)
    {
        if(strcmp(container->item->name,name))
        {
            return container->item;
        }
        container=container->next;
    }
    return NULL;
}
