#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"
#include "transformations.h"

struct bmp_image* flip_horizontally(const struct bmp_image* image)
{
    if(image==NULL)
    {
        return NULL;
    }
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    unsigned char *bgr=malloc(image->header->image_size);
    memcpy(bgr,image->data,image->header->image_size);
    uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->height;x++)
    {
        uint32_t a=0;
        for(uint32_t i=0;i<image->header->width/2;i++)
        {
            //printf("%d\t%d\t%d\t%d\t%d\t%d\n",x,i,a,size,size*x+a,image->header->image_size-size*x-size+a);
            unsigned char b;
            unsigned char g;
            unsigned char r;
            b=bgr[size*x+a];
            g=bgr[size*x+a+1];
            r=bgr[size*x+a+2];
            bgr[size*x+a]=bgr[size*x+image->header->width*3-a-3];
            bgr[size*x+a+1]=bgr[size*x+image->header->width*3-a-2];
            bgr[size*x+a+2]=bgr[size*x+image->header->width*3-a-1];
            bgr[size*x+image->header->width*3-a-3]=b;
            bgr[size*x+image->header->width*3-a-2]=g;
            bgr[size*x+image->header->width*3-a-1]=r;
            a=a+3;
        }
    }
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=header;
    img->data=(struct pixel*)bgr;
    return img;
}

struct bmp_image* flip_vertically(const struct bmp_image* image)
{
    if(image==NULL)
    {
        return NULL;
    }
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    unsigned char *bgr=malloc(image->header->image_size);
    memcpy(bgr,image->data,image->header->image_size);
    uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->height/2;x++)
    {
        uint32_t a=0;
        for(uint32_t i=0;i<image->header->width;i++)
        {
            //printf("%d\t%d\t%d\t%d\t%d\t%d\n",x,i,a,size,size*x+a,image->header->image_size-size*x-size+a);
            unsigned char b;
            unsigned char g;
            unsigned char r;
            b=bgr[size*x+a];
            g=bgr[size*x+a+1];
            r=bgr[size*x+a+2];
            bgr[size*x+a]=bgr[image->header->image_size-size*x-size+a];
            bgr[size*x+a+1]=bgr[image->header->image_size-size*x-size+a+1];
            bgr[size*x+a+2]=bgr[image->header->image_size-size*x-size+a+2];
            bgr[image->header->image_size-size*x-size+a]=b;
            bgr[image->header->image_size-size*x-size+a+1]=g;
            bgr[image->header->image_size-size*x-size+a+2]=r;
            a=a+3;
        }
    }
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=header;
    img->data=(struct pixel*)bgr;
    return img;
}

struct bmp_image* rotate_right(const struct bmp_image* image)
{
    if(image==NULL)
    {
        return NULL;
    }
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    unsigned char *bgr=malloc(image->header->image_size);
    memcpy(bgr,image->data,image->header->image_size);
    uint32_t save=header->width;
    header->width=header->height;
    header->height=save;
    uint32_t new_size=header->width*3;
    if(new_size%2==0)
    {
        new_size=new_size+2;
    }
    else
    {
        new_size=new_size+1;
    }
    header->image_size=header->height*new_size;
    header->size=header->image_size+(uint32_t)sizeof(struct bmp_header);
    unsigned char *nbgr=malloc(header->image_size);
    memcpy(nbgr,image->data,image->header->image_size);
    for(int i=0;i<header->image_size;i++)
    {
        nbgr[i]=0;
    }
    uint32_t size=image->header->image_size/image->header->width;
    uint32_t nsize=header->image_size/header->width;
    uint32_t q=0;
    uint32_t w=0;
    for(uint32_t x=0;x<header->height;x++)
    {
        uint32_t a=0;
        for(uint32_t i=0;i<header->width;i++)
        {
            //printf("%d\t%d\n",size*x+a,size*w+image->header->width*3-q*3-3);
            //printf("%d\t%d\t%d\n",bgr[size*i+image->header->width*3-x*3-3],bgr[size*i+image->header->width*3-x*3-2],bgr[size*i+image->header->width*3-x*3-1]);
            nbgr[nsize*x+a]=bgr[size*w+image->header->width*3-q*3-3];
            nbgr[nsize*x+a+1]=bgr[size*w+image->header->width*3-q*3-2];
            nbgr[nsize*x+a+2]=bgr[size*w+image->header->width*3-q*3-1];
            a=a+3;
            //printf("%d\t%d\t%d\n",nbgr[size*x+a],nbgr[size*x+a+1],nbgr[size*x+a+2]);
            w++;
            if(w>=image->header->height)
            {
                w=0;
                q++;
            }
        }
    }
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=header;
    img->data=(struct pixel*)nbgr;
    return img;
}

struct bmp_image* rotate_left(const struct bmp_image* image)
{
    
    if(image==NULL)
    {
        return NULL;
    }
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    unsigned char *bgr=malloc(image->header->image_size);
    memcpy(bgr,image->data,image->header->image_size);
    uint32_t save=header->width;
    header->width=header->height;
    header->height=save;
    uint32_t new_size=header->width*3;
    if(new_size%2==0)
    {
        new_size=new_size+2;
    }
    else
    {
        new_size=new_size+1;
    }
    header->image_size=header->height*new_size;
    header->size=header->image_size+(uint32_t)sizeof(struct bmp_header);
    unsigned char *nbgr=malloc(header->image_size);
    memcpy(nbgr,image->data,image->header->image_size);
    for(int i=0;i<header->image_size;i++)
    {
        nbgr[i]=0;
    }
    uint32_t size=image->header->image_size/image->header->width;
    uint32_t nsize=header->image_size/header->width;
    uint32_t q=0;
    uint32_t w=0;
    for(uint32_t x=0;x<header->height;x++)
    {
        uint32_t a=0;
        for(uint32_t i=0;i<header->width;i++)
        {
            //printf("%d\t%d\n",size*x+a,size*w+image->header->width*3-q*3-3);
            //printf("%d\t%d\t%d\n",bgr[size*i+image->header->width*3-x*3-3],bgr[size*i+image->header->width*3-x*3-2],bgr[size*i+image->header->width*3-x*3-1]);
            nbgr[nsize*i+image->header->width*3-x*3-3]=bgr[size*x+a];
            nbgr[nsize*i+image->header->width*3-x*3-2]=bgr[size*x+a+1];
            nbgr[nsize*i+image->header->width*3-x*3-1]=bgr[size*x+a+2];
            a=a+3;
            //printf("%d\t%d\t%d\n",nbgr[size*x+a],nbgr[size*x+a+1],nbgr[size*x+a+2]);
            w++;
            if(w>=image->header->height)
            {
                w=0;
                q++;
            }
        }
    }
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=header;
    img->data=(struct pixel*)nbgr;
    return img;
}

struct bmp_image* scale(const struct bmp_image* image, float factor)
{
    if(image==NULL)
    {
        return NULL;
    }
    if(factor<=0)
    {
        return NULL;
    }
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    struct pixel *data = (struct pixel*) malloc(sizeof(struct pixel));
    memcpy(data,image->data,image->header->image_size);
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=header;
    img->data=data;
    return img;
}

struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width)
{
    if(image==NULL)
    {
        return NULL;
    }
    if(height<=0||height>=image->header->height)
    {
        return NULL;
    }
    if(width<=0||width>=image->header->width)
    {
        return NULL;
    }
    if(start_y<0||start_y>=image->header->height)
    {
        return NULL;
    }
    if(start_x<0||start_x>=image->header->width)
    {
        return NULL;
    }
    if(start_y+height>image->header->height)
    {
        return NULL;
    }
    if(start_x+width>image->header->width)
    {
        return NULL;
    }
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    struct pixel *data = (struct pixel*) malloc(sizeof(struct pixel));
    memcpy(data,image->data,image->header->image_size);
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=header;
    img->data=data;
    return img;




    /*unsigned char *bgr=malloc(image->header->image_size);
    memcpy(bgr,image->data,image->header->image_size);
    header->width=width;
    header->height=height;
    uint32_t new_size=width*3;
    if(new_size%2==0)
    {
        new_size=new_size+2;
    }
    else
    {
        new_size=new_size+1;
    }
    header->image_size=height*new_size;
    header->size=header->image_size+(uint32_t)sizeof(struct bmp_header);
    unsigned char *nbgr=malloc(header->image_size);
    memcpy(nbgr,image->data,header->image_size);
    uint32_t nsize=header->image_size/header->width;
    for(int i=0;i<header->image_size;i++)
    {
        nbgr[i]=0;
    }
    uint32_t size=image->header->image_size/image->header->width;
    for(uint32_t x=0;x<height;x++)
    {
        uint32_t a=0;
        for(uint32_t i=0;i<width;i++)
        {
            //printf("%d\t%d\n",nsize*(width-x-1)+a,(image->header->height-start_y-1)*size+start_x*3+a-x*size);
            nbgr[nsize*(width-x-1)+a]=bgr[(image->header->height-start_y-1)*size+start_x*3+a-x*size];
            nbgr[nsize*(width-x-1)+a+1]=bgr[(image->header->height-start_y-1)*size+start_x*3+a-x*size+1];
            nbgr[nsize*(width-x-1)+a+2]=bgr[(image->header->height-start_y-1)*size+start_x*3+a-x*size+2];
            a=a+3;
        }
    }
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=header;
    img->data=data;
    return img;*/
}

struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep)
{
    if(image==NULL)
    {
        return NULL;
    }
    if(colors_to_keep==NULL)
    {
        return NULL;
    }
    int keep[3]={0,0,0};
    for(int i=0;i<strlen(colors_to_keep);i++)
    {
        if(colors_to_keep[i]=='b')
        {
            keep[0]=1;
        }
        else if(colors_to_keep[i]=='g')
        {
            keep[1]=1;
        }
        else if(colors_to_keep[i]=='r')
        {
            keep[2]=1;
        }
        else
        {
            return NULL;
        }
    }
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    unsigned char *bgr=malloc(image->header->image_size);
    memcpy(bgr,image->data,image->header->image_size);
    uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->height;x++)
    {
        uint32_t a=0;
        for(uint32_t i=0;i<image->header->width;i++)
        {
            if(keep[0]!=1)
            {
                bgr[size*x+a]=0;
            }
            if(keep[1]!=1)
            {
                bgr[size*x+a+1]=0;
            }
            if(keep[2]!=1)
            {
                bgr[size*x+a+2]=0;
            }
            a=a+3;
        }
    }
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=header;
    img->data=(struct pixel*)bgr;
    return img;
}
