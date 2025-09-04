#ifndef MESH_H
#define MESH_H


typedef struct Mesh{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int shader_id;
    int index_count;
    float* color; 
}Mesh;

Mesh* Mesh_init(void);

#endif