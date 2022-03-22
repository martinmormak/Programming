#include <stdio.h>

int main()
{
    int n;
    int k;
    scanf("%d %d\n",&n,&k);
    unsigned long long array [n][k];
    int retur [k*2-1];
    for(int i=0;i<n;i++)
    {
        for(int x=0;x<k;x++)
        {
            if(x<k-1)
            {
                scanf("%lld ",&array[i][k]);
            }
            else
            {
                scanf("%lld\n",&array[i][k]);
            }
        }
    }
    int m=0;
    int v=0;
    for(int i=0;i<n;i++)
    {
        for(int x=1;x<k;x++)
        {
            if(array[n][x]<array[n][0])
            {
                m=1;
            }
            else if(array[n][x]>array[n][0])
            {
                v=0;
            }
        }
        if(m==1&&v==1)
        {
            retur[0]++;
        }
    }
}