#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "playfair.h"

char* playfair_encrypt(const char* key, const char* text)
{
    if(strlen(text)==0||text == NULL||strlen(key)==0||key==NULL)
    {
        return NULL;
    }
    for(int i=0;i<strlen(key);i++)
    {
        if(key[i]<97||key[i]>122)
        {
            if(key[i]<65||key[i]>90)
            {
                if(key[i]!=32)
                {
                    return NULL;
                }
            }
        }
    }
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]<97||text[i]>122)
        {
            if(text[i]<65||text[i]>90)
            {
                if(text[i]!=32)
                {
                    return NULL;
                }
            }
        }
    }
    char diagram [5][5];
    int x=0;
    int y=0;
    int xa=0;
    int ya=0;
    int xb=0;
    int yb=0;
    char ke[strlen(key)+25];
    //char ch;
    int m=0;
    int p=0;
    char txt[255]={};
    char tx[255]={};
    char str[255]={};
    char *st=calloc(strlen(text)+1, sizeof *text);
    int q=0;
    char letter[25]="ABCDEFGHIJKLMNOPQRSTUVXYZ";
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
    for(int i=0;i<25;i++)
    {
        ke[strlen(key)+i]=letter[i];
    }
    for(int i=0;i<strlen(ke);i++)
    {
        for(int x=0;x<i;x++)
        {
            if(ke[i]==ke[x])
            {
                ke[i]=' ';
                x=i;
            }
        }
    }
    for(int i=0;i<strlen(ke);i++)
    {
        if(ke[i]!=' ')
        {
            ke[p]=ke[i];
            p++;
        }
    }
    ke[p]='\0';
    /*for(int i=0;i<25;i++)
    {
        for(int q=0;q<strlen(ke);q++)
        {
            if(ke[q]==letter[i])
            {
                break;
            }
            if(q==strlen(ke)-1)
            {
                ch=letter[i];
                ke[p]=ch;
                p++;
                break;
            }
        }
    }
    ke[p]='\0';*/
    x=0;
    y=0;
    for(int i=0;i<p;i++)
    {
        diagram[y][x]=ke[i];
        m++;
        x++;
        if(x==5)
        {
            x=0;
            y++;
        }
    }
    int a=m;
    int b=0;
    while(a>=5)
    {
        a=a-5;
        b++;
    }
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
    for(int i=0;i<strlen(ke);i++)
    {
        if(txt[i]!=' ')
        {
            tx[p]=txt[i];
            p++;
        }
    }
    tx[p]='\0';
    int c=0;
    for(int i=0;i<strlen(tx);i++)
    {
        str[c]=tx[i];
        c++;
        if(tx[i]!='X')
        {
            if(tx[i]==tx[i+1])
            {
                str[c]='X';
                c++;
            }
        }
        i++;
        str[c]=tx[i];
        c++;
    }
    str[c]='\0';
    if(strlen(str)%2!=0)
    {
        strcat(str,"X");
    }
    for(int i=0;i<strlen(str);i++)
    {
        char a=str[i];
        char b=str[i+1];
        for(int y=0;y<5;y++)
        {
            for(int x=0;x<5;x++)
            {
                if(a==diagram[y][x])
                {
                    xa=x;
                    ya=y;
                }
                if(b==diagram[y][x])
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
                st[q]=' ';
                q++;
            }
            st[q]=diagram[ya][xa];
            q++;
            st[q]=diagram[yb][xb];
            q++;
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
                st[q]=' ';
                q++;
            }
            st[q]=diagram[ya][xa];
            q++;
            st[q]=diagram[yb][xb];
            q++;
        }
        else
        {
            if(i!=0)
            {
                st[q]=' ';
                q++;
            }
            st[q]=diagram[ya][xb];
            q++;
            st[q]=diagram[yb][xa];
            q++;
        }
        i++;
    }
    for(int i=0;i<5;i++)
    {
        for(int w=0;w<5;w++)
        {
            printf("%c",diagram[i][w]);
        }
        printf("\n");
    }
    return st;
}

char* playfair_decrypt(const char* key, const char* text)
{
    if(strlen(text)==0||text == NULL||strlen(key)==0||key==NULL)
    {
        return NULL;
    }
    for(int i=0;i<strlen(key);i++)
    {
        if(key[i]<97||key[i]>122)
        {
            if(key[i]<65||key[i]>90)
            {
                if(key[i]!=32)
                {
                    return NULL;
                }
            }
        }
    }
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]<97||text[i]>122)
        {
            if(text[i]<65||text[i]>90)
            {
                if(text[i]!=32)
                {
                    return NULL;
                }
            }
        }
    }
    char diagram [5][5];
    int x=0;
    int y=0;
    int xa=0;
    int ya=0;
    int xb=0;
    int yb=0;
    char ke[strlen(key)];
    //char ch;
    int m=0;
    int p=0;
    char txt[255]={};
    char tx[255]={};
    char str[255]={};
    char *st=calloc(strlen(text)+1, sizeof *text);
    int q=0;
    char letter[25]="ABCDEFGHIJKLMNOPQRSTUVXYZ";
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
        for(int x=0;x<i;x++)
        {
            if(ke[i]==ke[x])
            {
                ke[i]=' ';
                x=i;
            }
        }
        if(ke[i]=='W')
        {
            ke[i]='V';
        }
    }
    ke[strlen(key)]='\0';
    for(int i=0;i<25;i++)
    {
        ke[strlen(key)+i]=letter[i];
    }
    for(int i=0;i<strlen(ke);i++)
    {
        for(int x=0;x<i;x++)
        {
            if(ke[i]==ke[x])
            {
                ke[i]=' ';
                x=i;
            }
        }
    }
    for(int i=0;i<strlen(ke);i++)
    {
        if(ke[i]!=' ')
        {
            ke[p]=ke[i];
            p++;
        }
    }
    ke[p]='\0';
    /*for(int i=0;i<25;i++)
    {
        for(int q=0;q<strlen(ke);q++)
        {
            if(ke[q]==letter[i])
            {
                break;
            }
            if(q==strlen(ke)-1)
            {
                ch=letter[i];
                ke[p]=ch;
                p++;
                break;
            }
        }
    }*/
    ke[p]='\0';
    x=0;
    y=0;
    for(int i=0;i<p;i++)
    {
        diagram[y][x]=ke[i];
        m++;
        x++;
        if(x==5)
        {
            x=0;
            y++;
        }
    }
    int a=m;
    int b=0;
    while(a>=5)
    {
        a=a-5;
        b++;
    }
    for(int i=0;i<strlen(text);i++)
    {
        if (text[i] >= 97 && text[i] <= 122)
        {
            txt[i] = text[i] - 32;
        }
        else
        {
            txt[i] = text[i];
        }
        if(txt[i]=='W')
        {
            return NULL;
        }
    }
    int c=0;
    for(int i=0;i<strlen(txt);i++)
    {
        if(txt[i]!=' ')
        {
            tx[c]=txt[i];
            c++;
        }
    }
    c=0;
    for(int i=0;i<strlen(tx);i++)
    {
        str[c]=tx[i];
        c++;
        i++;
        str[c]=tx[i];
        c++;
    }
    if(strlen(str)%2!=0)
    {
        strcat(str,"X");
    }
    for(int i=0;i<strlen(str);i++)
    {
        char a=str[i];
        char b=str[i+1];
        for(int y=0;y<5;y++)
        {
            for(int x=0;x<5;x++)
            {
                if(a==diagram[y][x])
                {
                    xa=x;
                    ya=y;
                }
                if(b==diagram[y][x])
                {
                    xb=x;
                    yb=y;
                }
            }
        }
        if(xa==xb)
        {
            if(ya==0)
            {
                ya=5;
            }
            if(yb==0)
            {
                yb=5;
            }
            ya--;
            yb--;
            st[q]=diagram[ya][xa];
            q++;
            st[q]=diagram[yb][xb];
            q++;
        }
        else if(ya==yb)
        {
            if(xa==0)
            {
                xa=5;
            }
            if(xb==0)
            {
                xb=5;
            }
            xa--;
            xb--;
            st[q]=diagram[ya][xa];
            q++;
            st[q]=diagram[yb][xb];
            q++;
        }
        else
        {
            st[q]=diagram[ya][xb];
            q++;
            st[q]=diagram[yb][xa];
            q++;
        }
        i++;
    }
    for(int i=0;i<5;i++)
    {
        for(int w=0;w<5;w++)
        {
            printf("%c",diagram[i][w]);
        }
        printf("\n");
    }
    return st;
}
