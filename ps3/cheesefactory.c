#include <stdio.h>

int main()
{
    unsigned long long number=0;
    unsigned long long sum=0;
    scanf("%lld",&number);
    do
    {
        sum=0;
        do
        {
            sum=sum+number%10;
            number=number/10;
        }while(number>=1);
        number=sum;
    }while(sum>9);
    printf("%lld\n",sum);
}