#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "playfair.h"

char* playfair_encrypt(const char* key, const char* text)
{
    if(strlen(key)==0||key==NULL||strlen(text)==0||text==NULL)
    {
        return NULL;
    }
    for(int i=0;i<strlen(text);i++)
    {
        if(isalpha(text[i])==0)
        {
            if(text[i]!=' ')
            {
                return NULL;
            }
        }
    }
    int l=strlen(key);
    l=l+25;
    char ke[l];
    char diagram[5][5];
    char txt[strlen(text)];
    char tx[strlen(text)];
    int p=0;
    char str[strlen(text)];
    char *st=calloc(strlen(text)+1,sizeof *text);
    int xa;
    int ya;
    int xb;
    int yb;
    for(int i=0;i<strlen(key);i++)
    {
        if(key[i]>=97&&key[i]<=122)
        {
            ke[i]=key[i]-32;
        }
        else
        {
            ke[i]=key[i];
        }
        if(ke[i]=='W')
        {
            ke[i]='V';
        }
    }
    ke[strlen(key)]='\0';
    strcat(ke,"ABCDEFGHIJKLMNOPQRSTUVXYZ\0");
    for(int i=0;i<strlen(ke);i++)
    {
        for(int x=0;x<i;x++)
        {
            if(ke[i]==ke[x])
            {
                ke[i]=' ';
            }
        }
    }
    p=0;
    for(int y=0;y<5;y++)
    {
        for(int x=0;x<5;x++)
        {
            if(ke[p]==' ')
            {
                x--;
                p++;
                continue;
            }
            diagram[y][x]=ke[p];
            p++;
        }
    }
    /*for(int y=0;y<5;y++)
    {
        for(int x=0;x<5;x++)
        {
            printf("%c",diagram[y][x]);
        }
        printf("\n");
    }*/
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]>=97&&text[i]<=122)
        {
            txt[i]=text[i]-32;
        }
        else
        {
            txt[i]=text[i];
        }
        if(txt[i]=='W')
        {
            txt[i]='V';
        }
    }
    txt[strlen(text)]='\0';
    p=0;
    for(int i=0;i<strlen(txt);i++)
    {
        if(txt[i]!=' ')
        {
            tx[p]=txt[i];
            p++;
        }
    }
    tx[p]='\0';
    l=p;
    p=0;
    for(int i=0;i<l;i++)
    {
        str[p]=tx[i];
        p++;
        if(tx[i]!='X')
        {
            if(tx[i]==tx[i+1])
            {
                str[p]='X';
                p++;
            }
        }
        i++;
        str[p]=tx[i];
        p++;
    }
    str[p]='\0';
    if(strlen(str)%2!=0)
    {
        str[p]='X';
        p++;
    }
    str[p]='\0';
    p=0;
    for(int i=0;i<strlen(str);i++)
    {
        char a=str[i];
        char b=str[i+1];
        for(int y=0;y<5;y++)
        {
            for(int x=0;x<5;x++)
            {
                if(diagram[y][x]==a)
                {
                    xa=x;
                    ya=y;
                }
                if(diagram[y][x]==b)
                {
                    xb=x;
                    yb=y;
                }
            }
        }
        if(xa==xb)
        {
            ya++;
            yb++;
            if(ya==5)
            {
                ya=0;
            }
            if(yb==5)
            {
                yb=0;
            }
            if(i!=0)
            {
                st[p]=' ';
                p++;
            }
            st[p]=diagram[ya][xa];
            p++;
            st[p]=diagram[yb][xb];
            p++;
        }
        else if(ya==yb)
        {
            xa++;
            xb++;
            if(xa==5)
            {
                xa=0;
            }
            if(xb==5)
            {
                xb=0;
            }
            if(i!=0)
            {
                st[p]=' ';
                p++;
            }
            st[p]=diagram[ya][xa];
            p++;
            st[p]=diagram[yb][xb];
            p++;
        }
        else
        {
            if(i!=0)
            {
                st[p]=' ';
                p++;
            }
            st[p]=diagram[ya][xb];
            p++;
            st[p]=diagram[yb][xa];
            p++;
        }
        i++;
    }
    return st;
}

char* playfair_decrypt(const char* key, const char* text)
{
    return "Playfair decrypt";
}
