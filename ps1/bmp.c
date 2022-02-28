#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "bmp.h"

char* reverse(const char* text)
{
    if(text == NULL)
    {
        return NULL;
    }
    for(long i=0;i<strlen(text);i++)
    {
        if(text[i]!=' ')
        {
            break;
        }
        else
        {
            if(strlen(text)==1)
            {
                break;
            }
        }
        if(i==strlen(text)-1)
        {
            return NULL;
        }
    }
    char *rever = calloc(strlen(text)+1,sizeof *text);
    for(long i=0;i<strlen(text);i++)
    {
        rever[i]=text[strlen(text)-1-i];
    }
    rever[strlen(text)]='\0';
    for(long i=0;i<strlen(rever);i++)
    {
        if (rever[i] >= 97 && rever[i] <= 122)
        {
            rever[i] = rever[i] - 32;
        }
    }
    return rever;
}

char* vigenere_encrypt(const char* key, const char* text)
{
    if(text == NULL||key==NULL)
    {
        return NULL;
    }
    for(int i=0;i<strlen(key);i++)
    {
        if(isalpha(key[i])==0)
        {
            return NULL;
        }
    }
    for(long i=0;i<strlen(key);i++)
    {
        if(key[i]!=' ')
        {
            break;
        }
        if(i==strlen(key)-1)
        {
            return NULL;
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
            return NULL;
        }
    }
    char ke[strlen(key)];
    char k[strlen(text)];
    char txt[strlen(text)];
    long p=0;
    long x=0;
    long y=0;
    char letters[26]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for(long i=0;i<strlen(text);i++)
    {
        if(text[i]<97 || text[i]>122)
        {
            if(text[i]<65 || text[i]>90)
            {
                if(text[i]!=32)
                {
                    if(text[i]!=33)
                    {
                        return NULL;
                    }
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
    p=0;
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
    }
    txt[strlen(text)]='\0';
    for(long i=0;i<strlen(txt);i++)
    {
        if(txt[i]>=65 && txt[i]<=90)
        {
            k[i]=ke[p];
            p++;
            if(p==strlen(ke))
            {
                p=0;
            }
        }
        else
        {
            k[i]=txt[i];
        }
    }
    k[strlen(text)]='\0';
    char table[26][26]={
    {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"BCDEFGHIJKLMNOPQRSTUVWXYZA"},
    {"CDEFGHIJKLMNOPQRSTUVWXYZAB"},
    {"DEFGHIJKLMNOPQRSTUVWXYZABC"},
    {"EFGHIJKLMNOPQRSTUVWXYZABCD"},
    {"FGHIJKLMNOPQRSTUVWXYZABCDE"},
    {"GHIJKLMNOPQRSTUVWXYZABCDEF"},
    {"HIJKLMNOPQRSTUVWXYZABCDEFG"},
    {"IJKLMNOPQRSTUVWXYZABCDEFGH"},
    {"JKLMNOPQRSTUVWXYZABCDEFGHI"},
    {"KLMNOPQRSTUVWXYZABCDEFGHIJ"},
    {"LMNOPQRSTUVWXYZABCDEFGHIJK"},
    {"MNOPQRSTUVWXYZABCDEFGHIJKL"},
    {"NOPQRSTUVWXYZABCDEFGHIJKLM"},
    {"OPQRSTUVWXYZABCDEFGHIJKLMN"},
    {"PQRSTUVWXYZABCDEFGHIJKLMNO"},
    {"QRSTUVWXYZABCDEFGHIJKLMNOP"},
    {"RSTUVWXYZABCDEFGHIJKLMNOPQ"},
    {"STUVWXYZABCDEFGHIJKLMNOPQR"},
    {"TUVWXYZABCDEFGHIJKLMNOPQRS"},
    {"UVWXYZABCDEFGHIJKLMNOPQRST"},
    {"VWXYZABCDEFGHIJKLMNOPQRSTU"},
    {"WXYZABCDEFGHIJKLMNOPQRSTUV"},
    {"XYZABCDEFGHIJKLMNOPQRSTUVW"},
    {"YZABCDEFGHIJKLMNOPQRSTUVWX"},
    {"ZABCDEFGHIJKLMNOPQRSTUVWXY"}
    };
    char *str = calloc(strlen(text)+1,sizeof *text);
    for(long i=0;i<strlen(text);i++)
    {
        if(txt[i]>=65&&txt[i]<=90)
        {
            for(long q=0;q<26;q++)
            {
                if(letters[q]==txt[i])
                {
                    y=q;
                }
                if(letters[q]==k[i])
                {
                    x=q;
                }
            }
            str[i]=table[y][x];
        }
        else
        {
            str[i]=txt[i];
        }
    }
    str[strlen(text)]='\0';
    return str;
}

char* vigenere_decrypt(const char* key, const char* text)
{
    if(text == NULL||key==NULL)
    {
        return NULL;
    }
    for(int i=0;i<strlen(key);i++)
    {
        if(isalpha(key[i])==0)
        {
            return NULL;
        }
    }
    for(long i=0;i<strlen(key);i++)
    {
        if(key[i]!=' ')
        {
            break;
        }
        if(i==strlen(key)-1)
        {
            return NULL;
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
            return NULL;
        }
    }
    char ke[strlen(key)];
    char k[strlen(text)];
    char txt[strlen(text)];
    char *str = calloc(strlen(text)+1,sizeof (char*));
    long p=0;
    long x=0;
    long y=0;
    char letters[26]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for(long i=0;i<strlen(text);i++)
    {
        if(text[i]<97 || text[i]>122)
        {
            if(text[i]<65 || text[i]>90)
            {
                if(text[i]!=32)
                {
                    if(text[i]!=33)
                    {
                        return NULL;
                    }
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
    p=0;
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
    }
    txt[strlen(text)]='\0';
    for(long i=0;i<strlen(txt);i++)
    {
        if(txt[i]>=65 && txt[i]<=90)
        {
            k[i]=ke[p];
            p++;
            if(p==strlen(ke))
            {
                p=0;
            }
        }
        else
        {
            k[i]=txt[i];
        }
    }
    k[strlen(text)]='\0';
    char table[26][26]={
    {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"BCDEFGHIJKLMNOPQRSTUVWXYZA"},
    {"CDEFGHIJKLMNOPQRSTUVWXYZAB"},
    {"DEFGHIJKLMNOPQRSTUVWXYZABC"},
    {"EFGHIJKLMNOPQRSTUVWXYZABCD"},
    {"FGHIJKLMNOPQRSTUVWXYZABCDE"},
    {"GHIJKLMNOPQRSTUVWXYZABCDEF"},
    {"HIJKLMNOPQRSTUVWXYZABCDEFG"},
    {"IJKLMNOPQRSTUVWXYZABCDEFGH"},
    {"JKLMNOPQRSTUVWXYZABCDEFGHI"},
    {"KLMNOPQRSTUVWXYZABCDEFGHIJ"},
    {"LMNOPQRSTUVWXYZABCDEFGHIJK"},
    {"MNOPQRSTUVWXYZABCDEFGHIJKL"},
    {"NOPQRSTUVWXYZABCDEFGHIJKLM"},
    {"OPQRSTUVWXYZABCDEFGHIJKLMN"},
    {"PQRSTUVWXYZABCDEFGHIJKLMNO"},
    {"QRSTUVWXYZABCDEFGHIJKLMNOP"},
    {"RSTUVWXYZABCDEFGHIJKLMNOPQ"},
    {"STUVWXYZABCDEFGHIJKLMNOPQR"},
    {"TUVWXYZABCDEFGHIJKLMNOPQRS"},
    {"UVWXYZABCDEFGHIJKLMNOPQRST"},
    {"VWXYZABCDEFGHIJKLMNOPQRSTU"},
    {"WXYZABCDEFGHIJKLMNOPQRSTUV"},
    {"XYZABCDEFGHIJKLMNOPQRSTUVW"},
    {"YZABCDEFGHIJKLMNOPQRSTUVWX"},
    {"ZABCDEFGHIJKLMNOPQRSTUVWXY"}
    };
    for(long i=0;i<strlen(text);i++)
    {
        if(txt[i]>=65&&txt[i]<=90)
        {
            for(long q=0;q<26;q++)
            {
                if(letters[q]==txt[i])
                {
                    y=q;
                }
                if(letters[q]==k[i])
                {
                    x=q;
                }
            }
            for(long q=0;q<26;q++)
            {
                if(table[q][x]==txt[i])
                {
                    y=q;
                }
            }
            str[i]=letters[y];
        }
        else
        {
            str[i]=txt[i];
        }
    }
    str[strlen(text)]='\0';
    return str;
}

unsigned char* bit_encrypt(const char* text)
{
    if(text == NULL)
    {
        return NULL;
    }
    long index=0;
    unsigned char *string = calloc(strlen(text)+1,sizeof (char*));
    for(long i=0;i<strlen(text);i++)
    {
        int tmp;
        int bit[8]={0,0,0,0,0,0,0,0};
        int num=(int)text[i];
        for(int x=7;x>=0;x--)
        {
            bit[x]=num%2;
            num=num/2;
        }
        tmp=bit[0];
        bit[0]=bit[1];
        bit[1]=tmp;
        tmp=bit[2];
        bit[2]=bit[3];
        bit[3]=tmp;
        for(int x=0;x<4;x++)
        {
            if(bit[x]==bit[x+4])
            {
                bit[x+4]=0;
            }
            else
            {
                bit[x+4]=1;
            }
        }
        int a=0;
        for(int x=0;x<8;x++)
        {
            if(bit[7-x]==1)
            {
                a=a+pow(2,x);
            }
        }
        string[index]=(unsigned char)a;
        index++;
    }
    string[index]='\0';
    return string;
}

char* bit_decrypt(const unsigned char* text)
{
    if(text == NULL)
    {
        return NULL;
    }
    int index=0;
    char *string = calloc(255,8);
    int num;
    long i=0;
    while(text[i]!='\0')
    {
        int tmp;
        int bit[8]={0,0,0,0,0,0,0,0};
        num=(int)text[i];
        if(num<0)
        {
            num=num+256;
        }
        for(int x=7;x>=0;x--)
        {
            bit[x]=num%2;
            num=num/2;
        }
        for(int x=0;x<4;x++)
        {
            if(bit[x]==bit[x+4])
            {
                bit[x+4]=0;
            }
            else
            {
                bit[x+4]=1;
            }
        }
        tmp=bit[0];
        bit[0]=bit[1];
        bit[1]=tmp;
        tmp=bit[2];
        bit[2]=bit[3];
        bit[3]=tmp;
        int a=0;
        for(int x=0;x<8;x++)
        {
            if(bit[7-x]==1)
            {
                a=a+pow(2,x);
            }
        }
        string[index]=(unsigned char)a;
        index++;
        i++;
    }
    string[index]='\0';
    return string;
}

unsigned char* bmp_encrypt(const char* key, const char* text)
{
    if(text == NULL||key==NULL)
    {
        return NULL;
    }
    for(int i=0;i<strlen(key);i++)
    {
        if(isalpha(key[i])==0)
        {
            return NULL;
        }
    }
    char* reversed=reverse(text);
    char* encrypted = vigenere_encrypt(key, reversed);
    free(reversed);
    unsigned char* b_encrypt = bit_encrypt(encrypted);
    free(encrypted);
    return b_encrypt;
}

char* bmp_decrypt(const char* key, const unsigned char* text)
{
    if(text == NULL||key==NULL)
    {
        return NULL;
    }
    for(int i=0;i<strlen(key);i++)
    {
        if(isalpha(key[i])==0)
        {
            return NULL;
        }
    }
    char* reversed=bit_decrypt(text);
    char* decrypted = vigenere_decrypt(key, reversed);
    free(reversed);
    char* b_decrypt = reverse(decrypted);
    free(decrypted);
    return b_decrypt;
}

/*char* ceasar_encrypt(const char* text, const int step)
{
    if(text==NULL || step < 0)
    {
        return NULL;
    }
    int len = strlen(text);
    char* result = (char*)calloc(len+1, sizeof(char));

    for(int index = 0;index <len; index++)
    {
        result[index] = (text[index] - 'A' + step) % 26 + 'A';
    }
    result[len] = '\0';

    return result;
}

char* ceasar_decrypt(const char* text, const int step)
{
    if(text==NULL || step < 0)
    {
        return NULL;
    }
    int len = strlen(text);
    char* result = (char*)calloc(len+1, sizeof(char));

    for(int index = 0;index <len; index++)
    {
        result[index] = (text[index] - 'A' - step) % 26 + 'A';
        
        if(result[index]<'A')
        {
            result[index]+=26;
        }
    }
    result[len] = '\0';

    return result;
}*/
