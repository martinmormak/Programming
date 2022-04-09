#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bmp.h"
#include "transformations.h"

int main()
{
    //FILE* stream=(FILE*)"assets/adventurer.bmp";
    //FILE* stream=(FILE*)"file.bmp";
    FILE* stream=(FILE*)"skuska.bmp";
    struct bmp_image* image=read_bmp(stream);
    /*uint32_t size=image->header->height*image->header->width;
    for(int i=(int)(size);i>0;i--)
    {
        printf("%d\t%d\t%d\t%d\n",i,image->data->blue,image->data->green,image->data->red);
        ++image->data;
    }*/
    //printf("%d\t%d\t%d\n",image->header->size,image->header->width,image->header->height);
    image=rotate_right(image);
    stream=(FILE*)"save3.bmp";
    printf("%d\n",write_bmp(stream,image));
    image=rotate_left(image);
    stream=(FILE*)"save4.bmp";
    printf("%d\n",write_bmp(stream,image));
    image=flip_horizontally(image);
    stream=(FILE*)"save1.bmp";
    printf("%d\n",write_bmp(stream,image));
    image=flip_vertically(image);
    stream=(FILE*)"save2.bmp";
    printf("Ahoj");
    printf("%d\n",write_bmp(stream,image));
    printf("Ahoj");
    float factor=1;
    const uint32_t start_y=0;
    const uint32_t start_x=0;
    const uint32_t height=0;
    const uint32_t width=0;
    const char* colors_to_keep="rgb";
    printf("Ahoj");
    image=scale(image, factor);
    image=crop(image, start_y, start_x, height, width);
    image=extract(image, colors_to_keep);
    stream=(FILE*)"save5.bmp";
    printf("%d\n",write_bmp(stream,image));
    free_bmp_image(image);
    return 0;
}
