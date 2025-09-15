#ifndef CRAFTER_H
#define CRAFTER_H

#include "wnd.h"
#include "mesh.h"

typedef struct UICtx {
    WndCtx* wnd;
    Mat4 view;
} UICtx;


UICtx* UICtx_init(char* title); 
void render(UICtx* ctx);

#endif