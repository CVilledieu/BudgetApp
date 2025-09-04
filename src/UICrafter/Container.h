#ifndef WIDGET_H
#define WIDGET_h

#include "mesh.h"

typedef struct Container{
    int visible;
    float height, width;
    float* pos; // pos[0] = x, pos[1] = y
    unsigned int child_count;
    Container* children;
    Container* parent;
    Mesh* mesh;
} Container;

typedef struct Widget{
    int visible;
    float height, width;
    float* pos; // pos[0] = x, pos[1] = y
    Widget* parent;
    Widget* children;
    Mesh* mesh;
} Widget;

#endif