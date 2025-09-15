#ifndef CRAFTER_H
#define CRAFTER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "mesh.h"

typedef struct UICtx {
    int wnd_width;
    int wnd_height;
    char* wnd_title;
    GLFWwindow* wnd;
    Widget* canvas;
} UICtx;

UICtx* UICtx_init(char* title); 
void render(UICtx* ctx);

typedef struct Widget{
    int visible;
    unsigned int child_count;
    Widget* children;
    Widget* parent;
    void* data;
} Widget;

typedef struct Frame {
    Mat4 model;
    Vec4 color;
} Frame;



#endif