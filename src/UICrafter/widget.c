#include "widget.h"

static void draw(RenderData* rend_data, Mat4 view);

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



//Currently using glUseProgram on each draw call, but will update
static void draw(RenderData* rend_data, Mat4 view){
    Mesh* mesh_ptr = rend_data->mesh;
    glUseProgram(mesh_ptr->shader->id);
    set_uniform(mesh_ptr->shader->color_u_loc, rend_data->color, UT_VEC4);
    set_uniform(mesh_ptr->shader->model_u_loc, rend_data->model, UT_MAT4);
    set_uniform(mesh_ptr->shader->view_u_loc, view, UT_MAT4);
    render_Mesh(mesh_ptr);

    //Unbind to prevent anything unintended
    glBindVertexArray(0);
}