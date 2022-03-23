#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *n1,const void *n2)
{
    return ( *(int*)n1 - *(int*)n2 );
}

int main()
{
    int n;
    int k;
    scanf("%d %d\n",&n,&k);
    unsigned long long array [n][k];
    int retur [2][n];
    for(int i=0;i<n;i++)
    {
        for(int x=0;x<k;x++)
        {
            if(x<k-1)
            {
                scanf("%lld ",&array[i][x]);
            }
            else
            {
                scanf("%lld\n",&array[i][x]);
            }
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int x=0;x<k;x++)
        {
            printf("%lld\t",array[i][x]);
        }
        printf("\n");
    }*/
    for(int i=0;i<n;i++)
    {
        int m=1000;
        int v=1000;
        int sum=0;
        for(int x=1;x<k;x++)
        {
            if(array[i][x]<array[i][0])
            {
                //printf("%lld<%lld\n",array[i][x],array[i][0]);
                m++;
            }
            else if(array[i][x]>array[i][0])
            {
                //printf("%lld>%lld\n",array[i][x],array[i][0]);
                v++;
            }
        }
        //printf("%d\t%d\n",m,v);
        retur[0][i]=m;
        retur[1][i]=v;
        if(m!=1000&&v!=1000)
        {
        }
        else
        {
            for(int x=1;x<k;x++)
            {
                if(array[i][x]<array[i][x-1])
                {
                    sum=sum-(int)pow(2,x);
                }
                else if(array[i][x]>array[i][x-1])
                {
                    sum=sum+(int)pow(2,x);
                }
            }
            retur[0][i]=sum;
            retur[1][i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int x=1;x<n;x++)
        {
            if(retur[0][x]<retur[0][x-1])
            {
                int m=retur[0][x];
                int v=retur[1][x];
                retur[0][x]=retur[0][x-1];
                retur[1][x]=retur[1][x-1];
                retur[0][x-1]=m;
                retur[1][x-1]=v;
            }
        }
    }
    //qsort(retur,(size_t)n,sizeof (int),cmp);
    int v=1;
    for(int i=1;i<n;i++)
    {
        if(retur[0][i]!=retur[0][i-1])
        {
            v++;
        }
        //printf("%d\t%d\n",retur[0][i],retur[1][i]);
    }
    printf("%d\n",v);
}