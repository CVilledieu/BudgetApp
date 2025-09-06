#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "mesh.h"



Mesh* Mesh_init(void){
    Mesh* mesh = malloc(sizeof(Mesh));

    float vertices[] = {
        0.0f, 0.0f,   0.5f, 0.0f,   0.0f,-0.5f,   0.5f, -0.5f
    };
    unsigned int indices[] = {
        0,1,2,  1,2,3
    };

    glGenBuffers(1, &mesh->EBO);
    glGenBuffers(1, &mesh->VBO);
    glGenVertexArrays(1, mesh->VAO);
    glBindVertexArray(mesh->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    mesh->index_count = sizeof(indices) / sizeof(unsigned int);

    glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return mesh;
}

