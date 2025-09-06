#ifndef CRAFTER_H
#define CRAFTER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "widget.h"
#include "shaders.h"



typedef struct UICtx {
    int wnd_width;
    int wnd_height;
    char* wnd_title;
    Shader shader;
    GLFWwindow* wnd;
    Widget* canvas;
} UICtx;



UICtx* UICtx_init(char* title); 
void render(UICtx* ctx);




#endif