#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "item.h"

struct item* create_item(char* name, char* description, unsigned int properties)
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
    struct item* item=calloc(1,sizeof(struct item));
    item->name=buf;
    item->description=description;
    item->properties=properties;
    return item;
}

struct item* destroy_item(struct item* item)
{
    if(item!=NULL)
    {
        item->name=NULL;
        item->description=NULL;
        free(item);
    }
    return NULL;
}
