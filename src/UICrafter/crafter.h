#ifndef CRAFTER_H
#define CRAFTER_H

#include <glad/glad.h>
#include "GLFW/glfw3.h"


typedef struct WndCtx {
    int height;
    int width;
    GLFWwindow* wnd;
    UICtx* ui;
} WndCtx;

typedef struct UIctx {
    float* bgColor; //4 index array initialized to white
    WndCtx* wnd;
} UICtx;



WndCtx* WndCtx_Init(char* title);
UICtx* UICtx_Init(char* title);

#endif