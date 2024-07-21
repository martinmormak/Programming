#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    /*clock_t ti;
    ti = clock();*/
    int p;
    double t;
    scanf("%d %lf\n",&p,&t);
    double v[p];
    double s[p];
    for(int i=0;i<p;i++)
    {
        scanf("%lf %lf\n",&s[i],&v[i]);
    }
    double min=v[0];
    for(int i=1;i<p;i++)
    {
        if(min>v[i])
        {
            min=v[i];
        }
    }
    min=min*-1+(float)pow(10,-6);
    //int mid;
    double max=2000;
    double middle=(max+min)/2;
    double vysledok=0;
    for(unsigned long long i=0;i<9999;i++)
    {
        vysledok=0;
        for(int x=0;x<p;x++)
        {
            vysledok=vysledok+(s[x]/(v[x]+middle));
        }
        if(t==vysledok)
        {
            i=9999;
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
    printf("%.6f\n",middle);
    
    /*ti = clock() - ti;
    double time_taken = ((double)ti)/CLOCKS_PER_SEC; // in seconds
  
    printf("%ld\t%f\n",ti,time_taken);*/
}
