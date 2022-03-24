#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    /*clock_t ti;
    ti = clock();*/
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
    min=min*-1+(float)pow(10,-6);
    //int mid;
    float max=1000000;
    float middle=(max+min)/2;
    float vysledok=0;
    for(int i=0;i<1000000;i++)
    {
        vysledok=0;
        for(int x=0;x<p;x++)
        {
            vysledok=vysledok+(s[x]/(v[x]+middle));
        }
        if(t==vysledok)
        {
            i=1000000;
        }
        if(t>vysledok)
        {
            max=middle;
            middle=(max+min)/2;
        }
        else if(t<vysledok)
        {
            min=middle;
            middle=(max+min)/2;
        }
    }
    printf("%f\n",middle);
    
    /*ti = clock() - ti;
    double time_taken = ((double)ti)/CLOCKS_PER_SEC; // in seconds
  
    printf("%f\n", time_taken);*/
}