#include <stdio.h>

int main()
{
    int n;
    int k;
    scanf("%d %d\n",n,k);
    unsigned long long array [n][k];
    for(int i=0;i<n;i++)
    {
        for(int x=0;x<k;x++)
        {
            if(x<k-1)
            {
                scanf("%d ",array[i][k]);
            }
            else
            {
                scanf("%d\n",array[i][k]);
            }
        }
    }
}