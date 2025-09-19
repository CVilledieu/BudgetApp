#ifndef RENDERER_H
#define RENDERER_H

#include "mesh.h"

typedef struct Renderer{
    Mat4 view;
    Shader shaders[SHADER_TYPE_COUNT];
    Mesh meshes[MESH_TYPE_COUNT];
} Renderer;


#endif