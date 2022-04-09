#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"
#include "transformations.h"

struct bmp_image* flip_horizontally(const struct bmp_image* image)
{
    /*struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=image->header;
    img->data=image->data;
    uint32_t i=0;
    unsigned char *bgr=(unsigned char*)image->data;
    uint32_t size=image->header->image_size/image->header->height;
    printf("%d\t%d\n",image->header->height,image->header->width);
    for(uint32_t x=0;x<image->header->height;x++)
    {
        i=0;
        while(i<image->header->width-i-3)
        {
            unsigned char b;
            unsigned char g;
            unsigned char r;
            b=bgr[size*x+i];
            g=bgr[size*x+i+1];
            r=bgr[size*x+i+2];
            bgr[size*x+i]=bgr[size*x+image->header->width-i-3];
            bgr[size*x+i+1]=bgr[size*x+image->header->width-i-2];
            bgr[size*x+i+2]=bgr[size*x+image->header->width-i-1];
            bgr[size*x+image->header->width-i-3]=b;
            bgr[size*x+image->header->width-i-2]=g;
            bgr[size*x+image->header->width-i-1]=r;
            i=i+3;
            //printf("%d\t%d\t%d\n",bgr[i],bgr[i+1],bgr[i+2]);
        }
    }
    printf("%d\t%d\n",image->header->height,image->header->width);
    img->data=(struct pixel*)bgr;
    free(bgr);
    return img;*/
    return NULL;
}

struct bmp_image* flip_vertically(const struct bmp_image* image)
{
    return NULL;
}

struct bmp_image* rotate_right(const struct bmp_image* image)
{
    return NULL;
}

struct bmp_image* rotate_left(const struct bmp_image* image)
{
    return NULL;
}

struct bmp_image* scale(const struct bmp_image* image, float factor)
{
    return NULL;
}

struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width)
{
    return NULL;
}

struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep)
{
    int keep[3]={0,0,0};
    for(int i=0;i<strlen(colors_to_keep);i++)
    {
        if(colors_to_keep[i]=='b')
        {
            keep[0]=1;
        }
        if(colors_to_keep[i]=='g')
        {
            keep[1]=1;
        }
        if(colors_to_keep[i]=='r')
        {
            keep[2]=1;
        }
    }
    struct bmp_image *img=malloc(sizeof(struct bmp_image));
    img->header=image->header;
    img->data=image->data;
    unsigned char *bgr=(unsigned char*)image->data;
    uint32_t position=0;
    for(uint32_t x=0;x<image->header->image_size;x=position)
    {
        for(uint32_t i=0;i<image->header->width;i=i+3)
        {
            if(keep[0]!=1)
            {
                bgr[position]=0;
            }
            position++;
            if(keep[1]!=1)
            {
                bgr[position]=0;
            }
            position++;
            if(keep[2]!=1)
            {
                bgr[position]=0;
            }
            position++;
            //printf("%d\t%d\t%d\n",bgr[i],bgr[i+1],bgr[i+2]);
        }
        if((int)position%2!=0)
        {
            position++;
        }
    }
    img->data=(struct pixel*)bgr;
    return img;
}
