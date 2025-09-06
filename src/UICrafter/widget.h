#ifndef WIDGET_H
#define WIDGET_h

#include "mesh.h"

typedef struct Shape {
    Vec2 scale;
    Vec2 position; 
    Vec4 color;
    Mesh* mesh;
} Shape;

typedef struct Widget{
    int visible;
    unsigned int child_count;
    Widget* children;
    Widget* parent;
    Shape* shape;
    void* data;
} Widget;



#endif