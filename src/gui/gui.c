#include "elements.h"
#include "window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef struct Gctx {
    unsigned int shaderId;
    Panel **panels;
    GLFWwindow *Wnd;
} GCtx;

GCtx *gui_init(){
    GCtx ctx;
    ctx.Wnd = wnd_init("Budget App");
    if (!ctx.Wnd) {
        return NULL;
    }

}

void gui_render(GCtx *ctx) {

    while(!glfwWindowShouldClose(ctx->Wnd)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        
        // APP loggic here
        // Render UI elements

        

        glfwSwapBuffers(ctx->Wnd);
        glfwPollEvents();
    }

    glfwDestroyWindow(ctx->Wnd);
    glfwTerminate();
}
