//
//An array containing all Meshes should be initialized near at start up
//The Widget should contain a MeshType that can be used to refrence the Mesh needed during render
//The goal / reason for this is to reduce the number of meshes needed
//
//Due to currently only having 1 MeshType so I have avoided unnecessary complexity 
//Once additional Meshtpes are needed many functions will be updated to handle them
//Areas that are expected to be updated with MeshTyping have been noted as such
//
#include "mesh.h"

//Forward declarations
static void create_VertexData(VertexObject* vo);

//Pending MeshTyping
void init_Mesh(Mesh* mesh, MeshType type){
    
    switch(type){
        case SQUARE:
            mesh->mesh_type = SQUARE;
            
            break;
    }
    
    create_VertexData(mesh->VO);
    
    return mesh;
}

//Pending MeshTyping
static void create_VertexData(VertexObject* vo){
    float vertices[] = {
        0.0f, 0.0f,   0.5f, 0.0f,   0.0f,-0.5f,   0.5f, -0.5f
    };
    unsigned int indices[] = {
        0,1,2,  1,2,3
    };

    glGenBuffers(1, vo->EBO);
    glGenBuffers(1, vo->VBO);
    glGenVertexArrays(1, vo->VAO);
    glBindVertexArray(vo->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, vo->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vo->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    vo->index_count = sizeof(indices) / sizeof(unsigned int);

    glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, 2*sizeof(float), NULL);
    glEnableVertexAttribArray(0);
}


//Pending MeshTyping
void render_Mesh(Mesh* mesh){
    //switch(MeshType){
    //  case SQUARE: 
    glBindVertexArray(mesh->VO->VAO);
    glDrawElements(GL_TRIANGLES, mesh->VO->index_count,GL_UNSIGNED_INT, 0);
    // break;
    //}
    glBindVertexArray(0);
}
