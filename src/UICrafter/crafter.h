#ifndef CRAFTER_H
#define CRAFTER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "wnd.h"
#include "widget.h"


typedef struct UICtx {
    int wnd_width;
    int wnd_height;
    char* wnd_title;
    GLFWwindow* wnd;
    Widget* canvas;
} UICtx;



UICtx* UICtx_init(char* title); 
void Canvas_render(UICtx* ctx);




#endif