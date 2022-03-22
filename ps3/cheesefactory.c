#include <stdio.h>

int main()
{
    int hole=0;
    float salaries=0;
    scanf("%d %f",&hole,&salaries);
    if(hole==0)
    {
        for(int i=0;i<salaries;i++)
        {
            printf("%.7f\n",100/salaries);
        }
    }
    else
    {
        for(int i=0;i<salaries;i++)
        {
            printf("%.7f\n",100/salaries);
        }
    }
}