//
//Renderer controls the aspects of drawing the various elements
//This includes converting the non-screen space coordinate system used in the elements
//Outside renderer nothing should need to call either the mesh or shader functions directly
//
//UI manager should call the render function passing in the positional data
//

#include "renderer.h"

void init_Shader_array(Shader shaders[SHADER_TYPE_COUNT]);
void init_Mesh_array(Mesh meshes[MESH_TYPE_COUNT]);

Renderer* create_Renderer(char* title){
    Renderer* renderer = malloc(sizeof(Renderer));
    renderer->wnd_ctx = init_WndCtx(title, DEFAULT_HEIGHT, DEFAULT_WIDTH);
    init_Shader_array(renderer->shaders);
    init_Mesh_array(renderer->meshes);
    //set up view matrix
    return renderer;
}

void init_Shader_array(Shader shaders[SHADER_TYPE_COUNT]){
    for (int i = 0; i < SHADER_TYPE_COUNT; i++){
        init_Shader(&shaders[i], i);
    }
}

void init_Mesh_array(Mesh meshes[MESH_TYPE_COUNT]){
    for (int i = 0; i < MESH_TYPE_COUNT; i++){
        init_Shader(&meshes[i], i);
    }

}

void update_view_Mat(Renderer* renderer, int width, int height){
    renderer->view_Mat[0] = 2/width;
    renderer->view_Mat[3] = -1;
    renderer->view_Mat[5] = -2/height;
    renderer->view_Mat[7] = 1;
    renderer->view_Mat[10] = 1;
    renderer->view_Mat[15] = 1;
    
}

//Dynamically creating the model matrix to be used with the view matrix
void set_model_data(Renderer* renderer, Model model){
    float width = model.width;
    float height = model.height;
    float pos_x = model.x;
    float pos_y = model.y;
    float model_Mat4[16] = {
        width, 0, 0, 0,
        0, height, 0, 0,
        0, 0, 1, 0,
        pos_x, pos_y, 0, 1
    };
    set_uniform_data(renderer->shaders->uniforms[MODEL], model_Mat4);
}

static void prep_buffer(Vec4 color){
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}

static void swap_buffer(WndCtx* wc){
    glfwSwapBuffers(wc->wnd);
    glfwPollEvents();
}
