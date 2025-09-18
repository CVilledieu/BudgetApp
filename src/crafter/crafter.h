#ifndef CRAFTER_H
#define CRAFTER_H

#include "wnd.h"
#include "mesh.h"


typedef struct Crafter{

} Crafter;

typedef struct UICtx {
    WndCtx* wnd;
    Mat4 view;
    Vec4 panel_color;
    Shader shaders[SHADER_TYPE_COUNT];
    Mesh meshes[MESH_TYPE_COUNT];
} UICtx;


UICtx* init_UICtx(char* title); 
void render(UICtx* uc);

#endif