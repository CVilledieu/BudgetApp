#ifndef MESH_H
#define MESH_H

typedef float Vec2[2];
typedef float Vec4[4];

typedef struct Mesh{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    int index_count;
}Mesh;

Mesh* Mesh_init(void);
void Mesh_draw(Mesh* mesh);

#endif