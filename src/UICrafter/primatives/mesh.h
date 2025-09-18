#ifndef MESH_H
#define MESH_H

#include "shaders.h"

#define MAX_MESH_TYPES 1

//Forward declarations
typedef struct VertexData;

typedef enum {
    SQUARE,
} MeshType;

typedef struct Mesh {
    MeshType mesh_type;
    VertexObject* VO;
    Shader* shader;
} Mesh;

typedef struct VertexObject{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    int index_count;
}VertexObject;



Mesh* init_Mesh(MeshType type);
void render_Mesh(Mesh* mesh);
void init_Mesh_array(Mesh meshes[MAX_MESH_TYPES]);


#endif