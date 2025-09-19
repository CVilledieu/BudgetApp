//
//Renderer controls the aspects of drawing the various elements
//This includes converting the non-screen space coordinate system used in the elements
//Outside renderer nothing should need to call either the mesh or shader functions directly
//
//UI manager should call the render function passing in the positional data
//
//Orthographic projection
//
#include "renderer.h"

void init_Shader_array(Shader shaders[SHADER_TYPE_COUNT]);
void init_Mesh_array(Mesh meshes[MESH_TYPE_COUNT]);

Renderer* create_Renderer(){
    Renderer* renderer = malloc(sizeof(Renderer));
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

void render_element(Renderer renderer){

}

