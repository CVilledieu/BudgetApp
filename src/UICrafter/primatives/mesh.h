#ifndef MESH_H
#define MESH_H

#include "shaders.h"

#define MAX_MESH_TYPES 1

//Forward declarations
typedef struct VertexData;
typedef enum MeshType;

typedef float Mat4[16];
typedef float Vec4[4];
typedef float Vec2[2];

typedef struct Mesh {
    MeshType mType;
    VertexObject* VO;
    Shader* shader;
} Mesh;

typedef enum {
    SQUARE,
} MeshType;


typedef struct VertexObject{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    int index_count;
}VertexObject;



Mesh* init_Mesh(MeshType type);
void render_Mesh(Mesh* mesh, Mat4 model, Vec4 color);
void init_Mesh_array(Mesh meshes[MAX_MESH_TYPES]);


#endif