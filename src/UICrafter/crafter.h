#ifndef CRAFTER_H
#define CRAFTER_H

#include "wnd.h"



typedef struct UICtx UICtx;


UICtx* UICtx_Init(char* title); 
void Render(UICtx* ctx);




#endif