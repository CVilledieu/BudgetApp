#ifndef FRAME_H
#define FRAME_H

#include "render.h"

typedef struct Panel {
    int id;
    float *matrix;
    float *color;
    Frame *frame;
} Panel;

typedef struct Container {
    int id;
    unsigned int child_count;
    float *matrix;
    Panel **children;
    Container *parent;
} Container;

#endif