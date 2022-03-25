#include <stdio.h>
#include <math.h>

struct hol{
    double r;
    double x;
    double y;
    double z;
    double v;
};

int main()
{
    double pi=3.1415926535897932384626433;
    int hole=0;
    float salaries=0;
    scanf("%d %f",&hole,&salaries);
    struct hol h[hole];
    double objem=pow(100000,3);
    double kus=0;
    for(int i=0;i<hole;i++)
    {
        scanf("%lf %lf %lf %lf",&h[i].r,&h[i].x,&h[i].y,&h[i].z);
        /*h[i].r=h[i].r/1000;
        h[i].x=h[i].x/1000;
        h[i].y=h[i].y/1000;
        h[i].z=h[i].z/1000;*/
        h[i].v=pi*4/3*pow(h[i].r,3);
        objem=objem-h[i].v;
    }
    double c=0;
    kus=objem/salaries;
    for(int i=1;i<salaries;i++)
    {
        double min=c;
        double max=100000;
        double pObjem;
        double mid;
        while(max-min>0.0000001)
        {
            mid=(max+min)/2;
            pObjem=pow(100000,2)*mid;
            for(int x=0;x<hole;x++)
            {
                if(h[x].z+h[x].r<=mid)
                {
                    pObjem=pObjem-h[x].v;
                }
                else if(h[x].z-h[x].r<=mid)
                {
                    double vyska=mid-h[x].z;
                    double cObjem=/*((pi*pow(vyska,2))/3)*(3*h[x].r-vyska)*//*pi*pow(vyska,2)*(h[x].r-vyska/3)*/pi*(vyska-1/3+pow(1-vyska,3)/3);
                    pObjem=pObjem-cObjem;
                }
            }
            if(i*kus>pObjem)
            {
                min=mid;
            }
            else
            {
                max=mid;
            }
        }
        mid=(max+min)/2;
        //double rez=(max+min)/2;
        //printf("%lf\t%lf\n",kus,pObjem);
        //printf("%lf\t%lf\n",min,max);
        printf("%lf\n",(mid-c)/1000);
        c=mid;
    }
    printf("%lf\n",(100000-c)/1000);
}