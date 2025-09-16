#ifndef MESH_H
#define MESH_H


#define MAX_MESH_TYPES 1

//Forward declarations
typedef struct Shader;
typedef struct VertexData;
typedef enum MeshType;
typedef enum UniformType;

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
    UNI_VEC2,
    UNI_VEC4,
    UNI_MAT4,
} UniformType;


Mesh* init_Mesh(MeshType type);
void render_Mesh(Mesh* mesh, Mat4 model, Vec4 color);
void init_Mesh_array(Mesh meshes[MAX_MESH_TYPES]);

void set_uniform(unsigned int location, void* data, UniformType type);

#endif