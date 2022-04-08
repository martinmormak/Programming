#include <stdio.h>
#include <string.h>

int main()
{
    unsigned long long number=0;
    unsigned long long sum=0;
    char num;
    //gets(num);
    scanf("%c",&num);
    sum=0;
    while((int)num!=10)
    {
        sum=sum+(unsigned long long)num-48;
        scanf("%c",&num);
    }
    while(sum>9)
    {
        number=sum;
        sum=0;
        do
        {
            sum=sum+number%10;
            number=number/10;
        }while(number>=1);
        number=sum;
    }
    printf("%lld\n",sum);
}
