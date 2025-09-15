#ifndef CRAFTER_H
#define CRAFTER_H

#include "wnd.h"
#include "mesh.h"

#define MAX_MESH_TYPES 1

typedef struct UICtx {
    WndCtx* wnd;
    Mat4 view;
    Vec4 panel_color;
    Mesh meshs[MAX_MESH_TYPES];
} UICtx;


UICtx* UICtx_init(char* title); 
void render_UI(UICtx* uc);

#endif