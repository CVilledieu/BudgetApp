#ifndef WIDGET_H
#define WIDGET_h

#include "mesh.h"

typedef struct Widget{
    int visible;
    float height, width;
    unsigned int child_count;
    float* pos; // pos[0] = x, pos[1] = y
    float* color; 
    Widget* children;
    Widget* parent;
    Mesh* mesh;
} Widget;



#endif