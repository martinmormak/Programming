#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bmp.h"

struct bmp_image* read_bmp(FILE* stream)
{
    struct bmp_image *image=malloc(sizeof(struct bmp_image));
    if(image==NULL)
    {
        free(image);
        return NULL;
    }
    image->header=read_bmp_header(stream);
    /*if(image->header==NULL)
    {
        printf("HEADER\n");
    }*/
    struct bmp_header *head=image->header;
    if(image->header==NULL)
    {
        printf("Error: This is not a BMP file.\n");
        free(image);
        return NULL;
    }
    else if(&head->size==NULL||&head->height==NULL||&head->width==NULL)
    {
        printf("Error: Corrupted BMP file.\n");
        free(image);
        return NULL;
    }
    struct bmp_header header;
    header.size=image->header->size;
    header.height=image->header->height;
    header.width=image->header->width;
    header.image_size=image->header->image_size;
    //printf("%d\t%d\t%d\n",image->header->height,image->header->width,image->header->image_size);
    image->data=malloc(sizeof(unsigned char) * (image->header->image_size));
    image->header->size=header.size;
    image->header->width=header.width;
    image->header->height=header.height;
    image->header->image_size=header.image_size;
    //printf("%d\t%d\t%d\n",image->header->height,image->header->width,image->header->image_size);
    image->data=read_data(stream,head);
    if(image->data==NULL)
    {
        free(image);
        return NULL;
    }
    image->header->size=header.size;
    image->header->width=header.width;
    image->header->height=header.height;
    image->header->image_size=header.image_size;
    //printf("%d\t%d\t%d\n",image->header->height,image->header->width,image->header->image_size);
    return image;
}

bool write_bmp(FILE* stream, const struct bmp_image* image)
{
    if(stream==NULL)
    {
        return NULL;
    }
    if(image==NULL)
    {
        return NULL;
    }
    struct bmp_header header;
    header.size=image->header->size;
    header.height=image->header->height;
    header.width=image->header->width;
    header.image_size=image->header->image_size;
    FILE* f=fopen((char*)stream,"w");
    if(f==NULL)
    {
        return false;
    }
    if(fwrite(&image->header,sizeof(struct bmp_header),1,f)!=1)
    {
        fclose(f);
        return false;
    }
    image->header->size=header.size;
    image->header->width=header.width;
    image->header->height=header.height;
    image->header->image_size=header.image_size;
    //printf("%d\n",image->header->image_size);
    fseek(f,54,SEEK_SET);
    fwrite(image->data,sizeof(char),image->header->image_size,f);
    /*if(fwrite(image->data,sizeof(char),image->header->image_size,f)!=1)
    {
        return false;
    }*/
    image->header->size=header.size;
    image->header->width=header.width;
    image->header->height=header.height;
    image->header->image_size=header.image_size;
    fseek(f,0,SEEK_SET);
    fwrite("BM",sizeof(uint16_t),1,f);
    fwrite(&header.size,sizeof(uint32_t),1,f);
    int32_t reserved = 0x0000;
    fwrite(&reserved,sizeof(uint16_t),1,f);
    fwrite(&reserved,sizeof(uint16_t),1,f);
    int32_t offset=0x00000036;
    fwrite(&offset,sizeof(uint32_t),1,f);
    int32_t dib_size=0x00000028;
    fwrite(&dib_size,sizeof(uint32_t),1,f);
    fwrite(&header.width,sizeof(uint32_t),1,f);
    fwrite(&header.height,sizeof(uint32_t),1,f);
    int32_t planes=0x0001;
    fwrite(&planes,sizeof(uint16_t),1,f);
    int32_t bpp=0x0018;
    fwrite(&bpp,sizeof(uint16_t),1,f);
    fwrite(&reserved,sizeof(uint32_t),1,f);
    fclose(f);
    return true;
}

struct bmp_header* read_bmp_header(FILE* stream)
{
    if(stream==NULL)
    {
        return NULL;
    }
    unsigned char *header=(unsigned char*)malloc(55);
    FILE* f=fopen((char*)stream,"rb");
    if(f==NULL)
    {
        free(header);
        return NULL;
    }
    fseek(f,0,SEEK_SET);
    fread(header,54,1,f);
    fclose(f);
    return (struct bmp_header*) header;
}

struct pixel* read_data(FILE* stream, const struct bmp_header* header)
{
    if(stream==NULL)
    {
        return NULL;
    }
    if(header==NULL)
    {
        return NULL;
    }
    unsigned char *pixel=(unsigned char*)malloc(header->image_size);
    FILE* f=fopen((char*)stream,"rb");
    if(f==NULL)
    {
        free(pixel);
        return NULL;
    }
    if (!pixel)
    {
        free(pixel);
        fclose(f);
        return NULL;
    }
    fseek(f,54,SEEK_SET);
    fread(pixel,header->image_size,1,f);
    fclose(f);
    return (struct pixel *) pixel;
}

void free_bmp_image(struct bmp_image* image)
{
    if (image != NULL)
    {
        if (image->data != NULL)
        {
            free(image->data);
        }
        free(image);
    }
    return;
}
