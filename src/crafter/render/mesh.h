#ifndef MESH_H
#define MESH_H

#include "shaders.h"

typedef enum {
    SQUARE,
    ROUNDED, //Square with rounded edges
    CIRCLE, //or round
    LINE,
    TRIANGE,
    GLYPH, //Labels or text. Avoiding TEXT unless I find a better word than texture for shaders
    MESH_TYPE_COUNT,
} MeshType;

typedef struct VertexObject{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    int index_count;
}VertexObject;

//Shader_index is the ShaderType by having the ShadersLoaded onto the controller in the same order as the enum
//This may lead to problems down the road, but it may cut down on some unneeded searching/look ups
typedef struct Mesh {
    MeshType mesh_type;
    ShaderType shader_type; //Shader_type = Shader_index
    VertexObject* VO; //Since these are simply values I should be able to pass by value instead of a pointer
} Mesh;

Mesh* init_Mesh(MeshType type);
void render_Mesh(Mesh* mesh);

#endif