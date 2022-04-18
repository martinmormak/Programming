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
    struct bmp_image *new_image=malloc(sizeof(struct bmp_image));
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    new_image->data=malloc(image->header->image_size*3);
    //uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->height;x++)
    {
        for(uint32_t i=0;i<image->header->width;i++)
        {
            //printf("%d\t%d\t%d\t%d\t%d\t%d\n",x,i,a,size,size*x+a,image->header->image_size-size*x-size+a);
            new_image->data[image->header->width*x+i]=image->data[image->header->width*x+(image->header->width-i-1)];
        }
    }
    new_image->header=header;
    return new_image;
}

struct bmp_image* flip_vertically(const struct bmp_image* image)
{
    if(image==NULL)
    {
        return NULL;
    }
    struct bmp_image *new_image=malloc(sizeof(struct bmp_image));
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    new_image->data=malloc(image->header->image_size*3);
    //uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->height;x++)
    {
        for(uint32_t i=0;i<image->header->width;i++)
        {
            //printf("%d\t%d\t%d\t%d\t%d\t%d\n",x,i,a,size,size*x+a,image->header->image_size-size*x-size+a);
            new_image->data[image->header->width*x+i]=image->data[image->header->width*(image->header->height-x-1)+i];
            //new_image->data[image->header->width*x+i]=image->data[image->header->width*x+(image->header->width-i-1)];
        }
    }
    new_image->header=header;
    return new_image;
}

struct bmp_image* rotate_right(const struct bmp_image* image)
{   
    if(image==NULL)
    {
        return NULL;
    }
    struct bmp_image *new_image=malloc(sizeof(struct bmp_image));
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    new_image->header=header;
    new_image->header->width=image->header->height;
    new_image->header->height=image->header->width;
    new_image->header->image_size=new_image->header->height*new_image->header->width*3+((new_image->header->width%4)*new_image->header->height);
    new_image->header->size=(uint32_t)sizeof(struct bmp_header)+new_image->header->image_size;
    new_image->data=malloc(new_image->header->image_size*3);
    for(int i=0;i<new_image->header->image_size;i++)
    {
        new_image->data[i].blue=0;
        new_image->data[i].green=0;
        new_image->data[i].red=0;
    }
    //uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->width;x++)
    {
        for(uint32_t i=0;i<image->header->height;i++)
        {
            //printf("%d\t%d\t%d\t%d\t%d\t%d\n",x,i,a,size,size*x+a,image->header->image_size-size*x-size+a);
            new_image->data[new_image->header->width*x+i]=image->data[image->header->width*i+image->header->width-1-x];
            //new_image->data[image->header->width*x+i]=image->data[image->header->width*x+(image->header->width-i-1)];
        }
    }
    new_image->header=header;
    return new_image;
}

struct bmp_image* rotate_left(const struct bmp_image* image)
{
    if(image==NULL)
    {
        return NULL;
    }
    struct bmp_image *new_image=malloc(sizeof(struct bmp_image));
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    new_image->header=header;
    new_image->header->width=image->header->height;
    new_image->header->height=image->header->width;
    new_image->header->image_size=new_image->header->height*new_image->header->width*3+((new_image->header->width%4)*new_image->header->height);
    new_image->header->size=(uint32_t)sizeof(struct bmp_header)+new_image->header->image_size;
    new_image->data=malloc(new_image->header->image_size*3);
    for(int i=0;i<new_image->header->image_size;i++)
    {
        new_image->data[i].blue=0;
        new_image->data[i].green=0;
        new_image->data[i].red=0;
    }
    //uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->height;x++)
    {
        for(uint32_t i=0;i<image->header->width;i++)
        {
            //printf("%d\t%d\t%d\t%d\t%d\t%d\n",x,i,a,size,size*x+a,image->header->image_size-size*x-size+a);
            new_image->data[new_image->header->width*i+new_image->header->width-1-x]=image->data[image->header->width*x+i];
            //new_image->data[image->header->width*x+i]=image->data[image->header->width*x+(image->header->width-i-1)];
        }
    }
    new_image->header=header;
    return new_image;
}

struct bmp_image* scale(const struct bmp_image* image, float factor)
{
    if(image==NULL)
    {
        return NULL;
    }
    if(factor<0)
    {
        return NULL;
    }
    struct bmp_image *new_image=malloc(sizeof(struct bmp_image));
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    new_image->header=header;
    new_image->header->width=(uint32_t)(image->header->width*(uint32_t)(factor*10000+0.5)+5000)/10000;
    new_image->header->height=(uint32_t)(image->header->height*(uint32_t)(factor*10000+0.5)+5000)/10000;
    //printf("%d\t%d\n",image->header->height,image->header->width);
    //printf("%d\t%d\n",new_image->header->height,new_image->header->width);
    new_image->header->image_size=new_image->header->width*new_image->header->height*3+((new_image->header->width%4)*new_image->header->height);
    new_image->header->size=(uint32_t)sizeof(struct bmp_header)+new_image->header->image_size;
    new_image->data=malloc(new_image->header->image_size*3);
    //printf("%d\t%d\n",new_image->header->image_size,new_image->header->size);
    //uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<new_image->header->height;x++)
    {
        for(uint32_t i=0;i<new_image->header->width;i++)
        {
            uint32_t o_x=(uint32_t)((float)x/factor);
            uint32_t o_i=(uint32_t)((float)i/factor);
            //printf("%d\t%d\t%d\t%d\n",x,i,o_x,o_i);
            //printf("%d\t%d\t%d\t%d\t%d\t%d\n",x,i,a,size,size*x+a,image->header->image_size-size*x-size+a);
            new_image->data[new_image->header->width*x+i]=image->data[image->header->width*o_x+o_i];
            //new_image->data[image->header->width*x+i]=image->data[image->header->width*x+(image->header->width-i-1)];
        }
    }
    new_image->header=header;
    return new_image;
}

struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width)
{
    //printf("%d\t%d\n",image->header->width,image->header->height);
    if(image==NULL)
    {
        return NULL;
    }
    if(height<0||height>image->header->height)
    {
        return NULL;
    }
    if(width<0||width>image->header->width)
    {
        return NULL;
    }
    if(start_y<0||start_y>image->header->height)
    {
        return NULL;
    }
    if(start_x<0||start_x>image->header->width)
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
    struct bmp_image *new_image=malloc(sizeof(struct bmp_image));
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    new_image->header=header;
    new_image->header->width=width;
    new_image->header->height=height;
    new_image->header->image_size=new_image->header->height*new_image->header->width*3+((new_image->header->width%4)*new_image->header->height);
    new_image->header->size=(uint32_t)sizeof(struct bmp_header)+new_image->header->image_size;
    new_image->data=malloc(new_image->header->image_size*3);
    for(int i=0;i<new_image->header->image_size;i++)
    {
        new_image->data[i].blue=0;
        new_image->data[i].green=0;
        new_image->data[i].red=0;
    }
    //uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->width;x++)
    {
        for(uint32_t i=0;i<image->header->height;i++)
        {
            //printf("%d\t%d\t%d\t%d\t%d\t%d\n",x,i,a,size,size*x+a,image->header->image_size-size*x-size+a);
            //printf("%d\t%d\t%d\n",i,x,(image->header->height-height-start_y+x)*image->header->width+start_x+i);
            new_image->data[new_image->header->height*x+i]=image->data[(image->header->height-height-start_y+x)*image->header->width+start_x+i];
            //new_image->data[image->header->width*x+i]=image->data[image->header->width*x+(image->header->width-i-1)];
        }
    }
    new_image->header=header;
    return new_image;
    
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
    struct bmp_image *new_image=malloc(sizeof(struct bmp_image));
    struct bmp_header *header = (struct bmp_header*) malloc(sizeof(struct bmp_header));
    memcpy(header,image->header,sizeof(struct bmp_header));
    new_image->data=malloc(image->header->image_size*3);
    //uint32_t size=image->header->image_size/image->header->height;
    for(uint32_t x=0;x<image->header->height;x++)
    {
        for(uint32_t i=0;i<image->header->width;i++)
        {
            new_image->data[image->header->width*x+i]=image->data[image->header->width*x+i];
            if(keep[0]!=1)
            {
                new_image->data[image->header->width*x+i].blue=0;
            }
            if(keep[1]!=1)
            {
                new_image->data[image->header->width*x+i].green=0;
            }
            if(keep[2]!=1)
            {
                new_image->data[image->header->width*x+i].red=0;
            }
        }
    }
    new_image->header=header;
    return new_image;
}
