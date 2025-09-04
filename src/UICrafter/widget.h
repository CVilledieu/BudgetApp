#ifndef WIDGET_H
#define WIDGET_h

#include "mesh.h"

typedef struct Widget{
    int visible;
    float height;
    float width;
    float* pos;
    float* color;
    Widget* parent;
    Widget* children;
    Mesh* mesh;
} Widget;

#endif