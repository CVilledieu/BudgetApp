#ifndef CRAFTER_H
#define CRAFTER_H

#include "wnd.h"
#include "mesh.h"

typedef struct UICtx {
    WndCtx* wnd;
    Mat4 view;
    Vec4 panel_color;
    Mesh meshes[MAX_MESH_TYPES];
} UICtx;


UICtx* init_UICtx(char* title); 
void render(UICtx* uc);

#endif