#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "container.h"

struct container* create_container(struct container* first, enum container_type type, void* entry)
{
    if(entry==NULL)
    {
        return NULL;
    }
    if(type!=ROOM&&type!=COMMAND&&type!=ITEM&&type!=TEXT)
    {
        return NULL;
    }
    if(first!=NULL)
    {
        if(first->type!=type)
        {
            return NULL;
        }
    }
    struct container* container=calloc(1,sizeof(struct container));
    container->type=type;
    container->next=NULL;
    if(type==ROOM)
    {
        container->room=entry;
    }
    else if(type==COMMAND)
    {
        container->command=entry;
    }
    else if(type==ITEM)
    {
        container->item=entry;
    }
    else if(type==TEXT)
    {
        container->text=entry;
    }
    if(first==NULL)
    {
        return container;
    }
    struct container* ptr=first;
    if(first==NULL)
    {
        first=container;
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=container;
    return container;
}

struct container* destroy_containers(struct container* first)
{
    struct container* ptr=first;
    struct container* prev=ptr;
    while(ptr!=NULL)
    {
        prev=ptr->next;
        if(ptr->type==ROOM)
        {
            destroy_room(ptr->room);
        }
        else if(ptr->type==COMMAND)
        {
            destroy_command(ptr->command);
        }
        else if(ptr->type==ITEM)
        {
            destroy_item(ptr->item);
        }
        else if(ptr->type==TEXT)
        {
            free(ptr->text);
        }
        ptr=prev;
    }
    if(ptr!=NULL)
    {
        free(ptr);
    }
    if(prev!=NULL)
    {
        free(prev);
    }
    return NULL;
}

void* get_from_container_by_name(struct container *first, const char *name)
{
    if(first==NULL)
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
    nam[a+1]='\0';
    struct container* ptr=first;
    while(ptr!=NULL)
    {
        if(ptr->type==ROOM)
        {
            if(strcmp(ptr->room->name,nam))
            {
                free(nam);
                free(inpu);
                return ptr;
            }
        }
        else if(ptr->type==COMMAND)
        {
            if(strcmp(ptr->command->name,nam))
            {
                free(nam);
                free(inpu);
                return ptr;
            }
        }
        else if(ptr->type==ITEM)
        {
            if(strcmp(ptr->item->name,nam))
            {
                free(nam);
                free(inpu);
                return ptr;
            }
        }
        else if(ptr->type==TEXT)
        {
            if(strcmp(ptr->text,nam))
            {
                free(nam);
                free(inpu);
                return ptr;
            }
        }
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        free(ptr);
    }
    if(nam!=NULL)
    {
        free(nam);
    }
    if(inpu!=NULL)
    {
        free(inpu);
    }
    return NULL;
}

struct container* remove_container(struct container *first, void *entry)
{
    if(first==NULL)
    {
        return NULL;
    }
    if(entry==NULL)
    {
        return first;
    }
    struct container* ptr=first;
    if(ptr->type==ROOM)
    {
        if(ptr->room==entry)
        {
            return ptr->next;
        }
    }
    else if(ptr->type==COMMAND)
    {
        if(ptr->command==entry)
        {
            return ptr->next;
        }
    }
    else if(ptr->type==ITEM)
    {
        if(ptr->item==entry)
        {
            return ptr->next;
        }
    }
    else if(ptr->type==TEXT)
    {
        if(ptr->text==entry)
        {
            return ptr->next;
        }
    }
    struct container* prev=ptr;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
        if(ptr->type==ROOM)
        {
            if(ptr->room==entry)
            {
                prev->next=ptr->next;
                /*if(ptr!=NULL)
                {
                    free(ptr);
                }
                if(prev!=NULL)
                {
                    free(prev);
                }*/
                return first;
            }
        }
        else if(ptr->type==COMMAND)
        {
            if(ptr->command==entry)
            {
                prev->next=ptr->next;
                /*if(ptr!=NULL)
                {
                    free(ptr);
                }
                if(prev!=NULL)
                {
                    free(prev);
                }*/
                return first;
            }
        }
        else if(ptr->type==ITEM)
        {
            if(ptr->item==entry)
            {
                prev->next=ptr->next;
                /*if(ptr!=NULL)
                {
                    free(ptr);
                }
                if(prev!=NULL)
                {
                    free(prev);
                }*/
                return first;
            }
        }
        else if(ptr->type==TEXT)
        {
            if(ptr->text==entry)
            {
                prev->next=ptr->next;
                /*if(ptr!=NULL)
                {
                    free(ptr);
                }
                if(prev!=NULL)
                {
                    free(prev);
                }*/
                return first;
            }
        }
    }
    /*if(ptr!=NULL)
    {
        free(ptr);
    }
    if(prev!=NULL)
    {
        free(prev);
    }*/
    return first;
}
