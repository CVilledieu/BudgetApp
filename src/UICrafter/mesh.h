#ifndef MESH_H
#define MESH_H

//Forward declarations
typedef struct Shader;
typedef struct VertexData;
typedef enum MeshType;

typedef float Mat4[16];
typedef float Vec4[4];

typedef struct Mesh {
    MeshType mType;
    VertexObject* VO;
    Shader* shader;
} Mesh;

typedef enum MeshType{
    SQUARE,
} MeshType;

typedef struct Shader{
    unsigned int id;
    int color_u_loc;
    int view_u_loc;
    int model_u_loc; 
} Shader;

typedef struct VertexObject{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    int index_count;
}VertexObject;

typedef enum {
    UNIFORM_VEC2,
    UNIFORM_VEC3,
    UNIFORM_VEC4,
    UNIFORM_MAT3,
    UNIFORM_MAT4
} UniformType;


Mesh* init_Mesh(MeshType type);
void render_Mesh(Mesh* mesh);
void set_uniform(unsigned int location, void* data, UniformType type);


#endif