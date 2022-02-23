#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "playfair.h"

char* playfair_encrypt(const char* key, const char* text)
{
    if(strlen(text)==0)
    {
        return "NULL";
    }
    for(long i=0;i<strlen(key);i++)
    {
        if(key[i]!=' ')
        {
            break;
        }
        if(i==strlen(key)-1)
        {
            return "NULL";
        }
    }
    for(long i=0;i<strlen(text);i++)
    {
        if(text[i]!=' ')
        {
            break;
        }
        if(i==strlen(text)-1)
        {
            return "NULL";
        }
    }
    char diagram[5][5];
    long x=0;
    long y=0;
    long m=0;
    long c=0;
    long xa=0;
    long ya=0;
    long xb=0;
    long yb=0;
    char str[9999]={};
    char *st=calloc(strlen(text)+1, sizeof *text);
    char txt[9999]={};
    char tx[9999]={};
    char ke[strlen(key)];
    char k[strlen(key)];
    char ch;
    long p=0;
    long q=0;
    char letter[25] = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    for(long i=0;i<strlen(text);i++)
    {
        if(text[i]<97 || text[i]>122)
        {
            if(text[i]<65 || text[i]>90)
            {
                if(text[i]!=32)
                {
                    return "NULL";
                }
            }
        }
    }
    for(long i=0;i<strlen(key);i++)
    {
        if (key[i] >= 97 && key[i] <= 122)
        {
            ke[i] = key[i] - 32;
        }
        else
        {
            ke[i]=key[i];
        }
    }
    ke[strlen(key)]='\0';
    for(long i=0;i<strlen(key);i++)
    {
        for(long x=0;x<i;x++)
        {
            if(ke[i]==ke[x])
            {
                ke[i]=' ';
                x=i;
            }
        }
    }
    ke[strlen(key)]='\0';
    for(long i=0;i<strlen(ke);i++)
    {
        if(ke[i]=='W')
        {
            ke[i]='V';
        }
    }
    ke[strlen(key)]='\0';
    for(long i=0;i<strlen(ke);i++)
    {
        if(ke[i]!=' ')
        {
            k[p]=ke[i];
            p++;
        }
    }
    k[p]='\0';
    for(int i=0;i<25;i++)
    {
        for(long q=0;q<strlen(k);q++)
        {
            if(k[q]==letter[i])
            {
                //printf("1   %c  -   %s\n",letter[i],k);
                break;
            }
            if(q==strlen(k)-1)
            {
                ch=letter[i];
                k[p]=ch;
                p++;
                //printf("2   %c  -   %s\n",ch,k);
                break;
            }
        }
    }
    k[p]='\0';
    //printf("%s\n",k);
    x=0;
    y=0;
    for(long i=0;i<p;i++)
    {
        diagram[y][x]=k[i];
        m++;
        x++;
        if(x==5)
        {
            x=0;
            y++;
        }
    }
    long a=m;
    long b=0;
    while(a>=5)
    {
        a=a-5;
        b++;
    }
    /*for(int i=0;i<25;i++)
    {
        for(int q=0;q<strlen(k);q++)
        {
                if(k[q] == letter[i])
                {
                    break;
                }
                if(q == strlen(k)-1)
                {
                    diagram[b][a]=letter[i];
                    a++;
                    if(a==5)
                    {
                        a=0;
                        b++;
                    }
                }
        }
    }*/
    /*for(int i=0;i<5;i++)
    {
        for(int w=0;w<5;w++)
        {
            printf("%c",diagram[i][w]);
        }
        printf("\n");
    }*/
    for(long i=0;i<strlen(text);i++)
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
            txt[i]='V';
        }
    }
    c=0;
    for(long i=0;i<strlen(txt);i++)
    {
        if(txt[i]!=' ')
        {
            tx[c]=txt[i];
            c++;
        }
    }
    c=0;
    for(long i=0;i<strlen(tx);i++)
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
    if(strlen(str)%2!=0)
    {
        strcat(str,"X");
    }
    for(long i=0;i<strlen(str);i++)
    {
        char a=str[i];
        char b=str[i+1];
        for(long y=0;y<5;y++)
        {
            for(long x=0;x<5;x++)
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
    //printf("%s\n",st);
    return st;
}

char* playfair_decrypt(const char* key, const char* text)
{
    if(strlen(text)==0)
    {
        return "NULL";
    }
    for(long i=0;i<strlen(key);i++)
    {
        if(key[i]!=' ')
        {
            break;
        }
        if(i==strlen(key)-1)
        {
            return "NULL";
        }
    }
    for(long i=0;i<strlen(text);i++)
    {
        if(text[i]!=' ')
        {
            break;
        }
        if(i==strlen(text)-1)
        {
            return "NULL";
        }
    }
    char diagram[5][5];
    long x=0;
    long y=0;
    long m=0;
    long c=0;
    long xa=0;
    long ya=0;
    long xb=0;
    long yb=0;
    char str[255]={};
    char *st=calloc(strlen(text)+1, sizeof *text);
    char txt[255]={};
    char tx[255]={};
    char ke[strlen(key)];
    char k[strlen(key)];
    char ch;
    long p=0;
    long q=0;
    char letter[25] = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    for(long i=0;i<strlen(text);i++)
    {
        if(text[i]<97 || text[i]>122)
        {
            if(text[i]<65 || text[i]>90)
            {
                if(text[i]!=32)
                {
                    return "NULL";
                }
            }
        }
    }
    for(long i=0;i<strlen(key);i++)
    {
        if (key[i] >= 97 && key[i] <= 122)
        {
            ke[i] = key[i] - 32;
        }
        else
        {
            ke[i]=key[i];
        }
    }
    ke[strlen(key)]='\0';
    for(long i=0;i<strlen(key);i++)
    {
        for(long x=0;x<i;x++)
        {
            if(ke[i]==ke[x])
            {
                ke[i]=' ';
                x=i;
            }
        }
    }
    ke[strlen(key)]='\0';
    for(long i=0;i<strlen(ke);i++)
    {
        if(ke[i]=='W')
        {
            ke[i]='V';
        }
    }
    ke[strlen(key)]='\0';
    for(long i=0;i<strlen(ke);i++)
    {
        if(ke[i]!=' ')
        {
            k[p]=ke[i];
            p++;
        }
    }
    k[p]='\0';
    for(int i=0;i<25;i++)
    {
        for(long q=0;q<strlen(k);q++)
        {
            if(k[q]==letter[i])
            {
                //printf("1   %c  -   %s\n",letter[i],k);
                break;
            }
            if(q==strlen(k)-1)
            {
                ch=letter[i];
                k[p]=ch;
                p++;
                //printf("2   %c  -   %s\n",ch,k);
                break;
            }
        }
    }
    k[p]='\0';
    //printf("%s\n",k);
    x=0;
    y=0;
    for(long i=0;i<strlen(k);i++)
    {
        diagram[y][x]=k[i];
        m++;
        x++;
        if(x==5)
        {
            x=0;
            y++;
        }
    }
    long a=m;
    long b=0;
    while(a>=5)
    {
        a=a-5;
        b++;
    }
    /*for(int i=0;i<25;i++)
    {
        for(int q=0;q<strlen(k);q++)
        {
                if(k[q] == letter[i])
                {
                    break;
                }
                if(q == strlen(k)-1)
                {
                    diagram[b][a]=letter[i];
                    a++;
                    if(a==5)
                    {
                        a=0;
                        b++;
                    }
                }
        }
    }*/
    /*for(int i=0;i<5;i++)
    {
        for(int w=0;w<5;w++)
        {
            printf("%c",diagram[i][w]);
        }
        printf("\n");
    }*/
    for(long i=0;i<strlen(text);i++)
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
            txt[i]='V';
        }
    }
    c=0;
    for(long i=0;i<strlen(txt);i++)
    {
        if(txt[i]!=' ')
        {
            tx[c]=txt[i];
            c++;
        }
    }
    c=0;
    for(long i=0;i<strlen(tx);i++)
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
    for(long i=0;i<strlen(str);i++)
    {
        char a=str[i];
        char b=str[i+1];
        for(long y=0;y<5;y++)
        {
            for(long x=0;x<5;x++)
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
    //printf("%s\n",st);
    //char *stri=st;
    return st;
}
