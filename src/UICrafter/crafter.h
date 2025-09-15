#ifndef CRAFTER_H
#define CRAFTER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "mesh.h"


typedef struct UICtx {
    int wnd_width;
    int wnd_height;
    char* wnd_title;
    Shader shader;
    GLFWwindow* wnd;
    Widget* canvas;
} UICtx;

typedef struct RenderCtx {
    Shader* shaders;
} RenderCtx;

UICtx* UICtx_init(char* title); 
void render(UICtx* ctx);



typedef struct Widget{
    int visible;
    unsigned int shader_id;
    Vec2 scale;
    Vec2 position; 
    Vec4 color;
    Mesh* mesh;
    unsigned int child_count;
    Widget* children;
    Widget* parent;
    void* data;
} Widget;

#endif