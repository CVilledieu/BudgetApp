#ifndef WIDGET_H
#define WIDGET_H


#include "mesh.h"

typedef struct Widget{
    int visible;
    unsigned int child_count;
    Widget* children;
    Widget* parent;
    RenderData* render_data;
} Widget;

typedef enum Widget_Type{
    CONTAINER_TYPE_CANVAS,
    CONTAINER_TYPE_CONTAINER,
    CONTAINER_TYPE_BUTTON, 
} Widget_Type;

typedef struct RenderData {
    Mat4 model;
    Vec4 color;
    MeshType* type;
} RenderData;


#endif