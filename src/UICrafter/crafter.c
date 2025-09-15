#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "wnd.h"
#include "crafter.h"



#include <stdlib.h>

UICtx* UICtx_init(char* title){
    UICtx* ctx = malloc(sizeof(UICtx));
    ctx->wnd = init_WndCtx(title, 600, 800);
    return ctx;
}



static void render_setup(){
    glClearColor(0.0f, 0.0f, 0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

static void render_cleanup(WndCtx* wc){
    glfwSwapBuffers(wc->wnd);
    glfwPollEvents();
}

static void render_ui(Widget* root){

}

void render(UICtx* ctx){
    render_setup();
    render_ui(ctx->canvas);
    render_cleanup(ctx->wnd);
}




//Tasks:
//  Function: Convert pos 
//          Pos(0,0) should be in upper left corner and be based on parent
//
//  Function: Add child
//
//  Function: Remove child
//  
//  Function: Update visiblity
//
//  ENUM
// 

typedef enum Widget_Type{
    CONTAINER_TYPE_CANVAS,
    CONTAINER_TYPE_CONTAINER,
    CONTAINER_TYPE_BUTTON, 
} Widget_Type;


Widget* Widget_create(Widget_Type type){
    Widget* new = malloc(sizeof(Widget));
    switch(type){
        case CONTAINER_TYPE_CANVAS:
            break;
        case CONTAINER_TYPE_CONTAINER:
            break;
        case CONTAINER_TYPE_BUTTON:
            break;
    }
    return new;
}




void Shape_draw(Shader* shader, Widget* widget){
    glUseProgram(shader->id);
    glUniform2fv(shader->pos_u_loc, 1, widget->position);
    glUniform2fv(shader->scale_u_loc, 1, widget->scale);
    glUniform4fv(shader->color_u_loc, 1, widget->color);

    glBindVertexArray(widget->mesh->VAO);
    glDrawElements(GL_TRIANGLES, widget->mesh->index_count, GL_UNSIGNED_INT, 0);

    //Unbind to prevent anything unintended
    glBindVertexArray(0);
}