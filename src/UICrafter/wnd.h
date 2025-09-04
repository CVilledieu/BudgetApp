#ifndef WND_H
#define WND_H

typedef struct WndCtx {
    int height;
    int width;
    GLFWwindow* wnd;
} WndCtx;

WndCtx* WndCtx_Init(char* title);

#endif