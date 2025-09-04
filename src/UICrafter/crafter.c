#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "wnd.h"

typedef struct UICtx {
    float* bg_color; //4 index array initialized to white
    WndCtx* wnd_ctx;
} UICtx;

void UI_background_color(UICtx* ctx, float* color){
    ctx->bg_color[0] = color[0];
    ctx->bg_color[1] = color[1];
    ctx->bg_color[2] = color[2];
    ctx->bg_color[3] = color[3];
}

UICtx* UICtx_init(char* title){
    UICtx* ctx = malloc(sizeof(UICtx));
    ctx->wnd_ctx = WndCtx_Init(title);
    
    ctx->bg_color = malloc(sizeof(float) * 4);
    UI_background_color(ctx, (float[]){1.0f, 1.0f, 1.0f, 1.0f});
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
    render_init(ctx->bg_color);
    
    

    render_end(ctx->wnd_ctx);
}



