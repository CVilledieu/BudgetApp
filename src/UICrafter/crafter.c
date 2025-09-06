#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "wnd.h"
#include "crafter.h"
#include "shaders.h"


UICtx* UICtx_init(char* title){
    UICtx* ctx = malloc(sizeof(UICtx));
    ctx->wnd_title = title;
    ctx->wnd_width = 800;
    ctx->wnd_height = 600;
    WndCtx_init(ctx);
    Shader_create_id(&ctx->shader);
    return ctx;
}



static void render_setup(){
    glClearColor(0.0f, 0.0f, 0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

static void render_cleanup(GLFWwindow* wnd){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}

static void render_ui(Widget* root){

}

void render(UICtx* ctx){
    render_setup();
    render_ui(ctx->canvas);
    render_cleanup(ctx->wnd);
}




