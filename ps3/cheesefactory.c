#include <stdio.h>
#include <math.h>

struct hol{
    double r;
    double x;
    double y;
    double z;
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
        //h[i].v=pi*4/3*pow(h[i].r,3);
        objem=objem-pi*4/3*pow(h[i].r,3);;
    }
    double c=0;
    kus=objem/salaries;
    for(int i=1;i<salaries;i++)
    {
        double min=c;
        double max=100000;
        double pObjem;
        double mid;
        double m;
        double vyska;
        while(max-min>0.0000001)
        {
            mid=(max+min)/2;
            m=mid;
            pObjem=pow(100000,2)*mid;
            for(int x=0;x<hole;x++)
            {
                if(h[x].z+h[x].r<mid)
                {
                    pObjem=pObjem-pi*4/3*h[x].r*h[x].r*h[x].r;
                }
                else if(h[x].z-h[x].r<mid)
                {
                    vyska=mid-h[x].z;
				    double cObjem=h[x].r*h[x].r*vyska-vyska*vyska*vyska/3.0+2.0/3*h[x].r*h[x].r*h[x].r;
                    //double cObjem=1/3*vyska*vyska*(3*h[x].r-vyska);
				    cObjem=cObjem*pi;
				    pObjem=pObjem-cObjem;
                }
            }
            if(i*kus<pObjem)
            {
                max=m;
                //printf("max\t%lf\t%lf\t%lf\t%lf\t%lf\n",i*kus,pObjem,i*kus-pObjem,max,min);
            }
            else if(i*kus==pObjem)
            {
                min=m;
                max=m;
            }
            else
            {
                min=m;
                //printf("min\t%lf\t%lf\t%lf\t%lf\t%lf\n",i*kus,pObjem,i*kus-pObjem,max,min);
            }
        }
        mid=(max+min)/2;
        //double rez=(max+min)/2;
        //printf("%lf\t%lf\n",kus,pObjem);
        //printf("%lf\t%lf\n",min,max);
        printf("%.6lf\n",(mid-c)/1000);
        c=mid;
    }
    printf("%.6lf\n",(100000-c)/1000);
}
