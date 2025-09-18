//
//
//
//
//
#include <stdlib.h>
#include "widget.h"

static RenderData* create_RenderData(MeshType type, Vec2 pos, float height, float width);

Widget* create_Widget(Widget* parent, Widget_Type type, Vec2 pos, float height, float width){
    Widget* new_widget = malloc(sizeof(Widget));
    new_widget->render_data = create_RenderData(type, pos, height, width);
    new_widget->child_count = 0;
    new_widget->children = NULL;
    new_widget->parent = parent;
    switch(type){
        case CONTAINER:
            new_widget->visible = 1;

            break;
        case BUTTON:
            new_widget->visible = 1;
            break;
        case LABEL:
            break;
        default:
            //Catch and handle errors
            break;
    }
    return new_widget;
}

static RenderData* create_RenderData(MeshType type, Vec2 pos, float height, float width){
    RenderData* render_data = malloc(sizeof(RenderData));


    return render_data;
}

//At the moment functions is simple, but will add functionality 
//Based on RenderData's MeshType will change which uniforms get set
void set_render_data(Shader* shader, RenderData* render_data){
    for (int i = 0; i < shader->uniform_count; i++){
        
    }
    set_uniform(shader->color_u_loc, render_data->color, UNI_VEC4);
    set_uniform(shader->model_u_loc, render_data->model, UNI_MAT4);
}