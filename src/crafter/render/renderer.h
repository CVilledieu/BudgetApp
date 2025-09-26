#ifndef RENDERER_H
#define RENDERER_H

#include "mesh.h"
#include "wnd.h"

typedef struct Renderer{
    Mat4 view_Mat;
    WndCtx* wnd_ctx;
    Shader shaders[SHADER_TYPE_COUNT];
    Mesh meshes[MESH_TYPE_COUNT];
} Renderer;

typedef struct Model{
    float pos_x;
    float pos_y;
    float height;
    float width;
} Model;

typedef struct Model {
    float x;
    float y;
    float width;
    float height;
} Model;

#endif