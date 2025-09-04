#ifndef CRAFTER_H
#define CRAFTER_H

#include "wnd.h"
#include "Container.h"




typedef struct UICtx {
    unsigned int container_count;
    Container* containers;
    WndCtx* wnd_ctx;
} UICtx;


UICtx* UICtx_Init(char* title); 
void Render(UICtx* ctx);




#endif