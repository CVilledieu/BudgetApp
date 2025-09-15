#ifndef WND_H
#define WND_H

#include "GLFW/glfw3.h"

#define MAX_WND_TITLE 16

typedef struct WndCtx{
    int width;
    int height;
    char title[MAX_WND_TITLE];
    GLFWwindow* wnd;
} WndCtx;

WndCtx* init_WndCtx(char* title, int height, int width);

#endif