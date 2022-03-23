#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    clock_t ti;
    ti = clock();
    int p;
    float t;
    scanf("%d %f\n",&p,&t);
    float v[p];
    float s[p];
    for(int i=0;i<p;i++)
    {
        scanf("%f %f\n",&s[i],&v[i]);
    }
    float min=v[0];
    for(int i=1;i<p;i++)
    {
        if(min>v[i])
        {
            min=v[i];
        }
    }
    min=min*-1;
    min=min+(float)pow(10,-6);
    float vysledok=0;
    do
    {
        vysledok=0;
        for(int i=0;i<p;i++)
        {
            vysledok=vysledok+(s[i]/(v[i]+min));
        }
        min=min+(float)pow(10,-6);
        printf("%f\t%f\n",min,vysledok);
    }while(t!=vysledok);
    min=min-(float)pow(10,-6);
    printf("%f\n",min);
    
    ti = clock() - ti;
    double time_taken = ((double)ti)/CLOCKS_PER_SEC; // in seconds
  
    printf("%f\n", time_taken);
}