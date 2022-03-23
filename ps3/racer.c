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
    min=min*-1;
    float vysledok=0;
    float pvysledok=0;
    int q;
    for(int i=2;i>=-7;i--)
    {
        do
        {
            q=1;
            min=min+(float)pow(10,i);
            vysledok=0;
            for(int x=0;x<p;x++)
            {
                vysledok=vysledok+(s[x]/(v[x]+min));
            }
            if(t==vysledok)
            {
                i=-8;
                q=0;
            }
            if(t>vysledok)
            {
                min=min-(float)pow(10,i);
                q=0;
            }
            else if(t>vysledok&&t<pvysledok)
            {
                q=0;
            }
            pvysledok=vysledok;
        }while(q);
    }
    printf("%f\n",min);
    
    /*ti = clock() - ti;
    double time_taken = ((double)ti)/CLOCKS_PER_SEC; // in seconds
  
    printf("%f\n", time_taken);*/
}