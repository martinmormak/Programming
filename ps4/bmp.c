#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bmp.h"

struct bmp_image* read_bmp(FILE* stream)
{
    if(stream==NULL)
    {
        fprintf(stderr,"Error: This is not a BMP file.\n");
        return NULL;
    }
    if(stream==stdin)
    {
        fprintf(stderr,"Error: This is not a BMP file.\n");
        return NULL;
    }
    struct bmp_image *image=malloc(sizeof(struct bmp_image));
    if(image==NULL)
    {
        free(image);
        return NULL;
    }
    image->header=read_bmp_header(stream);
    struct bmp_header *head=image->header;
    //printf("%d\t%d\n",image->header->width,image->header->height);
    if(image->header==NULL)
    {
        fprintf(stderr,"Error: This is not a BMP file.\n");
        free(image);
        return NULL;
    }
    else if(&head->size==NULL||&head->height==NULL||&head->width==NULL)
    {
        fprintf(stderr,"Error: Corrupted BMP file.\n");
        free(image);
        return NULL;
    }
    image->data=malloc(sizeof(unsigned char) * (image->header->image_size));
    image->data=read_data(stream,head);
    if(image->data==NULL)
    {
        free(image);
        return NULL;
    }
    return image;
}

bool write_bmp(FILE* stream, const struct bmp_image* image)
{
    if(stream==NULL)
    {
        return NULL;
    }
    if(stream==stdin)
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
    fseek(stream,54,SEEK_SET);
    fwrite(image->data,sizeof(char),image->header->image_size,stream);
    fseek(stream,0,SEEK_SET);
    fwrite("BM",sizeof(uint16_t),1,stream);
    fwrite(&header.size,sizeof(uint32_t),1,stream);
    int32_t reserved = 0x0000;
    fwrite(&reserved,sizeof(uint16_t),1,stream);
    fwrite(&reserved,sizeof(uint16_t),1,stream);
    int32_t offset=0x00000036;
    fwrite(&offset,sizeof(uint32_t),1,stream);
    int32_t dib_size=0x00000028;
    fwrite(&dib_size,sizeof(uint32_t),1,stream);
    fwrite(&header.width,sizeof(uint32_t),1,stream);
    fwrite(&header.height,sizeof(uint32_t),1,stream);
    int32_t planes=0x0001;
    fwrite(&planes,sizeof(uint16_t),1,stream);
    int32_t bpp=0x0018;
    fwrite(&bpp,sizeof(uint16_t),1,stream);
    fwrite(&reserved,sizeof(uint32_t),1,stream);
    return true;
}

struct bmp_header* read_bmp_header(FILE* stream)
{
    if(stream==NULL)
    {
        return NULL;
    }
    if(stream==stdin)
    {
        return NULL;
    }
    struct bmp_header *header=malloc(sizeof(struct bmp_header));
    fseek(stream,0,SEEK_SET);
    fread(header,sizeof(struct bmp_header),1,stream);
    if(header->type!=19778)
    {
        free(header);
        return NULL;
    }
    return header;
}

struct pixel* read_data(FILE* stream, const struct bmp_header* header)
{
    if(stream==NULL)
    {
        return NULL;
    }
    if(stream==stdin)
    {
        return NULL;
    }
    if(header==NULL)
    {
        return NULL;
    }
    struct pixel *pixel=malloc(header->image_size);

    //uint32_t row_padded = (uint32_t)((header->width*3 + 3) & (uint32_t)(~3));
    uint32_t size=header->width*header->height*3+((header->width%4)*header->height);
    unsigned char* data = malloc(size);

    for(int i = 0; i < header->height; i++)
    {
        fread(data, sizeof(unsigned char), size, stream);
    }

    pixel=(struct pixel *)data;
    return pixel;
}

void free_bmp_image(struct bmp_image* image)
{
    if (image != NULL)
    {
        if (image->data != NULL)
        {
            free(image->data);
        }
        if (image->header != NULL)
        {
            free(image->header);
        }
        free(image);
    }
}
