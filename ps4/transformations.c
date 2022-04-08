#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "bmp.h"
#include "transformations.h"

struct bmp_image* flip_horizontally(const struct bmp_image* image)
{
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
    return NULL;
}
