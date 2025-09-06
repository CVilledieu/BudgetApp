#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "widget.h"
#include <stdlib.h>
#include "shaders.h"

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


//int visible, float* pos, float height, float width
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



void Shape_draw(Shader* shader, Shape* shape){
    glUseProgram(shader->id);
    glUniform2fv(shader->pos_u_loc, 1, shape->position);
    glUniform2fv(shader->scale_u_loc, 1, shape->scale);
    glUniform4fv(shader->color_u_loc, 1, shape->color);

    glBindVertexArray(shape->mesh->VAO);
    glDrawElements(GL_TRIANGLES, shape->mesh->index_count, GL_UNSIGNED_INT, 0);

    //Unbind to prevent anything unintended
    glBindVertexArray(0);
}
