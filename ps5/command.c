#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "command.h"

struct command* create_command(char* name, char* description, char* pattern, size_t nmatch)
{
    if(name==NULL||description==NULL)
    {
        return NULL;
    }
    //remove spaces from name
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

    //remove spaces from pattern
    char* patt=(char*)calloc(1,strlen(pattern)+1);
    memcpy(patt,pattern,strlen(pattern));
    for(int i=1;i<strlen(pattern)-1;i++)
    {
        patt[i-1]=(char)toupper(pattern[i]);
        patt[i]='\0';
    }
    //printf("%s\n",patt);
    a=0;
    while(patt[a]==' ')
    {
        a++;
    }
    bfr='a';
    char* patter=(char*)calloc(1,strlen(patt)+1);
    for(a=a;a<strlen(patt);a++)
    {
        if(bfr==' '&&patt[a]==' ')
        {}
        else
        {
            patter[strlen(patter)]=patt[a];
            patter[strlen(patter)]='\0';
        }
        bfr=patt[a];
    }
    a=(int)strlen(patter)-1;
    while(patter[a]==' ')
    {
        a--;
    }
    patter[a+1]='\0';
    //printf("%s\n\n",patter);
    struct command* command=calloc(1,sizeof(struct command));
    command->name=nam;
    command->description=description;
    regcomp(&command->preg,patter,REG_ICASE|REG_EXTENDED);
    command->nmatch=nmatch;
    command->groups=NULL;
    free(patt);
    free(patter);
    free(inpu);
    free(nam);
    return command;
}

struct command* destroy_command(struct command* command)
{
    if(command!=NULL)
    {
        if(command->name!=NULL)
        {
            command->name=NULL;
        }
        if(command->description!=NULL)
        {
            command->description=NULL;
        }
        if(command->groups!=NULL)
        {
            command->groups=NULL;
        }
        free(command);
    }
    return NULL;
}
