#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "wnd.h"
#include "crafter.h"
#include "widget.h"


static void first_render_step(Vec4 color);
static void last_render_step(WndCtx* wc);


UICtx* UICtx_init(char* title){
    UICtx* uc = malloc(sizeof(UICtx));
    uc->wnd = init_WndCtx(title, 600, 800);
    return uc;
}




void render_UI(UICtx* uc){
    //Pre render processes

    int stop_render = 0;
    while(!stop_render){
        first_render_step(uc->panel_color);

        last_render_step(uc->wnd);
    }
}

static void render_element(Widget* widget, Mesh* mesh, Mat4 view){}


static void first_render_step(Vec4 color){
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}

static void last_render_step(WndCtx* wc){
    glfwSwapBuffers(wc->wnd);
    glfwPollEvents();
}

