#ifndef MESH_H
#define MESH_H


typedef struct Mesh{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int shader;
    int count;
    
}Mesh;

Mesh* Mesh_init(unsigned int shader_id);

#endif