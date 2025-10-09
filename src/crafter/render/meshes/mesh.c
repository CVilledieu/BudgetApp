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
#include "vertex.h"

//Forward declarations
void create_Mesh(Mesh* mesh);

Mesh* init_Mesh(MeshType type){
    Mesh* mesh = malloc(sizeof(Mesh));
    mesh->type = type;
    mesh->VAO = 0;
    mesh->index_count = 0;
    create_Mesh(mesh); 
    return mesh;
}

static void create_Mesh(Mesh* mesh){
    glGenVertexArrays(1, &mesh->VAO);
    glBindVertexArray(mesh->VAO);
    switch(mesh->type){
        case MESH_TRIANGLE:
            create_TRIANGLE(mesh);
            break;
        case MESH_SQUARE:
            create_SQUARE(mesh);
            break;
        default:
            //Handle error
            break;
    }
    glBindVertexArray(0);
}


void create_SQUARE(Mesh* mesh){
    unsigned int EBO, VBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, SQUARE_VERT_SIZE, SQUARE_VERT, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, SQUARE_INDEX_SIZE, SQUARE_INDICES, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    mesh->index_count = SQUARE_INDEX_SIZE / sizeof(unsigned int);
    return mesh;
}

void create_TRIANGLE(Mesh* mesh){
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, TRIANGLE_VERT_SIZE, TRIANGLE_VERT, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
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
