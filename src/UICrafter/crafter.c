#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "wnd.h"
#include "crafter.h"




UICtx* UICtx_init(char* title){
    UICtx* ctx = malloc(sizeof(UICtx));
    ctx->wnd_ctx = WndCtx_Init(title);
    ctx->containers = Container_create();

    return ctx;
}


static void render_init(float* color){
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT );
}

static void render_end(WndCtx* ctx){
    glfwSwapBuffers(ctx->wnd);
    glfwPollEvents();
}

void Render(UICtx* ctx){
    render_init(ctx->containers->mesh->color);
    
    

    render_end(ctx->wnd_ctx);
}



