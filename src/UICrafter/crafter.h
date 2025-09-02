#ifndef CRAFTER_H
#define CRAFTER_H

#include <glad/glad.h>
#include "GLFW/glfw3.h"


typedef struct WndCtx {
    int height;
    int width;
    GLFWwindow* wnd;
} WndCtx;

typedef struct UIctx {
    float* bgColor; //4 index array initialized to white
    WndCtx* wnd;
} UICtx;



WndCtx* WndCtx_Init(char* title);
UICtx* UICtx_Init(char* title);
void Render(UICtx* ctx);

typedef struct Mesh{
    unsigned int VAO;
    unsigned int shader;
}Mesh;


typedef struct Widget Widget;

struct Widget{
    int visible;
    float height;
    float width;
    float* pos;
    float* color;
    Widget* parent;
    Widget* children;
    Mesh* mesh;
};

#endif