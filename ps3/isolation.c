#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    int k;
    scanf("%d %d\n",&n,&k);
    unsigned long long array [n][k];
    //int retur [2][n];
    unsigned long long tree [n][k][2*k];
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
    for(int z=0;z<n;z++)
    {
        for(int y=0;y<k;y++)
        {
            if(y!=0)
            {
                for(int x=0;x<2*y;x++)
                {
                    tree[z][y][x]=0;
                }
            }
            else
            {
                tree[z][y][0]=0;
            }
        }
    }
    for(int z=0;z<n;z++)
    {
        for(int i=0;i<k;i++)
        {
            int a=0;
            int o=0;
            for(int y=0;y<k;y++)
            {
                if(tree[z][y][o]==0)
                {
                    tree[z][y][o]=array[z][i];
                    y=k;
                }
                else if(tree[z][y][o]<array[z][i])
                {
                    a=1;
                    o=2*o+a;
                }
                else
                {
                    a=0;
                    o=2*o+a;
                }
            }
        }
    }
    for(int z=0;z<n;z++)
    {
        if(tree[z][0][0]!=0)
        {
            tree[z][0][0]=1;
        }
        for(int y=1;y<k;y++)
        {
            for(int x=0;x<2*y;x++)
            {
                if(tree[z][y][x]!=0)
                {
                    tree[z][y][x]=1;
                }
            }
        }
    }
    /*for(int z=0;z<n;z++)
    {
        printf("%lld\n",tree[z][0][0]);
        for(int y=1;y<k;y++)
        {
            for(int x=0;x<2*y;x++)
            {
                printf("%lld\t",tree[z][y][x]);
            }
            printf("\n");
        }
        printf("\n\n");
    }*/
    int c;
    int w=0;
    int count=1;
    for(int z=1;z<n;z++)
    {
        w=0;
        for(int q=0;q<z;q++)
        {
            c=0;
            if(tree[z][0][0]!=tree[q][0][0])
            {
                c=1;
            }
            for(int y=1;y<k;y++)
            {
                for(int x=0;x<2*y;x++)
                {
                    if(tree[z][y][x]!=tree[q][y][x])
                    {
                        c=1;
                    }
                }
            }
            w=w+c;
        }
        if(w==z)
        {
            count++;
        }
    }
    printf("%d\n",count);
}
