#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "wnd.h"
#include "crafter.h"



UICtx* UICtx_init(char* title){
    UICtx* ctx = malloc(sizeof(UICtx));
    ctx->wnd_title = title;
    ctx->wnd_width = 800;
    ctx->wnd_height = 600;
    WndCtx_Init(ctx);
    ctx->canvas = NULL;
    return ctx;
}



static void render_setup(float* color){
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT );
}

static void render_end(GLFWwindow* wnd){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}

void render_ui(UICtx* ctx){
    render_setup(ctx->canvas->color);
    
    

    render_cleanup(ctx->wnd);
}




