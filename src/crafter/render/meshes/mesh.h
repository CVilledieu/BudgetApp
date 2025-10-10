#ifndef MESH_H
#define MESH_H

#include "shaders.h"

typedef enum {
    SQUARE_MESH,
    TRIANGLE_MESH,
    LINE_MESH,
    GLYPH_MESH, //Labels or text. Avoiding TEXT unless I find a better word than texture for shaders
    MESH_TYPE_COUNT,
} MeshType;

//Shader_index is the ShaderType by having the ShadersLoaded onto the controller in the same order as the enum
//This may lead to problems down the road, but it may cut down on some unneeded searching/look ups
typedef struct Mesh {
    MeshType type;
    unsigned int VAO;
    int index_count;
} Mesh;

typedef struct Texture{ //test
    unsigned int id;
    float height;
    float width;
} Texture;

Mesh* init_Mesh(MeshType type);
void render_Mesh(Mesh* mesh);

#endif