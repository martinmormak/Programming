#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bmp.h"
#include "transformations.h"

int main()
{
    FILE* stream=fopen("assets/cherry.bmp","rb");
    //FILE* stream=fopen("file.bmp","rb");
    //FILE* stream=fopen("skuska.bmp","rb");
    if(stream==NULL)
    {
        return false;
    }
    struct bmp_image* image=read_bmp(stream);
    fclose(stream);
    struct bmp_image* img1;
    img1=flip_horizontally(image);
    stream=fopen("save1.bmp","w");
    if(stream==NULL)
    {
        return false;
    }
    printf("%d\n",write_bmp(stream,img1));
    free(img1);
    fclose(stream);
    struct bmp_image* img2;
    img2=flip_vertically(image);
    stream=fopen("save2.bmp","w");
    if(stream==NULL)
    {
        return false;
    }
    printf("%d\n",write_bmp(stream,img2));
    free(img2);
    fclose(stream);
    struct bmp_image* img3;
    img3=rotate_right(image);
    stream=fopen("save3.bmp","w");
    if(stream==NULL)
    {
        return false;
    }
    printf("%d\n",write_bmp(stream,img3));
    free(img3);
    fclose(stream);
    struct bmp_image* img4;
    img4=rotate_left(image);
    stream=fopen("save4.bmp","w");
    if(stream==NULL)
    {
        return false;
    }
    printf("%d\n",write_bmp(stream,img4));
    free(img4);
    fclose(stream);
    float factor=(float)0.559676;
    const uint32_t start_y=10;
    const uint32_t start_x=10;
    const uint32_t height=20;
    const uint32_t width=20;
    const char* colors_to_keep="rgb";
    struct bmp_image* img5;
    img5=scale(image, factor);
    stream=fopen("save5.bmp","w");
    if(stream==NULL)
    {
        return false;
    }
    printf("%d\n",write_bmp(stream,img5));
    free(img5);
    fclose(stream);
    struct bmp_image* img6;
    img6=crop(image, start_y, start_x, height, width);
    stream=fopen("save6.bmp","w");
    if(stream==NULL)
    {
        return false;
    }
    printf("%d\n",write_bmp(stream,img6));
    free(img6);
    fclose(stream);
    struct bmp_image* img7;
    img7=extract(image, colors_to_keep);
    stream=fopen("save7.bmp","w");
    if(stream==NULL)
    {
        return false;
    }
    printf("%d\n",write_bmp(stream,img7));
    free(img7);
    fclose(stream);
    free_bmp_image(image);
    return 0;
}
