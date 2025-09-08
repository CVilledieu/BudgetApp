#ifndef WIDGET_H
#define WIDGET_h

#include "mesh.h"

typedef struct View {
    unsigned int shader_id;
    Vec2 scale;
    Vec2 position; 
    Vec4 color;
    Mesh* mesh;
} View;

typedef struct Widget{
    int visible;
    unsigned int child_count;
    Widget* children;
    Widget* parent;
    View* view;
    void* data;
} Widget;

#endif