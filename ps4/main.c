#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bmp.h"
#include "transformations.h"

int main()
{
    FILE* stream=(FILE*)"assets/adventurer.bmp";
    struct bmp_image* image=read_bmp(stream);
    /*uint32_t size=image->header->height*image->header->width;
    for(int i=(int)(size);i>0;i--)
    {
        printf("%d\t%d\t%d\t%d\n",i,image->data->blue,image->data->green,image->data->red);
        ++image->data;
    }*/
    //printf("%d\t%d\t%d\n",image->header->size,image->header->width,image->header->height);
    stream=(FILE*)"save.bmp";
    printf("%d\n",write_bmp(stream,image));
    flip_horizontally(image);
    flip_vertically(image);
    rotate_right(image);
    rotate_left(image);
    float factor=1;
    const uint32_t start_y=0;
    const uint32_t start_x=0;
    const uint32_t height=0;
    const uint32_t width=0;
    const char* colors_to_keep="rgb";
    scale(image, factor);
    crop(image, start_y, start_x, height, width);
    extract(image, colors_to_keep);
    free_bmp_image(image);
    return 0;
}
